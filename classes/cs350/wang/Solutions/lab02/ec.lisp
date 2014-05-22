;Extra Credit: 
; returns the number of 'a's in a list and recursively check sublists

; cleanest solution 
(defun count_a (a lst)
  (if (null lst)
    0
    (if (listp (car lst))
      (+ (count_a a (car lst)) (count_a a (cdr lst)))
      (if (eql a (car lst))
	(+ 1 (count_a a (cdr lst)))
	(count_a a (cdr lst))))))

; another solution 
(defun cnt_a ( lst )
   ( let (( n 0 ))
      ( if ( null lst )
          n
          ( progn
             ( if ( listp ( car lst ) )
                ( setf n ( + n ( cnt_a ( car lst ) ) ) ))

             ( if ( eq 'a ( car lst ) )
                 ( setf n ( + 1 n ( cnt_a ( cdr lst ) ) ) )
                 ( setf n ( + 0 n ( cnt_a ( cdr lst ) ) ) )) 
                n))))


; another solution 
(defun myfunc4 (x)
   (if (null x)
      0
      (let ((z
    (if (listp (car x))
       (myfunc4(car x))
       (if (eql 'a (car x))
          1
          0))))
    (+ z (myfunc4(cdr x))))))

; another solution 
(defun findit (x)
    (if (eq x nil)
        0
        (if (listp (car x))
            (findit (append (cdr x) (car x)))
            (if (eq 'a (car x))
                (+ (findit (cdr x)) 1)
                (findit (cdr x))))))

