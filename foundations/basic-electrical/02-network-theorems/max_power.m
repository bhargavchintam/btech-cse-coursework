# max_power.m - sweep RL, plot P vs RL, find RL that maximises load power
# runs under Octave

Vth = 8;
Rth = 2e3;

RL = 0:50:6000;                      % load values, ohm
P  = (Vth ./ (Rth + RL)).^2 .* RL;   % P = I^2 * RL, I = Vth/(Rth+RL)

[Pmax, idx] = max(P);
RL_opt = RL(idx);

printf("P is maximum at RL = %.4g ohm\n", RL_opt);
printf("Pmax = %.4g mW\n", Pmax*1e3);
printf("theory: RL = Rth = %.4g ohm, Pmax = Vth^2/(4*Rth) = %.4g mW\n", ...
       Rth, Vth^2/(4*Rth)*1e3);

plot(RL, P*1e3);
xlabel("RL (ohm)");
ylabel("P in RL (mW)");
title("Maximum power transfer");
grid on;

# expected: RL = 2000 ohm, Pmax = 8 mW
