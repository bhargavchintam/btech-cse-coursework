% power_triangle.m -- from V, I and the phase angle work out the real,
% reactive and apparent power and the power factor, then check that the
% power triangle closes: S^2 = P^2 + Q^2.

clear all;

V   = 230;    % volts (rms)
I   = 5;      % amps  (rms)
phi = 30;     % degrees, current lagging the voltage

P  = V*I*cosd(phi);     % real power, W
Q  = V*I*sind(phi);     % reactive power, VAR
S  = V*I;               % apparent power, VA
pf = cosd(phi);         % power factor

printf('P  (real)     = %.2f W\n',   P);
printf('Q  (reactive) = %.2f VAR\n', Q);
printf('S  (apparent) = %.2f VA\n',  S);
printf('power factor  = %.4f lagging\n', pf);
printf('check: sqrt(P^2 + Q^2) = %.2f VA   vs   S = %.2f VA\n', sqrt(P^2 + Q^2), S);

if abs(sqrt(P^2 + Q^2) - S) < 1e-6
  printf('power triangle closes.\n');
else
  printf('MISMATCH -- check the working.\n');
end
