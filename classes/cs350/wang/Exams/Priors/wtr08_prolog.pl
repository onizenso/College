/* filename: exam1.pl                                      TOTAL:  / 10 pts 

  1 pt for each correct query response with correct code to get that query.

  Important: Prolog subject variables (X,Y,etc.) must begin with uppercase 
  letters; Prolog literals (dog, animal, fido, etc.) must begin with 
  lowercase letters. 
  Notation: '==' is logical equivalence  */
% 
/**********************************************************************/
/*                  EXAM 1 INFERENCE ENGINE                           */
/**********************************************************************/
%
% Your job is to convert the premises of three arguments into Prolog facts 
% and rules. I have written the conclusions as Prolog queries for you, and 
% will test your code against these queries at the interactive console.
%
% note: make sure that you place all predicates contiguously or you will
% not get the correct answers to the queries.
%
%==========================================================================
% ARGUMENT #1.  (4 pts)
%==========================================================================
% Use this logical equivalence:  p -> (q ^ r) == (p -> q) ^ (p -> r)
%  
% If an animal has claws then it is a cat and has fur. 
% A lion has claws.
% A dog has fur. 
% Conclusion: A lion is a cat and has fur, a shark doesn't have fur, and a 
% dog isn't a cat.
%  
cat(X) :- claws(X).
claws(lion).
fur(X) :- claws(X).
fur(dog).
%
% These are the Prolog queries I will run against your code:
% |-? cat(lion).  yes
% |-? fur(lion). yes
% |-? fur(shark). no
% |-? cat(dog). no
%
%==========================================================================
% ARGUMENT #2.  (4 pts)
%==========================================================================
% If the day is sunny or overcast, then the race will be held. 
% If the race is held, then the trophy will be awarded. 
% The race was held on tuesday. 
% It was sunny on monday.
% It was overcast on friday.
% Conclusion: The trophy was awarded on friday and tuesday and it was sunny 
% or overcast on tuesday. 
%
% Use this logical equivalence:
% (p v q) -> r  == (p -> r) ^ (q -> r)
% 
race(X) :- sunny(X).
race(X) :- overcast(X).
race(tuesday).
trophy(X) :- race(X).
sunny(monday).
overcast(friday).
%
% These are the Prolog queries I will run against your code.
% |- sunny(tuesday).  no
% |- overcast(tuesday). no
% |- trophy(friday).  yes
% |- trophy(tuesday).  yes
%
%==========================================================================
% ARGUMENT #3. (2 pts)
%==========================================================================
% Use the above logical equivalences to convert the following argument into
% Prolog facts and rules. Use this equivalence: 
% p v q -> r == p -> r ^ q -> r
% Hint: recall that the absence of a predicate is the same as a negation 
% 
% If an animal has feathers or wings then it is a bird.
% An eagle has feathers.
% A bat has wings.
% Conclusion: Eagles and bats are birds.
%
bird(X) :- feathers(X).
bird(X) :- wings(X).
feathers(eagle).
wings(bat).
%
% These are the Prolog queries I will run against your code.
% |- bird(bat). yes
% |- bird(eagle). yes

% ========================================================================
% EXTRA CREDIT:  (2 pts)
% ========================================================================
% Use this equivalence:
% p -> (q v r) == (p ^ ~q) -> r   OR   (p ^ ~r) -> q
%
% use this NOT predicate
% usage:  junk(X) :- not(stuff(X)).
not(P) :- ( call(P) -> fail ; true ).
%
% ARGUMENT:
% If an animal has a horn then it is a unicorn or a rhinoceros.
% A rimu has a horn.
% A rimu is not a rhinoceros.
% Therefore, a rimu is a unicorn.
%
unicorn(X) :- horn(X), not(rhinoceros(X)).
% OR rhinoceros(X) :- horn(X), not(unicorn(X)). 
horn(rimu).
rhinoceros(fido). 
%
% These are the Prolog queries I will run against your code.
% |- rhinoceros(rimu). no 
% |- unicorn(rimu).  yes


%======================
% BACKGROUND REVIEW   |
%======================
% The table of logical equivalences (if you need it) is online at 
% http://www.cs.csubak.edu/~donna/cs350/Code/Prolog/logic.txt  
% 
% Rules in Prolog are Horn clauses 
%      (p ^ q ^ r ^ ... ^ z) -> u
% that are converted into implications in Prolog
% u :- p, q, r, ..., t
%    and read as
% If p,q,r,...,t are true then u is true.
%
% The consequence of the inference (the head) is limited to a single predicate
% and the antecedent is a conjunctive clause (only ANDs are used).
%
% To convert propositions into something that will work in Prolog,
% you may need to apply logical equivalences rules.
% 
% For example, a proposition that reads "(p v q) -> r" is converted into
% two implications by logical equivalences:
%
% (p v q) -> r  == ~(p v q) v r
%               == (~p ^ ~q) v r
%               == (r v ~p) ^ (r v ~q)
%               ==  (p -> r) ^ (q -> r)
% 
% And is represented in Prolog as:
% r :- p.
% r :- q.
 
% Likewise, (p v q v r ) -> s in Prolog is
% s :- p.
% s :- q.
% s :- r.
%
%  Another example:
%  p -> (q v r) == ~(p) v (q v r)
%               == ~(p) v (q v r)
%               == (~p v q) v r
%               == ~(~p v q) -> r
%               == (p ^ ~q) -> r
%                     or
%               == (p ^ ~r) -> q 

% A logical argument consists of 2 or more premises followed by a conclusion:
%
% premise 1.   
% premise 2.    
% premise 3.    
% ...
% premise n.
% ==========
% conclusion 
%
% An argument is read "if premise 1 and premise 2 and premise 3 ... and
% premise n are true, then the conclusion is true.
% 
% Arguments with exactly 2 premises and 1 conclusion are syllogisms. For
% example, the form of this argument is called Hypothetical Syllogism:  
%
%  p -> q  
%  q -> r  
% ----------
% : p -> r
%
