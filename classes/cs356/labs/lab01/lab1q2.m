p1 = 0.5; p2 = 0.5; m1 = [1 1]'; m2 = [3 3]'; 
s = eye(2); x = [1.8 1.8]'; [l , c] = size(m1);
[l c] = size(m1);
p1 = p1*(1/((2*pi)^(l/2)*det(s)^0.5))*exp(-0.5*(x-m1)'*inv(s)*(x-m1));
[l c] = size(m2);
p2 = p2*(1/((2*pi)^(l/2)*det(s)^0.5))*exp(-0.5*(x-m2)'*inv(s)*(x-m2);
