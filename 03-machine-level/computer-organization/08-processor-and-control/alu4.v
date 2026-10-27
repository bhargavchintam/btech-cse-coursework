// 4-bit alu, sel: 000 add 001 sub 010 and 011 or 100 xor 101 not a 110 shl 111 shr
module alu4(a, b, sel, y, cout, zero);
    input [3:0] a, b;
    input [2:0] sel;
    output [3:0] y;
    output cout, zero;

    wire [4:0] t;

    // 5th bit catches carry (add), borrow (sub), or the bit shifted out
    assign t = (sel == 3'b000) ? {1'b0, a} + {1'b0, b} :
               (sel == 3'b001) ? {1'b0, a} - {1'b0, b} :
               (sel == 3'b010) ? {1'b0, a & b} :
               (sel == 3'b011) ? {1'b0, a | b} :
               (sel == 3'b100) ? {1'b0, a ^ b} :
               (sel == 3'b101) ? {1'b0, ~a} :
               (sel == 3'b110) ? {a, 1'b0} :
                                 {a[0], 1'b0, a[3:1]};

    assign y = t[3:0];
    assign cout = t[4];
    assign zero = (y == 4'b0000);
endmodule
