% voltmeter_multiplier.m
% Convert a PMMC movement into a voltmeter with a series multiplier Rs.
% Same Ig flows through Rs and the movement:  V = Ig*(Rg + Rs)
%   Rs = V/Ig - Rg ,  multiplying factor  m = V/(Ig*Rg) = 1 + Rs/Rg

Ig = 2e-3;     % full-scale deflection current, A
Rg = 50;       % movement resistance, ohm
V  = 300;      % desired full-scale voltage, V

vg = Ig*Rg;                 % volts dropped by the movement alone at FSD
Rs = V/Ig - Rg;             % series multiplier resistance
m  = V / vg;                % multiplying factor
m_check = 1 + Rs/Rg;

printf('Movement : Ig = %.1f mA, Rg = %.1f ohm (drops %.3f V at full scale)\n', ...
       Ig*1e3, Rg, vg);
printf('Extend range to V = %.0f V\n\n', V);
printf('Series multiplier Rs = V/Ig - Rg = %.1f ohm  (= %.3f kohm)\n', Rs, Rs/1e3);
printf('Multiplying factor m = V/(Ig*Rg) = %.1f\n', m);
printf('Cross-check       m = 1 + Rs/Rg  = %.1f\n', m_check);

if abs(m - m_check) < 1e-6
  printf('\nm = 1 + Rs/Rg verified.\n');
else
  printf('\nMISMATCH in m.\n');
end
