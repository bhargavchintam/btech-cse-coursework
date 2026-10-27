// iverilog -o sipo shift_register.v shift_register_tb.v && vvp sipo
// shifting in 1011 MSB first, register should read 1011 after 4 clocks
module shift_register_tb;
    reg clk, rst, sin;
    wire [3:0] q;

    shift_register dut(clk, rst, sin, q);

    always #10 clk = ~clk;

    initial begin
        clk = 0; rst = 1; sin = 0;
        #25 rst = 0;
        $display("clk# sin | q");
        sin = 1; @(posedge clk); #1;
        // $display("debug q3q2q1q0 = %b%b%b%b", q[3], q[2], q[1], q[0]);
        $display("  1   %b  | %b", sin, q);
        sin = 0; @(posedge clk); #1;
        $display("  2   %b  | %b", sin, q);
        sin = 1; @(posedge clk); #1;
        $display("  3   %b  | %b", sin, q);
        sin = 1; @(posedge clk); #1;
        $display("  4   %b  | %b", sin, q);
        $finish;
    end
endmodule
