// T flip-flop, rising edge, async clear. t=1 toggles, t=0 holds
module t_ff(input clk, input clr, input t, output reg q);
    always @(posedge clk or posedge clr)
        if (clr)
            q <= 1'b0;
        else
            q <= t ? ~q : q;
endmodule
