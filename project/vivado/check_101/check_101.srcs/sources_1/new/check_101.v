`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 08:43:58
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


module check_101(clk,clr,x,z);
    input clk,clr;
    input x;
    output reg z;
    reg[1:0] state,next_state;
    parameter S0=2'b00,S1=2'b01,S2=2'b11,S3=2'b10;
    always @(posedge clk or posedge clr)
    begin if(clr) state<=S0;
    else state<=next_state;
    end
    always @(state or x) begin
    case(state)
        S0:if(x) next_state=S1; 
        else next_state=S0;
        S1:if(x) next_state=S1;
        else next_state=S2;
        S2:if(x) next_state=S3;
        else next_state=S0;
        S3:if(x) next_state=S1;
        else next_state=S2;
        default:next_state=S0;
    endcase
    end
    always @(state)
    begin case(state)
            S3:z=1'b1;
            default:z=1'b0;
         endcase
    end   
endmodule
