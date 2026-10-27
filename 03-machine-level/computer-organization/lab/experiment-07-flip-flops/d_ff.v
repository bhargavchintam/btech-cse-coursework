// D flip-flop, rising edge, async clear. q follows d at the clock edge
module d_ff(input clk, input clr, input d, output reg q);
    always @(posedge clk or posedge clr) begin
        if (clr)
            q <= 1'b0;
        else
            q <= d;
    end
endmodule
