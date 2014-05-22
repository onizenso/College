; These examples are for Common Lisp
; 
; To load the file and execute a function:
;     $ clisp
;     > (load 'examples.cl)
;     > (test) 
;     > (quit)

; recursive version of factorial function
(defun fac1 (n)   ;  recursive version 
    (if (<= n 1)
       1
    (* n (fac1 (- n 1)))))


; how is fac1 (5) evaluated?
;  (fac1 5)
;  (* 5 (fac1 4))
;  (* 5 (* 4 (fac1 3)))
;  (* 5 (* 4 (* 3 (fac1 2))))
;  (* 5 (*4 (*3 (*2 (fac1 1))))
;  (* 5 (*4 (*3 (*2 1))))
;  (* 5 (*4 (*3 2))))
;  (* 5 (*4 6))
;  (* 5 24)
;  120

; A functional language has no side effects! The assignment statement in an 
; imperative language is a side effect so original lisp did not use them.
; Variables instead are "bound" to values. Variables can be bound to another
; value, but this is not the same as changing the value in the memory 
; address of that variable.
; You can mplement a simple algorithm to accumulate something in a loop 
; without assignments using DO.
;
; the DO macro
;
; 'do' is a Lisp macro, which is expanded when the lisp program is evaluated
; the first argument of do is a list of variable specifications of the form:
; do (variable initial update)
; where variable is a symbol, and initial and update are expressions.
;
;  The second argument of do is a list containing one or more expressions. The 
;  first of these expression is the stopping condition. The remaining 
;  expressions are evaluated when iteration stops and the last value returned.
;  The remaining expressions comprise the body of the loop. 

; simple example of do
;  ( do   ( (var init update)... )  ( (control) ( exit)) (body) ) 
;
(defun test_do (n)              ; in C for - control and update are reversed
   (do                          ; for
       ( ( i 1                  ; i = 1; 
         (+ i 1) ))             ; i++       
         ((> i n) )             ; i <= 10  
          ( print i )           ; printf("\n%d", i);
    )
)   

 
; iterative version of factorial function using do binds f and i to new values
(defun fac2 (n)   
   (do ( (j n (- j 1)) (f 1 (* j f)) ) ; two (var init update) expressions  
       ( (= j 0) f )                   ; the body is empty
   )
)    

; another example of the do macro
; sample call is show-squares (2 5)
(defun show-squares (start end)
  (do ((i start (+ i 1)))              ; set loop variable i to 2 
      ((> i end) 'done)                ; stopping condition 
    (format t "~D ~D ~%" i (* i i)))
)


; iterative version of factorial function using 'for loop'
; 'finally' causes the specified expression to be evaluated in the 
; loop epilogue after normal iteration terminates.    
(defun fac3 (n)   
    (loop for i from 1 to n
          for fac = 1 then (* fac i)
          finally return fac))

; let binds a variable name to a value
; syntax is (let  ( (x value)...)  (body)) 
(defun ask-number ()
  (format t "Please enter a number. ")
  (let ((val (read)))
     (if (numberp val)
         val
         (ask-number)
     )
   )
)
     



; format is an imperative feature added to lisp
; the format directive ~% prints a newline - ~D prints a decimal number
; the format directive ~A prints ASCII character(s)
; lisp uses prefix expressions, which means that (+ 4 5 6 7 ) is valid

(defun test  ()
   (format t "~D ~D ~D ~D ~%" (fac1 3) (fac2 5) (show-squares 2 5) (+ 5 6 7 8)) 
)

; another way to call the functions and display results  
( defun test2 ()
(list ( fac1 3) ( fac2 5) (show-squares 2 5)) )

; lambda 

(defun test_lambda (x) ((lambda (x) (+ x 100)) 5))

; or use #' to create and execute a function on the fly
(funcall #'(lambda (x) (+ x 100)) 1)


