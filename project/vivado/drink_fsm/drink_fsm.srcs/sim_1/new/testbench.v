`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/11/04 09:57:41
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
    reg rst,clk,op_start,cancel_flag;
    reg [1:0] coin_val;
    wire hold_ind,charge_ind,drinktk_ind;
    wire [2:0] charge_val;
    drink_fsm fsm(clk,rst,op_start,cancel_flag,coin_val,hold_ind,charge_ind,drinktk_ind,charge_val);
    initial clk=0;
    always #5 clk=~clk;
    initial begin 
        rst=0;op_start=0;cancel_flag=0;
        coin_val=2'b00;
        #5 rst=1;#3 rst=0;
        #10 op_start=1;
        #5 coin_val=2'b10;
        #10 coin_val=2'b10;
        #10 coin_val=2'b01;
        #10 op_start=0;
        
        #10 op_start=1;
        coin_val=2'b10;
        #10 coin_val=2'b10;
        #10 coin_val=2'b10;
        #10 op_start=0;
        
        #10 op_start=1;
        coin_val=2'b10;
        #10 coin_val=2'b10;
        #10 cancel_flag=1'b1;op_start=0;
        #10 cancel_flag=1'b0;
        
        #10 op_start=1;
        #10 coin_val=2'b01;
        #10 coin_val=2'b10;
        #10 op_start=0;
    end  
endmodule