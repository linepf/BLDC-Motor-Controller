################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User_Code/dev/DPS.c \
../User_Code/dev/PID.c \
../User_Code/dev/UART.c \
../User_Code/dev/adc.c \
../User_Code/dev/common.c \
../User_Code/dev/motor.c 

OBJS += \
./User_Code/dev/DPS.o \
./User_Code/dev/PID.o \
./User_Code/dev/UART.o \
./User_Code/dev/adc.o \
./User_Code/dev/common.o \
./User_Code/dev/motor.o 

C_DEPS += \
./User_Code/dev/DPS.d \
./User_Code/dev/PID.d \
./User_Code/dev/UART.d \
./User_Code/dev/adc.d \
./User_Code/dev/common.d \
./User_Code/dev/motor.d 


# Each subdirectory must supply rules for building sources it contributes
User_Code/dev/%.o User_Code/dev/%.su User_Code/dev/%.cyclo: ../User_Code/dev/%.c User_Code/dev/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/linep/Desktop/BLDC_stm/V_16/Drivers/UI" -I"C:/Users/linep/Desktop/BLDC_stm/V_16/Drivers/lvgl-release-v8.3" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/linep/Desktop/BLDC_stm/V_16/User_Code/dev" -I"C:/Users/linep/Desktop/BLDC_stm/V_16/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User_Code-2f-dev

clean-User_Code-2f-dev:
	-$(RM) ./User_Code/dev/DPS.cyclo ./User_Code/dev/DPS.d ./User_Code/dev/DPS.o ./User_Code/dev/DPS.su ./User_Code/dev/PID.cyclo ./User_Code/dev/PID.d ./User_Code/dev/PID.o ./User_Code/dev/PID.su ./User_Code/dev/UART.cyclo ./User_Code/dev/UART.d ./User_Code/dev/UART.o ./User_Code/dev/UART.su ./User_Code/dev/adc.cyclo ./User_Code/dev/adc.d ./User_Code/dev/adc.o ./User_Code/dev/adc.su ./User_Code/dev/common.cyclo ./User_Code/dev/common.d ./User_Code/dev/common.o ./User_Code/dev/common.su ./User_Code/dev/motor.cyclo ./User_Code/dev/motor.d ./User_Code/dev/motor.o ./User_Code/dev/motor.su

.PHONY: clean-User_Code-2f-dev

