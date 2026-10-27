# Fluorescent lamp: choke reactance for a 40 W tube on 230 V, 50 Hz,
# and the power factor before and after adding a shunt capacitor.

P     = 40;      % tube power (W)
Vs    = 230;     % supply voltage (V)
f     = 50;      % supply frequency (Hz)
Vtube = 100;     % running (arc) voltage across the tube (V)
w     = 2*pi*f;  % w = 2*pi*f, keep forgetting this

% tube is resistive, so running current follows from P and Vtube
I = P/Vtube;

% choke is reactive; supply = phasor sum of tube (in phase) and choke (quadrature)
Vchoke = sqrt(Vs^2 - Vtube^2);
XL = Vchoke/I;
L  = XL/w;
printf("Line current I      = %.3f A\n", I);
printf("Choke voltage       = %.1f V\n", Vchoke);
printf("Choke reactance XL  = %.1f ohm\n", XL);
printf("Choke inductance L  = %.3f H\n\n", L);

% ---- power factor before correction ----
S  = Vs*I;
pf = P/S;
Q  = sqrt(S^2 - P^2);
printf("Before capacitor: S = %.2f VA, pf = %.3f lag, Q = %.2f VAR\n", S, pf, Q);
printf("  check Q = I^2*XL = %.2f VAR\n\n", I^2*XL);

% ---- capacitor to raise pf to target ----
pft = 0.95;
Sa  = P/pft;
Qa  = sqrt(Sa^2 - P^2);
Qc  = Q - Qa;
C   = Qc/(Vs^2 * w);
Ia  = Sa/Vs;
printf("After capacitor (target pf %.2f):\n", pft);
printf("  S' = %.2f VA, Q' = %.2f VAR, Qc = %.2f VAR\n", Sa, Qa, Qc);
printf("  C  = %.2f uF\n", C*1e6);
printf("  new line current I' = %.3f A  (was %.3f A)\n", Ia, I);
