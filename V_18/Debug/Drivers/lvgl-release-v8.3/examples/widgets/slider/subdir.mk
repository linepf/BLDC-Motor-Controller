################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_1.c \
../Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_2.c \
../Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_3.c 

OBJS += \
./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_1.o \
./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_2.o \
./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_3.o 

C_DEPS += \
./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_1.d \
./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_2.d \
./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_3.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl-release-v8.3/examples/widgets/slider/%.o Drivers/lvgl-release-v8.3/examples/widgets/slider/%.su Drivers/lvgl-release-v8.3/examples/widgets/slider/%.cyclo: ../Drivers/lvgl-release-v8.3/examples/widgets/slider/%.c Drivers/lvgl-release-v8.3/examples/widgets/slider/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/linep/Desktop/BLDC_stm/V_17/Drivers/UI" -I"C:/Users/linep/Desktop/BLDC_stm/V_17/Drivers/lvgl-release-v8.3" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/linep/Desktop/BLDC_stm/V_17/User_Code/dev" -I"C:/Users/linep/Desktop/BLDC_stm/V_17/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-widgets-2f-slider

clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-widgets-2f-slider:
	-$(RM) ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_1.cyclo ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_1.d ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_1.o ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_1.su ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_2.cyclo ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_2.d ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_2.o ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_2.su ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_3.cyclo ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_3.d ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_3.o ./Drivers/lvgl-release-v8.3/examples/widgets/slider/lv_example_slider_3.su

.PHONY: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-widgets-2f-slider

