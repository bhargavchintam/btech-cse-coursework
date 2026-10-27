% sine_wave.m -- plot the mains voltage and check its RMS numerically
% single-phase 230 V rms, 50 Hz supply

clear all;

Vrms_spec = 230;             % rms value we are given
f         = 50;              % Hz
Vm        = Vrms_spec*sqrt(2);   % peak value
w         = 2*pi*f;          % w = 2*pi*f, keep forgetting this
T         = 1/f;             % period

% sample exactly two whole cycles, no repeated end point, so the
% numeric rms comes out clean
N = 2000;
t = (0:N-1)*(2*T/N);
v = Vm*sin(w*t);

% numeric rms = sqrt(mean of v^2)
Vrms_num     = sqrt(mean(v.^2));
Vrms_formula = Vm/sqrt(2);

printf('Vm  (peak)         = %.2f V\n', Vm);
printf('Vrms (numeric)     = %.4f V\n', Vrms_num);
printf('Vrms = Vm/sqrt(2)  = %.4f V\n', Vrms_formula);
printf('difference         = %.2e V\n', abs(Vrms_num - Vrms_formula));

plot(t*1000, v, 'b-', 'linewidth', 1.5);
hold on;
plot([0 t(end)*1000], [ Vm  Vm], 'r--');   % mark +Vm
plot([0 t(end)*1000], [-Vm -Vm], 'r--');   % mark -Vm
text(1, Vm+10, sprintf('Vm = %.1f V', Vm));
hold off;
xlabel('time (ms)');
ylabel('voltage (V)');
title('v(t) = Vm sin(wt), 230 V rms 50 Hz');
grid on;

% print -dpng sine_wave.png   % uncomment to save the figure (do not commit it)
