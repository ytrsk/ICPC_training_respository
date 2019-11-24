`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 02:14:15
// Design Name: 
// Module Name: testbench
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


module testbench();
    parameter n=32;
    reg [n-1:0] A,B;
    wire [n-1:0] S;
    reg CI;
    wire CO;
    FullAdder32 now(A,B,S,CI,CO);
    initial begin
        A=32'b11001010101010111110110011000011;
        B=32'b00101010000010000100101010010010;
        CI=1'b0;
        #30 CI=1'b1;
        #50 CI=0;A=35536;B=30000;
    end
endmodule