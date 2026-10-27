// iverilog -o mod10 mod10_counter.v mod10_counter_tb.v && vvp mod10
module mod10_counter_tb;
    reg clk, rst;
    wire [3:0] q;
    integer i;

    mod10_counter dut(clk, rst, q);

    always #5 clk = ~clk;

    initial begin
        clk = 0; rst = 1;
        #12 rst = 0;
        $display("clk#  q     dec");
        for (i = 1; i <= 12; i = i + 1) begin
            @(posedge clk); #1;
            $display("%4d  %b  %2d", i, q, q);
        end
        $finish;
    end
endmodule
