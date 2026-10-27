/* Bindu Bhargava  24-10-18 */
// SR flip-flop, rising edge, async clear. s=r=1 is forbidden -- output goes x
module sr_ff(input clk, input clr, input s, input r, output reg q);
    always @(posedge clk or posedge clr)
        if (clr)
            q <= 1'b0;
        else
            case ({s, r})
                2'b00: q <= q;
                2'b01: q <= 1'b0;
                2'b10: q <= 1'b1;
                2'b11: q <= 1'bx;
            endcase
endmodule
