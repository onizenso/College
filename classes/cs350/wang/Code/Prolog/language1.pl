% CMPS 350
% an example of Prolog's natural language processing capabilities

% This is a definite clause grammar (logic grammar) for a simple English 
% language. To avoid ambiguity, the prepositional phrases are only noun 
% clauses.

% BNF GRAMMAR:
% <sentence> ::= <noun phrase> <predicate> .
% <noun phrase> ::= <determiner> <noun> | <determiner> <noun> <prep phrase> |
%                   <determiner> <noun> and <noun phrase>
% <predicate> ::= <verb> <noun phrase> | <verb>
% <determiner> ::= a | the
% <prep phrase> ::= preposition <noun phrase>.
% <noun> ::= boy | girl | cat | telescope | song | feather
% <verb> ::= saw | touched | surprised | sang
% <preposition> --> by | with


% PROLOG DEFINITE CLAUSE GRAMMAR (without Parameters)

sentence --> nounPhrase, predicate, ['.'].
nounPhrase --> determiner, noun.
nounPhrase --> determiner, noun, prepPhrase.
nounPhrase --> determiner, noun, [and], nounPhrase.
predicate -->verb, nounPhrase.
predicate --> verb.
determiner --> [a].
determiner --> [the].
prepPhrase --> preposition, nounPhrase.
noun --> [boy]; [girl]; [cat]; [telescope]; [song]; [feather].
verb --> [saw]; [touched]; [surprised]; [sang].
preposition --> [by]; [with].

% queries to generate all the sentences
% make sure to recognize the shortest noun phrase first.
%  | ?- nounPhrase([the,boy,and,the,girl],[]).
%   true ?
%   yes

%  This grammar accurately identifies an illegal noun phrase:
%   | ?- nounPhrase([the,boy,and],[]).
%   no

% This query will generate all possible noun phrases (how many are there?):
%   | ?- nounPhrase(X,[]).
%   X = [the,boy] ? ;
%   X = [the,girl] ? ;
%   X = [a,boy] ? ;
%   X = [a,girl] ? ;
%   etc. 
