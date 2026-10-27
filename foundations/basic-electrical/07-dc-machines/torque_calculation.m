% torque_calculation.m -- armature torque, shaft torque, and a check against Pmech/omega
% Ta = 0.159*phi*Z*Ia*(P/A). The exact constant is 1/(2*pi); 0.159 is just that rounded.

P = 4;  A = 2;  Z = 400;     % 4-pole wave machine
phi = 0.025;                 % flux per pole, Wb
Ia  = 25;                    % armature current, A
N   = 1000;                  % speed, rpm
Wr  = 500;                   % rotational (iron + friction) loss, W

Ta = 0.159*phi*Z*Ia*(P/A);           % textbook form
printf("Armature torque Ta = %.2f N.m  (0.159 constant)\n", Ta);

% cross-check through power: Pmech = Eb*Ia, then T = Pmech/omega
Eb      = P*phi*Z*N/(60*A);
omega   = 2*pi*N/60;                 % rad/s
Pmech   = Eb*Ia;
T_power = Pmech/omega;
printf("Eb = %.2f V, Pmech = Eb*Ia = %.1f W, omega = %.3f rad/s\n", Eb, Pmech, omega);
printf("T from Pmech/omega = %.2f N.m\n", T_power);
printf("difference = %.4f N.m  (only the 0.159-vs-1/2pi rounding)\n", T_power - Ta);

% shaft torque: take off the rotational loss, then convert
Pout = Pmech - Wr;
Tsh  = Pout/omega;
printf("Shaft torque Tsh = %.2f N.m\n", Tsh);
printf("developed - shaft = %.2f N.m  (= Wr/omega = %.2f N.m)\n", T_power - Tsh, Wr/omega);
