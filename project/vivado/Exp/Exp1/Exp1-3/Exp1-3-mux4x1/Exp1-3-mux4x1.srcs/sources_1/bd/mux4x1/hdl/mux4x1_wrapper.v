//Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2015.2 (win64) Build 1266856 Fri Jun 26 16:35:25 MDT 2015
//Date        : Wed Nov 06 15:20:35 2019
//Host        : LAPTOP-T17AIMEK running 64-bit major release  (build 9200)
//Command     : generate_target mux4x1_wrapper.bd
//Design      : mux4x1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module mux4x1_wrapper
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

  wire [2:0]a;
  wire [2:0]b;
  wire [2:0]c;
  wire [2:0]d;
  wire [2:0]o;
  wire sel1;
  wire sel2;

  mux4x1 mux4x1_i
       (.a(a),
        .b(b),
        .c(c),
        .d(d),
        .o(o),
        .sel1(sel1),
        .sel2(sel2));
endmodule
