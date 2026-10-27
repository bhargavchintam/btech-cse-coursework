// 4-bit SIPO shift register, serial in at LSB side, shifts left
module shift_register(input clk, input rst, input sin, output reg [3:0] q);
    always @(posedge clk or posedge rst)
        if (rst)
            q <= 4'b0000;
        else
            q <= {q[2:0], sin};
endmodule
