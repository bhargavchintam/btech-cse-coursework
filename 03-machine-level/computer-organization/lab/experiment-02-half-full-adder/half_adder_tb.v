// iverilog -o ha half_adder.v half_adder_tb.v && vvp ha
module half_adder_tb;
    reg a, b;
    wire s, c;

    half_adder dut(a, b, s, c);

    initial begin
        $display("a b | s c");
        $monitor("%b %b | %b %b", a, b, s, c);
        a = 0; b = 0;
        #5 a = 0; b = 1;
        #5 a = 1; b = 0;
        #5 a = 1; b = 1;
        #5 $finish;
    end
endmodule
