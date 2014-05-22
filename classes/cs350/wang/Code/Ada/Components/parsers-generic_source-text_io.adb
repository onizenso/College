--                                                                    --
--  package                         Copyright (c)  Dmitry A. Kazakov  --
--     Parsers.Generic_Source.Text_IO              Luebeck            --
--  Implementation                                 Winter, 2004       --
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

with Ada.Characters.Latin_1;  use Ada.Characters.Latin_1;

package body Parsers.Generic_Source.Text_IO is

   procedure Put_Line (File : File_Type; Code : Source_Type) is
      Line    : String  := Get_Line (Code);
      Pointer : Integer := Get_Pointer (Code);
   begin
      Put_Line (File, Line);
      for Index in Line'Range loop
         if Line (Index) /= ' ' and then Line (Index) /= HT then
            Line (Index) := ' ';
         end if;
      end loop;
      for Index in Get_Backup_Pointer (Code)..Pointer - 1 loop
         Line (Index) := '^';
      end loop;
      if Pointer in Line'Range then
         Line (Pointer) := '|';
         Put_Line (File, Line);
      else
         Put_Line (File, Line);
         Put (File, "|");
      end if;
   end Put_Line;

   procedure Put_Line (Code : Source_Type) is
   begin
      Put_Line (Standard_Output, Code);
   end Put_Line;

end Parsers.Generic_Source.Text_IO;
