// iverilog -o dff d_ff.v d_ff_tb.v && vvp dff
module d_ff_tb;
    reg clk, rst, d;
    wire q;

    d_ff dut(clk, rst, d, q);

    always #5 clk = ~clk;

    initial begin
        $display("time rst d | q");
        $monitor("%4t   %b  %b | %b", $time, rst, d, q);
        clk = 0; rst = 1; d = 0;
        #12 rst = 0;
        #10 d = 1;
        #10 d = 0;
        #10 d = 1;
        #7  rst = 1;    // async reset between clock edges, q must fall at once
        #4  rst = 0;
        #14 $finish;
    end
endmodule
