################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/lv_spinbox.c 

OBJS += \
./Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/lv_spinbox.o 

C_DEPS += \
./Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/lv_spinbox.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/%.o Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/%.su Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/%.cyclo: ../Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/%.c Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/linep/Desktop/BLDC_stm/V_17/Drivers/UI" -I"C:/Users/linep/Desktop/BLDC_stm/V_17/Drivers/lvgl-release-v8.3" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/linep/Desktop/BLDC_stm/V_17/User_Code/dev" -I"C:/Users/linep/Desktop/BLDC_stm/V_17/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-extra-2f-widgets-2f-spinbox

clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-extra-2f-widgets-2f-spinbox:
	-$(RM) ./Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/lv_spinbox.cyclo ./Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/lv_spinbox.d ./Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/lv_spinbox.o ./Drivers/lvgl-release-v8.3/src/extra/widgets/spinbox/lv_spinbox.su

.PHONY: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-extra-2f-widgets-2f-spinbox

