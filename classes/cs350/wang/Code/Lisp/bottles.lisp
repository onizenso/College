;; see: http://www.99-bottles-of-beer.net

;; Bottles by Rebecca Walpole (walpolr@cs.orst.edu)
;; tested in Austin Kyoto Common Lisp version 1.615
;;
;; ~% is a newline
;; ~D is decimal 
;; ~A is ASCII 
;; ~p prints s if n >= 1, otherwise nothing
;; 
(defun bottles (n)
 "Prints the lyrics to '99 Bottles of Beer'"
(if (< n 1)
    (format t "~%Time to go to the store.~%")
    (progn (format t "~% ~D bottle~:p of beer on the wall." n)
           (format t "~% ~a bottle~:p of beer." n)
           (format t "~% Take one down, pass it around.")
           (format t "~% ~a bottle~:p of beer on the wall.~%" (- n 1))
           (bottles (- n 1))
	   )
  )
)

(bottles 99)
