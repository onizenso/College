(defun enigma (x)
         (and (not (null x))
           (or (null (car x))
             (enigma (cdr x)))))

(defun foo (obj lst)
  (if (null lst)
        NIL
      (if (eql (car lst) obj)
          t 
          (foo obj (cdr lst)))))

