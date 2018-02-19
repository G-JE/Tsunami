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
	arm-none-eabi-gcc -D__REDLIB__ -DFRDM_K66F -DARM_MATH_CM4 -DFREEDOM -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\board" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\source" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\drivers" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\CMSIS" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\sdmmc\inc" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\fatfs\fatfs_include" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\startup" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\utilities" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\codec" -I"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\sdmmc\port" -O1 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


