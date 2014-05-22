/* filename: prolog.pl                                            / 25 pts 
  CMPS 350 2011 EXAM2                                    
  NAME: 

  Submit this file.

 Your job is to convert each of the following english statements into prolog 
 rules and facts. For full credit, submit the queries you run to test 
 that your inference rules work in comments.

 You may use whatever predicate names you wish, just provide your queries.

 Don't forget that Prolog variables (X,Y,etc.) begin with uppercase and 
 predicate names or literals (loves, dog, animal, etc.) are lowercase.       

 Don't forget that discontiguous predicates are ignored. As you finish each
 question, put like predicates together. 

 Hint: If you make a change to your knowledge base, the safest thing to do is
 to exit prolog and reload the code from scratch.  */

% #1.

% A dog has fur. 
% A lobster has claws.
% A lion has fur and claws.
% If an animal has claws and fur then it is a cat.
% Who is a cat?  

cat(X) :- claws(X), fur(X).
fur(lion).
fur(dog).
claws(lion).

% Query: cat(X).  lion YES.

% #2. 
% A bird eats nuts.
% A bear eats nector.
% If an animal eats nuts then it eats nector.
% If an animal eats nuts and nector it has wings. 
% If an animal has wings it can fly.
% Can a bird fly? can a bear fly?  

eats(bird,nuts).
eats(bee,flowers).
eats(X,flowers) :- eats(X,nuts).
wings(X) :- eats(X,nuts), eats(X,flowers).
fly(X) :- wings(X).
% Query: fly(X).         bird   YES   bear NO 


% #3
%
% sam and harry like sally.  
% jill likes harry.
% if sam or jill like a person then that person likes jack.
% If someone likes jack then that person likes joe.
% If someone likes joe and sally then spike likes that person.
% Who does spike like?   

likes(sam,sally).
likes(harry,sally).
likes(jill,harry).
likes(X,jack) :- likes(sam,X).
likes(X,jack) :- likes(jill,X).
likes(X,joe) :- likes(X,jack).
likes(spike,X) :- likes(X,joe), likes(X,sally).
%
% Query: likes(spike,X) X = harry 


% #4 
% sam teaches cs350.
% sally teaches cs300.
% joe is taking cs300 and cs350.
% Someone who teaches a class instructs anyone who is taking the class.
% Who instructs joe?  

teaches(sam,cs350).
teaches(sally,cs300).
taking(joe,cs300).
taking(joe,cs350).
instructs(X,Z) :- teaches(X,Y), taking(Z,Y).

% Query: instructs(X,joe).  (X = sam ; X = sally)

% # 5
% You have a group of people: jack,joe,alice,sam, sally and bob. In this group:
% jack is taller than joe.
% joe is taller than alice. 
% anyone who is taller than joe is taller than sam.
% anyone who is taller than sam is taller than bob.
% sally is not taller than anyone.
% no one is taller than themselves.
% Who is taller than sally? Who is Jack is taller than?


% Start with these facts (if you want to).
exists(jack).
exists(joe).
exists(alice).
exists(sam).
exists(sally).
exists(bob).

taller(jack,joe).
taller(joe,alice).
taller(X,sally) :- exists(X), \==(X,sally).
taller(X,sam) :- exists(X), taller(X,joe), \==(X,joe), \==(X,sam).
taller(X,bob) :- exists(X), taller(X,sam), \==(X,sam), \==(X,bob).

% taller(X,sally) ? Everyone but sally
% taller(jack,X) ? Everyone but alice and jack
