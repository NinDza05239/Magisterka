################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf *.sni *.dbg *.lst *.lis *.lpp *.map *.x *.lbp src/*.src src/*.p src/*.pp src/*.mrc *.bls *.libelf *.lbk *.abs *.fsy

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include RX63N_UART/subdir.mk
-include RX63N_CPU/subdir.mk
-include RX63N_CAN/subdir.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_UPPER_DEPS)),)
-include $(CC_UPPER_DEPS)
endif
ifneq ($(strip $(C++_UPPER_DEPS)),)
-include $(C++_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_UPPER_DEPS)),)
-include $(CXX_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_UPPER_DEPS)),)
-include $(CPP_UPPER_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CP_DEPS)),)
-include $(CP_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(CP_UPPER_DEPS)),)
-include $(CP_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(OBJ_DEPS)),)
-include $(OBJ_DEPS)
endif
ifneq ($(strip $(ABS_DEPS)),)
-include $(ABS_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(O_DEPS)),)
-include $(O_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

ifneq ($(strip $(SRC_UPPER_SRCS)),)
ALL_ASMS += $(SRC_UPPER_SRCS) 
endif
ifneq ($(strip $(SRC_SRCS)),)
ALL_ASMS += $(SRC_SRCS) 
endif
ifneq ($(strip $(S_UPPER_SRCS)),)
ALL_ASMS += $(S_UPPER_SRCS) 
endif
ifneq ($(strip $(S_SRCS)),)
ALL_ASMS += $(S_SRCS) 
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
CONVERTOR_OUTPUT_OUTPUTS += \
OBMII.mot \

LINKER_OUTPUT_OUTPUTS += \
OBMII.abs \

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
OBMII.lib \

# All Target
all: OBMII.mot
	@echo 'Build complete.'

# Tool invocations
OBMII.mot: $(LINKER_OUTPUT_OUTPUTS)
	@echo 'Invoking: Converter'
	rlink   "D:\Git\Magisterka\OBMII\HardwareDebug\OBMII.abs" -form=stype  -output="D:\Git\Magisterka\OBMII\HardwareDebug\OBMII.mot"
	@echo 'Finished building target:'
	@echo.
	$(MAKE) --no-print-directory post-build

OBMII.abs: $(OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(ALL_ASMS) 
	@echo 'Invoking: Linker'
	@echo 'Building target:'
	rlink  -subcommand="LinkerSubCommand.tmp"  -library="D:\Git\MAGIST~1\OBMII\HARDWA~2\OBMII.lib" -list="OBMII.map" -show -nooptimize -debug -output="D:\Git\Magisterka\OBMII\HardwareDebug\OBMII.abs" -rom=D=R,D_1=R_1,D_2=R_2 -nocompress -nomessage -nologo
	@echo 'Finished building:'
	@echo.

OBMII.lib:  
	@echo 'Invoking: Standard Library'
	lbgrx -lang=c99 -head=runtime,stdio,stdlib,string,new -isa=rxv1 -exception -optimize=0 -fpu -output="OBMII.lib"
	@echo 'Finished building:'
	@echo.

# Other Targets
clean:
	-$(RM) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(CONVERTOR_OUTPUT_OUTPUTS) 
	-rm -rf "src"/*.obj "src"/*.d "src"/*.src "src"/*.p "src"/*.pp "src"/*.mrc "src"/*.prn
	-rm -rf "RX63N_UART"/*.obj "RX63N_UART"/*.d "RX63N_UART"/*.src "RX63N_UART"/*.p "RX63N_UART"/*.pp "RX63N_UART"/*.mrc "RX63N_UART"/*.prn
	-rm -rf "RX63N_CPU"/*.obj "RX63N_CPU"/*.d "RX63N_CPU"/*.src "RX63N_CPU"/*.p "RX63N_CPU"/*.pp "RX63N_CPU"/*.mrc "RX63N_CPU"/*.prn
	-rm -rf "RX63N_CAN"/*.obj "RX63N_CAN"/*.d "RX63N_CAN"/*.src "RX63N_CAN"/*.p "RX63N_CAN"/*.pp "RX63N_CAN"/*.mrc "RX63N_CAN"/*.prn
	@echo.
	@echo 'Clean complete.'

post-build:
	@echo.
	-C:\Renesas\E2_STU~1\DEBUGC~1\RX\RX_CON~1.EXE OBMII.abs OBMII.x
	@echo.

.PHONY: all clean dependents $(LINKER_OUTPUT_OUTPUTS)
.SECONDARY: post-build

-include ../makefile.targets
