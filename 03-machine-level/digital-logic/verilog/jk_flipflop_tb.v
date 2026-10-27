module jk_flipflop_tb;
  reg j, k, clk, rst;
  wire q;
  integer err;
  jk_flipflop dut(j, k, clk, rst, q);
  always #5 clk = ~clk;
  initial begin
    err = 0; clk = 0; rst = 1; j = 0; k = 0;
    @(negedge clk); rst = 0;
    j = 1; k = 0; @(negedge clk); if (q !== 1'b1) begin err=err+1; $display("set FAIL"); end
    j = 0; k = 1; @(negedge clk); if (q !== 1'b0) begin err=err+1; $display("clr FAIL"); end
    j = 1; k = 1; @(negedge clk); if (q !== 1'b1) begin err=err+1; $display("tgl1 FAIL"); end
    j = 1; k = 1; @(negedge clk); if (q !== 1'b0) begin err=err+1; $display("tgl2 FAIL"); end
    $display("%0d errors", err);
    $finish;
  end
endmodule
