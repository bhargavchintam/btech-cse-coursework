// iverilog -o jc johnson_counter.v johnson_counter_tb.v && vvp jc
// 4 flip-flops give 2n = 8 states, not 16
module johnson_counter_tb;
    reg clk, rst;
    wire [3:0] q;
    integer i;

    johnson_counter dut(clk, rst, q);

    always #5 clk = ~clk;

    initial begin
        clk = 0; rst = 1;
        #12 rst = 0;
        $display("state  q");
        $display("    0  %b", q);
        for (i = 1; i <= 8; i = i + 1) begin
            @(posedge clk); #1;
            $display("%5d  %b", i, q);
        end
        $finish;
    end
endmodule
