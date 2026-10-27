// 4:1 mux.  iverilog -o mux_4to1.vvp mux_4to1.v mux_4to1_tb.v && vvp mux_4to1.vvp
module mux_4to1(input [3:0] d, input [1:0] sel, output y);
  assign y = d[sel];
endmodule
