# two_wattmeter.m
# Two-wattmeter method, both directions.
#   forward:  W1, W2  ->  total power and power factor
#   reverse:  VL, IL, pf  ->  expected W1, W2
# then confirm the reverse feeds back into the forward (round trip).

% ---- forward: readings to power and pf ----
W1 = 8000;   % wattmeter 1, W
W2 = 4000;   % wattmeter 2, W

P      = W1 + W2;
tanphi = sqrt(3) * (W1 - W2) / (W1 + W2);   % the derived relation
phi    = atan(tanphi);
pf     = cos(phi);

printf("Forward:  W1 = %g W, W2 = %g W\n", W1, W2);
printf("  total power P = %.1f W\n", P);
printf("  tan(phi) = %.4f  ->  phi = %.2f deg,  pf = %.4f\n\n", tanphi, phi*180/pi, pf);

% ---- reverse: line quantities to expected wattmeter readings ----
VL = 400;                       % line voltage, V
IL = P / (sqrt(3) * VL * pf);   % line current consistent with P and pf
phi2 = acos(pf);
W1_exp = VL * IL * cos(pi/6 - phi2);   % W1 = VL IL cos(30 - phi)
W2_exp = VL * IL * cos(pi/6 + phi2);   % W2 = VL IL cos(30 + phi)

printf("Reverse:  VL = %g V, IL = %.4f A, pf = %.4f\n", VL, IL, pf);
printf("  expected W1 = %.1f W,  W2 = %.1f W\n\n", W1_exp, W2_exp);

% ---- round trip ----
printf("Round trip: W1 err = %.2e,  W2 err = %.2e\n", abs(W1_exp - W1), abs(W2_exp - W2));
if abs(W1_exp - W1) < 1e-6 && abs(W2_exp - W2) < 1e-6
  printf("tan(phi) = sqrt(3)(W1-W2)/(W1+W2) round-trips. OK\n");
else
  printf("MISMATCH\n");
end
