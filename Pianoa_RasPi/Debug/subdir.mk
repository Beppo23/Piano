################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../funtzioak.c \
../main.c \
../menua.c 

OBJS += \
./funtzioak.o \
./main.o \
./menua.o 

C_DEPS += \
./funtzioak.d \
./main.d \
./menua.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/uesandi/wiringPi/wiringPi -I/home/uesandi/wiringPi/ -I/home/uesandi/wiringPi/devLib -I/home/uesandi/wiringPi/gpio -I/home/uesandi/wiringPi/wiringPiD -I/home/uesandi/wiringPi/pins -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


