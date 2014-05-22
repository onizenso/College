
HINTS:
+  turn on paren-matching in vi with :set sm
+  In Emacs, do M-x lisp-mode 
+  if you end up in the debugger hit :q or CTRL-D
+  you must reload the source if you make changes to it
+  note: gnu readline will make up arrows work in clisp
+  Lisp is case insensitive

QUICK GUIDE TO USING CLISP 

   The lisp interpreter/compiler/debugger on helios is GNU CLISP 2.33.2.
   The compiler creates bytecode (see man clisp).  
   The easiest way to learn Lisp is interactively in the interpreter.
   Type 'clisp' to take you into the interpreter.
   The extension for lisp programs varies from .cl to .lisp.

To compile and check for syntax from the command line:
  $ clisp -c myprog.lisp

//////////// USING THE LISP INTERPRETER ///////////

   Assume examples.lisp contains two functions:

(defun is-member (obj lst)
  (if (null lst)
      nil
      (if (eql (car lst) obj)
          t 
          (is-member obj (cdr lst)))))

(defun sum-greater (x y z)
    (> (+ x y) z))


Start lisp 
  > clisp     ( or 'clisp -q' to start lisp without the opening banner ) 

Load the code into the interpreter (syntax will be checked also):

  > (load 'examples.lisp)

Run the function is-member and pass two arguments:

  > (is-member 'a '(a b c))
    T
  > (is-member 'a '(b c d))
    NIL

Run the function sum-greater:

   > (sum-greater 3 4 5)
   T
   > (sum-greater 2 3 9)
   NIL

To open a file for output:

  > (dribble "lab02.txt")      ; open file
   ...
  > (dribble)                  ; close file


To exit clist:

  >(quit)  or 
  >(bye)   or 
  >(exit)


QUICK GUIDE TO USING SCHEME 

  Turn on paren-matching in vi with :set sm
  To use the interpreter, type 'csi <filename>' at the command line
  Exit with ',q'

