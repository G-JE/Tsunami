################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../fatfs/drivers/fsl_adc16.c \
../fatfs/drivers/fsl_clock.c \
../fatfs/drivers/fsl_common.c \
../fatfs/drivers/fsl_dac.c \
../fatfs/drivers/fsl_dmamux.c \
../fatfs/drivers/fsl_dspi.c \
../fatfs/drivers/fsl_edma.c \
../fatfs/drivers/fsl_flash.c \
../fatfs/drivers/fsl_ftm.c \
../fatfs/drivers/fsl_gpio.c \
../fatfs/drivers/fsl_i2c.c \
../fatfs/drivers/fsl_i2c_edma.c \
../fatfs/drivers/fsl_lpuart.c \
../fatfs/drivers/fsl_sai.c \
../fatfs/drivers/fsl_sai_edma.c \
../fatfs/drivers/fsl_sdhc.c \
../fatfs/drivers/fsl_sdramc.c \
../fatfs/drivers/fsl_smc.c \
../fatfs/drivers/fsl_uart.c 

OBJS += \
./fatfs/drivers/fsl_adc16.o \
./fatfs/drivers/fsl_clock.o \
./fatfs/drivers/fsl_common.o \
./fatfs/drivers/fsl_dac.o \
./fatfs/drivers/fsl_dmamux.o \
./fatfs/drivers/fsl_dspi.o \
./fatfs/drivers/fsl_edma.o \
./fatfs/drivers/fsl_flash.o \
./fatfs/drivers/fsl_ftm.o \
./fatfs/drivers/fsl_gpio.o \
./fatfs/drivers/fsl_i2c.o \
./fatfs/drivers/fsl_i2c_edma.o \
./fatfs/drivers/fsl_lpuart.o \
./fatfs/drivers/fsl_sai.o \
./fatfs/drivers/fsl_sai_edma.o \
./fatfs/drivers/fsl_sdhc.o \
./fatfs/drivers/fsl_sdramc.o \
./fatfs/drivers/fsl_smc.o \
./fatfs/drivers/fsl_uart.o 

C_DEPS += \
./fatfs/drivers/fsl_adc16.d \
./fatfs/drivers/fsl_clock.d \
./fatfs/drivers/fsl_common.d \
./fatfs/drivers/fsl_dac.d \
./fatfs/drivers/fsl_dmamux.d \
./fatfs/drivers/fsl_dspi.d \
./fatfs/drivers/fsl_edma.d \
./fatfs/drivers/fsl_flash.d \
./fatfs/drivers/fsl_ftm.d \
./fatfs/drivers/fsl_gpio.d \
./fatfs/drivers/fsl_i2c.d \
./fatfs/drivers/fsl_i2c_edma.d \
./fatfs/drivers/fsl_lpuart.d \
./fatfs/drivers/fsl_sai.d \
./fatfs/drivers/fsl_sai_edma.d \
./fatfs/drivers/fsl_sdhc.d \
./fatfs/drivers/fsl_sdramc.d \
./fatfs/drivers/fsl_smc.d \
./fatfs/drivers/fsl_uart.d 


# Each subdirectory must supply rules for building sources it contributes
fatfs/drivers/%.o: ../fatfs/drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__USE_CMSIS -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\board" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\codec" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\source" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\CMSIS" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\utilities" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\dma_manager" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\fatfs" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\fatfs\fatfs_include" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\sdmmc\inc" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


