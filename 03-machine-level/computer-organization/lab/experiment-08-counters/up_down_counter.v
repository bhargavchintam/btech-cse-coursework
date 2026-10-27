// 4-bit up/down counter. mode=1 counts up, mode=0 counts down
// wraps 15->0 going up and 0->15 going down
module up_down_counter(input clk, input rst, input mode, output reg [3:0] count);
    always @(posedge clk or posedge rst)
        if (rst)
            count <= 4'b0000;
        else if (mode)
            count <= count + 1;
        else
            count <= count - 1;
endmodule
