/* filename: queens.pl
   Project:  queens 8 queens problem

Sample session  
hit ; to display next solution 
hit Enter to stop 

?- [queens].
?- queens(P).
P = [5,2,6,1,7,4,8,3] ;
P = [6,3,5,7,1,4,2,8] [Enter]
?- setof(P,queens(P),Set), length(Set,L).
L = 92

*/

perm([X|Y],Z) :- perm(Y,W), takeout(X,Z,W).   
perm([],[]).

takeout(X,[X|R],R).
takeout(X,[F|R],[F|S]) :- takeout(X,R,S).

queens(P) :-
     perm([1,2,3,4,5,6,7,8],P), 
     combine([1,2,3,4,5,6,7,8],P,S,D),
     all_diff(S),
     all_diff(D).

combine([X1|X],[Y1|Y],[S1|S],[D1|D]) :-
     S1 is X1 +Y1,
     D1 is X1 - Y1,
     combine(X,Y,S,D).
combine([],[],[],[]).

all_diff([X|Y]) :-  \+member(X,Y), all_diff(Y).
all_diff([X]).
