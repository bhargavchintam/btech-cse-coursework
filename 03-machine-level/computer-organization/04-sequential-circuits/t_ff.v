// T flip-flop, positive edge, async reset. t=1 toggles, t=0 holds
module t_ff(input clk, input rst, input t, output reg q);
    always @(posedge clk or posedge rst)
        if (rst)
            q <= 1'b0;
        else if (t)
            q <= ~q;
endmodule
