% Demonstrates predicate logic
%
% load with:
% prolog
% [test2].
% exit with CTRL-D

% FACTS
professor(chan,math273).
professor(patel,ee222).
professor(grossman,cs301).
enrolled(suzy,math273).
enrolled(juana,ee222).
enrolled(juana,cs301).
enrolled(kiko,math273).
enrolled(kiko,cs301).
enrolled(samantha,cs301).

% RULES
% Prolog rules are based on predicate logic

% Variables whose first appearance is on the left hand side of the clause have 
% implicit universal quantifiers.
%
% Variables whose first appearance is on the right hand side of the clause 
% have implicit existential quantifiers.
%
% The implication is read right to left, where the comma is interpreted as AND 

teaches(P,S) :- professor(P,C), enrolled(S,C).

% Given that P and S are universally quantified and C is existentially 
% quantified, the meaning is:   
% If there exists a class C, such that for all professors P and all students S,
% P teaches class C and student S is enrolled in class C, then P is a 
% professor of S.
%
% In implication form: 
% if P is the professor of class C and S is enrolled in class C then P 
% teaches S.
%
% In predicate logic:

% p: professor, s: students,  c: classes
% universe: all professors, all students, all classes
% T(p,s) : professor p teaches student s 
% P(p,c) : professor p is the professor of class c
% E(s,c) : student s is enrolled in class c

% Ap As Ec ( P(p,c) ^ E(s,c) ) -> T(p,s)

% QUERIES

% run queries in the interactive interpretor after loading rules and facts
% queries must end with '.' and cannot have white spaces 
% hit ';' to continue query resolution or [CR] to end query

% this query:
% teaches (X, juana).

% will return all the teachers of the classes juana is enrolled in

% this query:
% enrolled(suzy,ee222).
% will return T if suzy is enrolled in ee222 otherwise NO 
