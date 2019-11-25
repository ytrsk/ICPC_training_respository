//Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2015.2 (win64) Build 1266856 Fri Jun 26 16:35:25 MDT 2015
//Date        : Mon Nov 04 12:52:29 2019
//Host        : LAPTOP-T17AIMEK running 64-bit major release  (build 9200)
//Command     : generate_target mux2x1_BD_wrapper.bd
//Design      : mux2x1_BD_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module mux2x1_BD_wrapper
   (a,
    b,
    c,
    sel);
  input a;
  input b;
  output [7:0]c;
  input sel;

  wire a;
  wire b;
  wire [7:0]c;
  wire sel;

  mux2x1_BD mux2x1_BD_i
       (.a(a),
        .b(b),
        .c(c),
        .sel(sel));
endmodule
