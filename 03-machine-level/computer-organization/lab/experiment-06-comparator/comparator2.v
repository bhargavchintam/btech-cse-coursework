// 2-bit magnitude comparator from boolean equations
// e1, e0 are the per-bit equality (xnor) terms
module comparator2(input [1:0] a, input [1:0] b, output gt, output eq, output lt);
    wire e1 = ~(a[1] ^ b[1]);
    wire e0 = ~(a[0] ^ b[0]);

    assign eq = e1 & e0;
    assign gt = (a[1] & ~b[1]) | (e1 & a[0] & ~b[0]);
    assign lt = (~a[1] & b[1]) | (e1 & ~a[0] & b[0]);
endmodule
