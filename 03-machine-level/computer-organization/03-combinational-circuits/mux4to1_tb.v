// iverilog -o mux mux4to1.v mux4to1_tb.v && vvp mux
module mux4to1_tb;
    reg i0, i1, i2, i3, s1, s0;
    wire y;
    integer k;

    mux4to1 dut(i0, i1, i2, i3, s1, s0, y);

    initial begin
        i0 = 1; i1 = 0; i2 = 1; i3 = 0;
        $display("inputs i0=1 i1=0 i2=1 i3=0");
        $display("s1 s0 | y");
        for (k = 0; k < 4; k = k + 1) begin
            {s1, s0} = k;
            #10 $display(" %b  %b | %b", s1, s0, y);
        end
        i0 = 0; i1 = 1; i2 = 0; i3 = 1;
        $display("inputs i0=0 i1=1 i2=0 i3=1");
        $display("s1 s0 | y");
        for (k = 0; k < 4; k = k + 1) begin
            {s1, s0} = k;
            #10 $display(" %b  %b | %b", s1, s0, y);
        end
        $finish;
    end
endmodule
