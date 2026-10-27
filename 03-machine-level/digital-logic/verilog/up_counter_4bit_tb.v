module up_counter_4bit_tb;
  reg clk, rst;
  wire [3:0] q;
  integer i, err;
  up_counter_4bit dut(clk, rst, q);
  always #5 clk = ~clk;
  initial begin
    err = 0; clk = 0; rst = 1;
    @(negedge clk); rst = 0;
    for (i = 1; i <= 18; i = i + 1) begin
      @(negedge clk);
      if (q !== (i % 16)) begin err=err+1; $display("count FAIL i=%0d q=%0d", i, q); end
    end
    $display("%0d errors", err);
    $finish;
  end
endmodule
