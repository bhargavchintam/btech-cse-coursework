% earthing_resistance.m
% Earth resistance of a driven pipe electrode (IS 3043 formula):
%   R = rho/(2*pi*L) * ln(4L/d)
% rho = soil resistivity (ohm-m), L = length (m), d = diameter (m)

R = @(rho,L,d) rho ./ (2*pi.*L) .* log(4.*L./d);

rho = 100;      % soil resistivity, ohm-m
L   = 2.5;      % electrode length, m
d   = 0.025;    % pipe outer diameter, m  (25 mm)

printf('Pipe electrode: rho = %.0f ohm-m, L = %.2f m, d = %.0f mm\n', rho, L, d*1000);
printf('R = rho/(2*pi*L)*ln(4L/d) = %.2f ohm\n\n', R(rho,L,d));

printf('Vary length L (rho = %.0f ohm-m, d = %.0f mm):\n', rho, d*1000);
printf('   L (m)   R (ohm)\n');
for Lv = [1 2 2.5 3 4 5]
  printf('  %5.1f   %7.2f\n', Lv, R(rho,Lv,d));
end

printf('\nVary soil resistivity rho (L = %.2f m, d = %.0f mm):\n', L, d*1000);
printf('  rho(ohm-m)   R (ohm)\n');
for rv = [50 100 150 200]
  printf('  %8.0f   %7.2f\n', rv, R(rv,L,d));
end

printf('\nA single pipe gives ~%.1f ohm, well above the < 1 ohm wanted.\n', R(rho,L,d));
printf('Longer rods, wetter/saltier soil, or several pipes in parallel bring it down.\n');
printf('Two such pipes in parallel: about %.2f ohm.\n', R(rho,L,d)/2);
