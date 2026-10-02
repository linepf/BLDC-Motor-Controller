################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_1.c \
../Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_2.c \
../Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_approve.c 

OBJS += \
./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_1.o \
./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_2.o \
./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_approve.o 

C_DEPS += \
./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_1.d \
./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_2.d \
./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_approve.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl-release-v8.3/examples/libs/rlottie/%.o Drivers/lvgl-release-v8.3/examples/libs/rlottie/%.su Drivers/lvgl-release-v8.3/examples/libs/rlottie/%.cyclo: ../Drivers/lvgl-release-v8.3/examples/libs/rlottie/%.c Drivers/lvgl-release-v8.3/examples/libs/rlottie/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/linep/Desktop/BLDC_stm/V_18/Drivers/UI" -I"C:/Users/linep/Desktop/BLDC_stm/V_18/Drivers/lvgl-release-v8.3" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/linep/Desktop/BLDC_stm/V_18/User_Code/dev" -I"C:/Users/linep/Desktop/BLDC_stm/V_18/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-libs-2f-rlottie

clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-libs-2f-rlottie:
	-$(RM) ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_1.cyclo ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_1.d ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_1.o ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_1.su ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_2.cyclo ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_2.d ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_2.o ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_2.su ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_approve.cyclo ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_approve.d ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_approve.o ./Drivers/lvgl-release-v8.3/examples/libs/rlottie/lv_example_rlottie_approve.su

.PHONY: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-libs-2f-rlottie

