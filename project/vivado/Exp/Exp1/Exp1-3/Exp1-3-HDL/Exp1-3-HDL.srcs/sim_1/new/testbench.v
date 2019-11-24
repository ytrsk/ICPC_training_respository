`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 01:21:08
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
    reg [2:0] a,b,c,d;
    reg sel1,sel2;
    wire [2:0] o;
    mux4x1_HDL test(a,b,c,d,sel1,sel2,o);
    initial begin
        #5 a=3'b001;b=3'b101;c=3'b111;d=3'b010;sel1=1;sel2=1;
        #50 sel1=1;sel2=0;
        #50 sel1=0;sel2=1;
        #50 sel1=0;sel2=0;
    end
endmodule
