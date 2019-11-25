`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 09:22:08
// Design Name: 
// Module Name: drink_fsm
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


module drink_fsm(clk,rst,op_start,cancel_flag,coin_val,
hold_ind,charge_ind,drinktk_ind,charge_val
);
    input clk,rst;
    input op_start,cancel_flag;
    input [1:0]coin_val;
    output reg hold_ind,charge_ind,drinktk_ind;
    output reg [2:0] charge_val;
    reg [2:0] state,next_state;
    parameter S0=3'b000,S1=3'b001,S2=3'b010,S3=3'b011,S4=3'b100,S5=3'b101,S6=3'b110;
    always @(posedge clk or posedge rst)
    if(rst) state<=S0;
    else state<=next_state;
    always@(state or rst or op_start or cancel_flag or coin_val)
    if(rst) next_state=S0;
    else begin
        if(state==S0) begin
           if(op_start) next_state=state+coin_val;
        end
        else if(state<=S4) begin
            if(cancel_flag) next_state=S0;
            else next_state=state+coin_val;
        end
        else next_state=S0;
     end
     always @(state)
        if(state == S0) hold_ind=1'b0;
        else hold_ind=1'b1;
     always @(state)
        if(state>=S5) drinktk_ind=1'b1;
        else drinktk_ind=1'b0;
     always @(state or cancel_flag) 
     if(state==S0) charge_ind=1'b0;
     else if(state==S6) charge_ind=1'b1;
     else if(cancel_flag) charge_ind=1'b1;
     else charge_ind=1'b0;
     always @(state or cancel_flag)
        if(state==S0) charge_val=3'b000;
        else if(state==S6) charge_val=3'b001;
        else if(cancel_flag) begin
            if(state<=S4) charge_val=state;
            else charge_val=0;
        end
endmodule