; The code in this file was mechanically extracted from the TeX
; source files of _Ansi Common Lisp_, except for bst-remove and
; bst-delete and their subroutines, which replace broken versions 
; in the book.

; If you have questions or comments about this code, or you want
; something I didn't include, send mail to lispcode@paulgraham.com.

; This code is copyright 1995 by Paul Graham, but anyone who wants
; to use it is free to do so.

; *** list ***


(defun askem (string)
  (format t "~A" string)
  (read))

(defun ask-number ()
  (format t "Please enter a number. ")
  (let ((val (read)))
    (if (numberp val)
        val
        (ask-number))) ; end let
)

; iterative version of show-squares
(defun show-squares (start end)
  (do ((i start (+ i 1)))
      ((> i end) 'done)
    (format t "~A ~A~%" i (* i i))))

; recursive version of show-squares
(defun show-squares (i end)
  (if (> i end)
      'done
      (progn
        (format t "~A ~A~%" i (* i i))
        (show-squares (+ i 1) end))))


; dolist takes an argument of the form (variable expression),
; followed by a body of expressions. The body will be evaluated with
; variable bound to successive elements of the list returned by
; expression.  So the loop above says, for each obj in lst, increment
; len.

(defun our-length (lst)
  (let ((len 0))
    (dolist (obj lst)
      (setf len (+ len 1)))


; recursive version of this function would be:
(defun our-length (lst)
  (if (null lst)
      0
      (+ (our-length (cdr lst)) 1)))



(defun compress (x)
  (if (consp x) 
      (compr (car x) 1 (cdr x))
      x))

(defun compr (elt n lst)
  (if (null lst)
      (list (n-elts elt n))
      (let ((next (car lst)))
        (if (eql next elt)
            (compr elt (+ n 1) (cdr lst))
            (cons (n-elts elt n)
                  (compr next 1 (cdr lst)))))))

(defun n-elts (elt n)
  (if (> n 1)
      (list n elt)
      elt))


(defun uncompress (lst)
  (if (null lst)
      nil
      (let ((elt (car lst))
            (rest (uncompress (cdr lst))))
        (if (consp elt)
            (append (apply #'list-of elt)
                    rest)
            (cons elt rest)))))

(defun list-of (n elt)
  (if (zerop n)
      nil
      (cons elt (list-of (- n 1) elt))))


(defun mirror? (s)
  (let ((len (length s)))
    (and (evenp len)
         (let ((mid (/ len 2)))
           (equal (subseq s 0 mid)
                  (reverse (subseq s mid)))))))


(defun shortest-path (start end net)
  (bfs end (list (list start)) net))


