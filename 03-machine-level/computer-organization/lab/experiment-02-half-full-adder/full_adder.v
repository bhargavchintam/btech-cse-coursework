// full adder = two half adders + one OR gate
module full_adder(input a, input b, input cin, output s, output cout);
    wire s1, c1, c2;

    half_adder ha1(a, b, s1, c1);
    half_adder ha2(s1, cin, s, c2);
    assign cout = c1 | c2;
endmodule
