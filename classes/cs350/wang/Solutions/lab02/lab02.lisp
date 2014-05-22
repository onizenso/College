; cmps 350  lab 02   - answers to coding questions 

;07. What does this function return?

; enigma returns true if x contains a null list otherwise false
; the structure of enigma is:  (AND (condition) (condition))


(defun enigma (x)
   (and
      (not (null x) )  ; first condition returns T if a non-null list  
                                           
      (or (null (car x)) (enigma (cdr x)))  ; second condition OR returns T if 
                                            ; first element is a null list else 
                                            ; start all over again
)) 

;08. What does this function return?
; mystery returns the position of x in list y or NIL if x is not in the list 

; Preconditions: x is a single character and y is a list
; let establishes variable bindings (binds a variable to a value)
; for example: (let ((z 5)) (+ z 1))  binds z to 5, increments z, and returns 6
; the 'and' operator returns last value if T else NIL; e.g. (and 3 2) returns 2 
 
(defun mystery (x y)
     (if (null y)                            ; return NIL if y is a null list
        nil                                  ; otherwise 
        (if (eql (car y) x)                  ; return 0 if the 1st atom in y=x
              0                              ; otherwise
              (let ((z (mystery x (cdr y)))) ; z is bound to 0 or NIL
                 (and z (+ z 1))             ; increment z by 1  
))))


;09. Define an iterative function that takes positive int n and prints n dots.

(defun iter_dots (n)                 
   (do (( i 1 (+ i 1)))               ; do loop
      (( > i n) 'done)                ; return 'done instead of NIL
      (format t "~A" ".")))

(defun dots (x)                       ; for loop 
  (loop for i from 1 to x do
    (format t ".")))


;10. Define a recursive function that takes a positive int n and prints n dots.

(defun recur_dots (n)
   (if (> n 1)
     (recur_dots (- n 1)))
   (if (> n 0)
      (format t "~A" ".")))

(defun recur_dots2 ( x )
   ( if ( > x 0 )
      ( format t "~A" "." ( recur_dots2 ( - x 1 ) ) )))

; the use of AND forces two function evaluations for the else
(defun print-dot (x)
    (if (eql x 0)
        T
        (AND (princ "." ) (print-dot (- x 1)))))


;11. Define a recursive function that takes a list and returns the number of 
;    times the symbol 'a' occurs in it. (note: you do not need to look for 
;    a's in a sublist within a list)

; this is a simple recursive algorithm  - don't complicate it!
( defun rcount ( lst )
   ( if ( null lst )
        0
     ( if ( eq ( car lst ) 'a )
          ( + 1 (rcount ( cdr lst )))
          ( + 0 (rcount ( cdr lst ))))))


; this works but is more complicated
(defun recur_cnt_a (lst)
   (if (null lst)  
       0 
       (+ (recur_cnt_a (cdr lst))(if (eq (car lst) 'a) 1 0))))
;
; Sample run:
; junk (b a a) = (+ (junk(a a)) (if (eq b a) 1 0))
;       = (+ (+ (junk (a) (if (eq a a) 1 0 )(if (eq b a) 1 0))  
;       = (+ (+ (junk () (if (eq a a) 1 0)(if (eq a a) 1 0 )(if (eq b a) 1 0))  
;       = (+ (+ (0 (if (eq a a) 1 0) (if (eq a a) 1 0 )(if (eq b a) 1 0))  
;       = (+ (+ 1) (+1  0))  
;       = (+ (+ 1)(+1))  
;       = (2)  


; this is an iterative version
(defun iter_cnt_a (lst)
  (let ((cnt 0))
     (dolist (obj lst)
         (setf cnt ( if (eq obj 'a)
                     (+ cnt 1)
                      cnt)))
   cnt))

;12. Define a recursive function that returns the Fibonacci number where the
;    Fibonacci sequence is defined as
;
;    n =       0 1  2  3  4  5  6   7   8  9   ...
;    fib(n) =  0 1  1  2  3  5  8  13  21  34  ...
;    where fib (n) = fib(n-1) + fib(n-2) for n > 1.

(defun fib (n)
   ( if ( = 0 n ) 0 (if ( = 1 n ) 1 ( + (fib (- n 1)) (fib (- n 2))))))
    
; for n >= 1 you can do this 
(defun fib2 (n)
   ( if ( OR (= 1 n ) ( = 2 n ))
            1 
   ( + (fib (- n 1)) (fib (- n 2)))))

; 13. Define a function with 2 arguments and returns the greater of the two.

(defun greater (x y)
  ( if ( > x y ) x y))

; create a function to test everything
; each function is enclosed in a format command to display the result
; you can also embed all the functions in a single format operator
; "~%" is a newline and "~A" formats output as alphanumeric

(defun test () 
   (format t "~A" "enigma should yield T: ")  
   (format t "~A~%" (enigma '(a ())))      
 
   (format t "~A" "mystery should yield position 2: ")   
   (format t "~A~%" (mystery 'a '(b b a)))   

   (format t "~A" "recursive dots 5: ")   
   (recur_dots 5)      
   (format t "~%")
                   
   (format t "~A" "recursive dots 7: ")   
   (recur_dots2 7)                         
   (format t "~%")
   (recur_dots 0)                           ; just testing 
   (format t "~A" "iterative dots 5: ")   
   (iter_dots 5)                            
   (format t "~%")
   (iter_dots 0)                            ; just testing
 
   (format t "~A" "recursive_count_a should yield 1: " )
   (format t "~D~%" (recur_cnt_a '(b c a))) 
   (format t "~A" "iterative_count_a should yield 2: " )
   (format t "~D~%" (iter_cnt_a '(b a b c a)))             

   (format t "~A" "fib 7 should yield 13: " )
   (format t "~D~%" (fib 7))               
 
   (format t "~A" "greater should yield 7: " )
   (format t "~D~%" (greater 5 7))         
)
