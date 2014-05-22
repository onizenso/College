% 99 bottles of beer.
% Remko Troncon <spike@kotnet.org>

bottles :-
    bottles(99).

bottles(1) :- 
    write('1 bottle of beer on the wall, 1 bottle of beer,'), nl,
    write('Take one down, and pass it around,'), nl,
    write('Now they are alle gone.'), nl.
bottles(X) :-
    X > 1,
    write(X), write(' bottles of beer on the wall,'), nl,
    write(X), write(' bottles of beer,'), nl,
    write('Take one down and pass it around,'), nl,
    NX is X - 1,
    write(NX), write(' bottles of beer on the wall.'), nl, nl,
    bottles(NX).
