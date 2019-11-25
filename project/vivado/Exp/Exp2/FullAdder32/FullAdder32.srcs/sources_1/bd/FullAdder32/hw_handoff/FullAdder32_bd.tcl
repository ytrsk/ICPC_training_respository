
################################################################
# This is a generated script based on design: FullAdder32
#
# Though there are limitations about the generated script,
# the main purpose of this utility is to make learning
# IP Integrator Tcl commands easier.
################################################################

namespace eval _tcl {
proc get_script_folder {} {
   set script_path [file normalize [info script]]
   set script_folder [file dirname $script_path]
   return $script_folder
}
}
variable script_folder
set script_folder [_tcl::get_script_folder]

################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2019.1
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   catch {common::send_msg_id "BD_TCL-109" "ERROR" "This script was generated using Vivado <$scripts_vivado_version> and is being run in <$current_vivado_version> of Vivado. Please run the script in Vivado <$scripts_vivado_version> then open the design in Vivado <$current_vivado_version>. Upgrade the design by running \"Tools => Report => Report IP Status...\", then run write_bd_tcl to create an updated script."}

   return 1
}

################################################################
# START
################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source FullAdder32_script.tcl

# If there is no project opened, this script will create a
# project, but make sure you do not have an existing project
# <./myproj/project_1.xpr> in the current working folder.

set list_projs [get_projects -quiet]
if { $list_projs eq "" } {
   create_project project_1 myproj -part xc7a35ticpg236-1L
}


# CHANGE DESIGN NAME HERE
variable design_name
set design_name FullAdder32

# If you do not already have an existing IP Integrator design open,
# you can create a design using the following command:
#    create_bd_design $design_name

# Creating design if needed
set errMsg ""
set nRet 0

set cur_design [current_bd_design -quiet]
set list_cells [get_bd_cells -quiet]

if { ${design_name} eq "" } {
   # USE CASES:
   #    1) Design_name not set

   set errMsg "Please set the variable <design_name> to a non-empty value."
   set nRet 1

} elseif { ${cur_design} ne "" && ${list_cells} eq "" } {
   # USE CASES:
   #    2): Current design opened AND is empty AND names same.
   #    3): Current design opened AND is empty AND names diff; design_name NOT in project.
   #    4): Current design opened AND is empty AND names diff; design_name exists in project.

   if { $cur_design ne $design_name } {
      common::send_msg_id "BD_TCL-001" "INFO" "Changing value of <design_name> from <$design_name> to <$cur_design> since current design is empty."
      set design_name [get_property NAME $cur_design]
   }
   common::send_msg_id "BD_TCL-002" "INFO" "Constructing design in IPI design <$cur_design>..."

} elseif { ${cur_design} ne "" && $list_cells ne "" && $cur_design eq $design_name } {
   # USE CASES:
   #    5) Current design opened AND has components AND same names.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 1
} elseif { [get_files -quiet ${design_name}.bd] ne "" } {
   # USE CASES: 
   #    6) Current opened design, has components, but diff names, design_name exists in project.
   #    7) No opened design, design_name exists in project.

   set errMsg "Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 2

} else {
   # USE CASES:
   #    8) No opened design, design_name not in project.
   #    9) Current opened design, has components, but diff names, design_name not in project.

   common::send_msg_id "BD_TCL-003" "INFO" "Currently there is no design <$design_name> in project, so creating one..."

   create_bd_design $design_name

   common::send_msg_id "BD_TCL-004" "INFO" "Making design <$design_name> as current_bd_design."
   current_bd_design $design_name

}

common::send_msg_id "BD_TCL-005" "INFO" "Currently the variable <design_name> is equal to \"$design_name\"."

if { $nRet != 0 } {
   catch {common::send_msg_id "BD_TCL-114" "ERROR" $errMsg}
   return $nRet
}

##################################################################
# DESIGN PROCs
##################################################################



