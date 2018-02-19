################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/system_MK66F18.c 

OBJS += \
./CMSIS/system_MK66F18.o 

C_DEPS += \
./CMSIS/system_MK66F18.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/%.o: ../CMSIS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__USE_CMSIS -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\board" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\codec" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\source" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\drivers" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\CMSIS" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\utilities" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\dma_manager" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\fatfs" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\fatfs\fatfs_include" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\sdmmc\inc" -I"C:\Users\ericksong\Documents\Tsunami\WaveBee\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


