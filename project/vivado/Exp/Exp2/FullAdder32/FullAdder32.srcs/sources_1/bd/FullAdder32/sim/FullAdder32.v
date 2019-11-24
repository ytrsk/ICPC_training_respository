//Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
//Date        : Sun Nov 10 02:45:50 2019
//Host        : DESKTOP-UB8SBA3 running 64-bit major release  (build 9200)
//Command     : generate_target FullAdder32.bd
//Design      : FullAdder32
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "FullAdder32,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=FullAdder32,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=32,numReposBlks=32,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=Global}" *) (* HW_HANDOFF = "FullAdder32.hwdef" *) 
module FullAdder32
   ();

  wire FullAdder1_0_CO;
  wire FullAdder1_10_CO;
  wire FullAdder1_11_CO;
  wire FullAdder1_12_CO;
  wire FullAdder1_13_CO;
  wire FullAdder1_14_CO;
  wire FullAdder1_15_CO;
  wire FullAdder1_16_CO;
  wire FullAdder1_17_CO;
  wire FullAdder1_18_CO;
  wire FullAdder1_19_CO;
  wire FullAdder1_1_CO;
  wire FullAdder1_20_CO;
  wire FullAdder1_21_CO;
  wire FullAdder1_22_CO;
  wire FullAdder1_23_CO;
  wire FullAdder1_24_CO;
  wire FullAdder1_25_CO;
  wire FullAdder1_26_CO;
  wire FullAdder1_27_CO;
  wire FullAdder1_28_CO;
  wire FullAdder1_29_CO;
  wire FullAdder1_2_CO;
  wire FullAdder1_30_CO;
  wire FullAdder1_3_CO;
  wire FullAdder1_4_CO;
  wire FullAdder1_5_CO;
  wire FullAdder1_6_CO;
  wire FullAdder1_7_CO;
  wire FullAdder1_8_CO;
  wire FullAdder1_9_CO;

  FullAdder32_FullAdder1_0_0 FullAdder1_0
       (.B(1'b0),
        .CI(1'b0),
        .CO(FullAdder1_0_CO));
  FullAdder32_FullAdder1_0_1 FullAdder1_1
       (.B(1'b0),
        .CI(FullAdder1_0_CO),
        .CO(FullAdder1_1_CO));
  FullAdder32_FullAdder1_0_10 FullAdder1_10
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_9_CO),
        .CO(FullAdder1_10_CO));
  FullAdder32_FullAdder1_0_11 FullAdder1_11
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_10_CO),
        .CO(FullAdder1_11_CO));
  FullAdder32_FullAdder1_0_12 FullAdder1_12
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_11_CO),
        .CO(FullAdder1_12_CO));
  FullAdder32_FullAdder1_0_13 FullAdder1_13
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_12_CO),
        .CO(FullAdder1_13_CO));
  FullAdder32_FullAdder1_0_14 FullAdder1_14
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_13_CO),
        .CO(FullAdder1_14_CO));
  FullAdder32_FullAdder1_0_15 FullAdder1_15
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_14_CO),
        .CO(FullAdder1_15_CO));
  FullAdder32_FullAdder1_0_16 FullAdder1_16
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_15_CO),
        .CO(FullAdder1_16_CO));
  FullAdder32_FullAdder1_0_17 FullAdder1_17
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_16_CO),
        .CO(FullAdder1_17_CO));
  FullAdder32_FullAdder1_0_18 FullAdder1_18
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_17_CO),
        .CO(FullAdder1_18_CO));
  FullAdder32_FullAdder1_0_19 FullAdder1_19
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_18_CO),
        .CO(FullAdder1_19_CO));
  FullAdder32_FullAdder1_0_2 FullAdder1_2
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_1_CO),
        .CO(FullAdder1_2_CO));
  FullAdder32_FullAdder1_0_20 FullAdder1_20
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_19_CO),
        .CO(FullAdder1_20_CO));
  FullAdder32_FullAdder1_0_21 FullAdder1_21
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_20_CO),
        .CO(FullAdder1_21_CO));
  FullAdder32_FullAdder1_0_22 FullAdder1_22
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_21_CO),
        .CO(FullAdder1_22_CO));
  FullAdder32_FullAdder1_0_23 FullAdder1_23
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_22_CO),
        .CO(FullAdder1_23_CO));
  FullAdder32_FullAdder1_16_0 FullAdder1_24
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_23_CO),
        .CO(FullAdder1_24_CO));
  FullAdder32_FullAdder1_16_1 FullAdder1_25
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_24_CO),
        .CO(FullAdder1_25_CO));
  FullAdder32_FullAdder1_16_2 FullAdder1_26
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_25_CO),
        .CO(FullAdder1_26_CO));
  FullAdder32_FullAdder1_16_3 FullAdder1_27
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_26_CO),
        .CO(FullAdder1_27_CO));
  FullAdder32_FullAdder1_16_4 FullAdder1_28
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_27_CO),
        .CO(FullAdder1_28_CO));
  FullAdder32_FullAdder1_16_5 FullAdder1_29
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_28_CO),
        .CO(FullAdder1_29_CO));
  FullAdder32_FullAdder1_0_3 FullAdder1_3
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_2_CO),
        .CO(FullAdder1_3_CO));
  FullAdder32_FullAdder1_16_6 FullAdder1_30
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_29_CO),
        .CO(FullAdder1_30_CO));
  FullAdder32_FullAdder1_16_7 FullAdder1_31
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_30_CO));
  FullAdder32_FullAdder1_0_4 FullAdder1_4
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_3_CO),
        .CO(FullAdder1_4_CO));
  FullAdder32_FullAdder1_0_5 FullAdder1_5
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_4_CO),
        .CO(FullAdder1_5_CO));
  FullAdder32_FullAdder1_0_6 FullAdder1_6
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_5_CO),
        .CO(FullAdder1_6_CO));
  FullAdder32_FullAdder1_0_7 FullAdder1_7
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_6_CO),
        .CO(FullAdder1_7_CO));
  FullAdder32_FullAdder1_0_8 FullAdder1_8
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_7_CO),
        .CO(FullAdder1_8_CO));
  FullAdder32_FullAdder1_0_9 FullAdder1_9
       (.A(1'b0),
        .B(1'b0),
        .CI(FullAdder1_8_CO),
        .CO(FullAdder1_9_CO));
endmodule
