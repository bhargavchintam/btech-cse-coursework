// 4-bit magnitude comparator.  iverilog -o cmp.vvp comparator_4bit.v comparator_4bit_tb.v && vvp cmp.vvp
module comparator_4bit(input [3:0] a, b, output gt, eq, lt);
  assign gt = (a > b);
  assign eq = (a == b);
  assign lt = (a < b);
endmodule
