// iverilog -o addsub adder_subtractor.v adder_subtractor_tb.v && vvp addsub
module adder_subtractor_tb;
    reg [3:0] a, b;
    reg m;
    wire [3:0] s;
    wire cout, v;

    adder_subtractor dut(a, b, m, s, cout, v);

    task show;
        begin
            #10;
            // $display("carries %b", dut.c);
            if (m == 0)
                $display(" ADD  %b(%2d)  %b(%2d)   %b  %2d   %2d     %b    %b",
                         a, a, b, b, s, s, $signed(s), cout, v);
            else
                $display(" SUB  %b(%2d)  %b(%2d)   %b  %2d   %2d     %b    %b",
                         a, a, b, b, s, s, $signed(s), cout, v);
        end
    endtask

    initial begin
        $display(" op   a         b         s     uns  signed  cout  v");
        $display(" -----------------------------------------------------");
        m = 0; a = 4'b0100; b = 4'b0011; show;   // 4+3
        m = 0; a = 4'b0110; b = 4'b0101; show;   // 6+5 signed overflow
        m = 0; a = 4'b1100; b = 4'b1110; show;   // (-4)+(-2)
        m = 1; a = 4'b0111; b = 4'b0011; show;   // 7-3
        m = 1; a = 4'b0010; b = 4'b0101; show;   // 2-5 negative result
        m = 1; a = 4'b1000; b = 4'b0001; show;   // (-8)-1 signed overflow
        $finish;
    end
endmodule
