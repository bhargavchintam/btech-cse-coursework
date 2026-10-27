// iverilog -o ra half_adder.v full_adder.v ripple_adder4.v ripple_adder4_tb.v && vvp ra
module ripple_adder4_tb;
    reg [3:0] a, b;
    reg cin;
    wire [3:0] s;
    wire cout;

    ripple_adder4 dut(a, b, cin, s, cout);

    initial begin
        $display("  a      b   cin | cout sum   dec");
        a = 4'b0011; b = 4'b0101; cin = 0;
        #10 $display("%b + %b + %b |  %b  %b  %2d", a, b, cin, cout, s, {cout, s});
        a = 4'b0111; b = 4'b1000; cin = 0;
        #10 $display("%b + %b + %b |  %b  %b  %2d", a, b, cin, cout, s, {cout, s});
        a = 4'b1010; b = 4'b0110; cin = 0;
        #10 $display("%b + %b + %b |  %b  %b  %2d", a, b, cin, cout, s, {cout, s});
        a = 4'b1111; b = 4'b0001; cin = 0;
        #10 $display("%b + %b + %b |  %b  %b  %2d", a, b, cin, cout, s, {cout, s});
        a = 4'b0010; b = 4'b0100; cin = 1;
        #10 $display("%b + %b + %b |  %b  %b  %2d", a, b, cin, cout, s, {cout, s});
        $finish;
    end
endmodule
