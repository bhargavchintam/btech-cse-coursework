module mux_4to1_tb;
  reg [3:0] d;
  reg [1:0] sel;
  wire y;
  integer s, err;
  mux_4to1 dut(d, sel, y);
  initial begin
    err = 0; d = 4'b1010;
    for (s = 0; s < 4; s = s + 1) begin
      sel = s[1:0];
      #1;
      if (y !== d[s]) begin err=err+1; $display("route FAIL sel=%0d", s); end
    end
    $display("%0d errors", err);
    $finish;
  end
endmodule
