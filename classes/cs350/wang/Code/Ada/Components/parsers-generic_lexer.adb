--                                                                    --
--  package                         Copyright (c)  Dmitry A. Kazakov  --
--     Parsers.Generic_Lexer                       Luebeck            --
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

package body Parsers.Generic_Lexer is
--
-- Do_{Binary|Postfix|Prefix} -- Process an operator
--
--    Context  - The context
--    Code     - The source code being parsed
--    Operator - The operator
--    Left     - Priority of the operator
--    Right    - Priority of the operator
--
-- On  an  association  error  a corresponding handler is called and one
-- more attempt is made.
--
   procedure Do_Binary
             (  Context  : in out Lexer'Class;
                Code     : in out Source_Type;
                Operator : in out Operation_Type;
                Left     : Priority_Type;
                Right    : Priority_Type
             );
   procedure Do_Postfix
             (  Context  : in out Lexer'Class;
                Code     : in out Source_Type;
                Operator : in out Operation_Type;
                Left     : Priority_Type;
                Right    : Priority_Type
             );
   procedure Do_Prefix
             (  Context  : in out Lexer'Class;
                Code     : in out Source_Type;
                Operator : in out Operation_Type;
                Left     : Priority_Type;
                Right    : Priority_Type
             );
   pragma Inline (Do_Binary, Do_Postfix, Do_Prefix);
--
-- Do_Comma -- Process a comma
--
--    Context - The context
--    Code    - The source code being parsed
--    Comma   - The comma operation
--    Plain   - True - comma, False - ligature
--    Got_It  - True if accepted, otherwise it has to be returned back
--
-- On  an  association  error  a corresponding handler is called and one
-- more attempt is made.
--
   procedure Do_Comma
             (  Context : in out Lexer'Class;
                Code    : in out Source_Type;
                Comma   : in out Operation_Type;
                Plain   : Boolean;
                Got_It  : out Boolean
             );
   pragma Inline (Do_Comma);
--
-- Do_Left_Bracket -- Process a left index bracket
--
--    Context - The context
--    Code    - The source code being parsed
--    Bracket - The bracket
--    Left    - The left priority
--
-- On  an  association  error  a corresponding handler is called and one
-- more attempt is made.
--
   procedure Do_Left_Bracket
             (  Context : in out Lexer'Class;
                Code    : in out Source_Type;
                Bracket : in out Operation_Type;
                Left    : Priority_Type
             );
   pragma Inline (Do_Left_Bracket);
--
-- Do_Postmodifier -- Process a postmodifier
--
--    Context  - The context
--    Code     - The source code being parsed
--    Argument - True if modifies an argument
--    Modifier - The modifier
--    Got_It   - Set to false if modifier is discarded
--
   procedure Do_Postmodifier
             (  Context  : in out Lexer'Class;
                Code     : in out Source_Type;
                Argument : Boolean;
                Modifier : in out Operation_Type;
                Got_It   : out Boolean
             );
   pragma Inline (Do_Postmodifier);
--
-- Do_Right_Bracket -- Process an right bracket
--
--    Context - The context
--    Code    - The source code being parsed
--    Bracket - The bracket
--    Got_It  - Set to false if bracket is discarded
--
-- On an error a corresponding handler is called and one more attempt is
-- made. Also a handler is called when the bracket is unexpected.
--
   procedure Do_Right_Bracket
             (  Context : in out Lexer'Class;
                Code    : in out Source_Type;
                Bracket : in out Operation_Type;
                Got_It  : out Boolean
             );
   pragma Inline (Do_Right_Bracket);
