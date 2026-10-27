% phasor_addition.m -- add two phasors given in polar form and check the
% answer against plain complex-number arithmetic.
% V1 = 50 <  30 deg
% V2 = 40 < -45 deg

clear all;

M1 = 50;  a1 =  30;      % magnitude, angle in degrees
M2 = 40;  a2 = -45;

% by hand: resolve into rectangular components and add
x = M1*cosd(a1) + M2*cosd(a2);
y = M1*sind(a1) + M2*sind(a2);
Mag = sqrt(x^2 + y^2);
Ang = atan2d(y, x);

% the same thing with Octave complex numbers as a cross-check
V1 = M1*exp(1i*a1*pi/180);
V2 = M2*exp(1i*a2*pi/180);
V  = V1 + V2;

printf('component method : %.4f < %.4f deg   (%.4f + j%.4f)\n', Mag, Ang, x, y);
printf('complex method   : %.4f < %.4f deg   (%.4f + j%.4f)\n', abs(V), angle(V)*180/pi, real(V), imag(V));

if abs(Mag - abs(V)) < 1e-9 && abs(Ang - angle(V)*180/pi) < 1e-9
  printf('the two methods agree.\n');
else
  printf('MISMATCH -- check the working.\n');
end
