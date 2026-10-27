// not, and, or built from nand primitives only
// nand is universal: (a nand a) = a', the rest is de morgan
module not_nand(input a, output y);
    nand g1(y, a, a);
endmodule

module and_nand(input a, input b, output y);
    wire t;
    nand g1(t, a, b);
    nand g2(y, t, t);
endmodule

module or_nand(input a, input b, output y);
    wire na, nb;
    nand g1(na, a, a);
    nand g2(nb, b, b);
    nand g3(y, na, nb);    // (a'b')' = a + b
endmodule
