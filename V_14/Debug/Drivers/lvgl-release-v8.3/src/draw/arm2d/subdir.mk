################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl-release-v8.3/src/draw/arm2d/lv_gpu_arm2d.c 

OBJS += \
./Drivers/lvgl-release-v8.3/src/draw/arm2d/lv_gpu_arm2d.o 

C_DEPS += \
./Drivers/lvgl-release-v8.3/src/draw/arm2d/lv_gpu_arm2d.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl-release-v8.3/src/draw/arm2d/%.o Drivers/lvgl-release-v8.3/src/draw/arm2d/%.su Drivers/lvgl-release-v8.3/src/draw/arm2d/%.cyclo: ../Drivers/lvgl-release-v8.3/src/draw/arm2d/%.c Drivers/lvgl-release-v8.3/src/draw/arm2d/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/Drivers/UI" -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/Drivers/lvgl-release-v8.3" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/User_Code/dev" -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-draw-2f-arm2d

clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-draw-2f-arm2d:
	-$(RM) ./Drivers/lvgl-release-v8.3/src/draw/arm2d/lv_gpu_arm2d.cyclo ./Drivers/lvgl-release-v8.3/src/draw/arm2d/lv_gpu_arm2d.d ./Drivers/lvgl-release-v8.3/src/draw/arm2d/lv_gpu_arm2d.o ./Drivers/lvgl-release-v8.3/src/draw/arm2d/lv_gpu_arm2d.su

.PHONY: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-draw-2f-arm2d

