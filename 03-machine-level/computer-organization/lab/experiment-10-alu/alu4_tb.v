// iverilog -o alu4 alu4.v alu4_tb.v && vvp alu4
module alu4_tb;
    reg [3:0] a, b;
    reg [2:0] sel;
    wire [3:0] y;
    wire cout, zero;
    reg [31:0] op;
    integer i;

    alu4 dut(a, b, sel, y, cout, zero);

    initial begin
        a = 4'd10; b = 4'd6;
        $display("a = %b (%0d), b = %b (%0d)", a, a, b, b);
        $display(" sel  op    y        cout  zero");
        for (i = 0; i < 8; i = i + 1) begin
            sel = i[2:0];
            #5;
            case (sel)
                3'b000: op = "ADD ";
                3'b001: op = "SUB ";
                3'b010: op = "AND ";
                3'b011: op = "OR  ";
                3'b100: op = "XOR ";
                3'b101: op = "NOTA";
                3'b110: op = "SHL ";
                3'b111: op = "SHR ";
            endcase
            $display(" %b  %s  %b(%2d)   %b     %b", sel, op, y, y, cout, zero);
        end
        $finish;
    end
endmodule
