;; CMPS 350 EXAM I WTR 2011 LISP                                        / 50 
;;
;; One question is extra credit.                     
;;
;; Do not use predefined Lisp functions--write functions from scratch. When in 
;; doubt, ask me.
;;
;; The name 'foo' below denotes some function name that you come up with. 
;;
;; Assume valid input. SUBMIT THIS FILE TO ME.


;;  #1.  
;; What does this function return for any integer x and y, x > y > 0? 
;; (write answer as a comment)

(defun stuff (x y)
    (if (eql y 0) x (stuff y (mod x y))))

;; ANSWER:


;;  #2.  
;; What does this function return?  (write answer as a comment)

(defun junk (x)
  (if  (eql NIL (cdr x))
     (car x) 
  (junk (cdr x))))

;; ANSWER: 




;; #3.
;; Define a recursive function foo that returns the size of a list; e.g., 
;; (foo '(a b c)) returns 3 and (foo '()) returns 0.






;; #4.  
;; Define a recursive function (foo x y), where for y=0 or x=y, foo returns 1. 
;; For all other values of x and y, foo returns foo(x-1 y) + foo(x-1 y-1); e.g.
;; (foo 5 0) returns 1, (foo 6 6) returns 1, and (foo 6 3) returns 20.








;; #5.  
;; Define a function foo that computes n to the falling power of k; e.g. 
;; (foo 7 3) returns 210, which is 7*6*5, (foo 7 2) returns 42, which is 7*6, 
;; (foo 7 1) returns 7 and (foo 7 7) returns 5040, which is 7*6*5*4*3*1. 






 
;; #6.  
;; Use the predefined 'mod' operator to define a function (foo n) that returns 
;; returns T if n is odd otherwise NIL. 





;; #7.  
;; Define a recursive function foo that returns the sum of the first n positive
;; ODD integers; e.g. (foo 7) and (f00 8) return 16, which is 7+5+3+1. 
;; Hint: call (odd n) which you defined above.





;;  #8.  
;; Define a recursive function foo that returns the nth term of the sequence 
;; defined as follows:
;;
;;  int f(0) = 3, f(n) = 2 * f(n-1) + 3.
;;  e.g., (foo 1) returns 2*3+3=9 and (foo 2) returns 2*9+3=21. 
;;  Check:(foo 5) should return 189.







;; #9.
;; Function rev below reverses a list; e.g. (rev '(1 2 3)) returns (3 2 1).
;; Rev calls 'append', which concatenates two or more lists into a single 
;; list, and also calls 'list', which turns an atom into a list.
;; 
(defun rev(x)
   (if (null x) () (append (rev (cdr x)) (list (car x)))))

;; Using append and list as demonstrated in function rev above, define function 
;; foo that takes a list of numbers, doubles each number in the original list 
;; and returns the result as a new list; e.g., (foo '(1 2 3)) returns (2 4 6). 
;; Note that the new list is NOT reversed. 





;; #10.
;; Using the lisp 'eql' operator, which compares an atom with an atom, define 
;; a function (foo x y) that returns true if list x equals list y; e.g.,
;; (foo '(a b c) '(a b c)) returns T and (foo '(a b c) '(a b)) returns NIL.

;; Assume your input list does NOT include sublists.






;; #11.
;; Write a Test function that calls each of your functions and displays
;; output. The function below gets you started. 

(defun test ()
(progn 
   (format t "~A ~A ~%" 'Prob1 (stuff 10 7)) 
   (format t "~A ~A ~%" 'Prob2 (rev '(a b c))))
   'done 
)

