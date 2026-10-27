// iverilog -o dec decoder2to4.v decoder2to4_tb.v && vvp dec
module decoder2to4_tb;
    reg en;
    reg [1:0] a;
    wire [3:0] y;
    integer i;

    decoder2to4 dut(en, a, y);

    initial begin
        $display("en a1 a0 | y3 y2 y1 y0");
        en = 0; a = 2'b00; #10;
        $display(" %b  %b  %b |  %b  %b  %b  %b", en, a[1], a[0], y[3], y[2], y[1], y[0]);
        en = 1;
        for (i = 0; i < 4; i = i + 1) begin
            a = i; #10;
            $display(" %b  %b  %b |  %b  %b  %b  %b", en, a[1], a[0], y[3], y[2], y[1], y[0]);
        end
        $finish;
    end
endmodule
