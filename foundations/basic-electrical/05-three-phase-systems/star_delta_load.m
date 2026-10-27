# star_delta_load.m
# Same balanced load impedance connected first in star, then in delta,
# on the same line voltage. Shows the 3:1 power ratio.

VL = 400;          % line voltage, volts
R  = 8;            % ohms per phase
X  = 6;            % ohms per phase (inductive)
Z  = hypot(R, X);  % |Z| per phase
pf = R / Z;        % cos(phi), lagging

printf("Load per phase: (%g + j%g) ohm, |Z| = %.2f ohm, pf = %.3f lag\n\n", R, X, Z, pf);

% ---- STAR ----
Vph_star = VL / sqrt(3);       % phase voltage
Iph_star = Vph_star / Z;       % phase current
IL_star  = Iph_star;           % line current = phase current in star
P_star   = 3 * Iph_star^2 * R; % total real power (3 * I^2 * R)

printf("STAR connection\n");
printf("  Vph = %.2f V   Iph = IL = %.2f A\n", Vph_star, Iph_star);
printf("  P   = %.1f W\n\n", P_star);

% ---- DELTA ----
Vph_delta = VL;                  % phase voltage = line voltage in delta
Iph_delta = Vph_delta / Z;       % phase current
IL_delta  = sqrt(3) * Iph_delta; % line current = sqrt(3) * phase current
P_delta   = 3 * Iph_delta^2 * R; % total real power

printf("DELTA connection\n");
printf("  Vph = %.2f V   Iph = %.2f A   IL = %.2f A\n", Vph_delta, Iph_delta, IL_delta);
printf("  P   = %.1f W\n\n", P_delta);

% ---- ratio ----
ratio = P_delta / P_star;
printf("P(delta) / P(star) = %.4f\n", ratio);   % expect 3.0000
printf("The same load in delta draws 3x the power it does in star.\n");
