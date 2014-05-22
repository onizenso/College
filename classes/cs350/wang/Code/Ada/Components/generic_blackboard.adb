--                                                                    --
--  package Generic_Blackboard      Copyright (c)  Dmitry A. Kazakov  --
--  Implementation                                 Luebeck            --
--                                                 Autumn, 2007       --
--                                                                    --
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

with System.Address_To_Access_Conversions;

package body Generic_Blackboard is
   use System;

   Storage_Offset_Size : constant Storage_Count :=
      (Storage_Count'Size + Storage_Unit - 1) / Storage_Unit;
   Aligned_Storage_Offset_Size : constant Storage_Count :=
      (  Storage_Offset_Size
      -  (Storage_Offset_Size mod (-Element_Type'Alignment))
      );

   Address_Offset : Storage_Offset := 0; -- To the "official" address
--
-- Stored_Offset -- A sequence  of  storage  elements  of  the  size  of
--                  Storage_Offset. It is used  to  pack  Storage_Offset
--                  items into arrays of Storage_Element.
--
   subtype Stored_Offset is Buffer (1..Storage_Offset_Size);

   package Stored_Offset_Access is
      new System.Address_To_Access_Conversions (Stored_Offset);
   use Stored_Offset_Access;

   package Element_Type_Access is
      new System.Address_To_Access_Conversions (Element_Type);
   use Element_Type_Access;

   function Get_Offset
            (  Storage : Blackboard'Class;
               Pointer : Reference
            )  return Storage_Offset is
      pragma Inline (Get_Offset);
   begin
      return Storage_Offset (Pointer mod Reference (Storage.Size));
   end Get_Offset;

   function Get_Block_Size
            (  Storage : Blackboard'Class;
               Offset  : Storage_Offset
            )  return Storage_Offset is
      pragma Inline (Get_Block_Size);
      Size : aliased Storage_Offset;
   begin
      To_Pointer (Size'Address).all :=
         Storage.Data (Offset + 1..Offset + Storage_Offset_Size);
      return Size;
   end Get_Block_Size;

   procedure Allocate
             (  Storage   : in out Blackboard;
                Address   : out System.Address;
                Size      : Storage_Count;
                Alignment : Storage_Count
             )  is
      Parameters : Put_Parameters renames Storage.Parameters.all;
      Length : Storage_Count := Size + Aligned_Storage_Offset_Size;
      Upper  : Storage_Count := Get_Offset (Storage, Storage.Upper);
      Lower  : Storage_Count := Get_Offset (Storage, Storage.Lower);
   begin
      Parameters.Pointer := Storage.Upper;
      if Alignment /= 0 then
         -- Rounding Length to have all following elements aligned
         Length := Length - (Length mod (-Alignment));
      end if;
      Parameters.Pointer := Storage.Upper;
      if Upper + Length > Storage.Size then
         if Length > Storage.Size then   -- Too large to fit
            raise Storage_Error;
         end if;
         --
         -- We have to wrap the buffer
         --
         if Lower >= Upper then
            --
            -- |<-current->|             |<-previous->|
            -- |           |<---------new-block-------|--->
            -- |           |Upper        |Lower       |
            -- |<Lower                                |
            --
            Storage.Lower :=
               Storage.Lower + Reference (Storage.Size - Lower);
         end if;
         if Upper + Length > Storage.Size then
            --
            -- |   |<-current->|<-----new-block-------|-->
            -- |   |<Lower     |<Upper                |
            -- |               |0000000000000000000000|
            -- |<Upper
            --
            for Index in Upper + 1..Storage.Size loop
               Storage.Data (Index) := 0;
            end loop;
            --
            -- Moving to the next frame
            --
            Parameters.Pointer :=
               Parameters.Pointer + Reference (Storage.Size - Upper);
            Upper := 0;
         end if;
      end if;
      --
      -- Here  we  already  know  that  the new block would fit into the
      -- buffer. We have to move Storage.Lower by block if necessary.
      --
      if (  Storage.Lower /= Storage.Upper -- Not empty
         and then            -- |<-current->|             |<-previous->|
            Lower >= Upper   -- |           |<--new-block-|-->         |
         and then            -- |           |Upper        |Lower       |
            Lower - Upper < Length
         )
      then
         --
         -- We have to move Storage.Lower by  block  sizes  until  there
         -- would be Length place between Upper and Lower.
         --
         declare
            Old  : constant Storage_Offset := Lower;
            Size : Storage_Offset;
         begin
            Size := Get_Block_Size (Storage, Lower);
            if Size > 0 then
               loop
                  Lower := Lower + Size;
                  exit when Lower >= Storage.Size;
                  Size := Get_Block_Size (Storage, Lower);
                  exit when Size <= 0;
                  if Lower - Upper >= Length then
                     --
                     -- Now we have the place. Storage.Lower is advanced
                     -- to this index staying in the current frame.
                     --
                     Storage.Lower :=
                        Storage.Lower + Reference (Lower - Old);
                     goto Done;
                  end if;
               end loop;
            end if;
            --
            -- The rest of the buffer is unused. Storage.Lower  is
            -- advanced to the next frame.
            --
            Storage.Lower :=
               (  Storage.Lower
               +  Reference
                  (  Storage.Size
                  -  Get_Offset (Storage, Storage.Lower)
               )  );
         end;
      end if;
<<Done>>
      Parameters.Index  := Upper + 1;
      Parameters.Length := Length;
      Address :=
         Storage.Data (Upper + 1)'Address + Aligned_Storage_Offset_Size;
   end Allocate;

   procedure Deallocate
             (  Storage   : in out Blackboard;
                Address   : System.Address;
                Size      : Storage_Count;
                Alignment : Storage_Count
             )  is
   begin
      null;
   end Deallocate;

   function First (Storage : Blackboard) return Reference is
   begin
      return Storage.Lower;
   end First;

   function Get (Storage : Blackboard; Pointer : Reference)
      return Element_Type is
      Offset : Storage_Count := Get_Offset (Storage, Pointer);
      Size   : Storage_Offset;
   begin
      if Pointer >= Storage.Upper then
         raise Constraint_Error;
      end if;
      Size :=
         Get_Block_Size (Storage, Offset) - Aligned_Storage_Offset_Size;
      if Size <= 0 or else Pointer < Storage.Lower then
         raise Constraint_Error;
      end if;
      --
      -- The  size  must  be valid, that means we can use it to copy the
      -- data from the buffer
      --
      Offset := Offset + Aligned_Storage_Offset_Size;
      declare
         Result : Buffer (1..Size) :=
                     Storage.Data (Offset + 1..Offset + Size);
      begin
         --
         -- Here Result contains a raw bit-wise copy of  the  referenced
         -- item. If the reference is no longer valid, we just  drop  an
         -- exception. Otherwise  it  is  safe  to  convert  it  to  the
         -- legitimate  element  type.  Address to pointer conversion is
         -- used for. Note how Address_Offset is  added  to  obtain  the
         -- "official" address. The offset  is  0  for  all  types,  but
         -- indefinite arrays. Though the offset is static it need to be
         -- evaluated, which the procedure Put does.
         --
         if Pointer < Storage.Lower then
            raise Constraint_Error;
         else
            return To_Pointer (Result'Address + Address_Offset).all;
         end if;
      end;
   end Get;

   function Is_Valid (Storage : Blackboard; Pointer : Reference)
      return Boolean is
   begin
      return Pointer >= Storage.Lower and then Pointer < Storage.Upper;
   end Is_Valid;

   procedure Next
             (  Storage : Blackboard;
                Pointer : in out Reference;
                Sequent : out Boolean
             )  is
      Offset : Storage_Count;
      Size   : Storage_Offset;
      Moved  : Boolean := False;
   begin
      Sequent := True;
      loop
         if Pointer >= Storage.Upper then
            return;
         end if;
         Offset := Get_Offset (Storage, Pointer);
         Size   := Get_Block_Size (Storage, Offset);
         if Pointer < Storage.Lower then
            Pointer := Storage.Lower;
            Sequent := False;
            return;
         end if;
         if Size <= 0 then
            Pointer := Pointer + Reference (Storage.Size - Offset);
         else
            exit when Moved;
            Moved   := True;
            Pointer := Pointer + Reference (Size);
         end if;
      end loop;
   end Next;

   procedure Put
             (  Storage : in out Blackboard;
                Element : Element_Type;
                Pointer : out Reference
             )  is
      --
      -- The implementation of Blackboard is a storage pool. So in order
      -- to  copy something into, we just allocate it there. For this an
      -- access type is created.
      --
      type Element_Type_Ptr is access Element_Type;
      for Element_Type_Ptr'Storage_Pool use Storage;

      Parameters : aliased Put_Parameters;
      Ptr        : Element_Type_Ptr;
   begin
      Storage.Parameters := Parameters'Unchecked_Access;
      Ptr := new Element_Type'(Element);
      --
      -- A  copy of Element is allocated and Ptr is a pointer to it. The
      -- pointer might be shifted if Element  is  an  indefinite  array.
      -- Usually  the  array address is the address of its first element
      -- rather than of the first allocated storage element. This offset
      -- is type specific and need to be evaluated. Which is the purpose
      -- of Address_Offset.
      --
      Address_Offset :=
         (  Ptr.all'Address
         -  Storage.Data (Parameters.Index)'Address
         -  Aligned_Storage_Offset_Size
         );
      Storage.Data       -- Store the block size in front of the element
      (  Parameters.Index
      .. Parameters.Index + Storage_Offset_Size - 1
      )  := To_Pointer (Parameters.Length'Address).all;
      --
      -- Finally, move the upper reference making new element accessible
      --
      Pointer       := Parameters.Pointer;
      Storage.Upper := Pointer + Reference (Parameters.Length);
   end Put;

   procedure Put
             (  Storage : in out Blackboard;
                Element : Element_Type
             )  is
      type Element_Type_Ptr is access Element_Type;
      for Element_Type_Ptr'Storage_Pool use Storage;

      Parameters : aliased Put_Parameters;
      Ptr        : Element_Type_Ptr;
   begin
      Storage.Parameters := Parameters'Unchecked_Access;
      Ptr := new Element_Type'(Element);
      --
      -- A  copy of Element is allocated and Ptr is a pointer to it. The
      -- pointer might be shifted if Element  is  an  indefinite  array.
      -- Usually  the  array address is the address of its first element
      -- rather than of the first allocated storage element. This offset
      -- is type specific and need to be evaluated. Which is the purpose
      -- of Address_Offset.
      --
      Address_Offset :=
         (  Ptr.all'Address
         -  Storage.Data (Parameters.Index)'Address
         -  Aligned_Storage_Offset_Size
         );
      Storage.Data       -- Store the block size in front of the element
      (  Parameters.Index
      .. Parameters.Index + Storage_Offset_Size - 1
      )  := To_Pointer (Parameters.Length'Address).all;
      --
      -- Finally, move the upper reference making new element accessible
      --
      Storage.Upper :=
         Parameters.Pointer + Reference (Parameters.Length);
   end Put;

   function Storage_Size (Storage : Blackboard) return Storage_Count is
   begin
      return Storage.Size;
   end Storage_Size;

   function Upper (Storage : Blackboard) return Reference is
   begin
      return Storage.Upper;
   end Upper;

   function "<" (Storage : Blackboard; Pointer : Reference)
      return Boolean is
   begin
     return Storage.Upper <= Pointer;
   end "<";

   function ">" (Storage : Blackboard; Pointer : Reference)
      return Boolean is
   begin
     return Storage.Lower > Pointer;
   end ">";

   function "<" (Pointer : Reference; Storage : Blackboard)
      return Boolean is
   begin
     return Pointer < Storage.Lower;
   end "<";

   function ">" (Pointer : Reference; Storage : Blackboard)
      return Boolean is
   begin
     return Pointer >= Storage.Upper;
   end ">";

end Generic_Blackboard;
