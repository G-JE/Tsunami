################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include sdmmc/src/subdir.mk
-include sdmmc/port/subdir.mk
-include fatfs/fatfs_source/subdir.mk
-include drivers/subdir.mk
-include codec/subdir.mk
-include board/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: frdmk66f_demo_apps_sai.axf

# Tool invocations
frdmk66f_demo_apps_sai.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\ericksong\Documents\Tsunami\frdmk66f_demo_apps_sai\libs" -Xlinker -print-memory-usage -Xlinker --gc-sections -Xlinker -Map="frdmk66f_demo_apps_sai.map" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -T MK66FN2M0xxx18_flash_mcux.ld -L ../source -o "frdmk66f_demo_apps_sai.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) frdmk66f_demo_apps_sai.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "frdmk66f_demo_apps_sai.axf"; # arm-none-eabi-objcopy -v -O binary "frdmk66f_demo_apps_sai.axf" "frdmk66f_demo_apps_sai.bin" ; # checksum -p MK66FN2M0xxx18 -d "frdmk66f_demo_apps_sai.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
