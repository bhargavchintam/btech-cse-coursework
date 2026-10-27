module full_adder_tb;
  reg a, b, cin;
  wire sum, cout;
  integer i, err;
  full_adder dut(a, b, cin, sum, cout);
  initial begin
    err = 0;
    for (i = 0; i < 8; i = i + 1) begin
      {a, b, cin} = i[2:0];
      #1;
      if (sum !== (a ^ b ^ cin))                 begin err=err+1; $display("sum FAIL i=%0d", i); end
      if (cout !== ((a&b)|(b&cin)|(a&cin)))       begin err=err+1; $display("cout FAIL i=%0d", i); end
    end
    $display("%0d errors", err);
    $finish;
  end
endmodule
