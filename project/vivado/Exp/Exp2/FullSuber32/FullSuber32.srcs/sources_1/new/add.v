`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 05:54:08
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
module add(clk,A,B,sub,segs,col,sw,CO,overflow);
    parameter n=4;
    input clk;
    input [n-1:0] A,B;input sub;
    input [1:0]sw;
    output CO,overflow;
    output[7:0] segs;
    output[3:0] col;
    wire [n-1:0] B2,A2;
    wire [n-1:0] S;
    assign A2=A[n-1]?~{1'b0,A[n-2:0]}+1:A[n-1:0];
    assign B2=B[n-1]?~{1'b0,B[n-2:0]}+1:B[n-1:0];
    FullAdder32 now(A2,B2,S,1'b0,sub,CO,overflow);
    reg [3:0] a,b;
    always @(A or B or S or sw) begin
        if(sw==2'b10) begin
            a=A[n-1]?4'h9:4'h8;
            b=A2[n-1]?~A2[n-1:0]+1:A2[n-1:0];
        end
        else if(sw==2'b01) begin
            a=B[n-1]?4'h9:4'h8;
            b=B2[n-1]?~B2[n-1:0]+1:B2[n-1:0];
        end
        else if(sw==2'b11) begin
            a=S[n-1]?4'h9:4'h8;
            b=S[n-1]?~S[n-1:0]+1:S[n-1:0];
        end
    end
    hex_dp display(clk,col,segs,a,b);
endmodule