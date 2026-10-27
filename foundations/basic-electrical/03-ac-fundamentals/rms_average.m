% rms_average.m -- get RMS and average by numeric integration, then
% work out the form factor and peak factor for
%   (a) a full sine wave
%   (b) a half-wave rectified sine
% compare against the standard results (1.11 / 1.414 for the sine).

clear all;

Vm = 100;                 % peak, take any value
N  = 2000;
th = (0:N-1)*(2*pi/N);    % one full cycle, no repeated end point

sine = Vm*sin(th);
half = max(sine, 0);      % half-wave rectified: negative part chopped

% average of a bidirectional wave is taken as the mean of |v| over a
% cycle (the plain mean of a full sine is zero)
rms_sine = sqrt(mean(sine.^2));
avg_sine = mean(abs(sine));

% for the half-wave the plain mean is the meaningful average
rms_half = sqrt(mean(half.^2));
avg_half = mean(half);

ff_sine = rms_sine/avg_sine;   pf_sine = Vm/rms_sine;
ff_half = rms_half/avg_half;   pf_half = Vm/rms_half;

printf('               RMS      AVG     Form    Peak\n');
printf('full sine   %7.3f %7.3f %7.4f %7.4f\n', rms_sine, avg_sine, ff_sine, pf_sine);
printf('half-wave   %7.3f %7.3f %7.4f %7.4f\n', rms_half, avg_half, ff_half, pf_half);
printf('\n');
printf('expected full sine : rms=Vm/sqrt2=%.3f  avg=2Vm/pi=%.3f  ff=1.1107  pf=1.4142\n', Vm/sqrt(2), 2*Vm/pi);
printf('expected half-wave : rms=Vm/2=%.3f      avg=Vm/pi=%.3f   ff=1.5708  pf=2.0000\n', Vm/2, Vm/pi);
