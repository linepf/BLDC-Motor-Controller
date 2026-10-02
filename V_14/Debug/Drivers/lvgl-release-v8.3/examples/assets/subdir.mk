################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl-release-v8.3/examples/assets/animimg001.c \
../Drivers/lvgl-release-v8.3/examples/assets/animimg002.c \
../Drivers/lvgl-release-v8.3/examples/assets/animimg003.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_caret_down.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_alpha16.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_argb.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_chroma_keyed.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_indexed16.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_rgb.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_hand.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_skew_strip.c \
../Drivers/lvgl-release-v8.3/examples/assets/img_star.c \
../Drivers/lvgl-release-v8.3/examples/assets/imgbtn_left.c \
../Drivers/lvgl-release-v8.3/examples/assets/imgbtn_mid.c \
../Drivers/lvgl-release-v8.3/examples/assets/imgbtn_right.c 

OBJS += \
./Drivers/lvgl-release-v8.3/examples/assets/animimg001.o \
./Drivers/lvgl-release-v8.3/examples/assets/animimg002.o \
./Drivers/lvgl-release-v8.3/examples/assets/animimg003.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_caret_down.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_alpha16.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_argb.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_chroma_keyed.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_indexed16.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_rgb.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_hand.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_skew_strip.o \
./Drivers/lvgl-release-v8.3/examples/assets/img_star.o \
./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_left.o \
./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_mid.o \
./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_right.o 

C_DEPS += \
./Drivers/lvgl-release-v8.3/examples/assets/animimg001.d \
./Drivers/lvgl-release-v8.3/examples/assets/animimg002.d \
./Drivers/lvgl-release-v8.3/examples/assets/animimg003.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_caret_down.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_alpha16.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_argb.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_chroma_keyed.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_indexed16.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_rgb.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_hand.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_skew_strip.d \
./Drivers/lvgl-release-v8.3/examples/assets/img_star.d \
./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_left.d \
./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_mid.d \
./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_right.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl-release-v8.3/examples/assets/%.o Drivers/lvgl-release-v8.3/examples/assets/%.su Drivers/lvgl-release-v8.3/examples/assets/%.cyclo: ../Drivers/lvgl-release-v8.3/examples/assets/%.c Drivers/lvgl-release-v8.3/examples/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/Drivers/UI" -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/Drivers/lvgl-release-v8.3" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/User_Code/dev" -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-assets

clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-assets:
	-$(RM) ./Drivers/lvgl-release-v8.3/examples/assets/animimg001.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/animimg001.d ./Drivers/lvgl-release-v8.3/examples/assets/animimg001.o ./Drivers/lvgl-release-v8.3/examples/assets/animimg001.su ./Drivers/lvgl-release-v8.3/examples/assets/animimg002.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/animimg002.d ./Drivers/lvgl-release-v8.3/examples/assets/animimg002.o ./Drivers/lvgl-release-v8.3/examples/assets/animimg002.su ./Drivers/lvgl-release-v8.3/examples/assets/animimg003.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/animimg003.d ./Drivers/lvgl-release-v8.3/examples/assets/animimg003.o ./Drivers/lvgl-release-v8.3/examples/assets/animimg003.su ./Drivers/lvgl-release-v8.3/examples/assets/img_caret_down.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_caret_down.d ./Drivers/lvgl-release-v8.3/examples/assets/img_caret_down.o ./Drivers/lvgl-release-v8.3/examples/assets/img_caret_down.su ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_alpha16.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_alpha16.d ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_alpha16.o ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_alpha16.su ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_argb.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_argb.d ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_argb.o ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_argb.su ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_chroma_keyed.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_chroma_keyed.d ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_chroma_keyed.o ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_chroma_keyed.su ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_indexed16.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_indexed16.d ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_indexed16.o ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_indexed16.su ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_rgb.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_rgb.d ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_rgb.o ./Drivers/lvgl-release-v8.3/examples/assets/img_cogwheel_rgb.su ./Drivers/lvgl-release-v8.3/examples/assets/img_hand.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_hand.d ./Drivers/lvgl-release-v8.3/examples/assets/img_hand.o ./Drivers/lvgl-release-v8.3/examples/assets/img_hand.su ./Drivers/lvgl-release-v8.3/examples/assets/img_skew_strip.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_skew_strip.d ./Drivers/lvgl-release-v8.3/examples/assets/img_skew_strip.o ./Drivers/lvgl-release-v8.3/examples/assets/img_skew_strip.su ./Drivers/lvgl-release-v8.3/examples/assets/img_star.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/img_star.d ./Drivers/lvgl-release-v8.3/examples/assets/img_star.o ./Drivers/lvgl-release-v8.3/examples/assets/img_star.su ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_left.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_left.d ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_left.o ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_left.su ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_mid.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_mid.d ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_mid.o ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_mid.su ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_right.cyclo ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_right.d ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_right.o ./Drivers/lvgl-release-v8.3/examples/assets/imgbtn_right.su

.PHONY: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-examples-2f-assets

