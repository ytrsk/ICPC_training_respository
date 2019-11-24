`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 03:00:40
// Design Name: 
// Module Name: FullAdder32
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


module FullAdder32(A,B,S,CI,CO);
    parameter n=32;
    input [n-1:0] A,B;input CI;
    output [n-1:0] S;
    output CO;
    wire [n:0] C;
    assign C[0]=CI;
    assign CO=C[n];
    generate
        for (genvar i=0;i<n;i=i+1)
        begin
            FullAdder stage(A[i],B[i],C[i],S[i],C[i+1]);
        end
    endgenerate
endmodule