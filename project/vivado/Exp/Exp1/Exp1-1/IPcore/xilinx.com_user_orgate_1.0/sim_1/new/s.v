`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 12:17:30
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
    reg[2: 0] a = 0;
    reg[2 :0] b = 0;
    wire[2 :0] c;
    
    orgate test(a, b, c);
    
    initial
    begin
        #50 a = 3'b111; b = 3'b010;
        #50 b = 3'b110;
        #50 a = 3'b010;
    end
    
endmodule
