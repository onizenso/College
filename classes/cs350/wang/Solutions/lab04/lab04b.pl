/* filename: lab04b.pl          SOLUTIONS
   Project:  lab04 cs 350  
   Descrip:  demonstrates Prolog support of first-order (predicate) logic 
             with nested variables */
%
% 
/**************************************************************************/
/*                 VALENTINE'S DAY INFERENCE ENGINE                       */
/**************************************************************************/
%  
% In this part of the lab you will use Prolog's inference engine to create a
% more sophisticated knowledge base involving predicates with nested variables.
%
% Nested variables express relationships in predicates, so "loves(jack,jill)"
% means jack loves jill.
% 
% If you don't know predicate logic - don't panic - you will be able to learn 
% enough to do the assignment. Just read the English and the corresponding rule
% below to understand how Prolog thinks.
%
% In Prolog, variables that appear for the first time in the head of a clause 
% are implicitly universal and variables that appear for the first time in
% the body of the clause are implicitly existential. Thus, since a query is a 
% headless clause and a fact is a bodyless clause, all facts and rules are 
% universal and all queries existential:

% The fact
%           loves(jack,X).

% means    Ax loves(jack,X)              "jack loves everyone"

% The rule
%           loves(jack,X) :- rich(X).

% means:  Ax rich(x)-> loves(jack,x)     "jack loves everyone who is rich"
%
% And the query
%
%       |-?  loves(X,jack), loves(X,jill).

% means:  Ex loves(x,jack) and loves (x,jill). 
%                        "is there anyone who loves both jack and jill?"

% Because of these limitations, Prolog cannot express all combinations of 
% quantifiers. You also need to be careful when variables are in a rule head
% or in a fact; i.e., you can't just let prolog run wild. For example,

% The fact loves(X,Y) and the query |?- loves(foo,bar) with nothing else 
% will stack overflow.

% The rule loves(jack,Y) :- loves(X,Y). and the query |-? loves(jack,abc) will 
% result in an infinite number of recursive calls to loves(jack,abc) unless 
% there is a fact: loves(def,abc). 
 
% The rule, loves(X,Y) :- loves(rick,llsa), and the query |?- loves(abc,def)
% will result in infinite recursive calls to resolve loves(rick,llsa). But if  
% you include the fact, loves(joe,harry), then everybody loves everybody is 
% true.   

% Why? Because in Prolog a claim is false unless explicitly stated to be true 
% (closed world assumption); thus, to show ~loves(larry,sally), you must enter 
% a single positive fact: loves(joe,lucy), for Prolog to know that all other 
% claims are false. Also Prolog attempts to resolve a goal infinitely. If you
% carefully follow the instructions in this lab and enter your rules and facts
% correctly, you will not get any stack overflows in queries to the knowledge 
% base. If you do, you have made a mistake.
%
% Things you need to know:
% variables must be uppercase; predicate names must start with a lowercase 
% letter; Prolog uses top-down resolution (backward chaining) so order does 
% matter - put all like predicates together; If you expect lots of answers and 
% you only need one, cut the tree with !:

%           foobar(junk,X) :- stuff(X), !. 
%
% relational operators work ( == , <= , >=, \==, etc.); e.g.
%            loves(foo,bar) :- stuff \== junk. 
% means:  if stuff does not equal junk then foo loves bar. 

% (see /Code/Prolog/predicates.txt for more operators...)

% 
%| ?- loves(mamma,baby).
% true ?    <== This means  mamma loves baby is true, and do you want
%               prolog to look for other solutions? Hit ENTER if not
%               or ; to continue looking
%================================
%   INSTRUCTIONS FOR THIS LAB           
%================================
% Your job is a create a knowledge base where the universe of discourse is 
% all people and the predicates are: loves(x,y) (meaning x loves y) and
% rich(X) (meaning x is rich).
% Start with these facts:

% you do not need the exists predicate but it may make your logic easier to follow...
exists(sally).  
exists(joker).  
exists(jack).  
exists(jill).  
exists(tarzan).
exists(jane).
exists(pooh).
exists(honey).

rich(sally).
loves(sally,tarzan).    
loves(jane,tarzan).   
loves(tarzan,jane).   
loves(pooh,honey).
loves(jack,jill).   
loves(jack,pooh).   
loves(jill,pooh).   

% Convert these English sentences into Prolog rules:


% Rule #1. "Everyone loves himself or herself." 
loves(X,X) :- exists(X).

% Rule #2. "joker loves no one but himself."

% Rule #1 infers that joker loves joker. To prevent the joker from loving anyone else
% exclude the joker from any rule that might return true to loves(joker,X).

% "Everybody loves jerry except joker."
loves(X,jerry) :- exists(X), \==(X, joker).       

% "pooh loves everyone who loves tarzan or who jane loves."
loves(pooh,X) :- loves(X,tarzan).
loves(pooh,X) :- loves(jane,X). 

% "If anyone loves someone else then harry loves sally."
loves(harry,sally) :- exists(X), exists(Y), loves(X,Y), !. 

% "Jack loves everyone who is rich and whom harry also loves."
loves(jack,X) :- exists(X), rich(X), loves(harry,X). 

% "lydia loves everyone whom jack or jill love (excluding jack and jill)."
loves(lydia,X) :- loves(jack,X); loves(jill,X), \==(X,jack), \==(X,jill).

% "sam loves everyone who love at least two other people other than themselves."
loves(sam,X) :- loves(X,Y), loves(X,Z), \==(X,Y), \==(X,Z), \==(Y,Z).
  

% ==========================================================================
% Test your knowledge base by converting these questions into prolog queries.
% ==========================================================================

% "Who does tarzan love?"            
% | ?- loves(tarzan,X).

% "Does anybody love somebody?"       
% | ?- loves(X,Y), !.           

% "Does jack love jane or sally?"   
% | ?- loves(jack,jane); loves(jack,sally).      

% "Who does sally love?"             
% | ?- loves(sally,X).     
   
% "Does pooh love tarzan and jane?"        
% | ?- loves(pooh,tarzan), loves(pooh,jane).   

% "Who does sam love?"                     
% | ?- loves(sam,X).
    
% "Who loves joker?                        
% | ?- loves(X,joker).

% "Who does joker love?"             
% | ?- loves(joker,X). 
%
% "Who does lydia love besides herself?"  
% (see if you can figure out why jerry is listed twice)

% | ?- loves(lydia,X), X \== lydia.
