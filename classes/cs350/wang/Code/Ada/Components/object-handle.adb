--                                                                    --
--  package Object.Handle           Copyright (c)  Dmitry A. Kazakov  --
--  Implementation                                 Luebeck            --
--                                                 Winter, 2002       --
--                                                                    --
--                                Last revision :  09:14 29 Jun 2008  --
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

package body Object.Handle is

   procedure Adjust (Reference : in out Handle) is
   begin
      if Reference.Ptr /= null then
         Reference.Ptr.Use_Count := Reference.Ptr.Use_Count + 1;
      end if;
   end Adjust;

   procedure Finalize (Reference : in out Handle) is
   begin
      Release (Reference.Ptr);
      Reference.Ptr := null;
   end Finalize;

   procedure Invalidate (Reference : in out Handle) is
   begin
      if Reference.Ptr /= null then
         Release (Reference.Ptr);
         Reference.Ptr := null;
      end if;
   end Invalidate;

   function Is_Valid (Reference : Handle) return Boolean is
   begin
      return Reference.Ptr /= null;
   end Is_Valid;

   function Ptr (Reference : Handle) return Object_Type_Ptr is
   begin
      return Reference.Ptr;
   end Ptr;

   function Ref (Thing : Object_Type_Ptr) return Handle is
   begin
      if Thing /= null then
         Thing.Use_Count := Thing.Use_Count + 1;
      end if;
      return Handle'(Ada.Finalization.Controlled with Thing);
   end Ref;

   procedure Release (Ptr : in out Object_Type_Ptr) is
      Pointer : Entity_Ptr := Entity_Ptr (Ptr);
   begin
      Release (Pointer);
      if Pointer = null then
         Ptr := null;
      end if;
   end Release;

   procedure Set (Reference : in out Handle; Thing : Object_Type_Ptr) is
   begin
      if Reference.Ptr /= Thing then
         if Reference.Ptr /= null then
            Release (Reference.Ptr);
         end if;
         if Thing /= null then
            Thing.Use_Count := Thing.Use_Count + 1;
            Reference.Ptr := Thing;
         end if;
      end if;
   end Set;

   function "<" (Left, Right : Handle) return Boolean is
   begin
      return Less (Left.Ptr.all, Right.Ptr.all);
   end "<";

   function "<=" (Left, Right : Handle) return Boolean is
   begin
      return
      (  Equal (Left.Ptr.all, Right.Ptr.all)
      or else
         Less (Left.Ptr.all, Right.Ptr.all)
      );
   end "<=";

   function "=" (Left, Right : Handle) return Boolean is
   begin
      if Left.Ptr = null then
         if Right.Ptr = null then
            return True;
         else
            return False;
         end if;
      else
         if Right.Ptr = null then
            return False;
         else
            return Equal (Left.Ptr.all, Right.Ptr.all);
         end if;
      end if;
   end "=";

   function ">=" (Left, Right : Handle) return Boolean is
   begin
      return not Less (Left.Ptr.all, Right.Ptr.all);
   end ">=";

   function ">" (Left, Right : Handle) return Boolean is
   begin
      return
         not
         (  Equal (Left.Ptr.all, Right.Ptr.all)
         or else
            Less (Left.Ptr.all, Right.Ptr.all)
         );
   end ">";

   function "="  (Left : Handle; Right : access Object_Type'Class)
      return Boolean is
   begin
      return
      (  Left.Ptr /= null
      and then
         Left.Ptr.all'Unchecked_Access = Right
      );
   end "=";

   function "="  (Left : access Object_Type'Class; Right : Handle)
      return Boolean is
   begin
      return
      (  Right.Ptr /= null
      and then
         Right.Ptr.all'Unchecked_Access = Left
      );
   end "=";

end Object.Handle;
