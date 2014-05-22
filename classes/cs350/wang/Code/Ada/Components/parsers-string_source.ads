--                                                                    --
--  package                         Copyright (c)  Dmitry A. Kazakov  --
--     Parsers.String_Source                       Luebeck            --
--  Interface                                      Winter, 2004       --
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
--  This package provides an implementation of  code  sources  based  on
--  standard strings. 
--
with Parsers.Generic_Source;

package Parsers.String_Source is
   type Location is record
      From   : Integer;
      Length : Natural;
   end record;
--
-- Source -- The source containing only one string
--
--    Text - The source line
--
   type Source (Text : access String) is limited record
      Pointer : Integer := Text'First;
      Last    : Integer := Text'First;
   end record;
   type Line_Ptr is access constant String;
--
-- Implementations of the Parsers.Generic_Source interface
--
   function "&" (Left, Right : Location) return Location; 
   function End_Of (Code : Source) return Boolean;
      pragma Inline (End_Of);
   function Get_Backup_Pointer (Code : Source) return Integer;
      pragma Inline (Get_Backup_Pointer);
   function Get_Line (Code : Source) return String;
   procedure Get_Line
             (  Code    : Source;
                Line    : out Line_Ptr;
                Pointer : out Integer;
                Last    : out Integer
             );
      pragma Inline (Get_Line);
   function Get_Pointer (Code : Source) return Integer;
      pragma Inline (Get_Pointer);
   function Image (Link : Location) return String;
   function Link (Code : Source) return Location;
      pragma Inline (Link);
   procedure Next_Line (Code : in out Source);
   procedure Reset_Pointer (Code : in out Source);
      pragma Inline (Reset_Pointer);
   procedure Set_Pointer (Code : in out Source; Pointer : Integer);
--
-- Code -- The implementation
--
   package Code is new
      Parsers.Generic_Source
      (  Location_Type => Location,
         Source_Type   => Source,
         Line_Ptr_Type => Line_Ptr
      );

end Parsers.String_Source;
