% CMPS 350 LAB 05 Extra Credit

% Assume list constants have the form: [3,-6,1],[86],[].  

%  General list expressions may be formed using the binary infix operators 
%  +,-,*,and @ (for concatenation), where * has highest precedence, - and + 
%  are next with equal precedence, and @ has lowest precedence. All operators
%  including @ are right associative, but parens can override the rules.
%  For example:
%  [1,2,3] + [2,2,3] * [5,-1,0] @ [8,21] evaluates to [11,0,3,8,21].

% Your job is to add the '@' operator for concatenation to the BNF grammar
% and the corresponding Prolog logic grammar. If you are careful, you only
% need to add one line to the BNF grammar, 2 lines to the logic grammar,
% and a few other minor changes
% 
% Your grammar should work with the following query:

% | ?- expr(X,[lb,5,rb,'@',lb,2,rb,'-',lb,5,rb,'*',lb,3,rb,'@',lb,3,rb,'+',lb,8,
rb ],[]).
% true ?
% yes



%    BNF without @:
%    <expr>  ::= <expr> <weakop> <term> | <term>
%    <term>  ::= <term> * <factor>  | <factor>
%    <factor> ::= ( <expr> ) | <list>
%    <list>  ::= [ ] | [ <integer> {,<integer> } ]
%    <weakop> ::= + | -
%    <integer> ::= 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

% LOGIC GRAMMAR (without parameters):
expr --> term.
expr --> term, weakop, expr.      
term --> factor.
term --> factor, ['*'], term.   
factor -->  list.
factor --> ['('], expr, [')'].
list --> [lb],int, restlist.
list --> [].
restlist --> comma, int, restlist.
restlist --> [rb].
int --> [1];[2];[3];[4];[5];[6];[7];[8];[9].
comma --> [','].
weakop --> ['-']; ['+'].
   
% SAMPLE QUERIES:
% | ?- list([],[]).
% yes
% | ?- term([lb,5,rb,'*',lb,3,rb],[]).
% true ? 
% yes 
% | ?- expr([lb,5,',',8,rb],[]).
% true ?
% (10 ms) yes
% | ?- expr([lb,5,',',8,',',9,',',7,',',3,rb,'+',lb,3,rb],[]).
% true ?
% (10 ms) yes
% yes
% | ?- expr([lb,5,',',8,',',9,',',7,',',3,rb],[]).
% true ?
% yes
% | ?- expr(['(',lb,5,rb,')','*',lb,6,rb],[]).
% true ? 
% yes
