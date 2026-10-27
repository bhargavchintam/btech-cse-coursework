# Thevenin's theorem - bridge network across a 470 ohm load
# left divider R1-R2, right divider R3-R4, load RL between the two midpoints A and C.
# find Vth and Rth at A-C, then check the equivalent draws the same load current.

Vs = 12;
R1 = 100; R2 = 200; R3 = 300; R4 = 100;
RL = 470;

% open-circuit voltage across A-C (load removed) - two independent dividers
VA = Vs * R2/(R1+R2);
VC = Vs * R4/(R3+R4);
Vth = VA - VC;

% resistance looking back into A-C with the source shorted
Rth = (R1*R2)/(R1+R2) + (R3*R4)/(R3+R4);

% load current predicted by the Thevenin equivalent
IL_eq = Vth/(Rth+RL);

% load current from the full original network.
% node equations with the load in place (vA, vC unknown, source node = Vs):
%   at A: (Vs-vA)/R1 = vA/R2 + (vA-vC)/RL
%   at C: (Vs-vC)/R3 + (vA-vC)/RL = vC/R4
G = [ 1/R1+1/R2+1/RL,  -1/RL ;
      -1/RL,            1/R3+1/R4+1/RL ];
b = [ Vs/R1 ; Vs/R3 ];
v = G \ b;
IL_orig = (v(1) - v(2))/RL;

printf('Vth = %.4f V\n', Vth);
printf('Rth = %.4f ohm\n', Rth);
printf('IL from Thevenin equivalent = %.4f mA\n', IL_eq*1e3);
printf('IL from original network    = %.4f mA\n', IL_orig*1e3);
printf('difference = %.3e mA\n', (IL_eq - IL_orig)*1e3);
