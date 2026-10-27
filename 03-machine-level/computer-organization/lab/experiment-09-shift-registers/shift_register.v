// 4-bit universal shift register (74194 style)
// mode: 00 hold, 01 shift right, 10 shift left, 11 parallel load
module shift_register(input clk, input rst, input [1:0] mode,
                      input sin_r, input sin_l, input [3:0] pin,
                      output reg [3:0] q);
    always @(posedge clk or posedge rst)
        if (rst)
            q <= 4'b0000;
        else
            case (mode)
                2'b01: q <= {sin_r, q[3:1]};
                2'b10: q <= {q[2:0], sin_l};
                2'b11: q <= pin;
                default: q <= q;
            endcase
endmodule
