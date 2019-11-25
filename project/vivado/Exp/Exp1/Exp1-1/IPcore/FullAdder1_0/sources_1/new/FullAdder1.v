`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/07 20:34:42
// Design Name: 
// Module Name: FullAdder1
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


module FullAdder1(
    input A,
    input B,
    input CI,
    output S,
    output CO
    );
    assign {CO, S} = A + B + CI;
endmodule
