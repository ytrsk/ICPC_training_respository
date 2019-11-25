`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 12:50:42
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
    reg a = 0;
    reg b = 0;
    reg sel = 0;
    wire c;
    
    mux2x1_BD test(.a(a), .b(b), .c(c), .sel(sel));
    
    initial
    begin
        #50 a = 1; b = 0; sel = 1;
        #50 sel = 0;
    end
    
endmodule
