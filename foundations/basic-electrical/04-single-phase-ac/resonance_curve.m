% resonance_curve.m -- series RLC: sweep frequency, plot the current and
% pick out the resonance peak, Q factor and bandwidth. Confirm the located
% peak agrees with f0 = 1/(2*pi*sqrt(L*C)).

clear all;

R = 10;      % ohm
L = 10e-3;   % H
C = 1e-6;    % F
V = 1;       % ac source, 1 V

f  = linspace(200, 6000, 20000);
w  = 2*pi*f;                 % w = 2*pi*f
XL = w*L;
XC = 1./(w*C);
Z  = sqrt(R.^2 + (XL - XC).^2);
I  = V ./ Z;

[Imax, k]  = max(I);
f0_peak    = f(k);                  % resonance located from the curve
f0_formula = 1/(2*pi*sqrt(L*C));    % textbook formula
Q          = (1/R)*sqrt(L/C);
BW         = f0_formula / Q;

printf('f0 (located on curve)   = %.2f Hz\n', f0_peak);
printf('f0 = 1/(2*pi*sqrt(LC))  = %.2f Hz\n', f0_formula);
printf('Q  = (1/R)*sqrt(L/C)    = %.3f\n', Q);
printf('BW = f0/Q               = %.2f Hz\n', BW);
printf('Imax at resonance       = %.4f A   (V/R = %.4f A)\n', Imax, V/R);

half = Imax/sqrt(2);        % half-power (0.707) level

plot(f, I, 'b-', 'linewidth', 1.5);
hold on;
plot([f(1) f(end)], [half half], 'r--');            % half-power line
plot(f0_formula, V/R, 'ko', 'markerfacecolor', 'k'); % resonance point
hold off;
xlabel('frequency (Hz)');
ylabel('current (A)');
title('Series RLC resonance: R=10, L=10mH, C=1uF');
grid on;

% print -dpng resonance_curve.png   % uncomment to save the figure (do not commit it)
