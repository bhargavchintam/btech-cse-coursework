# Ohm's Law - current through a 470 ohm resistor as V goes 0..10 V
# recompute the theory from scratch, tabulate, and fit the slope of the V-I line

R = 470;                 % ohm
V = 0:2:10;              % applied voltage, volts
I = V ./ R;              % Ohm's law: I = V/R, amps

printf('  V (V)     I (mA)\n');
for k = 1:length(V)
  printf('  %5.1f   %8.4f\n', V(k), I(k)*1000);
end

% slope of the I-vs-V line is the conductance 1/R
p = polyfit(V, I, 1);    % p(1) = slope in siemens, p(2) ~ 0 intercept
printf('\nfitted slope = %.6f S = %.4f mA/V\n', p(1), p(1)*1000);
printf('1/R          = %.6f S = %.4f mA/V\n', 1/R, 1000/R);
printf('R from slope = %.2f ohm  (nominal %d ohm)\n', 1/p(1), R);

% V-I characteristic. straight line through the origin, slope 1/R.
figure('visible','off');
plot(V, I*1000, '-o');
xlabel('V (volts)'); ylabel('I (mA)');
title('V-I characteristic of a 470 ohm resistor'); grid on;
