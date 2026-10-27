# OC and SC test on a 1 kVA, 230/115 V single phase transformer
# Finds R0, X0 (LV side) and Z01, R01, X01 (HV side), then efficiency and regulation.

% nameplate
S   = 1000;      % VA
VHV = 230;       % HV side
VLV = 115;       % LV side
I_HV = S/VHV;    % rated HV current
I_LV = S/VLV;    % rated LV current
printf("Rated current  HV = %.2f A , LV = %.2f A\n\n", I_HV, I_LV);

% ---- OC test readings (LV side, HV open) ----
V0 = 115; I0 = 0.6; W0 = 18;
cos0 = W0/(V0*I0);
sin0 = sqrt(1 - cos0^2);
Iw  = I0*cos0;          % core-loss component
Imu = I0*sin0;          % magnetising component
R0  = V0/Iw;            % = V0^2/W0
X0  = V0/Imu;
printf("OC test (LV side):\n");
printf("  cos(phi0) = %.3f\n", cos0);
printf("  Iw = %.3f A , Imu = %.3f A\n", Iw, Imu);
printf("  R0 = %.1f ohm , X0 = %.1f ohm\n\n", R0, X0);

% ---- SC test readings (HV side, LV shorted) ----
Vsc = 12; Isc = 4.35; Wsc = 35;
Z01 = Vsc/Isc;
R01 = Wsc/Isc^2;
X01 = sqrt(Z01^2 - R01^2);
printf("SC test (HV side):\n");
printf("  Z01 = %.3f ohm , R01 = %.3f ohm , X01 = %.3f ohm\n", Z01, R01, X01);
printf("  check Z01^2 - (R01^2+X01^2) = %.2e\n\n", Z01^2 - (R01^2 + X01^2));

% ---- efficiency at 0.8 pf lagging ----
pf = 0.8;
printf("Efficiency at 0.8 pf lagging:\n");
for x = [0.5 1.0]
  out = x*S*pf;
  cu  = x^2*Wsc;
  eff = out/(out + W0 + cu)*100;
  printf("  x = %.1f : output = %.0f W , loss = %.2f W , eff = %.2f %%\n", ...
         x, out, W0+cu, eff);
end

% ---- full-load voltage regulation, 0.8 pf lagging (HV side) ----
cosp = 0.8; sinp = 0.6;
VR = I_HV*(R01*cosp + X01*sinp)/VHV*100;   % I_HV = rated = 4.35 A
printf("\nVoltage regulation (full load, 0.8 pf lag) = %.2f %%\n", VR);
