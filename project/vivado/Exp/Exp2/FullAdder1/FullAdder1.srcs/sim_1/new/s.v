`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/07 20:36:25
// Design Name: 
// Module Name: s
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


module s();
    reg A = 1;
    reg B = 1;
    reg CI = 0;
    wire CO;
    wire S;
    FullAdder1 test(A, B, CI, S, CO);
    
    initial
    begin
        #100 A = 0; B = 1; CI = 1;
        #100 B = 1;
    end
endmodule
