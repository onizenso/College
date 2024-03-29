--                                                                    --
--  package                         Copyright (c)  Dmitry A. Kazakov  --
--     Parsers.Generic_Lexer.Ada_Blanks            Luebeck            --
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
--  This   package   provides  lexers  that  skip  blanks  by  consuming
--  characters CR, HT, VT,  LF,  FF,  SP  (carriage  return,  horizontal
--  tabulation,  vertical  tabulation,  line  feed, form feed, space). A
--  comment  ends  either  at  the  line end or in the one of the format
--  effectors as ARM 2.2(2) requires. It skips to the next  source  line
--  when necessary. The generic parameter is a lexer type, descendant of
--  Lexer defined in the  parent  package.  This  type  is  extended  to
--  provide the functionality.   
--
generic
   type Lexer_Type (<>) is
      abstract new Parsers.Generic_Lexer.Lexer with private;
package Parsers.Generic_Lexer.Ada_Blanks is
--
-- Lexer -- Lexer with Get_Blank defined
--
   type Lexer is abstract new Lexer_Type with null record;
--
-- Get_Blank -- Overrides Parsers.Generic_Lexer...
--
   procedure Get_Blank
             (  Context : in out Lexer;
                Code    : in out Source_Type;
                Got_It  : out Boolean
             );
end Parsers.Generic_Lexer.Ada_Blanks;
