# thevenin_calc.m - Vth and Rth for the network in thevenin.cir, from first principles
# runs under Octave

# source network: V1 - R1 - node A - R2 - ground, terminals A-B (B = ground)
V1 = 12;
R1 = 3e3;
R2 = 6e3;

# Vth = open-circuit voltage at A. With the load off, R1 and R2 carry the same
# current, so node A is just the divider output.
Vth = V1 * R2 / (R1 + R2);

# Rth = resistance looking into A-B with V1 shorted -> R1 in parallel with R2
Rth = (R1 * R2) / (R1 + R2);

printf("Vth = %.4g V\n", Vth);
printf("Rth = %.4g ohm\n", Rth);

# cross-check against a load: I_L and V_L for RL = 2k
RL = 2e3;
IL = Vth / (Rth + RL);
VL = IL * RL;
printf("with RL = %.4g ohm:  IL = %.4g mA,  VL = %.4g V\n", RL, IL*1e3, VL);

# expected: Vth = 8 V, Rth = 2000 ohm, IL = 2 mA, VL = 4 V
# matches thevenin.cir
