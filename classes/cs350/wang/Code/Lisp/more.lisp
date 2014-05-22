;; more Common Lisp examples

;; what does this function do?
;; atom returns true if the argument is an atom or the empty list
(defun trash ( x )
  ( if (atom x)
       nil 
     ( if (NULL (cdr x))
        (car x)
      ( max (car x) ( trash (cdr x))))))
   
;; what does this function do?
(defun thing ( x )
   ( if ( NULL x )
       NIL
       ( if ( listp ( car x ) )
          T
          ( thing ( cdr x ) ) ) )) 


;; what does this function do?
(defun stuff (x y)
  (if (null y)
      nil
      (if (eql (car y) x)
          t 
          (stuff x (cdr y)))))

;; what does this function do?
(defun junk (x y z)
    (> (+ x y) z))

;; what does this function do? note - this is NOT tail recursion
(defun foo (x) 
   (if (null x)
     0
    (+ (foo (cdr x)) 1)))

;; what does this function do? 
;; consp returns true if the argument is a non-empty list
(defun bar (x y)
  (or (eql x y )
      (and (consp x)
           (consp y)
           ( bar (car x) (car y))
           ( bar (cdr x) (cdr y)))))


;; what does this function do? 
;; consp returns true if the argument is a non-empty list
;; append concatenates the arguments into a single list 
(defun dog (x)
   (if (consp x)
         (if ( = (length x) 1) x (append (dog(cdr x)) (list(car x))))))

;; what does this function do? 
;; append concatenates the arguments into a single list 
(defun horse (lst) 
   (if (null lst) () (append (horse (cdr lst)) (list (car lst)))))


;; returns sum of numbers read from stdin until user hits 99
;; progn is a way of constructing blocks; e.g. begin/end or { }
(defun sum()
   (progn
      (format t "~A" "Enter an int or 99 to end:")
      (let (( val (read)))
         (if ( eql val 99)
         0 
         (+ val ( sum ))))))


;; the same thing without progn
(defun sum2()
      (format t "~A" "Enter an int or 99 to end:")
      (let (( val (read)))
         (if ( eql val 99)
         0 
         (+ val ( sum )))))

(defun test ()
(format t "~A ~A ~A ~A~%"  (junk 10 7 20 )
   (stuff 'a '(a b c) )
   (stuff 'a '( b (a) c) ) (thing '(a b ())) ) 
)

;; progn is a control structure construct for compound statements; e.g. blocks
(defun test2 ()
(progn 
   (format t "~A ~%"  (junk 10 7 20)) 
   (format t "~A ~%"  (stuff 'a '(a b c)))
   (format t "~A ~%"  (stuff 'a '( b (a) c))))) 


;; what does this function do?

( defun foobar (n l)
     ( cond ( (< n 0 ) nil )
        ( (eq n 0) (car l) )
        ( t (foobar (- n 1) (cdr l)))))


; this function that takes a list and returns true if one of its elements
; is a list (does not check sublists).
;;
    (defun findlst (x)
        (if (null x)
            nil
        (if (listp (car x))
            T
        (findlst (cdr x)))))

;(findlst '(a (a))) yields (findlist '((a))) yields (if (listp'(a))) yields T
;;
