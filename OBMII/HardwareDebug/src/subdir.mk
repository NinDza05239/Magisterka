################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\src/OBMII.cpp 

C_SRCS += \
..\src/dbsct.c \
..\src/interrupt_handlers.c \
..\src/reset_program.c \
..\src/sbrk.c \
..\src/vector_table.c 

C_DEPS += \
./src/dbsct.d \
./src/interrupt_handlers.d \
./src/reset_program.d \
./src/sbrk.d \
./src/vector_table.d 

OBJS += \
./src/OBMII.obj \
./src/dbsct.obj \
./src/interrupt_handlers.obj \
./src/reset_program.obj \
./src/sbrk.obj \
./src/vector_table.obj 

CPP_DEPS += \
./src/OBMII.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.cpp
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=cpp  -exception  -include="C:\PROGRA~2\Renesas\RX\2_4_1/include","D:\Git\Magisterka\OBMII\Interfaces","D:\Git\Magisterka\OBMII\ActionFactory","D:\Git\Magisterka\OBMII\OnBoardMonitorApi","D:\Git\Magisterka\OBMII\RX63N_CAN","D:\Git\Magisterka\OBMII\RX63N_CPU","D:\Git\Magisterka\OBMII\RX63N_UART","D:\Git\Magisterka\OBMII\Tests","D:\Git\Magisterka\OBMII\Transmitter","D:\Git\Magisterka\OBMII\src"  -debug -isa=rxv1 -optimize=0 -fpu -alias=noansi -nologo  -define=__RX   "$<"
	ccrx -lang=cpp -output=obj="$(@:%.d=%.obj)" -exception  -include="C:\PROGRA~2\Renesas\RX\2_4_1/include","D:\Git\Magisterka\OBMII\Interfaces","D:\Git\Magisterka\OBMII\ActionFactory","D:\Git\Magisterka\OBMII\OnBoardMonitorApi","D:\Git\Magisterka\OBMII\RX63N_CAN","D:\Git\Magisterka\OBMII\RX63N_CPU","D:\Git\Magisterka\OBMII\RX63N_UART","D:\Git\Magisterka\OBMII\Tests","D:\Git\Magisterka\OBMII\Transmitter","D:\Git\Magisterka\OBMII\src"  -debug -isa=rxv1 -optimize=0 -fpu -alias=noansi -nologo  -define=__RX   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

src/%.obj: ../src/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=c99   -include="C:\PROGRA~2\Renesas\RX\2_4_1/include","D:\Git\Magisterka\OBMII\Interfaces","D:\Git\Magisterka\OBMII\ActionFactory","D:\Git\Magisterka\OBMII\OnBoardMonitorApi","D:\Git\Magisterka\OBMII\RX63N_CAN","D:\Git\Magisterka\OBMII\RX63N_CPU","D:\Git\Magisterka\OBMII\RX63N_UART","D:\Git\Magisterka\OBMII\Tests","D:\Git\Magisterka\OBMII\Transmitter","D:\Git\Magisterka\OBMII\src"  -debug -isa=rxv1 -optimize=0 -fpu -alias=noansi -nologo  -define=__RX   "$<"
	ccrx -lang=c99 -output=obj="$(@:%.d=%.obj)"  -include="C:\PROGRA~2\Renesas\RX\2_4_1/include","D:\Git\Magisterka\OBMII\Interfaces","D:\Git\Magisterka\OBMII\ActionFactory","D:\Git\Magisterka\OBMII\OnBoardMonitorApi","D:\Git\Magisterka\OBMII\RX63N_CAN","D:\Git\Magisterka\OBMII\RX63N_CPU","D:\Git\Magisterka\OBMII\RX63N_UART","D:\Git\Magisterka\OBMII\Tests","D:\Git\Magisterka\OBMII\Transmitter","D:\Git\Magisterka\OBMII\src"  -debug -isa=rxv1 -optimize=0 -fpu -alias=noansi -nologo  -define=__RX   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

