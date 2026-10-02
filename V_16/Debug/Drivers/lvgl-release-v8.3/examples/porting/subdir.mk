################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl-release-v8.3/examples/porting/lv_port_disp_template.c \
../Drivers/lvgl-release-v8.3/examples/porting/lv_port_fs_template.c \
../Drivers/lvgl-release-v8.3/examples/porting/lv_port_indev_template.c 

OBJS += \
./Drivers/lvgl-release-v8.3/examples/porting/lv_port_disp_template.o \
./Drivers/lvgl-release-v8.3/examples/porting/lv_port_fs_template.o \
./Drivers/lvgl-release-v8.3/examples/porting/lv_port_indev_template.o 

C_DEPS += \
./Drivers/lvgl-release-v8.3/examples/porting/lv_port_disp_template.d \
./Drivers/lvgl-release-v8.3/examples/porting/lv_port_fs_template.d \
./Drivers/lvgl-release-v8.3/examples/porting/lv_port_indev_template.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl-release-v8.3/examples/porting/%.o Drivers/lvgl-release-v8.3/examples/porting/%.su Drivers/lvgl-release-v8.3/examples/porting/%.cyclo: ../Drivers/lvgl-release-v8.3/examples/porting/%.c Drivers/lvgl-release-v8.3/examples/porting/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/linep/Desktop/BLDC_stm/V_16/Drivers/UI" -I"C:/Users/linep/Desktop/BLDC_stm/V_16/Drivers/lvgl-release-v8.3" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/linep/Desktop/BLDC_stm/V_16/User_Code/dev" -I"C:/Users/linep/Desktop/BLDC_stm/V_16/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-porting

clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-porting:
	-$(RM) ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_disp_template.cyclo ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_disp_template.d ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_disp_template.o ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_disp_template.su ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_fs_template.cyclo ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_fs_template.d ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_fs_template.o ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_fs_template.su ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_indev_template.cyclo ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_indev_template.d ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_indev_template.o ./Drivers/lvgl-release-v8.3/examples/porting/lv_port_indev_template.su

.PHONY: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-porting

