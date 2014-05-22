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
% Code the argument in the form of prolog rules and facts. Although a prolog
% program often separates facts and rules, in this assignment it is easier 
% to enter the facts and rules just as you see them in the argument. 
%
% Test the conclusion as a Prolog query at the interactive console.
%
% If the argument is valid, Prolog should respond 'yes.'
% If the argument is a fallacy, Prolog should respond 'no.'
%
% Summary: If the inference engine is constructed correctly these 
% five queries should result in these responses: 
% ?- breathes(dolphin).   YES
% ?- bird(crow).          YES 
% ?- reptile(dragon).     YES
% ?- amphibian(dragon).   NO (or YES depending on the order of your rules)
% ?- fish(shark).         NO 
%
% NOTES: Do not put dashes in predicate names. Variables must be uppercase. 
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
% If an animal is a mammal it is warmblooded. (don't use a dash)
% If an animal is warmblooded it breathes.
% A dolphin produces milk for its young.
% Therefore: A dolphin  breathes.  <= this query should return YES


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
% The universe of discourse is all animals.
% An animal is a bird if it has feathers.
% A crow has feathers.
% Therefore, a crow is a bird.  <= this query should return YES
%
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
% An animal is a reptile if it is coldblooded.  (don't use dashes in prolog)
% An animal is an amphibian if it has slimy skin.
% A dragon is coldblooded or it has slimy skin.
% Therefore: A dragon is a reptile or an amphibian. 
%
%
% Queries:
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

