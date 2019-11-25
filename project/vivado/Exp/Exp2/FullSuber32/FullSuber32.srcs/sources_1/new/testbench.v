`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 06:15:27
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
    reg CI,sub;
    wire overflow;
    reg clk=0;
    wire CO;
    FullAdder32 now(A,B,S,CI,sub,CO,overflow);
    initial begin
        A=89;B=70;CI=1'b0;sub=1'b0;
        #30 A=20;B=20;
        #50 A=160;B=200;
        #50 sub=1;
        #50 A=3000;B=1250;sub=1;
        #50 A=2000000000;B=-2000000000;
    end
endmodule
