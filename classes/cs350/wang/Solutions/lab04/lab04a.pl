/* filename: lab04a.pl
   Project:  lab04 cs 350  
   Descrip:  demonstrate Prolog support of propositional logic       */
%
% 
/*********************************************************************/
/*                ANIMAL INFERENCE ENGINE                            */
/*********************************************************************/
%
% This part of the lab demonstrates Prolog's inference engine through logical
% arguments and logical fallacies in propositional logic.
%
% The universe of discourse is animals.
%
% Enter the argument in the form of rules and facts. Although a prolog
% program often separates facts and rules, in this assignment it is easier 
% to enter the facts and rules just as you see them in the argument. 
%
% Test the conclusion as a Prolog query at the interactive console.
%
% If the argument is valid, Prolog should respond 'yes.'
% If the argument is a fallacy, Prolog should respond 'no.'
%
% When completed you should be able to run these queries to test your code: 
% ?- breathes(dolphin). 
% ?- bird(crow).    
% ?- reptile(dragon).  
% ?- amphibian(dragon).
% ?- fish(shark).  
%
% NOTES: do not put dashes in predicate names. 
% Predicates not shown to be true are assumed false.
/******************************/
/*   Hypothetical Syllogism:  */
/******************************/
%
%  p -> q  
%  q -> r  
% ----------
% : p -> r
%
% ARGUMENT:
% If an animal produces milk for its young it is a mammal.
% If an animal is a mammal it is warmblooded.  (don't use a dash)
% If an animal is warmblooded it breathes.
% A dolphin produces milk for its young.
% Therefore: A dolphin  breathes.  <= this query should return YES

mammal(X) :- milk(X). 
breathes(pig).
warm(X) :- mammal(X).
breathes(X) :- warm(X).
milk(dolphin).


/******************************/
/*         Modus Ponens       */
/******************************/
%
%   p -> q  
%   p  
% ----------
% :  q
%
% ARGUMENT:
% An animal is a bird if it has feathers.
% A crow has feathers.
% Therefore, a crow is a bird.  <= this query should return YES
%
bird(X) :- feathers(X).
feathers(crow).
%
/******************************/
/*   Constructive Dilemma     */	
/******************************/
%
%  (p -> q) ^ (r -> s)  
%   p v r  
% ----------------------
% : q v s
%
% ARGUMENT:
% An animal is a reptile if it is coldblooded. (no dashes in predicate names)
% An animal is an amphibian if it has slimy skin.
% A dragon is cold-blooded or it has slimy skin.
% Therefore: A dragon is a reptile or an amphibian. 
%
%
reptile(X) :- cold(X).
amphibian(X) :- slimy(X).
% slimy(dragon) can also be added.
cold(dragon).
% this fact is needed if you don't put slimy(dragon).
slimy(snail).   
%
% ?- reptile(dragon).  yes 
% ?- amphibian(dragon). no
%
/*************************************************/
/*     Fallacy of affirming the consequence      */
/*************************************************/
% p -> q
% q
% -------
% p        
%
% FALLACY:
% An animal lives in the water if it is a fish.
% Sharks live in the water.
% Therefore: A shark is a fish.   <= this query should return NO
%
% Note: you need to enter at least one fact about a fish to get this
% query to work, so enter:
% fish(trout).
%
fish(trout).
% 
water(X) :- fish(X).
water(shark).
%

