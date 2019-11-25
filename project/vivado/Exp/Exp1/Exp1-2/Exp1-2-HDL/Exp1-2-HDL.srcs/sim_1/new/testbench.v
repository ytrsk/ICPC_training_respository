`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 00:38:35
// Design Name: 
// Module Name: testbench
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module testbench();
    reg [7:0] a,b;reg sel;wire[7:0] c;
    mux2x1_HDL test(a,b,sel,c);
    initial begin
        #5 a=8'b11001010;b=8'b00100010;sel=1;
        #50 sel=0;
        #50 a=8'b11111111;b=8'b00000001;
        #50 sel=1;
    end
endmodule
