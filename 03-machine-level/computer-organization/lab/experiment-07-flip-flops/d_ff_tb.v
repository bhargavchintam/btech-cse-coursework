// iverilog -o dff d_ff.v d_ff_tb.v && vvp dff
module d_ff_tb;
    reg clk, clr, d;
    wire q;
    reg qold;

    d_ff dut(clk, clr, d, q);

    always #10 clk = ~clk;

    initial begin
        clk = 0; clr = 1; d = 0;
        #25 clr = 0;
        $display("d | q -> q+");
        d = 1; qold = q; @(posedge clk); #1;
        $display("%b | %b -> %b", d, qold, q);
        d = 0; qold = q; @(posedge clk); #1;
        $display("%b | %b -> %b", d, qold, q);
        d = 1; qold = q; @(posedge clk); #1;
        $display("%b | %b -> %b", d, qold, q);
        d = 1; qold = q; @(posedge clk); #1;
        $display("%b | %b -> %b", d, qold, q);
        $finish;
    end
endmodule
