// decade (mod-10) counter: 0 to 9 then back to 0
module mod10_counter(input clk, input rst, output reg [3:0] q);
    always @(posedge clk or posedge rst)
        if (rst)
            q <= 4'd0;
        else if (q == 4'd9)
            q <= 4'd0;
        else
            q <= q + 1;
endmodule
