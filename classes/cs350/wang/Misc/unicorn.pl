/* If the unicorn is mythical, then it is immortal. If the unicorn is either 
immortal or a mammal, then it is horned. The unicorn is magical if it is horned. */

% RULES
immortal(X) :- mythical(X).
magical(X) :- horned(X).
horned(X) :- immortal(X); mammal (X).
mythical(X) :- immortal(X).


