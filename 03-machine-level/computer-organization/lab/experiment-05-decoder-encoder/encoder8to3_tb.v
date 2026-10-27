// iverilog -o enc encoder8to3.v encoder8to3_tb.v && vvp enc
module encoder8to3_tb;
    reg [7:0] d;
    wire [2:0] y;
    wire v;
    integer i;

    encoder8to3 dut(d, y, v);

    initial begin
        $display("d7......d0 | y2 y1 y0  v");
        d = 8'b00000000; #10;
        $display("  %b |  %b  %b  %b  %b", d, y[2], y[1], y[0], v);
        for (i = 0; i < 8; i = i + 1) begin
            d = 1 << i; #10;
            $display("  %b |  %b  %b  %b  %b", d, y[2], y[1], y[0], v);
        end
        // two lines high at once -- higher index must win
        d = 8'b00101000; #10;
        $display("  %b |  %b  %b  %b  %b", d, y[2], y[1], y[0], v);
        d = 8'b00000110; #10;
        $display("  %b |  %b  %b  %b  %b", d, y[2], y[1], y[0], v);
        $finish;
    end
endmodule
