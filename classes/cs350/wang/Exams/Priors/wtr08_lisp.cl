;; CMPS 350   WTR 2008  exam 1 Lisp Each problem worth 2 pts             / 10

;; #3. 
;; Explain what this function does. (put your answer in comments)

;; This function reverses a list
(defun p3 (x)
   (if (null x) 
        () 
   (append (p3 (cdr x)) (list (car x)))))

;; If you trace p3 for the call: (p3 '(a b c)) and use backwards 
;; substitution, you can show what happens. 

;;   p3 '(a b c) = 
;;  (append (p3 '(b c)) (list (a))) 
;;  (append (append (p3 '(c)) (list (b))) (a))
;;  (append (append (append (p3 NULL) (list 'c)) (b) (a)))
;;  (append (append (append () (list 'c)) (b) (a)))
;;  (append (append (c) (b)) (a))
;;  (append (c b) (a) )
;;  ( c b a )

;; PROBLEM #4.  (2 pts)
;; define a function p4 that takes a list and returns true if the list
;; contains the atom 'a' (you do not need to check sublists)

(defun p4 (lst)
    (if (null lst)
        NIL 
    (if (eql 'a (car lst))
         t
       (p4 (cdr lst)))))
     
 
;; PROBLEM #5.  (1 pt)
;; replace X in the following function so that the function returns (5 3)

; (list (or X (listp 3)) (+ 1 2))

(list (or 5 (listp 3)) (+ 1 2))

;; PROBLEM #6.  (2 pts)
;; Define a recursive lisp function that returns the last element in a list.
;; You can assume input is a non-empty list
;; Recall that the last element in a list is NIL, thus your stopping condition
;; is when you have a list with one element, in which case you return
;; (car list)

(defun p6 (lst)
  (if  (eql NIL (cdr lst))
     (car lst) 
  (p6 (cdr lst))))


;; Define a recursive function to return element x at position n in a list 
;; or and NIL if n is beyond the end of the list 
;; note: you can define the first position as 0 or 1
 
(defun findit(lst n)
   (if (null lst) 
         nil
   (if (eq n 0) 
       (car lst)
    (findit (cdr lst) (- n 1)))))

 
