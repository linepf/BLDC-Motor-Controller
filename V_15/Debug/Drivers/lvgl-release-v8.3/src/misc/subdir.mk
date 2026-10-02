################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl-release-v8.3/src/misc/lv_anim.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_anim_timeline.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_area.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_async.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_bidi.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_color.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_fs.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_gc.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_ll.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_log.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_lru.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_math.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_mem.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_printf.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_style.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_style_gen.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_templ.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_timer.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_tlsf.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_txt.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_txt_ap.c \
../Drivers/lvgl-release-v8.3/src/misc/lv_utils.c 

OBJS += \
./Drivers/lvgl-release-v8.3/src/misc/lv_anim.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_anim_timeline.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_area.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_async.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_bidi.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_color.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_fs.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_gc.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_ll.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_log.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_lru.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_math.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_mem.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_printf.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_style.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_style_gen.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_templ.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_timer.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_tlsf.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_txt.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_txt_ap.o \
./Drivers/lvgl-release-v8.3/src/misc/lv_utils.o 

C_DEPS += \
./Drivers/lvgl-release-v8.3/src/misc/lv_anim.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_anim_timeline.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_area.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_async.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_bidi.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_color.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_fs.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_gc.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_ll.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_log.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_lru.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_math.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_mem.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_printf.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_style.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_style_gen.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_templ.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_timer.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_tlsf.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_txt.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_txt_ap.d \
./Drivers/lvgl-release-v8.3/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl-release-v8.3/src/misc/%.o Drivers/lvgl-release-v8.3/src/misc/%.su Drivers/lvgl-release-v8.3/src/misc/%.cyclo: ../Drivers/lvgl-release-v8.3/src/misc/%.c Drivers/lvgl-release-v8.3/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I"C:/Users/linep/Desktop/BLDC_stm/V_15/Drivers/UI" -I"C:/Users/linep/Desktop/BLDC_stm/V_15/Drivers/lvgl-release-v8.3" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/linep/Desktop/BLDC_stm/V_15/User_Code/dev" -I"C:/Users/linep/Desktop/BLDC_stm/V_15/User_Code/user_main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-misc

clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-misc:
	-$(RM) ./Drivers/lvgl-release-v8.3/src/misc/lv_anim.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_anim.d ./Drivers/lvgl-release-v8.3/src/misc/lv_anim.o ./Drivers/lvgl-release-v8.3/src/misc/lv_anim.su ./Drivers/lvgl-release-v8.3/src/misc/lv_anim_timeline.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_anim_timeline.d ./Drivers/lvgl-release-v8.3/src/misc/lv_anim_timeline.o ./Drivers/lvgl-release-v8.3/src/misc/lv_anim_timeline.su ./Drivers/lvgl-release-v8.3/src/misc/lv_area.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_area.d ./Drivers/lvgl-release-v8.3/src/misc/lv_area.o ./Drivers/lvgl-release-v8.3/src/misc/lv_area.su ./Drivers/lvgl-release-v8.3/src/misc/lv_async.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_async.d ./Drivers/lvgl-release-v8.3/src/misc/lv_async.o ./Drivers/lvgl-release-v8.3/src/misc/lv_async.su ./Drivers/lvgl-release-v8.3/src/misc/lv_bidi.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_bidi.d ./Drivers/lvgl-release-v8.3/src/misc/lv_bidi.o ./Drivers/lvgl-release-v8.3/src/misc/lv_bidi.su ./Drivers/lvgl-release-v8.3/src/misc/lv_color.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_color.d ./Drivers/lvgl-release-v8.3/src/misc/lv_color.o ./Drivers/lvgl-release-v8.3/src/misc/lv_color.su ./Drivers/lvgl-release-v8.3/src/misc/lv_fs.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_fs.d ./Drivers/lvgl-release-v8.3/src/misc/lv_fs.o ./Drivers/lvgl-release-v8.3/src/misc/lv_fs.su ./Drivers/lvgl-release-v8.3/src/misc/lv_gc.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_gc.d ./Drivers/lvgl-release-v8.3/src/misc/lv_gc.o ./Drivers/lvgl-release-v8.3/src/misc/lv_gc.su ./Drivers/lvgl-release-v8.3/src/misc/lv_ll.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_ll.d ./Drivers/lvgl-release-v8.3/src/misc/lv_ll.o ./Drivers/lvgl-release-v8.3/src/misc/lv_ll.su ./Drivers/lvgl-release-v8.3/src/misc/lv_log.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_log.d ./Drivers/lvgl-release-v8.3/src/misc/lv_log.o ./Drivers/lvgl-release-v8.3/src/misc/lv_log.su ./Drivers/lvgl-release-v8.3/src/misc/lv_lru.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_lru.d ./Drivers/lvgl-release-v8.3/src/misc/lv_lru.o ./Drivers/lvgl-release-v8.3/src/misc/lv_lru.su ./Drivers/lvgl-release-v8.3/src/misc/lv_math.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_math.d ./Drivers/lvgl-release-v8.3/src/misc/lv_math.o ./Drivers/lvgl-release-v8.3/src/misc/lv_math.su ./Drivers/lvgl-release-v8.3/src/misc/lv_mem.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_mem.d ./Drivers/lvgl-release-v8.3/src/misc/lv_mem.o ./Drivers/lvgl-release-v8.3/src/misc/lv_mem.su ./Drivers/lvgl-release-v8.3/src/misc/lv_printf.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_printf.d ./Drivers/lvgl-release-v8.3/src/misc/lv_printf.o ./Drivers/lvgl-release-v8.3/src/misc/lv_printf.su ./Drivers/lvgl-release-v8.3/src/misc/lv_style.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_style.d ./Drivers/lvgl-release-v8.3/src/misc/lv_style.o ./Drivers/lvgl-release-v8.3/src/misc/lv_style.su ./Drivers/lvgl-release-v8.3/src/misc/lv_style_gen.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_style_gen.d ./Drivers/lvgl-release-v8.3/src/misc/lv_style_gen.o ./Drivers/lvgl-release-v8.3/src/misc/lv_style_gen.su ./Drivers/lvgl-release-v8.3/src/misc/lv_templ.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_templ.d ./Drivers/lvgl-release-v8.3/src/misc/lv_templ.o ./Drivers/lvgl-release-v8.3/src/misc/lv_templ.su ./Drivers/lvgl-release-v8.3/src/misc/lv_timer.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_timer.d ./Drivers/lvgl-release-v8.3/src/misc/lv_timer.o ./Drivers/lvgl-release-v8.3/src/misc/lv_timer.su ./Drivers/lvgl-release-v8.3/src/misc/lv_tlsf.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_tlsf.d ./Drivers/lvgl-release-v8.3/src/misc/lv_tlsf.o ./Drivers/lvgl-release-v8.3/src/misc/lv_tlsf.su ./Drivers/lvgl-release-v8.3/src/misc/lv_txt.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_txt.d ./Drivers/lvgl-release-v8.3/src/misc/lv_txt.o ./Drivers/lvgl-release-v8.3/src/misc/lv_txt.su ./Drivers/lvgl-release-v8.3/src/misc/lv_txt_ap.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_txt_ap.d ./Drivers/lvgl-release-v8.3/src/misc/lv_txt_ap.o ./Drivers/lvgl-release-v8.3/src/misc/lv_txt_ap.su ./Drivers/lvgl-release-v8.3/src/misc/lv_utils.cyclo ./Drivers/lvgl-release-v8.3/src/misc/lv_utils.d ./Drivers/lvgl-release-v8.3/src/misc/lv_utils.o ./Drivers/lvgl-release-v8.3/src/misc/lv_utils.su

.PHONY: clean-Drivers-2f-lvgl-2d-release-2d-v8-2e-3-2f-src-2f-misc

