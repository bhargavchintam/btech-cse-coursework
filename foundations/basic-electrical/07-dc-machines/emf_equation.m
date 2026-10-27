% emf_equation.m -- DC machine EMF, E = P*phi*Z*N/(60*A)
% Same machine wound two ways: lap (A = P) vs wave (A = 2). Compare and take the ratio.

P   = 4;        % poles
phi = 0.02;     % flux per pole, Wb
Z   = 500;      % total armature conductors
N   = 1200;     % speed, rpm

A_lap  = P;     % lap: as many parallel paths as poles
A_wave = 2;     % wave: always 2 paths

E_lap  = P*phi*Z*N/(60*A_lap);
E_wave = P*phi*Z*N/(60*A_wave);

printf("Machine: P=%d, phi=%.3f Wb, Z=%d, N=%d rpm\n", P, phi, Z, N);
printf("Lap  winding (A=%d): E = %.1f V\n", A_lap,  E_lap);
printf("Wave winding (A=%d): E = %.1f V\n", A_wave, E_wave);
printf("Ratio E_wave/E_lap = %.2f  (= A_lap/A_wave = P/2)\n", E_wave/E_lap);