# Procedure to create entire design; Provide argument to make
# procedure reusable. If parentCell is "", will use root.
proc create_root_design { parentCell } {

  variable script_folder
  variable design_name

  if { $parentCell eq "" } {
     set parentCell [get_bd_cells /]
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     catch {common::send_msg_id "BD_TCL-100" "ERROR" "Unable to find parent cell <$parentCell>!"}
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     catch {common::send_msg_id "BD_TCL-101" "ERROR" "Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."}
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj


  # Create interface ports

  # Create ports

  # Create instance: FullAdder1_0, and set properties
  set FullAdder1_0 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_0 ]

  # Create instance: FullAdder1_1, and set properties
  set FullAdder1_1 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_1 ]

  # Create instance: FullAdder1_2, and set properties
  set FullAdder1_2 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_2 ]

  # Create instance: FullAdder1_3, and set properties
  set FullAdder1_3 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_3 ]

  # Create instance: FullAdder1_4, and set properties
  set FullAdder1_4 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_4 ]

  # Create instance: FullAdder1_5, and set properties
  set FullAdder1_5 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_5 ]

  # Create instance: FullAdder1_6, and set properties
  set FullAdder1_6 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_6 ]

  # Create instance: FullAdder1_7, and set properties
  set FullAdder1_7 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_7 ]

  # Create instance: FullAdder1_8, and set properties
  set FullAdder1_8 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_8 ]

  # Create instance: FullAdder1_9, and set properties
  set FullAdder1_9 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_9 ]

  # Create instance: FullAdder1_10, and set properties
  set FullAdder1_10 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_10 ]

  # Create instance: FullAdder1_11, and set properties
  set FullAdder1_11 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_11 ]

  # Create instance: FullAdder1_12, and set properties
  set FullAdder1_12 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_12 ]

  # Create instance: FullAdder1_13, and set properties
  set FullAdder1_13 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_13 ]

  # Create instance: FullAdder1_14, and set properties
  set FullAdder1_14 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_14 ]

  # Create instance: FullAdder1_15, and set properties
  set FullAdder1_15 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_15 ]

  # Create instance: FullAdder1_16, and set properties
  set FullAdder1_16 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_16 ]

  # Create instance: FullAdder1_17, and set properties
  set FullAdder1_17 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_17 ]

  # Create instance: FullAdder1_18, and set properties
  set FullAdder1_18 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_18 ]

  # Create instance: FullAdder1_19, and set properties
  set FullAdder1_19 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_19 ]

  # Create instance: FullAdder1_20, and set properties
  set FullAdder1_20 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_20 ]

  # Create instance: FullAdder1_21, and set properties
  set FullAdder1_21 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_21 ]

  # Create instance: FullAdder1_22, and set properties
  set FullAdder1_22 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_22 ]

  # Create instance: FullAdder1_23, and set properties
  set FullAdder1_23 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_23 ]

  # Create instance: FullAdder1_24, and set properties
  set FullAdder1_24 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_24 ]

  # Create instance: FullAdder1_25, and set properties
  set FullAdder1_25 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_25 ]

  # Create instance: FullAdder1_26, and set properties
  set FullAdder1_26 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_26 ]

  # Create instance: FullAdder1_27, and set properties
  set FullAdder1_27 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_27 ]

  # Create instance: FullAdder1_28, and set properties
  set FullAdder1_28 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_28 ]

  # Create instance: FullAdder1_29, and set properties
  set FullAdder1_29 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_29 ]

  # Create instance: FullAdder1_30, and set properties
  set FullAdder1_30 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_30 ]

  # Create instance: FullAdder1_31, and set properties
  set FullAdder1_31 [ create_bd_cell -type ip -vlnv xilinx.com:user:FullAdder1:1.0 FullAdder1_31 ]

  # Create port connections
  connect_bd_net -net A_1 [get_bd_pins FullAdder1_0/A] [get_bd_pins FullAdder1_1/A]
  connect_bd_net -net FullAdder1_0_CO [get_bd_pins FullAdder1_0/CO] [get_bd_pins FullAdder1_1/CI]
  connect_bd_net -net FullAdder1_10_CO [get_bd_pins FullAdder1_10/CO] [get_bd_pins FullAdder1_11/CI]
  connect_bd_net -net FullAdder1_11_CO [get_bd_pins FullAdder1_11/CO] [get_bd_pins FullAdder1_12/CI]
  connect_bd_net -net FullAdder1_12_CO [get_bd_pins FullAdder1_12/CO] [get_bd_pins FullAdder1_13/CI]
  connect_bd_net -net FullAdder1_13_CO [get_bd_pins FullAdder1_13/CO] [get_bd_pins FullAdder1_14/CI]
  connect_bd_net -net FullAdder1_14_CO [get_bd_pins FullAdder1_14/CO] [get_bd_pins FullAdder1_15/CI]
  connect_bd_net -net FullAdder1_15_CO [get_bd_pins FullAdder1_15/CO] [get_bd_pins FullAdder1_16/CI]
  connect_bd_net -net FullAdder1_16_CO [get_bd_pins FullAdder1_16/CO] [get_bd_pins FullAdder1_17/CI]
  connect_bd_net -net FullAdder1_17_CO [get_bd_pins FullAdder1_17/CO] [get_bd_pins FullAdder1_18/CI]
  connect_bd_net -net FullAdder1_18_CO [get_bd_pins FullAdder1_18/CO] [get_bd_pins FullAdder1_19/CI]
  connect_bd_net -net FullAdder1_19_CO [get_bd_pins FullAdder1_19/CO] [get_bd_pins FullAdder1_20/CI]
  connect_bd_net -net FullAdder1_1_CO [get_bd_pins FullAdder1_1/CO] [get_bd_pins FullAdder1_2/CI]
  connect_bd_net -net FullAdder1_20_CO [get_bd_pins FullAdder1_20/CO] [get_bd_pins FullAdder1_21/CI]
  connect_bd_net -net FullAdder1_21_CO [get_bd_pins FullAdder1_21/CO] [get_bd_pins FullAdder1_22/CI]
  connect_bd_net -net FullAdder1_22_CO [get_bd_pins FullAdder1_22/CO] [get_bd_pins FullAdder1_23/CI]
  connect_bd_net -net FullAdder1_23_CO [get_bd_pins FullAdder1_23/CO] [get_bd_pins FullAdder1_24/CI]
  connect_bd_net -net FullAdder1_24_CO [get_bd_pins FullAdder1_24/CO] [get_bd_pins FullAdder1_25/CI]
  connect_bd_net -net FullAdder1_25_CO [get_bd_pins FullAdder1_25/CO] [get_bd_pins FullAdder1_26/CI]
  connect_bd_net -net FullAdder1_26_CO [get_bd_pins FullAdder1_26/CO] [get_bd_pins FullAdder1_27/CI]
  connect_bd_net -net FullAdder1_27_CO [get_bd_pins FullAdder1_27/CO] [get_bd_pins FullAdder1_28/CI]
  connect_bd_net -net FullAdder1_28_CO [get_bd_pins FullAdder1_28/CO] [get_bd_pins FullAdder1_29/CI]
  connect_bd_net -net FullAdder1_29_CO [get_bd_pins FullAdder1_29/CO] [get_bd_pins FullAdder1_30/CI]
  connect_bd_net -net FullAdder1_2_CO [get_bd_pins FullAdder1_2/CO] [get_bd_pins FullAdder1_3/CI]
  connect_bd_net -net FullAdder1_30_CO [get_bd_pins FullAdder1_30/CO] [get_bd_pins FullAdder1_31/CI]
  connect_bd_net -net FullAdder1_3_CO [get_bd_pins FullAdder1_3/CO] [get_bd_pins FullAdder1_4/CI]
  connect_bd_net -net FullAdder1_4_CO [get_bd_pins FullAdder1_4/CO] [get_bd_pins FullAdder1_5/CI]
  connect_bd_net -net FullAdder1_5_CO [get_bd_pins FullAdder1_5/CO] [get_bd_pins FullAdder1_6/CI]
  connect_bd_net -net FullAdder1_6_CO [get_bd_pins FullAdder1_6/CO] [get_bd_pins FullAdder1_7/CI]
  connect_bd_net -net FullAdder1_7_CO [get_bd_pins FullAdder1_7/CO] [get_bd_pins FullAdder1_8/CI]
  connect_bd_net -net FullAdder1_8_CO [get_bd_pins FullAdder1_8/CO] [get_bd_pins FullAdder1_9/CI]
  connect_bd_net -net FullAdder1_9_CO [get_bd_pins FullAdder1_10/CI] [get_bd_pins FullAdder1_9/CO]

  # Create address segments


  # Restore current instance
  current_bd_instance $oldCurInst

  validate_bd_design
  save_bd_design
}
# End of create_root_design()


##################################################################
# MAIN FLOW
##################################################################

create_root_design ""


