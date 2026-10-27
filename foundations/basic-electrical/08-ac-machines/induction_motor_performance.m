% induction_motor_performance.m -- power flow through a 3-phase induction motor
% Pin -> (stator loss) -> air-gap power -> (rotor Cu loss) -> mechanical -> (fric/wind) -> output

Pin     = 40000;   % input power, W
Pstator = 1500;    % stator copper + iron loss, W
Prcu    = 1155;    % rotor copper loss, W
Pfw     = 845;     % friction and windage loss, W

Pag   = Pin - Pstator;      % air-gap (rotor input) power
s     = Prcu/Pag;           % slip follows from  Prcu = s*Pag
Pmech = Pag - Prcu;         % gross mechanical power developed
Pout  = Pmech - Pfw;        % shaft output
eff   = Pout/Pin;

printf("air-gap power    Pag  = %.0f W\n", Pag);
printf("slip s = Prcu/Pag     = %.3f  (%.1f %%)\n", s, s*100);
printf("mechanical power Pmech = %.0f W\n", Pmech);
printf("output power     Pout  = %.0f W\n", Pout);
printf("efficiency        eta  = %.2f %%\n", eff*100);
printf("check: s*Pag = %.1f W  vs  rotor Cu loss = %.1f W\n", s*Pag, Prcu);
