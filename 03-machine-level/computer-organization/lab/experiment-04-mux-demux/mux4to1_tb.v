// iverilog -o mux mux4to1.v mux4to1_tb.v && vvp mux
module mux4to1_tb;
    reg [3:0] d;
    reg [1:0] sel;
    wire y;
    integer i;

    mux4to1 dut(d, sel, y);

    initial begin
        $display(" d3 d2 d1 d0  sel | y");
        $display(" -----------------+--");
        d = 4'b1010;
        for (i = 0; i < 4; i = i + 1) begin
            sel = i[1:0];
            #5;
            $display("  %b  %b  %b  %b   %b%b | %b", d[3], d[2], d[1], d[0], sel[1], sel[0], y);
        end
        d = 4'b0110;
        for (i = 0; i < 4; i = i + 1) begin
            sel = i[1:0];
            #5;
            $display("  %b  %b  %b  %b   %b%b | %b", d[3], d[2], d[1], d[0], sel[1], sel[0], y);
        end
        $finish;
    end
endmodule
