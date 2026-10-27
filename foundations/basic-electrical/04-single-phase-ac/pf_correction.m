% pf_correction.m -- size a shunt capacitor to correct the power factor of
% a lagging load. The real power P does not change; the capacitor only
% supplies part of the reactive power so the line sees a smaller angle.
%   Qc = P*(tan(phi1) - tan(phi2))
%   C  = Qc / (2*pi*f*V^2)

clear all;

P   = 10e3;    % W    -- load real power (10 kW)
pf1 = 0.80;    %      -- present power factor, lagging
pf2 = 0.95;    %      -- desired power factor, lagging
V   = 230;     % V    -- supply voltage
f   = 50;      % Hz

phi1 = acos(pf1);
phi2 = acos(pf2);

Q1 = P*tan(phi1);          % reactive power now
Q2 = P*tan(phi2);          % reactive power wanted
Qc = Q1 - Q2;              % capacitor must supply this
C  = Qc / (2*pi*f*V^2);    % farads

printf('present  reactive power Q1 = %.1f VAR   (pf %.2f)\n', Q1, pf1);
printf('required reactive power Q2 = %.1f VAR   (pf %.2f)\n', Q2, pf2);
printf('capacitor kVAR   Qc = %.1f VAR = %.3f kVAR\n', Qc, Qc/1000);
printf('capacitance      C  = %.3e F  = %.2f uF\n', C, C*1e6);
