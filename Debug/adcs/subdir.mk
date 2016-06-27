################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adcs/mpu6050.c \
../adcs/sensor_reader.c 

OBJS += \
./adcs/mpu6050.o \
./adcs/sensor_reader.o 

C_DEPS += \
./adcs/mpu6050.d \
./adcs/sensor_reader.d 


# Each subdirectory must supply rules for building sources it contributes
adcs/%.o: ../adcs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


