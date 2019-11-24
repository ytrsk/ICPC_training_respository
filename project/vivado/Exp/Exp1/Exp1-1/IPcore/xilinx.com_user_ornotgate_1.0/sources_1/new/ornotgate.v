`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 12:30:06
// Design Name: 
// Module Name: ornotgate
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


module ornotgate
#(parameter WIDTH = 3)
(
    input[WIDTH - 1: 0] a,
    input[WIDTH - 1: 0] b,
    output[WIDTH - 1: 0] c
    );
    assign c = ~(a | b);
endmodule

