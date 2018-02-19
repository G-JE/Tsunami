################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
C:/Users/ericksong/Downloads/SDK_2.3.0_FRDM-K66F/devices/MK66F18/drivers/fsl_dac.c \
../drivers/fsl_dmamux.c \
../drivers/fsl_dspi.c \
../drivers/fsl_edma.c \
../drivers/fsl_flash.c \
C:/Users/ericksong/Downloads/SDK_2.3.0_FRDM-K66F/devices/MK66F18/drivers/fsl_ftm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_sai.c \
../drivers/fsl_sai_edma.c \
../drivers/fsl_sdhc.c \
../drivers/fsl_smc.c \
../drivers/fsl_sysmpu.c \
../drivers/fsl_uart.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_dac.o \
./drivers/fsl_dmamux.o \
./drivers/fsl_dspi.o \
./drivers/fsl_edma.o \
./drivers/fsl_flash.o \
./drivers/fsl_ftm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_sai.o \
./drivers/fsl_sai_edma.o \
./drivers/fsl_sdhc.o \
./drivers/fsl_smc.o \
./drivers/fsl_sysmpu.o \
./drivers/fsl_uart.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_dac.d \
./drivers/fsl_dmamux.d \
./drivers/fsl_dspi.d \
./drivers/fsl_edma.d \
./drivers/fsl_flash.d \
./drivers/fsl_ftm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_sai.d \
./drivers/fsl_sai_edma.d \
./drivers/fsl_sdhc.d \
./drivers/fsl_smc.d \
./drivers/fsl_sysmpu.d \
./drivers/fsl_uart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DFRDM_K66F -DARM_MATH_CM4 -DFREEDOM -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\board" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\source" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\drivers" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\CMSIS" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\sdmmc\inc" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\fatfs\fatfs_include" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\startup" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\utilities" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\codec" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\sdmmc\port" -O1 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/fsl_dac.o: C:/Users/ericksong/Downloads/SDK_2.3.0_FRDM-K66F/devices/MK66F18/drivers/fsl_dac.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DFRDM_K66F -DARM_MATH_CM4 -DFREEDOM -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\board" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\source" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\drivers" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\CMSIS" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\sdmmc\inc" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\fatfs\fatfs_include" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\startup" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\utilities" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\codec" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\sdmmc\port" -O1 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/fsl_ftm.o: C:/Users/ericksong/Downloads/SDK_2.3.0_FRDM-K66F/devices/MK66F18/drivers/fsl_ftm.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DFRDM_K66F -DARM_MATH_CM4 -DFREEDOM -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\board" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\source" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\drivers" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\CMSIS" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\sdmmc\inc" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\fatfs\fatfs_include" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\startup" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\utilities" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\codec" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\sdmmc\port" -O1 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


