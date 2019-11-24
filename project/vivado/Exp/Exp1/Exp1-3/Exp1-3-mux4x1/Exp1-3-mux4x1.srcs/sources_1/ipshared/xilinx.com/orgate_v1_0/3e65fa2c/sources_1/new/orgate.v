`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 12:16:43
// Design Name: 
// Module Name: orgate
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


module orgate
#(parameter WIDTH = 3)
(
    input[WIDTH - 1: 0] a,
    input[WIDTH - 1: 0] b,
    output[WIDTH - 1: 0] c
    );
    assign c = a | b;
endmodule
