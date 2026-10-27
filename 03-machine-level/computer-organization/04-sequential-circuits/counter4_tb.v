// iverilog -o cnt counter4.v counter4_tb.v && vvp cnt
module counter4_tb;
    reg clk, rst;
    wire [3:0] q;
    integer i;

    counter4 dut(clk, rst, q);

    always #5 clk = ~clk;

    initial begin
        clk = 0; rst = 1;
        #12 rst = 0;
        $display("clk#  q     dec");
        for (i = 1; i <= 20; i = i + 1) begin
            @(posedge clk); #1;
            $display("%4d  %b  %2d", i, q, q);
        end
        $finish;
    end
endmodule
