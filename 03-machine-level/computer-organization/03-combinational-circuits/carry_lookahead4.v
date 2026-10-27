// p = propagate, g = generate, every carry is two levels from the inputs
module carry_lookahead4(input [3:0] a, input [3:0] b, input cin,
                        output [3:0] s, output cout);
    wire [3:0] p, g;
    wire c1, c2, c3;

    assign p = a ^ b;
    assign g = a & b;

    assign c1 = g[0] | (p[0] & cin);
    assign c2 = g[1] | (p[1] & g[0]) | (p[1] & p[0] & cin);
    assign c3 = g[2] | (p[2] & g[1]) | (p[2] & p[1] & g[0])
              | (p[2] & p[1] & p[0] & cin);
    assign cout = g[3] | (p[3] & g[2]) | (p[3] & p[2] & g[1])
                | (p[3] & p[2] & p[1] & g[0])
                | (p[3] & p[2] & p[1] & p[0] & cin);

    assign s = p ^ {c3, c2, c1, cin};
endmodule
