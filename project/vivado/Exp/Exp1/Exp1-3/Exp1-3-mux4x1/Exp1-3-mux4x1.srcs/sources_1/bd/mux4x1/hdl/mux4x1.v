//Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2015.2 (win64) Build 1266856 Fri Jun 26 16:35:25 MDT 2015
//Date        : Wed Nov 06 15:20:35 2019
//Host        : LAPTOP-T17AIMEK running 64-bit major release  (build 9200)
//Command     : generate_target mux4x1.bd
//Design      : mux4x1
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "mux4x1,IP_Integrator,{x_ipProduct=Vivado 2015.2,x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=mux4x1,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=13,numReposBlks=13,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,synth_mode=Global}" *) (* HW_HANDOFF = "mux4x1.hwdef" *) 
module mux4x1
   (a,
    b,
    c,
    d,
    o,
    sel1,
    sel2);
  input [2:0]a;
  input [2:0]b;
  input [2:0]c;
  input [2:0]d;
  output [2:0]o;
  input sel1;
  input sel2;

  wire [2:0]a_1;
  wire [2:0]andgate_0_c;
  wire [2:0]andgate_1_c;
  wire [2:0]andgate_2_c;
  wire [2:0]andgate_3_c;
  wire [2:0]andgate_4_c;
  wire [2:0]andgate_5_c;
  wire [2:0]andgate_6_c;
  wire [2:0]andgate_7_c;
  wire [2:0]b_1;
  wire [2:0]c_1;
  wire [2:0]d_1;
  wire [2:0]notgate_0_c;
  wire [2:0]notgate_1_c;
  wire [2:0]orgate_0_c;
  wire [2:0]orgate_1_c;
  wire [2:0]orgate_2_c;
  wire sel1_1;
  wire sel2_1;

  assign a_1 = a[2:0];
  assign b_1 = b[2:0];
  assign c_1 = c[2:0];
  assign d_1 = d[2:0];
  assign o[2:0] = orgate_2_c;
  assign sel1_1 = sel1;
  assign sel2_1 = sel2;
  mux4x1_andgate_0_0 andgate_0
       (.a({sel1_1,sel1_1,sel1_1}),
        .b({sel2_1,sel2_1,sel2_1}),
        .c(andgate_0_c));
  mux4x1_andgate_1_0 andgate_1
       (.a(notgate_0_c),
        .b({sel2_1,sel2_1,sel2_1}),
        .c(andgate_1_c));
  mux4x1_andgate_2_0 andgate_2
       (.a({sel1_1,sel1_1,sel1_1}),
        .b(notgate_1_c),
        .c(andgate_2_c));
  mux4x1_andgate_3_0 andgate_3
       (.a(notgate_0_c),
        .b(notgate_1_c),
        .c(andgate_3_c));
  mux4x1_andgate_4_0 andgate_4
       (.a(andgate_0_c),
        .b(a_1),
        .c(andgate_4_c));
  mux4x1_andgate_5_0 andgate_5
       (.a(andgate_1_c),
        .b(b_1),
        .c(andgate_5_c));
  mux4x1_andgate_6_0 andgate_6
       (.a(andgate_2_c),
        .b(c_1),
        .c(andgate_6_c));
  mux4x1_andgate_7_0 andgate_7
       (.a(andgate_3_c),
        .b(d_1),
        .c(andgate_7_c));
  mux4x1_notgate_0_0 notgate_0
       (.a({sel1_1,sel1_1,sel1_1}),
        .c(notgate_0_c));
  mux4x1_notgate_1_0 notgate_1
       (.a({sel2_1,sel2_1,sel2_1}),
        .c(notgate_1_c));
  mux4x1_orgate_0_1 orgate_0
       (.a(andgate_4_c),
        .b(andgate_5_c),
        .c(orgate_0_c));
  mux4x1_orgate_1_0 orgate_1
       (.a(andgate_6_c),
        .b(andgate_7_c),
        .c(orgate_1_c));
  mux4x1_orgate_2_0 orgate_2
       (.a(orgate_0_c),
        .b(orgate_1_c),
        .c(orgate_2_c));
endmodule
