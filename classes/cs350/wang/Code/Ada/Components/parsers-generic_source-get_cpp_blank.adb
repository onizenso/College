--                                                                    --
--  procedure                       Copyright (c)  Dmitry A. Kazakov  --
--     Parsers.Generic_Source.                     Luebeck            --
--        Get_Cpp_Blank                            Winter, 2004       --
--  Implementation                                                    --
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

with Ada.Characters.Latin_1;  use Ada.Characters.Latin_1;
with Ada.IO_Exceptions;       use Ada.IO_Exceptions;
with Ada.Strings.Maps;        use Ada.Strings.Maps;
with Strings_Edit;            use Strings_Edit;

procedure Parsers.Generic_Source.Get_Cpp_Blank
          (  Code     : in out Source_Type;
             Got_It   : out Boolean;
             Error    : out Boolean;
             Error_At : out Location_Type
          )  is
   To_Skip : constant Character_Set :=
                         To_Set (' ' & HT & VT & CR & LF & FF);
   Line    : Line_Ptr_Type;
   Pointer : Integer;
   Last    : Integer;
   --
   -- Skip_Comment -- The body of
   --
   -- Returns :
   --
   --    True if */ was matched, and false, otherwise (end of string)
   --
   function Skip_Comment return Boolean is
      Index : Integer := Pointer;
   begin
      while Index < Last loop
         if Line (Index..Index + 1) = "*/" then
            Pointer := Index + 2;
            return True;
         end if;
         Index := Index + 1;
      end loop;
      return False;
   end Skip_Comment;
   --
   -- Skip_Blank -- Blank text outside comment
   --
   -- Returns :
   --
   --    True  if  a  non-blank  character  is  found,  and  that is not
   --    beginning of a comment. 
   --
   function Skip_Blank return Boolean is
      Index : Integer := Pointer;
   begin
      Get (Line (Line'First..Last), Index, To_Skip);
      Pointer := Index;
      if Index > Last then
         return False;
      end if;
      if (  Index = Last
         or else
            (  Line (Index..Index + 1) /= "//"
            and then
               Line (Index..Index + 1) /= "/*"
         )  )
      then
         return True;
      end if;
      if Line (Index + 1) = '/' then
         Pointer := Last + 1;
      end if;
      return False;
   end Skip_Blank;

   In_Comment : Boolean := False;
begin
   loop
      Get_Line (Code, Line, Pointer, Last);
      loop
         if In_Comment then
            if Skip_Comment then
               In_Comment := False;
            else
               exit;   -- End of line in /*..*/
            end if;
         else
            if Skip_Blank then
               Got_It := True;
               Error  := False;
               Set_Pointer (Code, Pointer);
               return;
            elsif Pointer < Last then
               Set_Pointer (Code, Pointer);
               Pointer := Pointer + 2;
               Set_Pointer (Code, Pointer);
               Error_At   := Link (Code);
               In_Comment := True;
            else
               exit;   -- End of line in the text
            end if;
         end if;
      end loop;
      Set_Pointer (Code, Last + 1);
      Next_Line (Code);
   end loop;
exception
   when End_Error =>
      Got_It := False;
      Error  := In_Comment;
end Parsers.Generic_Source.Get_Cpp_Blank;
