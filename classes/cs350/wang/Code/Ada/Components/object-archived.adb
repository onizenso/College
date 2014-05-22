--                                                                    --
--  package Object.Archived         Copyright (c)  Dmitry A. Kazakov  --
--  Implementation                                 Luebeck            --
--                                                 Summer, 2003       --
--                                                                    --
--                                Last revision :  18:59 10 Feb 2008  --
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

with Ada.IO_Exceptions;     use Ada.IO_Exceptions;
with Object.Archived.Sets;  use Object.Archived.Sets;

package body Object.Archived is
   use Dispatch_Tables;

   package Link_Handles is
      new Object.Handle (Backward_Link, Backward_Link_Ptr);
   use Link_Handles;

   procedure Attach
             (  Link   : Backward_Link_Ptr;
                Object : Deposit_Ptr
             )  is
   begin
      Detach (Link.all);
      if Object /= null then
         Link.Object := Object;
         if Object.Delivery = null then
            Object.Delivery := Link;
            Link.Next := Link;
            Link.Prev := Link;
         else
            Link.Next      := Object.Delivery; -- This -> List head
            Link.Prev      := Link.Next.Prev;  -- List tail <- This
            Link.Prev.Next := Link;
            Link.Next.Prev := Link;
         end if;
      end if;
   end Attach;

   procedure Close (Object : in out Deposit'Class) is
      This : Backward_Link_Ptr := Object.Delivery;
      Lock : Link_Handles.Handle;
   begin
      while Object.Delivery /= null loop
         Lock := Ref (This);
         Destroyed (This.all);
         Detach (This.all);
         This := Object.Delivery;
      end loop;
   end Close;

   procedure Create
             (  Source  : String;
                Pointer : in out Integer;
                Class   : String;
                List    : Deposit_Container'Class;
                Object  : out Deposit_Ptr
             )  is
      Constructor : Restore;
   begin
      begin
         Constructor := Find (Dispatch_Table, Class);
      exception
         when End_Error =>
            raise Name_Error;
      end;
      Constructor (Source, Pointer, Class, List, Object);
   end Create;

   procedure Delete (Object : in out Deposit'Class) is
      Set  : Deposit_Set;
      Lock : Link_Handles.Handle;
      This : Backward_Link_Ptr := Object.Delivery;
      Next : Backward_Link_Ptr;
   begin
      while Object.Delivery /= null loop
         Next := This.Next;
         Lock := Ref (This);
         Deleted (This.all, Set);
         exit when Next = Object.Delivery;
         This := Next;
      end loop;
   end Delete;

   procedure Detach (Link : in out Backward_Link)  is
   begin
      if Link.Object /= null then
         if Link.Next = Link.Next.Next then
            Link.Object.Delivery := null;           -- The only item
         else
            if Link.Next.Prev = Link.Object.Delivery then
               Link.Object.Delivery := Link.Next;   -- The first item
            end if;
            Link.Next.Prev := Link.Prev;
            Link.Prev.Next := Link.Next;
         end if;
         Link.Object := null;
      end if;
   end Detach;

   procedure Finalize (Object : in out Deposit) is
   begin
      Close (Object);
      Finalize (Entity (Object));
   end Finalize;

   procedure Finalize (Link : in out Backward_Link) is
   begin
      Detach (Link);
      Finalize (Entity (Link));
   end Finalize;

   procedure Get_Referents
             (  Object    : Deposit;
                Container : in out Deposit_Container'Class
             )  is
   begin
      null;
   end Get_Referents;

   function Is_Empty (Container : Deposit_Container'Class)
      return Boolean is
   begin
      return Get_Size (Container) = 0;
   end Is_Empty;

   function Is_Registered (Class : String) return Boolean is
      Ptr : Restore;
   begin
      Ptr := Find (Dispatch_Table, Class);
      return True;
   exception
      when End_Error =>
         return False;
   end Is_Registered;

   procedure Register_Class
             (  Class       : String;
                Constructor : Restore
             )  is
   begin
      Add (Dispatch_Table, Class, Constructor);
   exception
      when Name_Error =>
         if Find (Dispatch_Table, Class) /= Constructor then
            raise;
         end if;
   end Register_Class;

   function Self (Link : Backward_Link) return Backward_Link_Ptr is
   begin
      if Link.Object = null then
         raise Constraint_Error;
      else
         return Link.Next.Prev;
      end if;
   end Self;

   function This (Link : Backward_Link) return Deposit_Ptr is
   begin
      if Link.Object = null then
         raise Constraint_Error;
      else
         return Link.Object;
      end if;
   end This;

end Object.Archived;
