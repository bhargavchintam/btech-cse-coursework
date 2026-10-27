% wattmeter_reading.m
% Dynamometer wattmeter: current coil carries I, pressure coil senses V,
% the deflection follows the average of v*i, i.e. the real power V*I*cos(phi).

V   = 230;      % rms voltage, V
I   = 5;        % rms current, A
phi = 60;       % phase angle between V and I, degrees

P = V*I*cosd(phi);        % wattmeter reading (active power), W
S = V*I;                  % apparent power, VA
Q = V*I*sind(phi);        % reactive power, VAR

printf('V = %.0f V, I = %.1f A, phi = %.0f deg  (pf = cos phi = %.3f)\n', ...
       V, I, phi, cosd(phi));
printf('Wattmeter reads P = V*I*cos(phi) = %.1f W\n', P);
printf('Apparent power   S = V*I         = %.1f VA\n', S);
printf('Reactive power   Q = V*I*sin(phi)= %.1f VAR\n\n', Q);

% Purely reactive (or purely inductive/capacitive) load: phi = 90 deg
phi2 = 90;
P2 = V*I*cosd(phi2);
printf('Purely reactive load: phi = %.0f deg, pf = cos(90) = %.0f\n', phi2, cosd(phi2));
printf('Wattmeter reads P = V*I*cos(90) = %.1f W\n', P2);
printf('  -> reads ZERO even though S = %.0f VA is flowing.\n', V*I);
