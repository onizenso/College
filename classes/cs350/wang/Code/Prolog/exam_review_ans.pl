/* filename: prolog.pl                                            / 25 pts 
  CMPS 350 2009 EXAM1                                    

 Submit this file.

 Your job is to convert each of the following logical statements into prolog 
 rules or facts. I will run the queries to test your knowledge base. 

 Your universe of discourse is animals and food. You may use whatever predicate 
 names you wish but you MUST use this predicate when you see the word 'likes':
     likes(X,Y), meaning X likes Y                                       

 Don't forget that Prolog variables (X,Y,etc.) begin with uppercase and 
 predicate names or literals (loves, dog, animal, etc.) in lowercase.       

 Don't forget that discontiguous predicates are ignored. As you finish each
 question, put like predicates together. 

 Hint: If you make a change to your knowledge base, the safest thing to do is
 to exit prolog and reload the code from scratch.  */

% #1.

% If an animal has claws and fur then it likes mice.
% A cat likes mice. 
% A lion has claws.
% A lion has fur.

% Query: does a cat have fur? NO 
% Query: does a lion like mice? YES 
% Query: does a dog like mice? NO 

% likes(X,mice) :- claws(X), fur(X).
% likes(cat,mice).
% claws(lion).
% fur(lion).
%
% #2. 
% birds like nuts.
% bees like flowers.
% All animals that like nuts or flowers have wings. 
% If an animal has wings then it can fly.

% Query: Can birds fly?   YES
% Query: Can bees fly?    YES 
% Query: Can dogs fly?    NO 

% likes(birds,nuts).
% likes(bees,flowers).
% wings(X) :- likes(X,nuts).
% wings(X) :- likes(X,flowers).
% fly(X) :- wings(X).


% #3
% 
% If an animal likes fish and berries then it is a bear.
% If an animal hybernates it likes fish and berries.
% smokey hybernates.
%
% bear(X) :- likes(X,fish), likes(X,berries).
% likes(X,fish) :- hybernates(X).
% hybernates(smokey).
%
% Query: Is smokey a bear?   YES
% Query: Is spot a bear?  NO 

% #4 
% All animals except smokey like pooh. 
%  
% likes(X,pooh) :- X \== smokey. 

% Query: does smokey like pooh?  NO
% Query: does spot like pooh?  NO

% # 5
% Spot likes all animals that pooh likes or that like pooh. 
% tigger likes pooh.

% Query: does spot like tigger?  YES
% Query: does spot like smokey?   NO or YES

% likes(spot,X) :- likes(pooh,X). 
% likes(spot,X) :- likes(X,pooh). 

% Put all your rules and facts together here:
likes(spot,X) :- likes(pooh,X). 
likes(spot,X) :- likes(X,pooh). 
likes(X,pooh) :- X \== smokey. 
likes(birds,nuts).
likes(bees,flowers).
likes(X,mice) :- claws(X), fur(X).
likes(cat,mice).
likes(X,fish) :- hybernates(X).
likes(X,berries) :- hybernates(X).
wings(X) :- likes(X,nuts).
wings(X) :- likes(X,flowers).
fly(X) :- wings(X).
fur(lion).
claws(lion).
bear(X) :- likes(X,fish), likes(X,berries).
hybernates(smokey).

