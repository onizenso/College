% CMPS 350 LAB 05 Extra Credit
% list constants have the form: [3,-6,1],[86],[].  

% General list expressions may be formed using the binary infix operators 
%  +,-,*,and @ (for concatenation), where * has highest precedence, - and + 
%  are next with equal precedence, and @ has lowest precedence. @ is right 
%  associative and all others left associative. Parens can override the rules.

%   Ex: [1,2,3] + [2,2,3] * [5,-1,0] @ [8,21] evaluates to [11,0,3,8,21].

%   BNF:

%    <expr>  ::= <adder> @ <expr> | <adder>
%    <adder> ::= <adder> (+ | -) <term> | <term>
%    <term>  ::= <term> * <factor>  | <factor>
%    <factor> ::= ( <expr> ) | <list>
%    <list>  ::= [ ] | [ <integer> {,<integer> } ]

% LOGIC GRAMMAR:
 
expr(E) --> adder(E1),['@'],expr(E2).         % right associative
expr(E) --> adder(E).

adder(E) --> term(E).
adder(A) --> term(F), restadder(A).           % left associative
   restadder(RA)  --> weakop(Op), term(L), restadder(RA2).
   restadder(RA) --> [].
   
term(T) --> factor(T).
term(T) --> factor(F), restterm(T).           % left associative
    restterm(RT) --> [*], factor(F), restterm(RT2).   
    restterm(RT) --> [].

factor(F) --> ['('], expr(E), [')'].
factor(F) -->  list(F).
list(L) --> [].
list(L) --> [lb],int(I), restlist(RL).
   restlist(RL) --> comma(C), int(I), restlist(RL2).
   restlist(RL) --> [rb].
int(I) --> [1];[2];[3];[4];[5];[6];[7];[8];[9].
comma(C) --> [','].
weakop(minus) --> ['-'].
weakop(plus) --> ['+'].
   
% SAMPLE OUTPUT:
% | ?- expr(X,[lb,5,',',8,',',9,',',7,',',3,rb,'+',lb,3,rb],[]).
% true ?
% (10 ms) yes
% | ?- expr(X,[lb,5,rb,'@',lb,2,rb,'-',lb,5,rb,'*',lb,3,rb,'@',lb,3,rb],[]).
% true ?
% yes
% | ?- expr(X,[lb,5,',',8,',',9,',',7,',',3,rb],[]).
% true ?
% yes
% | ?- expr(X,[lb,5,rb,'@',lb,2,rb,'-',lb,5,rb,'*',lb,3,rb,'@',lb,3,rb,'+',lb,8,rb ],[]).

% true ?
% yes
