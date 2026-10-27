// 1:4 demultiplexer, din routed to the line chosen by sel
module demux1to4(input din, input [1:0] sel,
                 output y0, output y1, output y2, output y3);
    assign y0 = (sel == 2'b00) ? din : 1'b0;
    assign y1 = (sel == 2'b01) ? din : 1'b0;
    assign y2 = (sel == 2'b10) ? din : 1'b0;
    assign y3 = (sel == 2'b11) ? din : 1'b0;
endmodule
