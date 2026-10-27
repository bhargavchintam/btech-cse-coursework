// mod-10 (decade) counter: counts 0 to 9 then wraps back to 0
module mod10_counter(input clk, input rst, output reg [3:0] count);
    always @(posedge clk or posedge rst)
        if (rst)
            count <= 4'b0000;
        else if (count == 4'b1001)
            count <= 4'b0000;
        else
            count <= count + 1;
endmodule
