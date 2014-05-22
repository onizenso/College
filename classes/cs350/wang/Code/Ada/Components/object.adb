--                                                                    --
--  package Object                  Copyright (c)  Dmitry A. Kazakov  --
--  Implementation                                 Luebeck            --
--                                                 Winter, 2002       --
--                                                                    --
--                                Last revision :  11:37 13 Oct 2007  --
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

with Ada.Exceptions;  use Ada.Exceptions;

with Ada.Unchecked_Deallocation;
with Ada.Tags;
with System; use type System.Address;

package body Object is

   procedure Finalize (This : in out Entity) is
   begin
      if 0 /= This.Use_Count then
         Raise_Exception
         (  Program_Error'Identity,
            (  Ada.Tags.Expanded_Name (Entity'Class (This)'Tag)
            &  " is still in use"
         )  );
      end if;
   end Finalize;

   procedure Free is new
      Ada.Unchecked_Deallocation (Entity'Class, Entity_Ptr);

   function Equal
            (  Left  : Entity;
               Right : Entity'Class;
               Flag  : Boolean := False
            )  return Boolean is
   begin
      if Flag or else Right in Entity then
         return Left'Address = Right'Address;
      else
         return Equal (Right, Left, True);
      end if;
   end Equal;

   function Less
            (  Left  : Entity;
               Right : Entity'Class;
               Flag  : Boolean := False
            )  return Boolean is
   begin
      if Flag or else Right in Entity then
         return Left'Address < Right'Address;
      else
         return
            not (Less (Right, Left, True) or else Equal (Right, Left));
      end if;
   end Less;

   procedure Release (Ptr : in out Entity_Ptr) is
   begin
      if Ptr /= null then
         declare
            Object : Entity renames Entity (Ptr.all);
         begin
            case Object.Use_Count is
               when 0 =>
                  Raise_Exception
                  (  Program_Error'Identity,
                     (  Ada.Tags.Expanded_Name (Ptr'Tag)
                     &  " is not in use"
                  )  );
               when 1 =>
                  Object.Use_Count := 0;
                  Free (Ptr);
               when others =>
                  Object.Use_Count := Object.Use_Count - 1;
            end case;
         end;
      end if;
   end Release;

end Object;
