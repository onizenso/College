:- use_module(library(strings)). 

edit(File) :- 
    concat_atom(['vi ', File],Cmd),     /*  e.g., use edt as editor  */ 
    vms(dcl(Cmd)),        
    write('Reconsult '),  
    write(File),          
    write(' (y or n)? '), 
    read(R),              
    (R == y ; R == yes),  
    reconsult(File).     
