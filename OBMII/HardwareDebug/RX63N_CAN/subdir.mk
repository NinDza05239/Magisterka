################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\RX63N_CAN/RX63N_CAN.cpp 

OBJS += \
./RX63N_CAN/RX63N_CAN.obj 

CPP_DEPS += \
./RX63N_CAN/RX63N_CAN.d 


# Each subdirectory must supply rules for building sources it contributes
RX63N_CAN/%.obj: ../RX63N_CAN/%.cpp
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=cpp  -exception  -include="C:\PROGRA~2\Renesas\RX\2_4_1/include","D:\Git\Magisterka\OBMII\Interfaces","D:\Git\Magisterka\OBMII\ActionFactory","D:\Git\Magisterka\OBMII\OnBoardMonitorApi","D:\Git\Magisterka\OBMII\RX63N_CAN","D:\Git\Magisterka\OBMII\RX63N_CPU","D:\Git\Magisterka\OBMII\RX63N_UART","D:\Git\Magisterka\OBMII\Tests","D:\Git\Magisterka\OBMII\Transmitter","D:\Git\Magisterka\OBMII\src"  -debug -isa=rxv1 -optimize=0 -fpu -alias=noansi -nologo  -define=__RX   "$<"
	ccrx -lang=cpp -output=obj="$(@:%.d=%.obj)" -exception  -include="C:\PROGRA~2\Renesas\RX\2_4_1/include","D:\Git\Magisterka\OBMII\Interfaces","D:\Git\Magisterka\OBMII\ActionFactory","D:\Git\Magisterka\OBMII\OnBoardMonitorApi","D:\Git\Magisterka\OBMII\RX63N_CAN","D:\Git\Magisterka\OBMII\RX63N_CPU","D:\Git\Magisterka\OBMII\RX63N_UART","D:\Git\Magisterka\OBMII\Tests","D:\Git\Magisterka\OBMII\Transmitter","D:\Git\Magisterka\OBMII\src"  -debug -isa=rxv1 -optimize=0 -fpu -alias=noansi -nologo  -define=__RX   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.

