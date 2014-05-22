n = 12;
a = .2;                         % the diameter of the small tube
c = .6;                         % the diameter of the bulb
t1 = pi/4 : pi/n : 5*pi/4;      % parameter along the tube
t2 = 5*pi/4 : pi/n : 9*pi/4;    % angle around the tube
u  = pi/2 : pi/n : 5*pi/2;
[X,Z1] = meshgrid(t1,u); 	% define the grid used to map the surface
[Y,Z2] = meshgrid(t2,u);

% The handle
len = sqrt(sin(X).^2 + cos(2*X).^2);
% define x, y and z bounds of the handle 
x1 = c*ones(size(X)).*(cos(X).*sin(X) ...
    - 0.5*ones(size(X))+a*sin(Z1).*sin(X)./len);
y1 = a*c*cos(Z1).*ones(size(X));
z1 = ones(size(X)).*cos(X) + a*c*sin(Z1).*cos(2*X)./len;
% define the surface using the handle's parameters
handleHndl=surf(x1,y1,z1,X);
set(handleHndl,'EdgeColor',[.5 .5 .5]);
hold on;

% The bulb
r = sin(Y) .* cos(Y) - (a + 1/2) * ones(size(Y)); % radius
% define x, y and z bounds of the bulb
x2 = c * sin(Z2) .* r; 
y2 = - c * cos(Z2) .* r;
z2 = ones(size(Y)) .* cos(Y);
% define the surface using the bulb's parameters
bulbHndl=surf(x2,y2,z2,Y);
% render the bulb
set(bulbHndl,'EdgeColor',[.5 .5 .5])

% Used to draw the bulb and render the different colors for each section
colormap(hsv);
axis vis3d % view with three-dimensional axis
view(-37,30);
axis off
light('Position',[2 -4 5]) % position of the light source
light
hold off
