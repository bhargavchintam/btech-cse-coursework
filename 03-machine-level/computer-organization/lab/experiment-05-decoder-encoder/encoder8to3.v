// 8:3 priority encoder, d[7] has highest priority
// v (valid) is 0 when no input line is active, else the y code means nothing
module encoder8to3(input [7:0] d, output reg [2:0] y, output reg v);
    always @(*) begin
        v = 1'b1;
        casez (d)
            8'b1???????: y = 3'd7;
            8'b01??????: y = 3'd6;
            8'b001?????: y = 3'd5;
            8'b0001????: y = 3'd4;
            8'b00001???: y = 3'd3;
            8'b000001??: y = 3'd2;
            8'b0000001?: y = 3'd1;
            8'b00000001: y = 3'd0;
            default: begin y = 3'd0; v = 1'b0; end
        endcase
    end
endmodule
