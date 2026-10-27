% back_emf_speed.m -- back EMF of a DC motor, and what flux does to speed
% Eb = V - Ia*Ra, and N = Eb*60*A/(P*phi*Z). Weaken the field -> the motor speeds up.

V   = 230;      % supply, V
Ia  = 20;       % armature current, A
Ra  = 0.5;      % armature resistance, ohm
P   = 4;  A = 4;  Z = 500;   % 4-pole lap machine
phi = 0.02;     % flux per pole, Wb

Eb = V - Ia*Ra;
N1 = Eb*60*A/(P*phi*Z);
printf("Back EMF  Eb = %.1f V\n", Eb);
printf("Speed     N1 = %.1f rpm  at phi = %.3f Wb\n", N1, phi);

% now weaken the field by 10%, Eb unchanged
phi2 = 0.9*phi;
N2 = Eb*60*A/(P*phi2*Z);
printf("Flux reduced 10%% -> phi = %.4f Wb\n", phi2);
printf("New speed N2 = %.1f rpm  (weaker field means higher speed)\n", N2);
