################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/UI/images/ui_img_2011016454.c \
../Drivers/UI/images/ui_img_2077717688.c \
../Drivers/UI/images/ui_img_321913857.c \
../Drivers/UI/images/ui_img_539230787.c \
../Drivers/UI/images/ui_img_582887121.c \
../Drivers/UI/images/ui_img_856152372.c \
../Drivers/UI/images/ui_img_ffff_png.c 

OBJS += \
./Drivers/UI/images/ui_img_2011016454.o \
./Drivers/UI/images/ui_img_2077717688.o \
./Drivers/UI/images/ui_img_321913857.o \
./Drivers/UI/images/ui_img_539230787.o \
./Drivers/UI/images/ui_img_582887121.o \
./Drivers/UI/images/ui_img_856152372.o \
./Drivers/UI/images/ui_img_ffff_png.o 

C_DEPS += \
./Drivers/UI/images/ui_img_2011016454.d \
./Drivers/UI/images/ui_img_2077717688.d \
./Drivers/UI/images/ui_img_321913857.d \
./Drivers/UI/images/ui_img_539230787.d \
./Drivers/UI/images/ui_img_582887121.d \
./Drivers/UI/images/ui_img_856152372.d \
./Drivers/UI/images/ui_img_ffff_png.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/UI/images/%.o Drivers/UI/images/%.su Drivers/UI/images/%.cyclo: ../Drivers/UI/images/%.c Drivers/UI/images/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/Drivers/UI" -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/Drivers/lvgl-release-v8.3" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/User_Code/dev" -I"C:/Users/JJH/Desktop/BLDC_stm/V_13/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-UI-2f-images

clean-Drivers-2f-UI-2f-images:
	-$(RM) ./Drivers/UI/images/ui_img_2011016454.cyclo ./Drivers/UI/images/ui_img_2011016454.d ./Drivers/UI/images/ui_img_2011016454.o ./Drivers/UI/images/ui_img_2011016454.su ./Drivers/UI/images/ui_img_2077717688.cyclo ./Drivers/UI/images/ui_img_2077717688.d ./Drivers/UI/images/ui_img_2077717688.o ./Drivers/UI/images/ui_img_2077717688.su ./Drivers/UI/images/ui_img_321913857.cyclo ./Drivers/UI/images/ui_img_321913857.d ./Drivers/UI/images/ui_img_321913857.o ./Drivers/UI/images/ui_img_321913857.su ./Drivers/UI/images/ui_img_539230787.cyclo ./Drivers/UI/images/ui_img_539230787.d ./Drivers/UI/images/ui_img_539230787.o ./Drivers/UI/images/ui_img_539230787.su ./Drivers/UI/images/ui_img_582887121.cyclo ./Drivers/UI/images/ui_img_582887121.d ./Drivers/UI/images/ui_img_582887121.o ./Drivers/UI/images/ui_img_582887121.su ./Drivers/UI/images/ui_img_856152372.cyclo ./Drivers/UI/images/ui_img_856152372.d ./Drivers/UI/images/ui_img_856152372.o ./Drivers/UI/images/ui_img_856152372.su ./Drivers/UI/images/ui_img_ffff_png.cyclo ./Drivers/UI/images/ui_img_ffff_png.d ./Drivers/UI/images/ui_img_ffff_png.o ./Drivers/UI/images/ui_img_ffff_png.su

.PHONY: clean-Drivers-2f-UI-2f-images

