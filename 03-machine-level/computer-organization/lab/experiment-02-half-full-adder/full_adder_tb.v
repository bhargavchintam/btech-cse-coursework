// iverilog -o fa full_adder.v half_adder.v full_adder_tb.v && vvp fa
module full_adder_tb;
    reg a, b, cin;
    wire s, cout;
    integer i;

    full_adder dut(a, b, cin, s, cout);

    initial begin
        $display("a b cin | s cout");
        for (i = 0; i < 8; i = i + 1) begin
            {a, b, cin} = i;
            #5;
            $display("%b %b  %b  | %b  %b", a, b, cin, s, cout);
        end
        $finish;
    end
endmodule
