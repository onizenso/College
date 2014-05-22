% from your sleipnir account start prolog
%  
%  $ prolog
%
% from within prolog load hw01.pl by doing this:
%
%  |?- [hw01].
%
% execute queries, hitting the semi-colon for additional answers:
%  |?- teaches(X,kiko).
%
%  exit Prolog by hitting CTRL-D

% FACTS
instructor(chan,math273).
instructor(patel,ee222).
instructor(grossman,cs301).
enrolled(kevin,math273).
enrolled(juana,ee222).
enrolled(juana,cs301).
enrolled(kiko,math273).
enrolled(kiko,cs301).


% RULES
% Prolog rules are based on predicate logic

% Variables whose first appearance is on the left hand side of the clause have 
% implicit universal quantifiers.
%
% Variables whose first appearance is on the right hand side of the clause 
% have implicit existential quantifiers.
%
% The implication is read right to left, where the comma is interpreted as AND 

teaches(P,S) :- instructor(P,C), enrolled(S,C).

% reads:
% If there is an instructor P that teaches class C and there is a student
% S enrolled in class C , then professor P teaches student S.
%
% In predicate logic:

% p (professor), s (students),  c (classes)
% universe: all professors, all students, all classes
% T(p,s) : professor p teaches student s 
% I(p,c) : professor p is the instructor of class c
% E(s,c) : student s is enrolled in class c

% Ep Ec Es ( ( I(p,c) ^ E(s,c) ) -> T(p,s) )

% QUERIES

% run queries in the interactive interpretor
% queries must end with '.' and cannot have white spaces 
% hit ';' to continue query
% hit [CR] to end query

% this query:
% teaches (X, juana).

% will return all the teachers of the classes juana is enrolled in

% exit prolog with CTRL-D
