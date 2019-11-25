`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 12:20:33
// Design Name: 
// Module Name: notgate
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


module notgate
#(parameter WIDTH = 3)
(
    input[WIDTH - 1: 0] a,
    output[WIDTH - 1: 0] c
    );
    assign c = ~a;
endmodule
