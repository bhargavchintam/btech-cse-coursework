// iverilog -o jkff jk_ff.v jk_ff_tb.v && vvp jkff
module jk_ff_tb;
    reg clk, rst, j, k;
    wire q;
    reg qold;

    jk_ff dut(clk, rst, j, k, q);

    always #5 clk = ~clk;

    initial begin
        clk = 0; rst = 1; j = 0; k = 0;
        #12 rst = 0;
        $display("j k | q -> q+  action");
        j = 1; k = 0; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   set", j, k, qold, q);
        j = 0; k = 0; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   hold", j, k, qold, q);
        j = 0; k = 1; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   reset", j, k, qold, q);
        j = 0; k = 0; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   hold", j, k, qold, q);
        j = 1; k = 1; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   toggle", j, k, qold, q);
        j = 1; k = 1; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   toggle", j, k, qold, q);
        $finish;
    end
endmodule
