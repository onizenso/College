/* filename: lab05.pl
   See:      http://www.cs.may.ie/~jpower/Courses/PROLOG/ 
   Notes:    R is used in the following predicates to denote the Result  
             The "Test with: " is a suggested method of testing the function */
%1. =========================================================================
% return a number incremented by 1
inc(X,R) :- R is X+1.

% test with: inc(7,X).
 
%2.=========================================================================
% return signum(x), which is 1 if x>0, 0 if x=0, and -1 if x < 0 
sgn(X,R) :- X > 0, R is 1; X = 0, R is 0; X < 0, R is -1.

% test with: sgn(-7,X).

%3.=========================================================================
% return the maximum of X and Y, or X if equal
getMax(X,Y,R) :- X > Y, R is X; X < Y, R is Y; R is X.

% test with: getMax(5,10,X).

%4.=========================================================================
% return TRUE if X >= Y
isMax(X,Y) :- X >= Y.

% test with: isMax(5,10).
%5.=========================================================================
% return the maximum of three numbers
getMax3(X,Y,Z,R) :- isMax(X,Y), isMax(X,Z), R is X.
getMax3(X,Y,Z,R) :- isMax(Y,X), isMax(Y,Z), R is Y.
getMax3(X,Y,Z,R) :- isMax(Z,X), isMax(Z,Y), R is Z.

% test with: getMax(5,10,7,X).
%6.=========================================================================
% return TRUE if N is even:
even(0).
even(2).
even(X) :- X > 2, X1 is X-2, even(X1).

% test with: even(16). 

% =========================================================================
% return TRUE if N is prime

% ! stops evaluation and fail causes the failure of the rule 
prime(N) :- N=1, !, fail.

prime(N) :- N = 2.
prime(N) :- D is N // 2, noDivisor(N,D).
noDivisor(N,D) :- D=2.
noDivisor(N,D) :- N1 is N rem D, N1 > 0, D2 is D-1, noDivisor(N,D2).

% test with : prime (1669)
% http://primes.utm.edu/lists/small/10000.txt
% =========================================================================

%7. Return TRUE if N is prime 
% fail predicate causes the failure of the rule (i.e., when x=1 return false)
isprime(X) :- X=1, fail ; X > 1, divide(X,2).
divide(X, X).
divide(X, R) :- Y is X mod R, Y > 0, K is R+1, divide(X, K).

