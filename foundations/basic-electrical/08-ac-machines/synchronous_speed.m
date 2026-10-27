% synchronous_speed.m -- Ns = 120*f/P for the common pole numbers, at 50 Hz and 60 Hz

P = [2 4 6 8 10];
printf("Synchronous speed  Ns = 120*f/P  (rpm)\n");
printf("%4s %10s %10s\n", "P", "50 Hz", "60 Hz");
for i = 1:length(P)
  Ns50 = 120*50/P(i);
  Ns60 = 120*60/P(i);
  printf("%4d %10.0f %10.0f\n", P(i), Ns50, Ns60);
end
