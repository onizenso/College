; These examples are written in Scheme.
;
; To compile, at the Unix command prompt type this:
;
;         csc examples.scm
;
; To run:
;
;         examples
;
; the syntax of 'define' varies from Common Lisp:
; define fac (n)   ; for common lisp
; define (fac n)   ; for scheme
;
; Differences between Clisp and Scheme:
; t is #t in Scheme
; Scheme does not accept ~D as a format output directive 
; There is no 'loop for' or 'numberp' in Scheme
;
;
; recursive version of factorial function
(define (fac n)  
    (if (= n 0)
       1
    (* n (fac (- n 1)))))

(format #t "fac 5: ~A ~%" (fac 5))

; 'do' is a macro created in lisp out of lisp functions
; macros are expanded when the lisp program is evaluated
; the first argument of do is a list of variable specifications of the form:
; do (variable initial update)
; where variable is a symbol, and initial and update are expressions.
;
; the second argument of do is a list containing one or more expressions
; the first of these expression is the stopping condition
; the rest of the expressions will be evaluated when iteration stops
; and the last value returned

; the remaining expressions comprise the body of the loop
; the value of the last expression will be returned
 
; iterative version of factorial function using do
(define (fac2 n)   
   (do ((j n (- j 1))   ; j=n j=j-1  
      (f 1 (* j f)))    ; f=1 f=f*j
      ((= j 0) f)))     ; second argument

(format #t "fac2 6: ~A ~%" (fac2 6))

; another example of the do macro
(define (squares start end)
  (do ((i start (+ i 1) ))             ; set loop variable i to 2 
      ((> i end) 'done)                ; stopping condition 
    (format #t "~A ~A ~%" i (* i i))))

(write Squares:)
(newline)
(squares 2 5)


; let binds a variable name to a value
; let binds an initial value and can bind subsequent values also 
(define (ask-number )
  (format #t "Please enter an integer. ")
  (let ((val (read)))
    (if (integer? val)
        val
        (ask-number))) ; end let
)

(ask-number)
