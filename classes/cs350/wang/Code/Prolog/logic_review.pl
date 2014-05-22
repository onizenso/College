filename: logic_review.txt          

%=================
% LOGIC REVIEW   |
%=================
% The table of logical equivalences is online at 
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
