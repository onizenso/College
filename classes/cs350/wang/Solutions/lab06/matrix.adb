-- File:    matrix.adb

with Ada.Text_IO; use Ada.Text_IO;          
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Matrix is

    -- matrix bounds
    MAX_ROW : constant := 3;
    MAX_COL : constant := 5;

    subtype SUB_INT is INTEGER range -100000..100000;      

    -- declare 2-dimensional array type
    type MATRIX is array(INTEGER range 1..MAX_ROW, INTEGER range 1..MAX_COL) of SUB_INT; 
    
    -- three 3x5 Matrices 
    matrix_A : MATRIX ;
    matrix_B : MATRIX ;
    matrix_C : MATRIX ;

    -- note: use of parameters is optional since data is visible
    procedure loadData(A : out MATRIX; B : out MATRIX) is   
    
        inf : FILE_TYPE;   -- declare input file handler
    begin 
        Open(inf, In_File, "matrix.in");  -- two lines with 15 ints per line
        
        -- load matrix A
        for j in 1..MAX_ROW loop
            for k in 1..MAX_COL loop
                Get(inf, A(j, k) );
            end loop;
        end loop;
        
        -- load matrix B 
        for j in 1..MAX_ROW loop
            for k in 1..MAX_COL loop
                Get(inf, B(j,k) );
            end loop;
        end loop;
        
        put_line("Loaded Matrix Data") ;
        Close(inf) ;
    end loadData ;

    -- Procedure to multiply two matrices (use of parameters is optional)
    procedure matrixMul( A : in MATRIX; B : in MATRIX; C : out MATRIX)  is
    
    begin
        for i in 1..MAX_ROW loop
            for j in 1..MAX_COL loop
                C(i,j) := A(i,j) * B(i,j);
            end loop;
        end loop;
        
        put_line("Multiplied Matrix Data");
    end matrixMul ;


    -- Write a matrix to file --

    procedure writeData(C : out MATRIX) is
        outf : FILE_TYPE;   -- declare output file handler
    begin
        
        Create(outf, Out_File, "matrix.out");  -- open file for writing
        -- Write matrix data to outfile
        put_line("Writing Matrix Data");
        Set_Output(outf);   -- set this for formatted output
        for j in 1..MAX_ROW loop
            for k in 1..MAX_COL loop
                Put(outf, C(j, k), 5 );
            end loop;
        end loop;
        Set_Output(Standard_Output);
        close(outf) ;
    end writeData ;


---- Begin Main Program -----

begin

    loadData(matrix_A, matrix_B) ;
    matrixMul(matrix_A, matrix_B, matrix_C);
    writeData(matrix_C);

end Matrix;
