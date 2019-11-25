`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 04:07:54
// Design Name: 
// Module Name: FullSuber32
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


module FullSuber32(A,B,S,CI,sub,overflow);
    parameter n=4;
    input [n-1:0] A,B;input CI,sub;
    output [n-1:0] S;
    output overflow;
    wire [n:0] C;
    wire [n-1:0] B2;
    assign C[0]=CI;
    assign overflow=C[n]^C[n-1];
    assign B2=sub?~B+1:B;
    generate
        for (genvar i=0;i<n;i=i+1)
        begin
            FullAdder stage(A[i],B2[i],C[i],S[i],C[i+1]);
        end
    endgenerate
endmodule