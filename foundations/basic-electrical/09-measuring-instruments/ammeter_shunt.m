% ammeter_shunt.m
% Convert a PMMC movement into an ammeter with a parallel shunt Rsh.
% Movement and shunt share the same voltage, so
%   Ig*Rg = (I - Ig)*Rsh   ->   Rsh = Ig*Rg / (I - Ig)

Ig = 20e-3;    % full-scale deflection current of the movement, A
Rg = 25;       % coil (movement) resistance, ohm
I  = 5;        % desired full-scale range of the ammeter, A

Rsh = Ig*Rg / (I - Ig);     % shunt resistance
n   = I / Ig;               % multiplying power = range / movement current
n_check = 1 + Rg/Rsh;       % same n, from the resistances

printf('Movement : Ig = %.1f mA, Rg = %.1f ohm\n', Ig*1e3, Rg);
printf('Extend range to I = %.2f A\n\n', I);
printf('Shunt  Rsh = Ig*Rg/(I-Ig) = %.5f ohm  (= %.3f mohm)\n', Rsh, Rsh*1e3);
printf('Multiplying power n = I/Ig     = %.4f\n', n);
printf('Cross-check       n = 1+Rg/Rsh = %.4f\n\n', n_check);

Ish = I - Ig;               % current the shunt carries at full scale
printf('At full scale: movement %.1f mA, shunt %.3f A\n', Ig*1e3, Ish);
printf('Voltage check: Ig*Rg = %.4f V , Ish*Rsh = %.4f V\n', Ig*Rg, Ish*Rsh);

if abs(n - n_check) < 1e-6
  printf('\nn = 1 + Rg/Rsh verified.\n');
else
  printf('\nMISMATCH in n.\n');
end
