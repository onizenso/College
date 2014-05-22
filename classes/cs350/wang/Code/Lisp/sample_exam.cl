;; CMPS 350   WTR 2009  Exam 1 (Lisp Component) 
;; each problem worth 5 pts                                                /25
;; submit this file

;; #1.

;; Define a recursive function that returns log2(n), where n = 2^k and k is an
;; integer >= 0; e.g. (log2 32 ) returns 5 and (log2 1) returns 0. 
 

;; #2. What does this recursive function  do?  (write answer in comments)

(defun mystery(lst n)
   (if (null lst) 
         nil
   (if (eq n 0) 
       (car lst)
    (mystery (cdr lst) (- n 1)))))

;; #3. 

;; Using 'and', 'not', and 'or' only (not 'if'), define a recursive function  
;; that takes a list and returns true if the list contains atom 'a'.  
;; (you do not need to check sublists)

     
 
;; #4.

;; define a recursive function that takes a non-empty list and returns the 
;; last element in the list.


;;  #5. Given this function 
   
(defun p5 (x)
   (if (null x)
     0
    (+ (car x) (p5 (cdr x)))))

;; Complete the trace of each call to p5(n) from the initial call (p5 '(2 4 6))
;; until the final result ( 12 ).    (write your answer in comments)

;;   p2 '(2 4 6) = 
