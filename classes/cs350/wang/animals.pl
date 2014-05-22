/* filename: animals.pl
   Project:  lab04 cs 350
   Descrip:  Animal categorization    */
%
% 
/*********************************************************************/
/*                 ANIMAL INFERENCE ENGINE                           */
/*********************************************************************/
%
% This program demonstrates Prolog's logical reasoning capabilities
% through a series of arguments (valid and invalid).
%
% Enter the argument in the form of rules and facts. Although a Prolog
% program often separates facts and rules, in this assignment it is easier 
% to put all the facts and rules of an argument together. 
%
% Recall that in Prolog the antecedent and consequence are reversed.
% Thus, this implication 
%       "If an animal produces milk for its young then it is a mammal."
% in Prolog is:
%        mammal(X) :- milk(X). 
%      
% The conclusion of each argument is a Prolog query. The predicate
% names are up to you, but must be such that the queries below work. 
%
% To prove that your argument is valid or invalid, enter the query at the 
% interactive console.
%
% If the argument is valid, Prolog should respond 'yes.'
% If the argument is a fallacy, Prolog should respond 'no.'
%
% The queries that you must run to test your code are:
% ?- breathes(dolphin).
% ?- bird(crow).
% ?- reptile(dragon).
% ?- amphibian(dragon).
% ?- fish(shark).     <= this should be 'no'
%
% All queries but the last one should return YES.
% Notation: '->' is implication and '^' is AND and 'v' is OR and '~' is NOT  
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
% If an animal is a mammal it is warm-blooded.
% If an animal is warm-blooded it breathes.
% A dolphin produces milk for its young.
% Therefore: A dolphin  breathes.  <= this query should return YES
%
% Enter the facts and rules of argument here:





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
% An animal is a reptile if it is cold-blooded.
% An animal is an amphibian if it has slimy skin.
% A dragon is either cold-blooded or it has slimy skin.
% Therefore: A dragon is either a reptile or an amphibian. <=  query S/B YES
%



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
%
fish(trout).
%
% 
