m=[0 1]';
s=eye(2);
x1=[0.2 1.3]';
[l,c]=size(m);
pg2=(1/((2*pi)^(l/2)*det(s)^0.5))*exp(-0.5*(x2-m)'*inv(s)*(x2-m));
Undefined function or variable 'x2'.
 
x2 = [2.2, -1.3]';
pg2=(1/((2*pi)^(l/2)*det(s)^0.5))*exp(-0.5*(x2-m)'*inv(s)*(x2-m));
pg1=(1/((2*pi)^(l/2)*det(s)^0.5))*exp(-0.5*(x1-m)'*inv(s)*(x1-m));
