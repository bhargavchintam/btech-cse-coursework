// iverilog -o gates gates.v gates_tb.v && vvp gates
module gates_tb;
    reg a, b;
    wire y_and, y_or, y_not, y_nand, y_nor, y_xor, y_xnor;
    integer i;

    gates dut(a, b, y_and, y_or, y_not, y_nand, y_nor, y_xor, y_xnor);

    initial begin
        $display(" a b | AND OR NOT NAND NOR XOR XNOR");
        $display(" ----+-----------------------------");
        for (i = 0; i < 4; i = i + 1) begin
            {a, b} = i;
            #10;
            $display(" %b %b |  %b   %b   %b    %b   %b   %b   %b",
                     a, b, y_and, y_or, y_not, y_nand, y_nor, y_xor, y_xnor);
        end
        $finish;
    end
endmodule
