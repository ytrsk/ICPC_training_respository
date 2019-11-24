`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 12:59:24
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
    reg[2: 0] a = 3'b010;
    reg[2: 0] b = 3'b101;
    reg[2: 0] c = 3'b110;
    reg[2: 0] d = 3'b001;
    reg sel1 = 0;
    reg sel2 = 0;
    wire[2 :0] o;
    
    mux4x1 test(.a(a), .b(b), .c(c), .d(d), .sel1(sel1), .sel2(sel2), .o(o));
    
    initial
    begin
         #50 sel1 = 1; sel2 = 1;
         #50 sel1 = 0; sel2 = 1;
         #50 sel1 = 1; sel2 = 0;
         #50 sel1 = 0; sel2 = 0;
         #50 d = 3'b111;       
    end
    
endmodule
