################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl-release-v8.3/demos/music/lv_demo_music.c \
../Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_list.c \
../Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_main.c 

OBJS += \
./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music.o \
./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_list.o \
./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_main.o 

C_DEPS += \
./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music.d \
./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_list.d \
./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_main.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl-release-v8.3/demos/music/%.o Drivers/lvgl-release-v8.3/demos/music/%.su Drivers/lvgl-release-v8.3/demos/music/%.cyclo: ../Drivers/lvgl-release-v8.3/demos/music/%.c Drivers/lvgl-release-v8.3/demos/music/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/linep/Desktop/BLDC_stm/V_16/Drivers/UI" -I"C:/Users/linep/Desktop/BLDC_stm/V_16/Drivers/lvgl-release-v8.3" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/linep/Desktop/BLDC_stm/V_16/User_Code/dev" -I"C:/Users/linep/Desktop/BLDC_stm/V_16/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-demos-2f-music

clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-demos-2f-music:
	-$(RM) ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music.cyclo ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music.d ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music.o ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music.su ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_list.cyclo ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_list.d ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_list.o ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_list.su ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_main.cyclo ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_main.d ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_main.o ./Drivers/lvgl-release-v8.3/demos/music/lv_demo_music_main.su

.PHONY: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-demos-2f-music

