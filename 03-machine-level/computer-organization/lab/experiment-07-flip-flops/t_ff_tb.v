// iverilog -o tff t_ff.v t_ff_tb.v && vvp tff
// with t held at 1 the q waveform is clk/2
module t_ff_tb;
    reg clk, clr, t;
    wire q;
    integer i;

    t_ff dut(clk, clr, t, q);

    always #10 clk = ~clk;

    initial begin
        clk = 0; clr = 1; t = 0;
        #25 clr = 0;
        $display("clk# t | q");
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
