# Parallel resonance - practical tank (coil R+L in parallel with C)
# Line current is minimum / impedance maximum at resonance. Coil resistance R lowers fr
# below the ideal 1/(2*pi*sqrt(LC)).

R = 10;        % coil resistance, ohm
L = 10e-3;     % H
C = 1e-6;      % F
V = 10;        % V

f0_ideal = 1/(2*pi*sqrt(L*C));
fr       = (1/(2*pi))*sqrt(1/(L*C) - R^2/L^2);   % unity-pf resonance
corr     = sqrt(1 - C*R^2/L);
Zr       = L/(R*C);                              % dynamic resistance
Imin     = V/Zr;

Y = @(f) 1./(R + j*2*pi*f*L) + j*2*pi*f*C;       % tank admittance

f = [1400 1480 1540 1583.572 1630 1690 1770];
Ith = V*abs(Y(f))*1e3;                           % mA
Zmag = 1 ./ abs(Y(f));
pf = cos(angle(1 ./ Y(f)));

printf("   f(Hz)     |Z|(ohm)   I(mA)     pf\n");
for k = 1:length(f)
  printf("  %8.2f  %8.2f  %8.4f  %6.4f\n", f(k), Zmag(k), Ith(k), pf(k));
end

printf("\nIdeal   f0 = 1/(2*pi*sqrt(LC))       = %.4f Hz\n", f0_ideal);
printf("Actual  fr = (1/2pi)sqrt(1/LC-R^2/L^2) = %.4f Hz\n", fr);
printf("Correction sqrt(1 - C*R^2/L) = %.5f  (fr is %.3f%% below ideal)\n", ...
        corr, (f0_ideal-fr)/f0_ideal*100);
printf("Dynamic resistance Zr = L/(RC) = %.2f ohm\n", Zr);
printf("Minimum line current Imin = V/Zr = %.3f mA\n", Imin*1e3);

% confirm the unity-pf point on a fine sweep (imag of admittance changes sign)
ff = linspace(1400,1800,4000001);
Yim = imag(Y(ff));
[~, ix] = min(abs(Yim));
printf("Numeric unity-pf frequency (imag Y = 0) = %.4f Hz\n", ff(ix));

plot(ff, V*abs(Y(ff))*1e3, "-");
xlabel("f (Hz)"); ylabel("line current (mA)");
title("Parallel resonance: line current vs frequency"); grid on;
