// JK flip-flop, rising edge, async clear
// no forbidden state: j=k=1 toggles instead
module jk_ff(input clk, input clr, input j, input k, output reg q);
    always @(posedge clk or posedge clr)
        if (clr)
            q <= 1'b0;
        else if (j & ~k)
            q <= 1'b1;
        else if (~j & k)
            q <= 1'b0;
        else if (j & k)
            q <= ~q;
endmodule
