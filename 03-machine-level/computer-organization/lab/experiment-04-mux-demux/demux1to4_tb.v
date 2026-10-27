// iverilog -o demux demux1to4.v demux1to4_tb.v && vvp demux
module demux1to4_tb;
    reg din;
    reg [1:0] sel;
    wire y0, y1, y2, y3;
    integer i;

    demux1to4 dut(din, sel, y0, y1, y2, y3);

    initial begin
        $display(" din sel | y3 y2 y1 y0");
        $display(" --------+------------");
        din = 1;
        for (i = 0; i < 4; i = i + 1) begin
            sel = i[1:0];
            #10;
            $display("  %b   %b%b |  %b  %b  %b  %b", din, sel[1], sel[0], y3, y2, y1, y0);
        end
        din = 0;   // nothing should come out on any line
        for (i = 0; i < 4; i = i + 1) begin
            sel = i[1:0];
            #10;
            $display("  %b   %b%b |  %b  %b  %b  %b", din, sel[1], sel[0], y3, y2, y1, y0);
        end
        $finish;
    end
endmodule