--
-- Do_Sublist -- Process a sublist separator
--
--    Context   - The context
--    Code      - The source code being parsed
--    Separator - The separator
--    Class     - The class of the separator
--    Priority  - The association priority
--    Got_It    - True if accepted, otherwise it has to be returned back
--
-- On  an  association  error  a corresponding handler is called and one
-- more attempt is made.
--
   procedure Do_Sublist
             (  Context   : in out Lexer'Class;
                Code      : in out Source_Type;
                Separator : in out Operation_Type;
                Class     : Semicolon_Class;
                Priority  : Priority_Type;
                Got_It    : out Boolean
             );
   pragma Inline (Do_Sublist);

   procedure Do_Binary
             (  Context  : in out Lexer'Class;
                Code     : in out Source_Type;
                Operator : in out Operation_Type;
                Left     : Priority_Type;
                Right    : Priority_Type
             )  is
      Explicit : constant Boolean :=
         Get_Pointer (Code) /= Get_Backup_Pointer (Code);
   begin
      begin
         Push_Binary
         (  Container => Context.Operations,
            Operation => Operator,
            Left      => Left,
            Right     => Right,
            Explicit  => Explicit
         );
      exception
         when Association_Error =>
            declare
               Other : Descriptor := Top (Context.Operations);
            begin
               On_Association_Error
               (  Context,
                  Code,
                  Other.Operation,
                  Operator
               );
               Replace (Context.Operations, Other);
               Push_Binary
               (  Container => Context.Operations,
                  Operation => Operator,
                  Left      => Left,
                  Right     => Right,
                  Unchecked => True,
                  Explicit  => Explicit
               );
            end;
      end;
   end Do_Binary;

   procedure Do_Postfix
             (  Context  : in out Lexer'Class;
                Code     : in out Source_Type;
                Operator : in out Operation_Type;
                Left     : Priority_Type;
                Right    : Priority_Type
             )  is
   begin
      begin
         Push_Postfix (Context.Operations, Operator, Left, Right);
      exception
         when Association_Error =>
            declare
               Other : Descriptor := Top (Context.Operations);
            begin
               On_Association_Error
               (  Context,
                  Code,
                  Other.Operation,
                  Operator
               );
               Replace (Context.Operations, Other);
               Push_Postfix
               (  Context.Operations,
                  Operator,
                  Left,
                  Right,
                  True
               );
            end;
      end;
   end Do_Postfix;

   procedure Do_Prefix
             (  Context  : in out Lexer'Class;
                Code     : in out Source_Type;
                Operator : in out Operation_Type;
                Left     : Priority_Type;
                Right    : Priority_Type
             )  is
   begin
      begin
         Push_Prefix (Context.Operations, Operator, Left, Right);
      exception
         when Association_Error =>
            declare
               Other : Descriptor := Top (Context.Operations);
            begin
               On_Association_Error
               (  Context,
                  Code,
                  Other.Operation,
                  Operator
               );
               Replace (Context.Operations, Other);
               Push_Prefix
               (  Context.Operations,
                  Operator,
                  Left,
                  Right,
                  True
               );
            end;
      end;
   end Do_Prefix;

   procedure Do_Left_Bracket
             (  Context : in out Lexer'Class;
                Code    : in out Source_Type;
                Bracket : in out Operation_Type;
                Left    : Priority_Type
             )  is
   begin
      begin
         Push_Left_Bracket (Context.Operations, Bracket, Left);
      exception
         when Association_Error =>
            declare
               Other : Descriptor := Top (Context.Operations);
            begin
               On_Association_Error
               (  Context,
                  Code,
                  Other.Operation,
                  Bracket
               );
               Replace (Context.Operations, Other);
               Push_Left_Bracket
               (  Context.Operations,
                  Bracket,
                  Left,
                  True
               );
            end;
      end;
   end Do_Left_Bracket;

   procedure Do_Comma
             (  Context : in out Lexer'Class;
                Code    : in out Source_Type;
                Comma   : in out Operation_Type;
                Plain   : Boolean;
                Got_It  : out Boolean
             )  is
   begin
      Push_Comma (Context.Operations, Comma, Plain);
      Got_It := True;
   exception
      when Unexpected_Comma =>
         On_Unexpected (Context, Code, Comma);
         Got_It := False;
      when Wrong_Comma_Type =>
         declare
            Other : Descriptor := Top (Context.Operations);
         begin
            On_Wrong_Comma (Context, Code, Other.Operation, Comma);
            Replace (Context.Operations, Other);
            Push_Comma (Context.Operations, Comma, Plain, True);
            Got_It := True;
         end;
   end Do_Comma;

   procedure Do_Postmodifier
             (  Context  : in out Lexer'Class;
                Code     : in out Source_Type;
                Argument : Boolean;
                Modifier : in out Operation_Type;
                Got_It   : out Boolean
             )  is
   begin
      if Argument then
         if Is_Empty (Context.Arguments) then
            Got_It := False;
         else
            declare
               Left : Frame (1..1);
            begin
               Pop (Context.Arguments, Left);
               On_Postmodifier
               (  Context,
                  Code,
                  Left (1),
                  Modifier,
                  Got_It
               );
               Push (Context.Arguments, Left (1)); 
            end;
         end if;
      else
         if Is_Empty (Context.Operations) then
            Got_It := False;
         else
            declare
               Left : Descriptor := Top (Context.Operations);
            begin
               case Left.Class is
                  when Stub =>
                     Got_It := False;
                  when others => 
                     On_Postmodifier
                     (  Context,
                        Code,
                        Left.Operation,
                        Modifier,
                        Got_It
                     );
               end case;
               if Got_It then
                  Replace (Context.Operations, Left);
               end if;
            end;
         end if;
      end if;
   end Do_Postmodifier;

   procedure Do_Right_Bracket
             (  Context : in out Lexer'Class;
                Code    : in out Source_Type;
                Bracket : in out Operation_Type;
                Got_It  : out Boolean
             )  is
   begin
      Push_Right_Bracket (Context.Operations, Bracket);
      Got_It := True;
   exception
      when Unexpected_Right_Bracket =>
         On_Unexpected (Context, Code, Bracket);
         Got_It := False;
      when Wrong_Right_Bracket_Type =>
         declare
            Other : Descriptor := Top (Context.Operations);
         begin
            On_Wrong_Right_Bracket
            (  Context,
               Code,
               Other.Operation,
               Bracket
            );
            Replace (Context.Operations, Other);
            Push_Right_Bracket (Context.Operations, Bracket, True);
         end;
   end Do_Right_Bracket;

   procedure Do_Sublist
             (  Context   : in out Lexer'Class;
                Code      : in out Source_Type;
                Separator : in out Operation_Type;
                Class     : Semicolon_Class;
                Priority  : Priority_Type;
                Got_It    : out Boolean
             )  is
   begin
      Push_Semicolon (Context.Operations, Separator, Class, Priority);
      Got_It := True;
   exception
      when Unexpected_Comma =>
         On_Unexpected (Context, Code, Separator);
         Got_It := False;
      when Wrong_Comma_Type =>
         declare
            Other : Descriptor := Top (Context.Operations);
         begin
            On_Wrong_Comma (Context, Code, Other.Operation, Separator);
            Replace (Context.Operations, Other);
            Push_Semicolon
            (  Context.Operations,
               Separator,
               Class,
               Priority,
               True
            );
            Got_It := True;
         end;
   end Do_Sublist;

   procedure On_Postmodifier
             (  Context   : in out Lexer;
                Code      : in out Source_Type;
                Operation : in out Operation_Type;
                Modifier  : Operation_Type;
                Got_It    : out Boolean
             )  is
   begin
      Reset_Pointer (Code);
      Got_It := False;      
   end On_Postmodifier;

   procedure On_Postmodifier
             (  Context  : in out Lexer;
                Code     : in out Source_Type;
                Argument : in out Argument_Type;
                Modifier : Operation_Type;
                Got_It   : out Boolean
             )  is
   begin
      Reset_Pointer (Code);
      Got_It := False;      
   end On_Postmodifier;

   procedure On_Premodifier
             (  Context  : in out Lexer;
                Code     : in out Source_Type;
                Token    : in out Lexical_Token;
                Modifier : Operation_Type;
                Got_It   : out Boolean
             )  is
   begin
      Reset_Pointer (Code);
      Got_It := False;      
   end On_Premodifier;

   procedure On_Unexpected
             (  Context : in out Lexer;
                Code    : in out Source_Type;
                Right   : Operation_Type
             )  is
   begin
      Reset_Pointer (Code);
   end On_Unexpected;

   procedure Call
             (  Stack     : in out Lexer_Operation_Stack;
                Operation : Operation_Type;
                Count     : Natural
             )  is
      List : Frame (1..Argument_No (Count));
   begin
      Pop (Stack.Context.Arguments, List);
      Push
      (  Stack.Context.Arguments,
         Call (Stack.Context, Operation, List)
      );
    end Call;

   procedure Enclose
             (  Stack : in out Lexer_Operation_Stack;
                Left  : Operation_Type;
                Right : Operation_Type;
                Count : Natural
             )  is
      List : Frame (1..Argument_No (Count));
   begin
      Pop (Stack.Context.Arguments, List);
      Push
      (  Stack.Context.Arguments,
         Enclose (Stack.Context, Left, Right, List)
      );
   end Enclose;

   procedure Parse
             (  Context : in out Lexer'Class;
                Code    : in out Source_Type;
                Result  : out Argument_Type
             )  is
      Got_Modifier : Boolean := False;
      Got_Argument : Boolean := False;
      Got_It       : Boolean;
      Modifier     : Operation_Type;
      Token        : Lexical_Token;
   begin
      Push_Start (Context.Operations);
      Mark (Context.Arguments);
      Turnover : loop
         --
         -- One turnover: prefixes-operand-postfixes-infix
         --
         loop
            --
            -- Getting a prefix operation
            --
            Get_Blank (Context, Code, Got_It);
            if not Got_It then
               --
               -- Missing operand
               --
               Set_Pointer (Code, Get_Pointer (Code));
               begin
                  if Top (Context.Operations).Class = Default then
                     Pop (Context.Operations);
                     exit Turnover;
                  end if;
               exception
                  when Constraint_Error =>
                     null;
               end;
               On_Missing_Operand (Context, Code, Result);
               Push (Context.Arguments, Result);
               exit Turnover;
            end if;
            Get_Prefix (Context, Code, Token, Got_It);
            if Got_Modifier then
               Got_Modifier := False;
               if Got_It then
                  On_Premodifier
                  (  Context,
                     Code,
                     Token,
                     Modifier,
                     Got_It
                  );
               else
                  On_Missing_Operation
                  (  Context,
                     Code,
                     Modifier,
                     Token,
                     Got_It
                  );
               end if;
            end if;
            exit when not Got_It;
            case Token.Class is
               when Bracket =>
                  Push_Left_Bracket
                  (  Context.Operations,
                     Token.Operation
                  );
                  Got_Argument := False;
               when Operator =>
                  Do_Prefix
                  (  Context,
                     Code,
                     Token.Operation,
                     Token.Left,
                     Token.Right
                  );
                  Got_Argument := False;
               when Postmodifier =>
                  Do_Postmodifier
                  (  Context,
                     Code,
                     Got_Argument,
                     Token.Operation,
                     Got_It
                  );
                  if not Got_It then
                     Set_Pointer (Code, Get_Pointer (Code));
                     On_Missing_Operand (Context, Code, Result);
                     exit Turnover;
                  end if;
               when Premodifier =>
                  Modifier     := Token.Operation;
                  Got_Modifier := True;
               when others =>
                  raise Constraint_Error;
            end case;
         end loop;
         --
         -- Getting an operand
         --
         Get_Operand (Context, Code, Result, Got_It);
         Got_Argument := True;
         if not Got_It then
            Set_Pointer (Code, Get_Pointer (Code));
            begin
               if Top (Context.Operations).Class = Default then
                  Pop (Context.Operations);
                  exit Turnover;
               end if;
            exception
               when Constraint_Error =>
                  null;
            end;
            On_Missing_Operand (Context, Code, Result);
         end if;
         Push (Context.Arguments, Result);
         loop
            --
            -- Getting a postfix operation
            --
            Get_Blank (Context, Code, Got_It);
            exit Turnover when not Got_It;
            Get_Postfix (Context, Code, Token, Got_It);
            if Got_Modifier then
               if Got_It then
                  On_Premodifier
                  (  Context,
                     Code,
                     Token,
                     Modifier,
                     Got_It
                  );
                  Got_Modifier := not Got_It;
               end if;
            end if;
            exit when not Got_It;
            case Token.Class is
               when Bracket =>
                  Do_Right_Bracket
                  (  Context,
                     Code,
                     Token.Operation,
                     Got_It
                  );
                  exit when not Got_It;
                  Got_Argument := False;
               when Operator =>
                  Do_Postfix
                  (  Context,
                     Code,
                     Token.Operation,
                     Token.Left,
                     Token.Right
                  );
                  Got_Argument := False;
               when Postmodifier =>
                  Do_Postmodifier
                  (  Context,
                     Code,
                     Got_Argument,
                     Token.Operation,
                     Got_It
                  );
                  exit Turnover when not Got_It;
               when Premodifier =>
                  Modifier     := Token.Operation;
                  Got_Modifier := True;
               when others =>
                  raise Constraint_Error;
            end case;
         end loop;
         --
         -- Getting an infix operation
         --
         Get_Infix (Context, Code, Token, Got_It);
         if Got_Modifier then
            Got_Modifier := False;
            if Got_It then
               On_Premodifier
               (  Context,
                  Code,
                  Token,
                  Modifier,
                  Got_It
               );
            else
               On_Missing_Operation
               (  Context,
                  Code,
                  Modifier,
                  Token,
                  Got_It
               );
            end if;
         end if;
         exit when not Got_It;
         case Token.Class is
            when Comma =>
               Do_Comma
               (  Context,
                  Code,
                  Token.Operation,
                  True,
                  Got_It
               );
               exit when not Got_It;
               Got_Argument := False;
            when Ligature =>
               Do_Comma
               (  Context,
                  Code,
                  Token.Operation,
                  False,
                  Got_It
               );
               exit when not Got_It;
               Got_Argument := False;
            when Operator =>
               Do_Binary
               (  Context,
                  Code,
                  Token.Operation,
                  Token.Left,
                  Token.Right
               );
               Got_Argument := False;
            when Index =>
               Do_Left_Bracket
               (  Context,
                  Code,
                  Token.Operation,
                  Token.Priority
               );
               Got_Argument := False;
            when Semicolon_Class'Range =>
               Do_Sublist
               (  Context,
                  Code,
                  Token.Operation,
                  Token.Class,
                  Token.Priority,
                  Got_It
               );
               exit when not Got_It; 
               Got_Argument := False;
            when Premodifier | Postmodifier =>
               Reset_Pointer (Code);
               exit;
            when others =>
               raise Constraint_Error;
         end case;
      end loop Turnover;
      Set_Pointer (Code, Get_Pointer (Code));
      loop
         begin
            Push_End (Context.Operations);
            exit;
         exception
            when Missing_Right_Bracket =>
               declare
                  Left  : Descriptor := Top (Context.Operations);
                  Right : Operation_Type;
               begin
                  On_Missing_Right_Bracket
                  (  Context,
                     Code,
                     Left.Operation,
                     Right
                  );
                  Replace (Context.Operations, Left);
                  Push_Right_Bracket (Context.Operations, Right);
               end;
         end;
      end loop;
      declare
         List : Frame (1..1);
      begin
         Pop (Context.Arguments, List);
         Result := List (List'First);
      end;
      Release (Context.Arguments);
   exception
      when others =>
         Push_Abort (Context.Operations);
         Release (Context.Arguments);
         raise;
   end Parse;

end Parsers.Generic_Lexer;
