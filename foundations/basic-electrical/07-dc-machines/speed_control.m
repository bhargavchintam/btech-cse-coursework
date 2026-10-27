% speed_control.m -- speed control of a DC shunt motor
% N = (V - Ia*Ra)/(k*phi), with k = P*Z/(60*A). Sweep armature voltage, then field flux.
% k has the 60 in it, keep forgetting that.

P = 4;  A = 4;  Z = 500;   % 4-pole lap machine
Ra = 0.5;  Ia = 20;        % ohm, A (assume the load current stays steady)
k  = P*Z/(60*A);           % machine constant, so Eb = k*phi*N

% --- armature-voltage control: phi fixed, V swept ---
phi0 = 0.02;
V   = 100:10:230;
N_V = (V - Ia*Ra)./(k*phi0);

% --- field-flux control: V fixed, phi swept ---
V0    = 230;
phi   = 0.012:0.001:0.02;
N_phi = (V0 - Ia*Ra)./(k*phi);

printf("Armature-voltage control (phi = %.3f Wb, V = %d..%d):\n", phi0, V(1), V(end));
printf("  N ranges %.0f -> %.0f rpm\n", N_V(1), N_V(end));
printf("Field-flux control (V = %d, phi = %.3f..%.3f Wb):\n", V0, phi(1), phi(end));
printf("  N ranges %.0f -> %.0f rpm\n", N_phi(end), N_phi(1));
printf("Base speed %.0f rpm: voltage control gives speeds below it, field control above.\n", N_V(end));

% lab PC has no gnuplot -- guard the plot so the numbers still print there
if isempty(available_graphics_toolkits())
  disp("(no graphics toolkit -- skipping the plot)");
else
  figure;
  subplot(1,2,1);
  plot(V, N_V, '-o'); grid on;
  xlabel('Armature voltage V'); ylabel('Speed N (rpm)');
  title('Voltage control (phi fixed)');
  subplot(1,2,2);
  plot(phi, N_phi, '-o'); grid on;
  xlabel('Flux phi (Wb)'); ylabel('Speed N (rpm)');
  title('Field control (V fixed)');
  % print -dpng speed_control.png   % uncomment to save the figure
end
