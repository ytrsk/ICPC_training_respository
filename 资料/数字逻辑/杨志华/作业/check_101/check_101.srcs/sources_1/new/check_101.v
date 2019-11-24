`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/04/14 23:13:40
// Design Name: 
// Module Name: check_101
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


module check_101(
    input x, clk, rst,
    output y);
    reg y;
    reg[1:0] currentstate, nextstate;
    parameter S0=2'b00;
    parameter S1=2'b01;
    parameter S2=2'b10;
    parameter S3=2'b11;
    
    always@(posedge clk or negedge rst)
    begin
        if(!rst)
            currentstate <= S0;
        else
            currentstate <= nextstate;
   end
   
   always@(currentstate or x or rst)
   begin
    if(!rst)
        nextstate = S0;
    else 
    begin
        case(currentstate)
            S0:nextstate = (x==1)?S1:S0;
            S1:nextstate = (x==0)?S2:S0;
            S2:nextstate = (x==1)?S3:S0;
            S3:nextstate = (x==1)?S1:S0;
            default: nextstate = S0;
        endcase
    end
end

always@(rst or currentstate)
begin
    if(!rst)
        y=0;
    else
        case(currentstate)
            S0: y=0;
            S1: y=0;
            S2: y=0;
            S3: y=1;
            default: y=0;
         endcase
     end
endmodule