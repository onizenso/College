/* 4. Extra Credit Problem Statement:
  ==================
  Jones, Smith, and Clark hold the jobs of programmer, engineer, and manager 
  (not necessarily in that order). Jones owes the programmer $10. The manager's
  spouse prohibits borrowing money. Smith is not married. Your task is to 
  figure out which person has which job.

  Represent the facts in propositional logic. You should have nine propositional
  symbols to represent the possible person/job assignments. For example, you
  might use the symbol SM to indicate that Smith is the manager. You do not need
  to represent the relation between owing and borrowing, or being married and
  having a spouse; you can just use these to draw conclusions (e.g. from "Smith
  is not married" and "the manager's spouse" we know that Smith can't be the
  manager, which you can represent as ~SM). The conjunction of all the relevant
  facts forms a sentence which you can call KB. The possible answers to the
  problem are sentences like JP^SK^CM.

  There are six such combinations of person/job assignments. Solve the problem
  by showing that only one of them is implied by KB, and by saying what its
  interpretation is.

*/

% what we know:
% jones is not the programmer (it may be smith or clark) 
% smith and jones are not the manager 

% the facts
manager(clark).
not_programmer(jones).

% the positive rules are circular thus won't work
programmer(smith):- manager(clark), engineer(jones).
engineer(jones):- manager(clark), programmer(smith).

