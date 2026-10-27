# Maximum power transfer - power delivered to RL as RL is varied
# Vth behind Rth feeding a variable load RL. Peak power at RL = Rth, efficiency 50%.

Vth = 10;      % V
Rth = 100;     % ohm
RL  = 20:20:200;

IL  = Vth ./ (Rth + RL);       % load current, A
VL  = Vth .* RL ./ (Rth + RL); % load voltage, V
PL  = IL.^2 .* RL;             % load power, W
eff = RL ./ (RL + Rth) * 100;  % efficiency, %

printf("  RL(ohm)   IL(mA)   VL(V)   PL(mW)   eta(%%)\n");
for k = 1:length(RL)
  printf("  %6d   %6.3f  %6.3f  %7.3f  %6.2f\n", RL(k), IL(k)*1e3, VL(k), PL(k)*1e3, eff(k));
end

[Pmax, idx] = max(PL);
printf("\nMaximum power %.3f mW at RL = %d ohm (Rth = %d ohm)\n", Pmax*1e3, RL(idx), Rth);
printf("Efficiency at the match = %.1f %%\n", eff(idx));
printf("Closed form P_max = Vth^2/(4*Rth) = %.3f mW\n", Vth^2/(4*Rth)*1e3);

% smooth curve to show the peak sits exactly at RL = Rth
r = 1:1:300;
p = (Vth^2 .* r) ./ (Rth + r).^2;
plot(r, p*1e3, "-", RL, PL*1e3, "o");
xlabel("R_L (ohm)"); ylabel("P_L (mW)");
title("Power delivered to load vs R_L"); grid on;
