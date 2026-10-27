// all the basic gates on two inputs, verilog gate primitives
module gates(input a, input b,
             output y_and, output y_or, output y_not,
             output y_nand, output y_nor, output y_xor, output y_xnor);
    and  g1(y_and,  a, b);
    or   g2(y_or,   a, b);
    not  g3(y_not,  a);
    nand g4(y_nand, a, b);
    nor  g5(y_nor,  a, b);
    xor  g6(y_xor,  a, b);
    xnor g7(y_xnor, a, b);
endmodule
