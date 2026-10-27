% slip_calculation.m -- slip, rotor frequency, rotor emf; then invert for N from a target slip

Ns = 1500;    % synchronous speed, rpm (4-pole, 50 Hz)
N  = 1440;    % rotor speed, rpm
f  = 50;      % supply frequency, Hz
E2 = 100;     % standstill rotor emf per phase, V

s   = (Ns - N)/Ns;
fr  = s*f;        % rotor frequency while running
E2r = s*E2;       % rotor emf while running
printf("Ns = %d rpm, N = %d rpm\n", Ns, N);
printf("slip s = %.3f  (%.1f %%)\n", s, s*100);
printf("rotor frequency fr = s*f  = %.2f Hz\n", fr);
printf("rotor emf/phase  E2r = s*E2 = %.2f V\n", E2r);

% invert: what rotor speed gives a chosen slip?
s_target = 0.05;
N_target = (1 - s_target)*Ns;
printf("for target slip %.2f -> N = (1-s)*Ns = %.0f rpm\n", s_target, N_target);
