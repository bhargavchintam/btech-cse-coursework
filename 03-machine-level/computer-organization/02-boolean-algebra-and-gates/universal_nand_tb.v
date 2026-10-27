// iverilog -o un universal_nand.v universal_nand_tb.v && vvp un
module universal_nand_tb;
    reg a, b;
    wire yn, ya, yo;
    integer i, errs;

    not_nand u1(a, yn);
    and_nand u2(a, b, ya);
    or_nand  u3(a, b, yo);

    initial begin
        errs = 0;
        $display("a b | not(a) exp | and exp | or exp");
        $display("----+------------+---------+-------");
        for(i = 0; i < 4; i = i + 1) begin
            {a, b} = i;
            #5;
            $display("%b %b |   %b     %b  |  %b   %b  | %b   %b",
                     a, b, yn, ~a, ya, a & b, yo, a | b);
            if(yn !== ~a || ya !== (a & b) || yo !== (a | b))
                errs = errs + 1;
        end
        if(errs == 0)
            $display("all three match the expected tables");
        else
            $display("%0d rows wrong", errs);
        $finish;
    end
endmodule
