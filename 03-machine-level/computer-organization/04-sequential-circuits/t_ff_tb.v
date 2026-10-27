// iverilog -o tff t_ff.v t_ff_tb.v && vvp tff
// with t held 1 the output is clk/2 -- this is why counters are built from T flip-flops
module t_ff_tb;
    reg clk, rst, t;
    wire q;
    integer i;

    t_ff dut(clk, rst, t, q);

    always #10 clk = ~clk;

    initial begin
        clk = 0; rst = 1; t = 0;
        #25 rst = 0;
        $display("clk# t | q");
        t = 0;
        for (i = 1; i <= 2; i = i + 1) begin
            @(posedge clk); #1;
            $display("%3d  %b | %b", i, t, q);
        end
        t = 1;
        for (i = 3; i <= 8; i = i + 1) begin
            @(posedge clk); #1;
            $display("%3d  %b | %b", i, t, q);
        end
        $finish;
    end
endmodule
