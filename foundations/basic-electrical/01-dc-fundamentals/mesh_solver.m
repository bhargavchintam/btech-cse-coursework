# mesh_solver.m - solve the two-mesh circuit from mesh_analysis.cir
# builds the mesh resistance matrix and solves R \ V for the loop currents
# runs under Octave

# V1 = 10 V, V2 = 5 V, R1 = R2 = 1k, R3 = 2k (shared branch)
R1 = 1e3;
R2 = 1e3;
R3 = 2e3;
V1 = 10;
V2 = 5;

# both mesh currents clockwise; R3 is common to both meshes
# mesh 1:  (R1+R3) I1 -      R3  I2 =  V1
# mesh 2:     -R3   I1 + (R2+R3) I2 = -V2   (V2 opposes mesh 2)
R = [ R1+R3,   -R3   ;
       -R3,   R2+R3 ];
V = [ V1 ; -V2 ];

I = R \ V;

printf("I1 = %.4g mA\n", I(1)*1e3);
printf("I2 = %.4g mA\n", I(2)*1e3);

# shared branch and node-2 voltage as a cross-check
I_R3 = I(1) - I(2);
printf("I(R3) = %.4g mA  (= I1 - I2)\n", I_R3*1e3);
printf("V(node2) = %.4g V\n", I_R3*R3);

# expected: I1 = 4 mA, I2 = 1 mA, I(R3) = 3 mA, V(node2) = 6 V
# these match mesh_analysis.cir
