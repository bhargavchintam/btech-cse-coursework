// iverilog -o srff sr_ff.v sr_ff_tb.v && vvp srff
module sr_ff_tb;
    reg clk, clr, s, r;
    wire q;
    reg qold;

    sr_ff dut(clk, clr, s, r, q);

    always #10 clk = ~clk;

    initial begin
        clk = 0; clr = 1; s = 0; r = 0;
        #25 clr = 0;
        $display("s r | q -> q+  action");
        s = 1; r = 0; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   set", s, r, qold, q);
        s = 0; r = 0; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   hold", s, r, qold, q);
        s = 0; r = 1; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   reset", s, r, qold, q);
        s = 0; r = 0; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   hold", s, r, qold, q);
        s = 1; r = 1; qold = q; @(posedge clk); #1;
        $display("%b %b | %b -> %b   forbidden", s, r, qold, q);
        $finish;
    end
endmodule
