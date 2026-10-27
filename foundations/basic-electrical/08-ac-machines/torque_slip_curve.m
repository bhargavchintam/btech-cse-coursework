% torque_slip_curve.m -- 3-phase induction motor torque vs slip
% T = (m/ws)*(s*E2^2*R2)/(R2^2 + (s*X2)^2). Maximum torque is at s = R2/X2.

R2 = 0.4;     % rotor resistance per phase, ohm
X2 = 2.0;     % rotor standstill reactance per phase, ohm
E2 = 120;     % standstill rotor emf per phase, V
Ns = 1500;    % synchronous speed, rpm
m  = 3;       % number of phases

ws = 2*pi*Ns/60;                 % synchronous speed, rad/s
s  = 0.001:0.001:1;
T  = (m/ws) .* (s.*E2^2*R2) ./ (R2^2 + (s*X2).^2);

s_maxT       = R2/X2;                    % slip at maximum torque
Tmax_formula = (m*E2^2)/(2*ws*X2);       % put s = R2/X2 into T, R2 cancels
[Tmax_grid, idx] = max(T);

printf("slip at maximum torque  s = R2/X2 = %.3f\n", s_maxT);
printf("Tmax (formula m*E2^2/(2*ws*X2)) = %.3f N.m\n", Tmax_formula);
printf("Tmax (peak of the curve)        = %.3f N.m at s = %.3f\n", Tmax_grid, s(idx));

% lab PC has no gnuplot -- guard the plot so the numbers still print there
if isempty(available_graphics_toolkits())
  disp("(no graphics toolkit -- skipping the plot)");
else
  plot(s, T); grid on; hold on;
  plot(s_maxT, Tmax_formula, 'ro');
  xlabel('slip s'); ylabel('torque T (N.m)');
  title('Torque-slip characteristic');
  % print -dpng torque_slip_curve.png   % uncomment to save the figure
end
