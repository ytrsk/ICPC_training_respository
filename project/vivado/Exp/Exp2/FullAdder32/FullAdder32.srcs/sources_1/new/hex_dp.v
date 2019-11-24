`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/10 05:25:27
// Design Name: 
// Module Name: hex_dp
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

module hex_dp(clk,col,segs,a,b,c);
    input clk;input [3:0] a,b,c;
    output reg [7:0] segs;output reg[3:0] col;
    reg [20:0]now;reg[3:0] hex;
    always@ (posedge clk)
    begin
        now=now+1;
        if(now==30000) now=0;
    end
    always@ (posedge clk) begin
    if(now<10000) begin col=4'b0111;hex=a;end
    else if(now<20000) begin col=4'b1011;hex=b;end
    else begin col=4'b1110;hex=c;end
        case(hex)
        4'h0: segs=8'b00000010;
        4'h1: segs=8'b10011110;
        4'h2: segs=8'b00100100;
        4'h3: segs=8'b00001100;
        4'h4: segs=8'b10011000;
        4'h5: segs=8'b01001000;
        4'h6: segs=8'b01000000;
        4'h7: segs=8'b00011110;
        4'h8: segs=8'b00000000;
        4'h9: segs=8'b00011000;
        4'ha: segs=8'b00010000;
        4'hb: segs=8'b11000000;
        4'hc: segs=8'b11100100;
        4'hd: segs=8'b10000100;
        4'he: segs=8'b01100000;
        4'hf: segs=8'b01110000;
        default:
            begin col=4'b1111;segs=8'b11111111;end
        endcase
    end

endmodule