// iverilog -o usr shift_register.v shift_register_tb.v && vvp usr
// one register, all four types: PIPO load, hold, PISO shift out, SIPO shift in
module shift_register_tb;
    reg clk, rst, sin_r, sin_l;
    reg [1:0] mode;
    reg [3:0] pin;
    wire [3:0] q;
    reg sout;

    shift_register dut(clk, rst, mode, sin_r, sin_l, pin, q);

    always #5 clk = ~clk;

    initial begin
        clk = 0; rst = 1; mode = 2'b00; sin_r = 0; sin_l = 0; pin = 4'b0000;
        #12 rst = 0;
        $display("clk#  mode  op    sin | q     sout(q0 before shift)");
        mode = 2'b11; pin = 4'b1001; @(posedge clk); #1;
        $display("  1    %b   load   -  | %b    -", mode, q);
        mode = 2'b00; @(posedge clk); #1;
        $display("  2    %b   hold   -  | %b    -", mode, q);
        mode = 2'b01; sin_r = 0;
        sout = q[0]; @(posedge clk); #1;
        $display("  3    %b   shr    0  | %b    %b", mode, q, sout);
        sout = q[0]; @(posedge clk); #1;
        $display("  4    %b   shr    0  | %b    %b", mode, q, sout);
        sout = q[0]; @(posedge clk); #1;
        $display("  5    %b   shr    0  | %b    %b", mode, q, sout);
        sout = q[0]; @(posedge clk); #1;
        $display("  6    %b   shr    0  | %b    %b", mode, q, sout);
        mode = 2'b10;
        sin_l = 1; @(posedge clk); #1;
        $display("  7    %b   shl    %b  | %b    -", mode, sin_l, q);
        sin_l = 0; @(posedge clk); #1;
        $display("  8    %b   shl    %b  | %b    -", mode, sin_l, q);
        sin_l = 1; @(posedge clk); #1;
        $display("  9    %b   shl    %b  | %b    -", mode, sin_l, q);
        sin_l = 1; @(posedge clk); #1;
        $display(" 10    %b   shl    %b  | %b    -", mode, sin_l, q);
        $finish;
    end
endmodule
