`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 07:05:53
// Design Name: 
// Module Name: add
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


module add(clk,A,B,CO,sub,segs,col);
    parameter n=4;
    input clk;
    input [n-1:0] A,B;input sub;
    output CO;
    output[7:0] segs;
    output[3:0] col;
    wire [n-1:0] S;
    FullAdder32 now(A,B,S,1'b0,CO);
    wire [3:0] a,b,c;
    assign a=A[3:0];
    assign b=B[3:0];
    assign c=S[3:0];
    hex_dp display(clk,col,segs,a,b,c);
endmodule
