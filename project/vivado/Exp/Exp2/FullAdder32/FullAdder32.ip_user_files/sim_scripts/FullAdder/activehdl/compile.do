vlib work
vlib activehdl

vlib activehdl/xil_defaultlib

vmap xil_defaultlib activehdl/xil_defaultlib

vlog -work xil_defaultlib  -v2k5 \
"../../../../../../Exp1/Exp1-1/IPcore/FullAdder/sources_1/new/FullAdder1.v" \
"../../../../../../Exp1/Exp1-1/IPcore/FullAdder/sim/FullAdder.v" \


vlog -work xil_defaultlib \
"glbl.v"

