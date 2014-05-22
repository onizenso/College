% CMPS 350
% example of Prolog's natural language processing capabilities


% This is a definite clause grammar (logic grammar) for a simple English 
% language. To avoid ambiguity, the prepositional phrases are only noun 
% clauses.

% A Definite Clause Grammar without Parameters

sentence --> nounPhrase, predicate, ['.'].
nounPhrase --> determiner, noun.
nounPhrase --> determiner, noun, prepPhrase.
predicate -->verb, nounPhrase.
predicate --> verb.
determiner --> [a].
determiner --> [the].
prepPhrase --> preposition, nounPhrase.
noun --> [boy]; [girl]; [cat]; [telescope]; [song]; [feather].
verb --> [saw]; [touched]; [surprised]; [sang].
preposition --> [by]; [with].

% in this next grammar, <noun phrase> supports 'and' 
% BNF    
% <noun phrase> ::= <determiner> <noun>  | 
%                   <determiner> <noun> and <noun phrase>

% logic grammar
nounPhrase( NP ) --> determiner(D), noun(N).
nounPhrase( NP ) --> determiner(D), noun(N), [and], nounPhrase(T).
determiner(det(the)) --> [the].
determiner(det(a)) --> [a].
noun(noun(boy)) --> [boy].
noun(noun(boy)) --> [girl].

% queries to generate all the sentences
% make sure to recognize the shortest noun phrase first.
%  | ?- nounPhrase(X,[the,boy,and,the,girl],[]).
%   true ?
%   yes

%  This grammar accurately identifies an illegal noun phrase:
%   | ?- nounPhrase(X,[the,boy,and],[]).
%   no

% This grammar will generate an infinite number of sentences as shown by
% this query (which I stopped after 12 matches):
%   | ?- nounPhrase(X,Y,[]).
%   X = [the,boy] ? ;
%   X = [the,girl] ? ;
%   X = [a,boy] ? ;
%   X = [a,girl] ? ;
%   X = [the,boy,and,the,boy] ? ;
%   X = [the,boy,and,the,girl] ? ;
%   X = [the,boy,and,a,boy] ? ;
%   X = [the,boy,and,a,girl] ? ;
%   X = [the,boy,and,the,boy,and,the,boy] ? ;
%   X = [the,boy,and,the,boy,and,the,girl] ? ;
%   X = [the,boy,and,the,boy,and,a,boy] ?.
%   etc. 

% A BNF specification of the language of Roman numerals < 500:

%  <roman> ::= <hundreds> <tens> <units>
%   <hundreds> ::= <empty> | C | CC | CCC | CD
%   <tens> ::= <low tens> | XL | L <low tens> | XC
%   <low tens> ::= <empty> | <low tens> | IX
%   <units> ::= <low units> | IV | V  <low units> | IX
%   <low tens> ::= <empty> | <low tens> | I

% Logic Grammar: (constraints: X's in <low tens> and I's in <low units> <= 3):
% roman --> hundreds, tens, units.
roman(roman(H,T,U)) --> hundreds(H), tens(T), units(U).

% <hundreds> ::= <empty> | C | CC | CCC | CD
hundreds([]) --> [].
hundreds(hun(c)) --> [c].
hundreds(hun(cc)) --> [c],[c].
hundreds(hun(ccc)) --> [c],[c],[c].
hundreds(hun(cd)) --> [c],[d].

% <tens> ::= <low tens> | XL | L <low tens> | XC
tens(ten(L)) --> lowtens(L).
tens(ten(xl)) --> [x],[l].
tens(ten(l,LT)) --> [l], lowtens(LT).
tens(ten(xc)) --> [x],[c].

% <low tens> ::= <empty> | X <low tens>; where x's <= 3
lowtens(LTC) --> [x], lowtens(LTC1), {LTC is LTC1 + 1, LTC =< 3}.
lowtens(0) --> [].

% <units> ::= <low units> | IV | V  <low units> | IX
units(units(U)) --> lowunits(U).
units(units(iv)) --> [i],[v].
units(units(ix)) --> [i],[x].
units(units(v,U)) --> [v], lowunits(U).

%  <low units> ::= <empty> | <low units> I;  where i's <=3
lowunits(LUC) --> [i], lowunits(LUC1),  {LUC is LUC1 + 1, LUC =< 3}.
lowunits(0) --> [].

% -----------------------------------------------------------------
% SAMPLE QUERIES:
% -----------------------------------------------------------------
% ?- roman(X,[c,c,l,x,x,x,v,i,i,i],[]).
% X = roman(hun(cc),ten(l,3),units(v,3)) ?
% yes

% | ?- roman(X,[c,d,x,l,v,i,i,i,i],[]).  <= testing constraint on 'i's
% no

% | ?- roman(X,[c,d,x,x,x,x,i],[]).      <= testing constraint on 'x's
% no

% | ?- roman(X,[c,d,x,x,x,v,i,i,i],[]).
% X = roman(hun(cd),ten(3),units(v,3)) ?
% yes

% | ?- roman(X,[c,c,c,x,l,i,x],[]).
% X = roman(hun(ccc),ten(xl),units(ix)) ?
% yes
