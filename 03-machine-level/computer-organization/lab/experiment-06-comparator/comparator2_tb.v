// iverilog -o cmp comparator2.v comparator2_tb.v && vvp cmp
module comparator2_tb;
    reg [1:0] a, b;
    wire gt, eq, lt;
    integer i, j;

    comparator2 dut(a, b, gt, eq, lt);

    initial begin
        $display(" a  b | a>b a=b a<b");
        for (i = 0; i < 4; i = i + 1)
            for (j = 0; j < 4; j = j + 1) begin
                a = i; b = j; #5;
                $display("%b %b |  %b   %b   %b", a, b, gt, eq, lt);
            end
        $finish;
    end
endmodule
