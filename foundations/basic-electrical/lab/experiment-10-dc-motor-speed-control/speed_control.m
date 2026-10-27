# Speed control of a DC shunt motor: armature voltage control and field flux control.
# Compares the measured speeds against N = Eb/(k*phi).

Nbase = 1500;   % base speed (rpm) at 220 V, If = 1.0 A
Ra    = 1.0;    % armature resistance (ohm)
Ia    = 2.0;    % armature current, held ~constant by the light load

% ---- Table 1: armature voltage control (field constant) ----
V  = [220 200 180 160 140 120];
Eb = V - Ia*Ra;
Nth = Nbase * Eb / Eb(1);              % N proportional to Eb
Nme = [1490 1355 1230 1080 945 815];   % tachometer readings
printf("Armature voltage control (If = 1.0 A):\n");
printf("   V    Eb    N_th    N_meas   %%err\n");
for k = 1:length(V)
  err = (Nme(k) - Nth(k))/Nth(k)*100;
  printf(" %4d %5d %8.2f %7d %7.2f\n", V(k), Eb(k), Nth(k), Nme(k), err);
end

% ---- Table 2: field flux control (armature voltage constant) ----
If  = [1.0 0.9 0.8 0.7 0.6];
Nthf = Nbase * If(1) ./ If;            % N proportional to 1/If  (phi ~ If)
Nmef = [1490 1655 1860 2160 2520];
printf("\nField flux control (V = 220 V):\n");
printf("   If    N_th    N_meas   %%err\n");
for k = 1:length(If)
  err = (Nmef(k) - Nthf(k))/Nthf(k)*100;
  printf(" %4.1f %8.2f %7d %7.2f\n", If(k), Nthf(k), Nmef(k), err);
end

printf("\nArmature control span: %d to %d rpm (<= base)\n", min(Nme), max(Nme));
printf("Field control span:    %d to %d rpm (>= base)\n", min(Nmef), max(Nmef));
