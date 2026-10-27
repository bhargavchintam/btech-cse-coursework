# star_delta.m - convert a star (Y) to delta and back, check the round trip
# runs under Octave

# star arm resistances (ohms)
Ra = 10;
Rb = 20;
Rc = 30;

printf("Star:  Ra = %.4g, Rb = %.4g, Rc = %.4g ohm\n", Ra, Rb, Rc);

# star -> delta
P = Ra*Rb + Rb*Rc + Rc*Ra;   % sum of products
Rab = P / Rc;
Rbc = P / Ra;
Rca = P / Rb;

printf("Delta: Rab = %.4g, Rbc = %.4g, Rca = %.4g ohm\n", Rab, Rbc, Rca);

# delta -> star (round trip)
S = Rab + Rbc + Rca;
Ra2 = Rab*Rca / S;
Rb2 = Rab*Rbc / S;
Rc2 = Rbc*Rca / S;

printf("Back:  Ra = %.4g, Rb = %.4g, Rc = %.4g ohm\n", Ra2, Rb2, Rc2);

tol = 1e-9;
if (abs(Ra2-Ra) < tol && abs(Rb2-Rb) < tol && abs(Rc2-Rc) < tol)
  printf("Round trip OK\n");
else
  printf("Round trip FAILED\n");
end

# expected:
#   Delta: Rab = 36.67, Rbc = 110, Rca = 55 ohm
#   Back:  Ra = 10, Rb = 20, Rc = 30 ohm, round trip OK
