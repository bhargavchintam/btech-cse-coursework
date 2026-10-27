// x1, x0 = bit equality (xnor), msb decides first
module comparator2(input [1:0] a, input [1:0] b,
                   output gt, output eq, output lt);
    wire x1, x0;

    assign x1 = ~(a[1] ^ b[1]);
    assign x0 = ~(a[0] ^ b[0]);

    assign gt = (a[1] & ~b[1]) | (x1 & a[0] & ~b[0]);
    assign eq = x1 & x0;
    assign lt = (~a[1] & b[1]) | (x1 & ~a[0] & b[0]);
endmodule
