;; CMPS 350 FINAL EXAM WTR 2010  (Lisp)                                / 15

;; PROBLEM #1.  (3 pts)
;; Define a recursive function that returns C(n,k).
;; The recursive definition for C(n,k) is:
;;    if (k=0) or (n = k) then 1
;;    else C(n-1,k) + C(n-1,k-1)
;;
;; Test for C(6,4) 


;; PROBLEM #2.  (3 pts)
;; Define a recursive function that returns the sum of the first n positive
;; integers; e.g. n = 5 returns 5+4+3+2+1 = 15.

   
;; PROBLEM #3.  (3 pts)
;; Use backwards substitution to trace each call in this function for x = 3 
;; (write your answer in comments)
(defun stuff (x)
    (if (eql x 0)
        T
        (AND (mod x 2) (stuff (- x 1)))))



;; PROBLEM #4.  (3 pts)
;; Write a recursive function to find the nth term of the sequence 
;; defined as follows:
;;
;;  int f(0) = 3, f(n) = 2 * f(n-1) + 3.
;;  Test for n = 5.


;; PROBLEM #5.  (3 pts)
;; What does this function do?

(defun prob5 (lst)
  (if  (eql NIL (cdr lst))
     (car lst) 
  (prob5 (cdr lst))))

