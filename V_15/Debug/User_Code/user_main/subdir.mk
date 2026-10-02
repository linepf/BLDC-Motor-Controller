################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User_Code/user_main/interrupt.c \
../User_Code/user_main/task.c \
../User_Code/user_main/user_main.c 

OBJS += \
./User_Code/user_main/interrupt.o \
./User_Code/user_main/task.o \
./User_Code/user_main/user_main.o 

C_DEPS += \
./User_Code/user_main/interrupt.d \
./User_Code/user_main/task.d \
./User_Code/user_main/user_main.d 


# Each subdirectory must supply rules for building sources it contributes
User_Code/user_main/%.o User_Code/user_main/%.su User_Code/user_main/%.cyclo: ../User_Code/user_main/%.c User_Code/user_main/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/linep/Desktop/BLDC_stm/V_15/Drivers/UI" -I"C:/Users/linep/Desktop/BLDC_stm/V_15/Drivers/lvgl-release-v8.3" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/linep/Desktop/BLDC_stm/V_15/User_Code/dev" -I"C:/Users/linep/Desktop/BLDC_stm/V_15/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User_Code-2f-user_main

clean-User_Code-2f-user_main:
	-$(RM) ./User_Code/user_main/interrupt.cyclo ./User_Code/user_main/interrupt.d ./User_Code/user_main/interrupt.o ./User_Code/user_main/interrupt.su ./User_Code/user_main/task.cyclo ./User_Code/user_main/task.d ./User_Code/user_main/task.o ./User_Code/user_main/task.su ./User_Code/user_main/user_main.cyclo ./User_Code/user_main/user_main.d ./User_Code/user_main/user_main.o ./User_Code/user_main/user_main.su

.PHONY: clean-User_Code-2f-user_main

