`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 00:33:55
// Design Name: 
// Module Name: Exp1-2-HDL
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


module mux2x1_HDL(a,b,sel,c);
    input [7:0] a,b;
    input sel;
    output  [7:0] c; 
    assign c=sel?a:b;
endmodule
