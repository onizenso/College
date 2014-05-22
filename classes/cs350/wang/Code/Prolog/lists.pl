% sample structures in Prolog

% a fact can be a structured object with multiple fields

student('sam spade', 21, 12345,'9222 Marlow Ave',3.5).
student('jane doe', 31, 67890,'9222 Marlow Ave',2.5).
student('john smith', 41, 00000,'1234 Chester',3.0).

% a fact can be a list, which is an abbreviation of a structured object:
% lista is an abbreviation of: lista ( 0, ( 1, ( 3, (4,[]))))  :
lista([0,1,3,4]).

% lists may contain lists
listb([5,2,[a,8,2],[x],9]).

% list pattern matching

% this matches any list of at least size 3 with a in 2nd position
seconda([X,a,Y | T]).

% define rules to mean "X is the last element of L"
isLast([X],X).
isLast([H|T],X) :- isLast(T,X).

% define rules to mean "X is a member of list L"
isMember(X,[X|T]).
isMember(X,[H|T]) :- isMember(X,T).

% define rules to mean "remove X from list L"
remove(X,[],[]).
remove(X, [X|T], U) :- remove(X,T,U).
remove(X, [H|T], [H|U]) :- remove(X,T,U).

% define rules to determine if a list is a sublist of another list
initialsublist([H|T],[H|U]) :-  initialsublist(T,U).
isSublist([],L).
isSublist([H|T],[H|U]) :- initialsublist(T,U).
isSublist(S,[H|T]) :- isSublist(S,T).

/* sample queries:
?- sublist([a,b],[y,x,a,b,c,d]).
yes
| ?- sublist([a,b],[y,x,a,c,d]).

*/
