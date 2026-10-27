% energy_bill.m
% Monthly energy (kWh) and the bill under a slab tariff for a list of appliances.
% units (kWh) = W * hours/day * qty * days / 1000

% appliance : watts, hours/day, quantity
names = {'Tube light','Ceiling fan','Refrigerator','Television','Geyser'};
watts = [ 40   75   150   100   2000 ];
hours = [  5    8     8     5      1 ];
qty   = [  4    3     1     1      1 ];

days = 30;

printf('%-14s %6s %6s %4s %10s %10s\n', 'Appliance','W','h/day','Qty','Wh/day','kWh/mon');
printf('%s\n', repmat('-',1,54));
day_wh = 0;
for k = 1:numel(watts)
  wh    = watts(k)*hours(k)*qty(k);      % Wh per day for this appliance
  kwh_m = wh*days/1000;                  % kWh per month
  day_wh += wh;
  printf('%-14s %6d %6d %4d %10d %10.2f\n', names{k}, watts(k), hours(k), qty(k), wh, kwh_m);
end

units = day_wh*days/1000;                % total monthly units (kWh)
printf('%s\n', repmat('-',1,54));
printf('Daily consumption = %.2f kWh\n', day_wh/1000);
printf('Monthly units     = %.1f kWh (units)\n\n', units);

% slab tariff : slab width (units) and rate (Rs per unit)
slab_w = [100 100 100 Inf];
slab_r = [4.0 5.5 7.0 8.5];
fixed  = 100;                            % fixed / meter charge, Rs

rem = units; charge = 0; lo = 0;
printf('Slab breakdown:\n');
for j = 1:numel(slab_w)
  take = min(rem, slab_w(j));
  if take <= 0, break; end
  hi = lo + take;
  printf('  units %6.1f - %6.1f  @ Rs %.2f = Rs %8.2f\n', lo, hi, slab_r(j), take*slab_r(j));
  charge += take*slab_r(j);
  rem -= take;  lo = hi;
end

total = charge + fixed;
printf('\nEnergy charge = Rs %.2f\n', charge);
printf('Fixed charge  = Rs %.2f\n', fixed);
printf('TOTAL BILL    = Rs %.2f\n', total);
