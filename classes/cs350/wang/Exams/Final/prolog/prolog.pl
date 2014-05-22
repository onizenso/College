/* filename: prolog.pl                                      TOTAL:  / 15 pts 
   CMPS 350 - Final Exam 

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
% ARGUMENT #1.  (5 pts for Rules and Queries)
%==========================================================================
% Use this logical equivalence:  p -> (q ^ r) == (p -> q) ^ (p -> r)
%  
% If a thing has feathers then it is a bird and lays eggs. 
% A hat has feathers.
% A snake lays eggs. 
% Conclusion: A hat is a bird and lays eggs and a snake has feathers.
%  
bird(X) :- feathers(X).
feathers(hat).
eggs(X) :- feathers(X).
eggs(snake).
%
% Write your own Prolog queries to match the conclusion. List them here:
% 
% bird(hat). yes
% eggs(hat). yes
% feathers(snake). no 
%
%==========================================================================
% ARGUMENT #2. (5 pts for rules and queries )
%==========================================================================
% Convert the following argument into Prolog facts and rules. 
% Use this equivalence: 
% p v q -> r == (p -> r) ^ (q -> r)
% Hint: Each implication must be a separate rule 
% 
% If an animal is mystical or magical then it is imaginary.
% A fairy is magical and a unicorn is mystical.
% Conclusion: Fairies and unicorns are imaginary.
%
imaginary(X) :- mystical(X).
imaginary(X) :- magical(X).
mystical(unicorn).
magical(fairy).
%
% Write your own Prolog queries to match the conclusion:
% imaginary(fairy).  yes
% imaginary(unicorn).  yes

% ========================================================================
% ARGUMENT #3. (5 pts for rules and queries)
% ========================================================================
% Use one of these equivalences:
% p -> (q v r) == (p ^ ~q) -> r   
% p -> (q v r) == (p ^ ~r) -> q
%
% use this NOT predicate
% usage:  junk(X) :- not(stuff(X)).
not(P) :- ( call(P) -> fail ; true ).
%
% ARGUMENT:
% If a color is festive then it is some shade of green or red.
% Mistletoe is red and green.
% Papaya is festive but it is not a shade of green.
% Celery is festive but it is not a shade of red.
% Therefore, papaya is a shade of red and celery is a shade of green.
%
% green(celery) :- not(green(papaya)).
green(X) :- festive(X), not(red(X)).
green(mistletoe).
% red(papaya) :- not(red(celery)).
red(mistletoe).
red(X) :- festive(X), not(green(X)).
festive(celery).
festive(papaya).

%
% Write your own Prolog queries to test your conclusion:
% red(papaya).
% green(celery).

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
