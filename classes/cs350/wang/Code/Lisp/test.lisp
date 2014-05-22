(defun test (n)
     (if (<= n 1)
        1
     (+ n (test (- n 1)))))


(defun enigma (x)
         (and (not (null x))
           (or (null (car x))
             (enigma (cdr x)))))

