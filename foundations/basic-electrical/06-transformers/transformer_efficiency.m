# transformer_efficiency.m
# Efficiency of a transformer at part load, and the load for maximum efficiency.

S   = 20000;   % rating, VA (20 kVA)
Pi  = 300;     % iron (core) loss, W  -- constant at all loads
Pcu = 675;     % full-load copper loss, W  -- varies as (load)^2
pf  = 0.8;     % power factor

printf("Rating %.0f kVA, Pi = %g W, full-load Pcu = %g W, pf = %g\n\n", S/1000, Pi, Pcu, pf);
printf(" load     output(W)   Cu loss(W)  total loss(W)  efficiency\n");

for x = [0.25 0.50 0.75 1.00]
  out  = x * S * pf;      % output power
  cu   = x^2 * Pcu;       % copper loss scales with load^2
  loss = Pi + cu;
  eta  = out / (out + loss);
  printf("  %4.2f   %9.1f   %9.2f   %10.2f      %6.2f%%\n", x, out, cu, loss, eta*100);
end

% ---- maximum efficiency: variable Cu loss = constant iron loss ----
xm    = sqrt(Pi / Pcu);      % load fraction for max efficiency
outm  = xm * S * pf;
cum   = xm^2 * Pcu;          % should equal Pi
etam  = outm / (outm + Pi + cum);

printf("\nMax efficiency at x = sqrt(Pi/Pcu) = %.4f  (= %.2f kVA)\n", xm, xm*S/1000);
printf("  Cu loss there = %.2f W  (equals Pi = %g W)\n", cum, Pi);
printf("  eta_max = %.2f%%\n", etam*100);
