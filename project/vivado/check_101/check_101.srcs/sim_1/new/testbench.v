`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 09:49:47
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
    reg clk,rst,x;wire z;
    check_101 fsm(clk,rst,x,z);
    wire [19:0] now=20'b11000010101010111100; 
    initial begin
        clk=0;x=0;rst=0;#5 rst=1;#3 rst=0;
        for(integer i=0;i<20;i=i+1) begin
            #30 x=now[i];
        end
    end
    always #10
    clk=~clk;
endmodule
