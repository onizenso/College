--                                                                    --
--  package Object                  Copyright (c)  Dmitry A. Kazakov  --
--  Interface                                      Luebeck            --
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
--
-- The  package Object provides the type Entity serving as the base type
-- for all derived types which require a garbage collection and  handles
-- (see the child package Object.Handle). The  type  Entity  is  derived
-- from Ada.Finalization.Limited_Controlled. 
--
with Ada.Finalization;

package Object is
   pragma Preelaborate (Object);
   type Entity is new
      Ada.Finalization.Limited_Controlled with
   record
      Use_Count : Natural := 0; -- Reference count
   end record;
   type Entity_Ptr is access all Entity'Class;
--
-- Equal, Less -- Comparisons
--
--    Left  - An object (dispatching)
--    Right - An object (class)
--    Flag  - Recursion flag (used by implementation)
--
-- Note  that  because  Ada  95  has  no  proper  multiple dispatch, one
-- argument has to be made class-wide to avoid exceptions when type tags
-- differ.  When  the  second  argument  is  in  Handle'Class  then  the
-- addresses of of the objects are  compared.  Otherwise,  the  function
-- re-dispatches  according  to  the second argument. A derived type may
-- override this method in the first argument, which  action  will  then
-- have a symmeric effect. The parameter  Flag  is  used  internally  to
-- distinguish recursive calls. An implementation sets this parameter to
-- true when it makes a recursive call the function. It is necessary  to
-- avoid infinite recursion when the function is inherited. 
--
-- Returns :
--
--    The result of comparison
--
   function Equal
            (  Left  : Entity;
               Right : Entity'Class;
               Flag  : Boolean := False
            )  return Boolean;
   function Less
            (  Left  : Entity;
               Right : Entity'Class;
               Flag  : Boolean := False
            )  return Boolean;
--
-- Finalize -- Destructor
--
--    This - The object to be finalized
--
-- Exceptions :
--
--    Program_Error - The object is still in use
--
   procedure Finalize (This : in out Entity);
--
-- Release -- Decrement object's use count
--
--    Ptr - To the object
--
-- The object pointed by Ptr is deleted if its use count in 1. Otherwise
-- the use count is decremented. Nothing happens if Ptr is null.
--
-- Exceptions :
--
--    Program_Error - Use count is already zero
--
   procedure Release (Ptr : in out Entity_Ptr);
   pragma Inline (Release);

end Object;
