// iverilog -o cla carry_lookahead4.v carry_lookahead4_tb.v && vvp cla
module carry_lookahead4_tb;
    reg [3:0] a, b;
    reg cin;
    wire [3:0] s;
    wire cout;
    reg [4:0] exp;

    carry_lookahead4 dut(a, b, cin, s, cout);

    task check;
        begin
            exp = a + b + cin;
            // $display("p=%b g=%b", dut.p, dut.g);
            if ({cout, s} == exp)
                $display("%b + %b + %b = %b %b  (%2d)  ok", a, b, cin, cout, s, {cout, s});
            else
                $display("%b + %b + %b = %b %b  FAIL, expected %b", a, b, cin, cout, s, exp);
        end
    endtask

    initial begin
        $display("  a      b   cin   co  sum");
        a = 9;  b = 3;  cin = 0; #10 check;
        a = 15; b = 1;  cin = 0; #10 check;
        a = 10; b = 5;  cin = 1; #10 check;
        a = 7;  b = 8;  cin = 0; #10 check;
        a = 12; b = 10; cin = 0; #10 check;
        $finish;
    end
endmodule
