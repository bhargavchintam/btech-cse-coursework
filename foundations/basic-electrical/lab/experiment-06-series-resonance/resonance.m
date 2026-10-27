# Series RLC resonance - current vs frequency, Q and bandwidth from the half-power points
# f0 where I is maximum and X = 0; verify I(f1)=I(f2)=Imax/sqrt(2) numerically.

R = 10;        % ohm
L = 10e-3;     % H
C = 1e-6;      % F
V = 10;        % V rms

f0 = 1/(2*pi*sqrt(L*C));
Q_formula = (1/R)*sqrt(L/C);      % Q = (1/R)sqrt(L/C)
BW_formula = f0/Q_formula;

% table at the frequencies used in the record
f = [1000 1200 1400 1513.960 1591.549 1673.115 1800 2000 2200];
w = 2*pi*f;
XL = w*L;                          % w = 2*pi*f, keep forgetting this
XC = 1./(w*C);
Z  = sqrt(R^2 + (XL-XC).^2);
I  = V ./ Z;

printf("   f(Hz)    XL      XC      |Z|      I(A)\n");
for k = 1:length(f)
  printf("  %8.2f  %6.2f  %6.2f  %6.3f  %7.5f\n", f(k), XL(k), XC(k), Z(k), I(k));
end

Imax = V/R;
printf("\nf0 = %.4f Hz, Imax = %.4f A (Z = R = %d ohm at resonance)\n", f0, Imax, R);

% locate the half-power points on a fine sweep and read off f1, f2
ff = linspace(1000, 2200, 1200001);
Ig = V ./ sqrt(R^2 + (2*pi*ff*L - 1./(2*pi*ff*C)).^2);
half = Imax/sqrt(2);
below = ff(Ig >= half);
f1 = below(1); f2 = below(end);
BW = f2 - f1;
Qm = f0/BW;

printf("Half-power level = Imax/sqrt(2) = %.5f A\n", half);
printf("f1 = %.2f Hz, f2 = %.2f Hz  ->  I(f1)/Imax = %.5f, I(f2)/Imax = %.5f\n", ...
        f1, f2, interp1(ff,Ig,f1)/Imax, interp1(ff,Ig,f2)/Imax);
printf("BW = f2 - f1 = %.4f Hz\n", BW);
printf("Q from f0/BW      = %.4f\n", Qm);
printf("Q from (1/R)sqrt(L/C) = %.4f\n", Q_formula);

plot(ff, Ig, "-", [f1 f2], [half half], "ro");
xlabel("f (Hz)"); ylabel("I (A)");
title("Series resonance: current vs frequency"); grid on;
