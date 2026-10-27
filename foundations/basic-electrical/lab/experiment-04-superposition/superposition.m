# Superposition theorem - current through load R2 from two independent sources
# V1=12 V through R1=100 into node A, V2=6 V through R3=200 into node A,
# R2=300 from node A to ground. Response measured = current through R2.

V1 = 12; V2 = 6;
R1 = 100; R2 = 300; R3 = 200;

% both sources active
VAb = (V1/R1 + V2/R3) / (1/R1 + 1/R2 + 1/R3);
Iboth = VAb/R2;

% V1 alone: V2 replaced by its internal resistance (short). R2 || R3 seen from A.
Rp1 = (R2*R3)/(R2+R3);
VA1 = V1 * Rp1/(R1+Rp1);
I_v1 = VA1/R2;

% V2 alone: V1 shorted. R1 || R2 seen from A.
Rp2 = (R1*R2)/(R1+R2);
VA2 = V2 * Rp2/(R3+Rp2);
I_v2 = VA2/R2;

printf('I(R2) due to V1 alone = %.4f mA\n', I_v1*1e3);
printf('I(R2) due to V2 alone = %.4f mA\n', I_v2*1e3);
printf('sum of contributions  = %.4f mA\n', (I_v1+I_v2)*1e3);
printf('I(R2) with both        = %.4f mA\n', Iboth*1e3);
printf('sum - both = %.3e mA\n', (I_v1 + I_v2 - Iboth)*1e3);
