# KVL & KCL verification for the two-loop network
# V1=10 V through R1=100 into node A, V2=6 V through R3=150 into node A,
# R2=47 from node A to ground. Node A voltage found by nodal analysis.

V1 = 10; V2 = 6;
R1 = 100; R2 = 47; R3 = 150;

VA = (V1/R1 + V2/R3) / (1/R1 + 1/R2 + 1/R3);   % node A voltage

I1 = (V1 - VA)/R1;    % current through R1, into node A
I3 = (V2 - VA)/R3;    % current through R3, into node A
I2 = VA/R2;           % current through R2, out of node A

printf('VA = %.4f V\n', VA);
printf('I1 = %.4f mA   I2 = %.4f mA   I3 = %.4f mA\n', I1*1e3, I2*1e3, I3*1e3);
printf('drops: V_R1 = %.4f V   V_R2 = %.4f V   V_R3 = %.4f V\n', I1*R1, I2*R2, I3*R3);

% KVL: algebraic sum of voltages round each loop must be zero
loop1 = V1 - I1*R1 - I2*R2;      % left loop
loop2 = V2 - I3*R3 - I2*R2;      % right loop
printf('KVL loop1 sum = %.3e V\n', loop1);
printf('KVL loop2 sum = %.3e V\n', loop2);

% KCL: algebraic sum of currents at node A must be zero
node = I1 + I3 - I2;
printf('KCL node sum  = %.3e A\n', node);
