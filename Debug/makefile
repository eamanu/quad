################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include uart/subdir.mk
-include i2c/subdir.mk
-include adcs/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
quadcopter_dev.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: quadcopter_dev.elf secondary-outputs

# Tool invocations
quadcopter_dev.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,quadcopter_dev.map -mmcu=atmega16 -o "quadcopter_dev.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

quadcopter_dev.lss: quadcopter_dev.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S quadcopter_dev.elf  >"quadcopter_dev.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: quadcopter_dev.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 quadcopter_dev.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) quadcopter_dev.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
