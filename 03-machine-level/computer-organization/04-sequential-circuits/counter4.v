// 4-bit synchronous up counter, wraps 15 -> 0
module counter4(input clk, input rst, output reg [3:0] q);
    always @(posedge clk or posedge rst)
        if (rst)
            q <= 4'b0000;
        else
            q <= q + 1;
endmodule
