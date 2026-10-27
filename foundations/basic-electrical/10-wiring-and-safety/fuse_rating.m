% fuse_rating.m
% Load current of a set of appliances at 230 V and the next standard fuse/MCB rating.
% Assume unity power factor (heating / lighting loads):  I = P / V

V = 230;                               % single-phase supply, V
names = {'Geyser','Air conditioner','Electric iron','Lights + fans'};
watts = [3000 1500 1000 1400];

P = sum(watts);
I = P / V;

printf('Supply = %.0f V, assumed pf = 1.0\n\n', V);
printf('%-16s %8s\n', 'Appliance','Watts');
for k = 1:numel(watts)
  printf('%-16s %8d\n', names{k}, watts(k));
end
printf('%s\n', repmat('-',1,26));
printf('%-16s %8d\n', 'Total load', P);

printf('\nLoad current I = P/V = %d/%d = %.2f A\n', P, V, I);

std_ratings = [6 10 16 20 25 32 40 50 63];    % standard MCB ratings, A
idx    = find(std_ratings >= I, 1);           % first rating that covers the load
rating = std_ratings(idx);

printf('Standard ratings (A): '); printf('%d ', std_ratings); printf('\n');
printf('Next standard rating >= %.2f A  =>  %d A fuse/MCB\n', I, rating);
