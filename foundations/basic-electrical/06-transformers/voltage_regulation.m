# voltage_regulation.m
# Voltage regulation at lagging, unity and leading power factor.
#   %reg = I2 (R02 cos(phi) +/- X02 sin(phi)) / V2 * 100
#   + for lagging, - for leading.  Leading pf can give NEGATIVE regulation.

R02 = 0.2;    % equivalent resistance referred to secondary, ohm
X02 = 0.4;    % equivalent reactance referred to secondary, ohm
I2  = 50;     % secondary (load) current, A
V2  = 200;    % secondary rated voltage, V

pf = 0.8;                 % power factor magnitude for the lag/lead cases
sinp = sqrt(1 - pf^2);

% sign convention: +1 lagging, -1 leading
reg_lag  = I2 * (R02 * pf   + X02 * sinp) / V2 * 100;
reg_unity= I2 * (R02 * 1.0  + X02 * 0.0 ) / V2 * 100;
reg_lead = I2 * (R02 * pf   - X02 * sinp) / V2 * 100;

printf("R02=%g ohm, X02=%g ohm, I2=%g A, V2=%g V\n\n", R02, X02, I2, V2);
printf("  0.8 lagging pf : regulation = %+6.2f %%\n", reg_lag);
printf("  unity pf       : regulation = %+6.2f %%\n", reg_unity);
printf("  0.8 leading pf : regulation = %+6.2f %%\n", reg_lead);

if reg_lead < 0
  printf("\nLeading pf gives negative regulation -- secondary voltage rises on load.\n");
end
