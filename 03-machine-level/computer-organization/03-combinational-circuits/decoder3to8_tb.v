// iverilog -o dec decoder3to8.v decoder3to8_tb.v && vvp dec
module decoder3to8_tb;
    reg [2:0] a;
    reg en;
    wire [7:0] y;
    integer k;

    decoder3to8 dut(a, en, y);

    initial begin
        $display("en  a  | y7......y0");
        en = 1;
        for (k = 0; k < 8; k = k + 1) begin
            a = k;
            #5 $display(" %b %b | %b", en, a, y);
        end
        en = 0; a = 3'b101;
        #5 $display(" %b %b | %b   (disabled)", en, a, y);
        $finish;
    end
endmodule
