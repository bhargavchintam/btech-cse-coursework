// iverilog -o ha half_adder.v half_adder_tb.v && vvp ha
module half_adder_tb;
    reg a, b;
    wire s, c;
    integer i;

    half_adder dut(a, b, s, c);

    initial begin
        $display("a b | s c");
        for (i = 0; i < 4; i = i + 1) begin
            {a, b} = i;
            #10 $display("%b %b | %b %b", a, b, s, c);
        end
        $finish;
    end
endmodule
