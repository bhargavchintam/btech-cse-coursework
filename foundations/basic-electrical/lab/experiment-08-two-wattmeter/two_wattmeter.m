# Two-wattmeter method for a balanced three-phase load
# W1 = VL*IL*cos(30-phi), W2 = VL*IL*cos(30+phi)
# Total power = W1 + W2 ;  tan(phi) = sqrt(3)*(W1-W2)/(W1+W2)
# For pf < 0.5, phi > 60 deg so W2 goes negative (wattmeter reads backward).

VL = 415;      % line voltage, V
IL = 10;       % line current, A (held constant)
deg = pi/180;

pf  = [1.0000 0.8660 0.7071 0.5000 0.3000];
phi = acos(pf);

W1t = VL*IL*cos(30*deg - phi);       % theoretical wattmeter 1
W2t = VL*IL*cos(30*deg + phi);       % theoretical wattmeter 2

% measured = theoretical nudged by a 1-3% instrument error
kW1 = [1.018 1.012 0.985 1.016 0.990];
kW2 = [0.984 0.978 1.021 1.000 1.022];
W1 = W1t .* kW1;
W2 = W2t .* kW2;

P    = W1 + W2;                      % measured total power
Pth  = sqrt(3)*VL*IL*pf;             % theoretical total power
err  = (P - Pth) ./ Pth * 100;
tanp = sqrt(3)*(W1 - W2) ./ (W1 + W2);   % recovered from the two readings
phir = atan(tanp);
pfr  = cos(phir);

printf("  pf     phi   W1(W)    W2(W)     P=W1+W2   Ptheo    %%Err   tanphi   pf_calc\n");
for k = 1:length(pf)
  printf("  %.4f  %5.1f  %8.2f %8.2f  %8.2f  %8.2f  %+5.2f  %6.4f  %6.4f\n", ...
         pf(k), phi(k)/deg, W1(k), W2(k), P(k), Pth(k), err(k), tanp(k), pfr(k));
end

printf("\nRound-trip check  tan(phi) = sqrt(3)*(W1-W2)/(W1+W2) = tan(acos(pf_calc)):\n");
for k = 1:length(pf)
  ok = abs(tanp(k) - tan(acos(pfr(k)))) < 1e-9;
  printf("  row %d (W2 = %8.2f W): %s\n", k, W2(k), merge(ok, "holds", "FAILS"));
end

printf("\nRow 5 is the pf<0.5 case: W2 = %.2f W is negative; taken as negative the\n", W2(5));
printf("total is still %.2f W and the recovered pf is %.4f.\n", P(5), pfr(5));
