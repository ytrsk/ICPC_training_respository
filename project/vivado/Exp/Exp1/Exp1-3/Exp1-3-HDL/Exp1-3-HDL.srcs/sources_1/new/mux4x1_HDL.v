`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 01:14:03
// Design Name: 
// Module Name: mux4x1_HDL
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


module mux4x1_HDL(a,b,c,d,sel1,sel2,o);
    input [2:0] a,b,c,d;
    input sel1,sel2;
    output [2:0] o;
    assign o=sel1?(sel2?a:c):(sel2?b:d);
endmodule
