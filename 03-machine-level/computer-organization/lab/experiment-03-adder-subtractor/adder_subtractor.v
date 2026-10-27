// 4-bit ripple carry adder-subtractor, m=0 add, m=1 subtract
module fa(input a, input b, input cin, output s, output cout);
    assign s = a ^ b ^ cin;
    assign cout = (a & b) | (cin & (a ^ b));
endmodule

module adder_subtractor(input [3:0] a, input [3:0] b, input m,
                        output [3:0] s, output cout, output v);
    wire [3:0] x;
    wire [4:0] c;

    // xor with m gives b when adding, ~b when subtracting; m also feeds cin
    assign x = b ^ {4{m}};
    assign c[0] = m;

    fa f0(a[0], x[0], c[0], s[0], c[1]);
    fa f1(a[1], x[1], c[1], s[1], c[2]);
    fa f2(a[2], x[2], c[2], s[2], c[3]);
    fa f3(a[3], x[3], c[3], s[3], c[4]);

    assign cout = c[4];
    assign v = c[3] ^ c[4];
endmodule
