--                                                                    --
--  package                         Copyright (c)  Dmitry A. Kazakov  --
--     Generic_Indefinite_FIFO                     Luebeck            --
--                                                 Summer, 2008       --
--  Implementation                                                    --
--                                Last revision :  15:51 13 Dec 2008  --
--                                                                    --
--  This  library  is  free software; you can redistribute it and/or  --
--  modify it under the terms of the GNU General Public  License  as  --
--  published by the Free Software Foundation; either version  2  of  --
--  the License, or (at your option) any later version. This library  --
--  is distributed in the hope that it will be useful,  but  WITHOUT  --
--  ANY   WARRANTY;   without   even   the   implied   warranty   of  --
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  --
--  General  Public  License  for  more  details.  You  should  have  --
--  received  a  copy  of  the GNU General Public License along with  --
--  this library; if not, write to  the  Free  Software  Foundation,  --
--  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.    --
--                                                                    --
--  As a special exception, if other files instantiate generics from  --
--  this unit, or you link this unit with other files to produce  an  --
--  executable, this unit does not by  itself  cause  the  resulting  --
--  executable to be covered by the GNU General Public License. This  --
--  exception  does not however invalidate any other reasons why the  --
--  executable file might be covered by the GNU Public License.       --
--____________________________________________________________________--

with Ada.Unchecked_Deallocation;
with Ada.Unchecked_Conversion;

package body Generic_Indefinite_FIFO is

   Address_Offset : Storage_Offset := 0; -- To the "official" address

   procedure Allocate
             (  Queue     : in out FIFO;
                Address   : out System.Address;
                Size      : Storage_Count;
                Alignment : Storage_Count
             )  is
      Total : constant Storage_Count := Size - (Size mod (-Alignment));
      Free  : constant Storage_Count := Queue.Free + Total;
   begin
      if Free_Space (Queue) < Total then
         raise Storage_Error;
      elsif Free > Queue.Size then
         if Free = Queue.Size + 1 then
            -- Exact fit
            Address := Queue.Storage (Queue.Free)'Address;
            Queue.Cut_Off := Free;
            Queue.Next    := 1;
         elsif Queue.First <= Total + 1 then
            if Queue.First = Queue.Free then
               -- This the case when the buffer is fragmented
               -- while it is empty. In this case we can reset
               -- First to 1
               Queue.Empty   := True;
               Queue.Cut_Off := Queue.Size + 1;
               Queue.Next    := Total + 1;
               Queue.First   := 1;
               Address := Queue.Storage (1)'Address;
            else
               raise Storage_Error;
            end if;
         else
            -- Cutting the tail off and moving to the buffer beginning
            Queue.Cut_Off := Queue.Free;
            Queue.Next    := Total + 1;
            Address := Queue.Storage (1)'Address;
         end if;
      else
         -- No wrapping
         Address := Queue.Storage (Queue.Free)'Address;
         Queue.Next := Free;
      end if;
      Queue.Last := Address;
   end Allocate;

   procedure Delete
             (  Queue : in out FIFO;
                Count : Natural := 1
             )  is
      type Element_Ptr is access Element_Type;
      for Element_Ptr'Size use Integer_Address'Size;
      for Element_Ptr'Storage_Pool use Queue;
      function To_Pointer is
         new Ada.Unchecked_Conversion (System.Address, Element_Ptr);
      procedure Free is
         new Ada.Unchecked_Deallocation (Element_Type, Element_Ptr);
      This : Element_Ptr;
   begin
      for Element in 1..Count loop
         exit when Queue.First = Queue.Free or else Queue.Empty;
         This :=
            To_Pointer
            (  Queue.Storage (Queue.First + Address_Offset)'Address
            );
         Free (This);
      end loop;
   end Delete;

   procedure Deallocate
             (  Queue     : in out FIFO;
                Address   : System.Address;
                Size      : Storage_Count;
                Alignment : Storage_Count
             )  is
      Total : constant Storage_Count := Size - (Size mod (-Alignment));
      First : constant Storage_Count := Queue.First + Total;
   begin
      if First >= Queue.Cut_Off then
         Queue.Cut_Off := Queue.Size + 1;
         Queue.First   := 1;
      else
         Queue.First := First;
      end if;
   end Deallocate;

   function Free_Space (Queue : FIFO) return Storage_Count is
      Count : Storage_Offset := Queue.First - Queue.Free;
   begin
      if Count <= 0 then
         return Queue.Size + Count - 1;
      else
         return Count - 1;
      end if;
   end Free_Space;

   function Get (Queue : FIFO) return Element_Type is
      type Element_Ptr is access Element_Type;
      for Element_Ptr'Size use Integer_Address'Size;
      for Element_Ptr'Storage_Pool use Queue.Self.all;
      function To_Pointer is
         new Ada.Unchecked_Conversion (System.Address, Element_Ptr);
      procedure Free is
         new Ada.Unchecked_Deallocation (Element_Type, Element_Ptr);
      This : Element_Ptr;
   begin
      if Queue.First = Queue.Free or else Queue.Empty then
         raise Constraint_Error;
      else
         This :=
            To_Pointer
            (  Queue.Storage (Queue.First + Address_Offset)'Address
            );
         declare
            Result : Element_Type := This.all;
         begin
            Free (This);
            return Result;
         end;
      end if;
   end Get;

   function Is_Empty (Queue : FIFO) return Boolean is
   begin
      return Queue.First = Queue.Free or else Queue.Empty;
   end Is_Empty;

   function Peek (Queue : FIFO) return Element_Type is
      type Element_Ptr is access Element_Type;
      for Element_Ptr'Size use Integer_Address'Size;
      for Element_Ptr'Storage_Pool use Queue.Self.all;
      function To_Pointer is
         new Ada.Unchecked_Conversion (System.Address, Element_Ptr);
   begin
      if Queue.First = Queue.Free or else Queue.Empty then
         raise Constraint_Error;
      else
         return
            To_Pointer
            (  Queue.Storage (Queue.First + Address_Offset)'Address
            ) .all;
      end if;
   end Peek;

   procedure Put
             (  Queue   : in out FIFO;
                Element : Element_Type
             )  is
      type Element_Ptr is access Element_Type;
      for Element_Ptr'Storage_Pool use Queue;
      Ptr : Element_Ptr;
   begin
      Ptr := new Element_Type'(Element);
      Address_Offset := Ptr.all'Address - Queue.Last;
      Queue.Free  := Queue.Next;
      Queue.Empty := False;
   exception
      when Storage_Error =>
         raise Constraint_Error;
   end Put;

   function Storage_Size (Queue : FIFO)
      return Storage_Count is
   begin
      return Queue.Size;
   end Storage_Size;

end Generic_Indefinite_FIFO;
