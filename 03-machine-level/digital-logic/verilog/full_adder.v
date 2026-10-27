// full adder.  iverilog -o full_adder.vvp full_adder.v full_adder_tb.v && vvp full_adder.vvp
module full_adder(input a, b, cin, output sum, cout);
  assign sum  = a ^ b ^ cin;
  assign cout = (a & b) | (b & cin) | (a & cin);
endmodule
