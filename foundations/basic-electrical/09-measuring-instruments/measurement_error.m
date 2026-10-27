% measurement_error.m
% Error, accuracy and precision from a set of repeated readings of one quantity.

x  = [98.6 99.4 100.2 99.0 100.3];   % readings (e.g. of a 100.0 ohm resistor)
At = 100.0;                          % true / reference value

n    = numel(x);
xbar = mean(x);                      % best estimate
s    = std(x);                       % sample std dev (Octave normalises by N-1)
sp   = std(x, 1);                    % population std dev (normalise by N)

abs_err  = abs(At - xbar);           % absolute error of the mean
rel_err  = abs_err / At;             % relative error
pct_err  = rel_err * 100;            % percentage error
accuracy = 100 - pct_err;            % accuracy = closeness to true value

printf('Readings: '); printf('%.1f  ', x); printf('\n');
printf('n = %d , true value At = %.1f\n\n', n, At);

printf('Mean (best estimate) xbar = %.3f\n', xbar);
printf('Sample std dev  (N-1) s   = %.4f\n', s);
printf('Population std dev (N)     = %.4f\n\n', sp);

printf('Absolute error  = |At - xbar| = %.3f\n', abs_err);
printf('Relative error  = %.4f\n', rel_err);
printf('Percentage error= %.2f %%\n', pct_err);
printf('Accuracy        = %.2f %%\n', accuracy);
printf('Precision: spread is +/- %.1f about the mean (s = %.4f)\n', ...
       max(abs(x - xbar)), s);
