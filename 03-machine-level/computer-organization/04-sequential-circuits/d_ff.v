// positive edge triggered D flip-flop with asynchronous reset
module d_ff(input clk, input rst, input d, output reg q);
    always @(posedge clk or posedge rst)
        if (rst)
            q <= 1'b0;
        else
            q <= d;
endmodule
