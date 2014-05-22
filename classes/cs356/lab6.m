I = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
	 0, 0, 1, 2, 4, 4, 2, 1, 0, 0;
	 0, 0, 1, 4, 8, 8, 4, 1, 0, 0;
	 0, 0, 1, 2, 4, 4, 2, 1, 0, 0;
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
	 0, 0, 0, 0, 1, 2, 4, 1, 0, 0;
	 0, 0, 0, 0, 2, 4, 8, 1, 0, 0;
	 0, 0, 0, 0, 4, 8, 4, 1, 0, 0;
	 0, 0, 0, 0, 1, 1, 1, 1, 0, 0;
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

D = I;
bw(:,:) = (D(:,:) > 0); 
D1      = -D;
D1(~bw) = -Inf;
L       = watershed(D1);
rgb     = label2rgb(L);
imshow(rgb, 'initialMagnification', 'fit');

Rule{1,1} = 'Temp is High';
Rule{1,2} = 'Velocity is Medium';
Rule{2,1} = 'Temp is Low';
Rule{2,2} = 'Velocity is High';

WM{1} = 'Temp is High';
WM{2} = 'Temp is Low';
outcome1 = strcmp(WM{1}, Rule{1,1});
outcome2 = strcmp(WM{2}, Rule{1,2});

if outcome1 
    disp('Current velocity: ');
    disp(Rule{1,2});
elseif outcome2
    disp('Current velocity: ');
    disp( Rule{2,2} );
end