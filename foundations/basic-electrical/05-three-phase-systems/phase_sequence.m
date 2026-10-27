# phase_sequence.m
# Plot the three phase voltages over one cycle and work out the sequence
# (RYB or RBY) from the given phase angles.

Vm = 325.27;    % peak phase voltage (230 V rms)
f  = 50;        % Hz
w  = 2*pi*f;    % w = 2*pi*f, keep forgetting this

% phase angles in degrees, R Y B
angR = 0;
angY = -120;
angB = -240;    % same as +120

t = linspace(0, 1/f, 500);   % one full cycle
vR = Vm * sin(w*t + angR*pi/180);
vY = Vm * sin(w*t + angY*pi/180);
vB = Vm * sin(w*t + angB*pi/180);

plot(t*1000, vR, 'r', t*1000, vY, 'g', t*1000, vB, 'b', 'linewidth', 1.5);
xlabel('time (ms)'); ylabel('voltage (V)');
title('Three-phase voltages over one cycle');
legend('v_R', 'v_Y', 'v_B'); grid on;

% ---- decide the sequence ----
% how far Y lags R, wrapped into 0..360
lagY = mod(angR - angY, 360);
printf("R at %d deg, Y at %d deg, B at %d deg\n", angR, angY, angB);
printf("Y lags R by %d deg\n", lagY);
if lagY == 120
  printf("Sequence: RYB  (positive sequence) -- order of peaks is R, Y, B\n");
elseif lagY == 240
  printf("Sequence: RBY  (negative sequence) -- order of peaks is R, B, Y\n");
else
  printf("Angles are not a balanced 120 deg set\n");
end
