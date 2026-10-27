// 4-bit alu for the lab record, behavioural version
// sel: 000 add, 001 sub, 010 and, 011 or, 100 xor, 101 not a, 110 shl, 111 shr
module alu4(input [3:0] a, input [3:0] b, input [2:0] sel,
            output reg [3:0] y, output reg cout, output zero);
    reg [4:0] t;

    always @(*) begin
        case (sel)
            3'b000: t = a + b;
            3'b001: t = a - b;
            3'b010: t = {1'b0, a & b};
            3'b011: t = {1'b0, a | b};
            3'b100: t = {1'b0, a ^ b};
            3'b101: t = {1'b0, ~a};
            3'b110: t = {a, 1'b0};
            3'b111: t = {a[0], 1'b0, a[3:1]};
        endcase
        y = t[3:0];
        cout = t[4];   // carry out, borrow, or the bit shifted out
    end

    assign zero = (y == 4'b0000);
endmodule
