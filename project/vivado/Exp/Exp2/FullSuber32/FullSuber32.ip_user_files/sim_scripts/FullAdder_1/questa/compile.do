vlib questa_lib/work
vlib questa_lib/msim

vlib questa_lib/msim/xil_defaultlib

vmap xil_defaultlib questa_lib/msim/xil_defaultlib

vlog -work xil_defaultlib -64 \
"../../../../../../Exp1/Exp1-1/IPcore/FullAdder_1/sources_1/new/FullAdder1.v" \
"../../../../../../Exp1/Exp1-1/IPcore/FullAdder_1/sim/FullAdder.v" \


vlog -work xil_defaultlib \
"glbl.v"

