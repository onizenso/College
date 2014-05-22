;; CMPS 350 FINAL EXAM WTR 2010  (Lisp)                                / 15

;; PROBLEM #1.  (3 pts)
;; Define a recursive function that returns C(n,k).
;; The recursive definition for C(n,k) is:
;;    if (k=0) or (n = k) then 1
;;    else C(n-1,k) + C(n-1,k-1)
;;
;; Test for C(6,4) 

(defun C (n k)
  (if ( OR (= k 0) (= n 0) ) 
     1
   ( + (C (- n 1) k)  (C (- n 1) (- k 1)))))
 

;; PROBLEM #2.  (3 pts)
;; Define a recursive function that returns the sum of the first n positive
;; integers; e.g. (sum 5) should return 5+4+3+2+1=15. Test for n = 5.

(defun sum (n )
 ( if ( = n 0) 0
    ( + ( sum (- n 1) ) n)))
   
;; PROBLEM #3.  (3 pts)
;; Use backwards substitution to trace each call in this function for x = 3 
;; (write your answer in comments)
(defun stuff (x)
    (if (eql x 0)
        T
        (AND (mod x 2) (stuff (- x 1)))))
;
;; (stuff (3))
;; (stuff (AND (1) (stuff (2))))
;; (stuff (AND (1) (AND (0) (stuff (1))))
;; (stuff (AND (1) (AND (0) (AND (1) stuff (0))))
;; (stuff (AND (1) (AND (0) (AND (1) T))))
;; (stuff (AND (1) (AND (0) (T))))
;; (stuff (AND (1) (T)))
;; (stuff (T))
;; T 


;; PROBLEM #4.  (3 pts)
;; Write a recursive function to find the nth term of the sequence 
;; defined as follows:
;;
;;  int f(0) = 3, f(n) = 2 * f(n-1) + 3.
;;  (term 5) should return 189.

(defun term (n )
  (if ( = n 0)
     3
  ( + (* 2 (term ( - n 1))) 3 )))

;; PROBLEM #5.  (3 pts)
;; What does this function do?

(defun prob5 (lst)
  (if  (eql NIL (cdr lst))
     (car lst) 
  (prob5 (cdr lst))))

;; ANS: returns the last element in the list
