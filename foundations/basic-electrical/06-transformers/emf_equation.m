# emf_equation.m
# Transformer EMF equation E = 4.44 f N Bm A, both ways round.

f  = 50;      % Hz
N  = 500;     % turns
Bm = 1.0;     % peak flux density, tesla
A  = 0.02;    % core cross-section area, m^2

phim = Bm * A;                 % peak flux, Wb
E    = 4.44 * f * N * phim;    % rms induced emf

printf("Given f=%g Hz, N=%d, Bm=%g T, A=%g m^2\n", f, N, Bm, A);
printf("  phi_m = Bm*A = %.4f Wb\n", phim);
printf("  E = 4.44*f*N*phi_m = %.1f V\n\n", E);

% ---- invert: how many turns for a target EMF ----
E_target = 444;                              % V
N_needed = E_target / (4.44 * f * Bm * A);   % rearranged for N
printf("For E = %g V on the same core: N = E/(4.44*f*Bm*A) = %.1f turns\n", ...
       E_target, N_needed);
