// 4-bit synchronous up counter.  iverilog -o upc.vvp up_counter_4bit.v up_counter_4bit_tb.v && vvp upc.vvp
module up_counter_4bit(input clk, rst, output reg [3:0] q);
  always @(posedge clk or posedge rst) begin
    if (rst) q <= 4'b0000;
    else     q <= q + 1'b1;
  end
endmodule
