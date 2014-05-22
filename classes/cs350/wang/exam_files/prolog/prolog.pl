/* filename: prolog.pl                                            / 25 pts 
   CMPS 350 WTR 2011 EXAM2                                    

 Submit this file.

 Your job is to convert each of the following english statements into prolog 
 rules and facts. For full credit, submit the queries you run to test your 
 inference rules.

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





% #2. 
% A bird eats nuts.
% A bear eats nector.
% If an animal eats nuts then it eats nector.
% If an animal eats nuts and nector it has wings. 
% If an animal has wings it can fly.
% Can a bird fly? can a bear fly?  





% #3
%
% sam and harry like sally.  
% jill likes harry.
% if sam or jill like a person then that person likes jack.
% If someone likes jack then that person likes joe.
% If someone likes joe and sally then spike likes that person.
% Who does spike like?   






% #4 
% sam teaches cs350.
% sally teaches cs300.
% joe is taking cs300 and cs350.
% Someone who teaches a class instructs anyone who is taking the class.
% Who instructs joe?  




% # 5
% You have a group of people: jack,joe,alice,sam, sally and bob. Of this group:
% jack is taller than joe.
% joe is taller than alice. 
% anyone who is taller than joe is taller than sam.
% anyone who is taller than sam is taller than bob.
% sally is not taller than anyone.
% no one is taller than themselves.
% Who is taller than sally? Who is Jack is taller than?

% You may start with the following facts if you want (this is not necessary but
% may make some of your rules easier to write.
exists(jack).
exists(joe).
exists(alice).
exists(sam).
exists(sally).
exists(bob).
