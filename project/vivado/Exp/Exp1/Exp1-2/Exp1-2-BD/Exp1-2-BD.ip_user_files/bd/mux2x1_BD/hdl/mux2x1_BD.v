//Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2015.2 (win64) Build 1266856 Fri Jun 26 16:35:25 MDT 2015
//Date        : Mon Nov 04 12:52:29 2019
//Host        : LAPTOP-T17AIMEK running 64-bit major release  (build 9200)
//Command     : generate_target mux2x1_BD.bd
//Design      : mux2x1_BD
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "mux2x1_BD,IP_Integrator,{x_ipProduct=Vivado 2015.2,x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=mux2x1_BD,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=4,numReposBlks=4,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,synth_mode=Global}" *) (* HW_HANDOFF = "mux2x1_BD.hwdef" *) 
module mux2x1_BD
   (a,
    b,
    c,
    sel);
  input a;
  input b;
  output [7:0]c;
  input sel;

  wire a_1;
  wire [7:0]andgate_0_c;
  wire [7:0]andgate_1_c;
  wire b_1;
  wire [7:0]notgate_0_c;
  wire [7:0]orgate_0_c;
  wire sel_1;

  assign a_1 = a;
  assign b_1 = b;
  assign c[7:0] = orgate_0_c;
  assign sel_1 = sel;
  mux2x1_BD_andgate_0_0 andgate_0
       (.a({a_1,a_1,a_1,a_1,a_1,a_1,a_1,a_1}),
        .b({sel_1,sel_1,sel_1,sel_1,sel_1,sel_1,sel_1,sel_1}),
        .c(andgate_0_c));
  mux2x1_BD_andgate_1_0 andgate_1
       (.a(notgate_0_c),
        .b({b_1,b_1,b_1,b_1,b_1,b_1,b_1,b_1}),
        .c(andgate_1_c));
  mux2x1_BD_notgate_0_0 notgate_0
       (.a({sel_1,sel_1,sel_1,sel_1,sel_1,sel_1,sel_1,sel_1}),
        .c(notgate_0_c));
  mux2x1_BD_orgate_0_0 orgate_0
       (.a(andgate_0_c),
        .b(andgate_1_c),
        .c(orgate_0_c));
endmodule
