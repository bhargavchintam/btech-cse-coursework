module comparator_4bit_tb;
  reg [3:0] a, b;
  wire gt, eq, lt;
  integer i, j, err;
  comparator_4bit dut(a, b, gt, eq, lt);
  initial begin
    err = 0;
    for (i = 0; i < 16; i = i + 1)
      for (j = 0; j < 16; j = j + 1) begin
        a = i[3:0]; b = j[3:0];
        #1;
        if (gt !== (i > j)) begin err=err+1; $display("gt FAIL %0d %0d", i, j); end
        if (eq !== (i == j)) begin err=err+1; $display("eq FAIL %0d %0d", i, j); end
        if (lt !== (i < j)) begin err=err+1; $display("lt FAIL %0d %0d", i, j); end
      end
    $display("%0d errors", err);
    $finish;
  end
endmodule
