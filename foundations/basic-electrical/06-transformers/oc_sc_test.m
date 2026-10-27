# oc_sc_test.m
# Work out the equivalent-circuit parameters from OC and SC test readings.
# OC test done on the LV side  -> shunt branch R0, X0
# SC test done on the HV side  -> series params R01, X01, Z01 (referred to HV/primary)

% ---- open-circuit test (LV side, secondary open) ----
V0 = 200;    % applied voltage, V
I0 = 0.7;    % no-load current, A
W0 = 70;     % wattmeter reading = iron loss, W

cos0 = W0 / (V0 * I0);        % no-load power factor
sin0 = sqrt(1 - cos0^2);
Iw   = I0 * cos0;             % core-loss (working) component
Imu  = I0 * sin0;             % magnetising component
R0   = V0 / Iw;               % core-loss resistance
X0   = V0 / Imu;              % magnetising reactance

printf("OC test (LV side):  V0=%g V, I0=%g A, W0=%g W\n", V0, I0, W0);
printf("  cos(phi0) = %.3f,  Iw = %.4f A,  Imu = %.4f A\n", cos0, Iw, Imu);
printf("  R0 = %.2f ohm,  X0 = %.2f ohm\n\n", R0, X0);

% ---- short-circuit test (HV side, secondary shorted, rated current) ----
Vsc = 100;   % applied (reduced) voltage, V
Isc = 10;    % short-circuit current (= rated HV current), A
Wsc = 200;   % wattmeter reading = full-load copper loss, W

Z01 = Vsc / Isc;                 % equivalent impedance referred to HV
R01 = Wsc / Isc^2;               % equivalent resistance referred to HV
X01 = sqrt(Z01^2 - R01^2);       % equivalent reactance referred to HV

printf("SC test (HV side):  Vsc=%g V, Isc=%g A, Wsc=%g W\n", Vsc, Isc, Wsc);
printf("  Z01 = %.2f ohm,  R01 = %.2f ohm,  X01 = %.3f ohm\n", Z01, R01, X01);
