// iverilog -o updown up_down_counter.v up_down_counter_tb.v && vvp updown
module up_down_counter_tb;
    reg clk, rst, mode;
    wire [3:0] count;
    integer i;

    up_down_counter dut(clk, rst, mode, count);

    always #5 clk = ~clk;

    initial begin
        clk = 0; rst = 1; mode = 1;
        #12 rst = 0;
        $display("clk# mode count  dec");
        for (i = 1; i <= 6; i = i + 1) begin
            @(posedge clk); #1;
            // $display("t=%0t count=%b", $time, count);
            $display("%3d   %b   %b  %2d", i, mode, count, count);
        end
        mode = 0;
        for (i = 7; i <= 14; i = i + 1) begin
            @(posedge clk); #1;
            $display("%3d   %b   %b  %2d", i, mode, count, count);
        end
        $finish;
    end
endmodule
