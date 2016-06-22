################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../croutine.c \
../event_groups.c \
../heap_3.c \
../hooks.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../tasks.c \
../timers.c 

OBJS += \
./croutine.o \
./event_groups.o \
./heap_3.o \
./hooks.o \
./list.o \
./main.o \
./port.o \
./queue.o \
./tasks.o \
./timers.o 

C_DEPS += \
./croutine.d \
./event_groups.d \
./heap_3.d \
./hooks.d \
./list.d \
./main.d \
./port.d \
./queue.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


