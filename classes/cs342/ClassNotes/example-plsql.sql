CREATE OR REPLACE FUNCTION topNAvg ( n IN NUMBER ) RETURN NUMBER IS 

	s NUMBER(9,2) := 0.0;
	p NUMBER(7,2);

	CURSOR c1 IS SELECT price FROM room ORDER BY price DESC;

BEGIN

    OPEN c1;
    FOR i IN 1 .. n LOOP

    	fetch c1 INTO p;
	s := s + p;

    END LOOP;
    CLOSE c1;
    RETURN s / n;
    COMMIT;
    EXCEPTION
	when others  THEN
	    raise_application_error( --not finished 
END;
/
