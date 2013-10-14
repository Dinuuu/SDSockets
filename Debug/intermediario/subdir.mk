################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../intermediario/comun.o \
../intermediario/intermediario.o 

C_SRCS += \
../intermediario/comun.c \
../intermediario/intermediario.c 

OBJS += \
./intermediario/comun.o \
./intermediario/intermediario.o 

C_DEPS += \
./intermediario/comun.d \
./intermediario/intermediario.d 


# Each subdirectory must supply rules for building sources it contributes
intermediario/%.o: ../intermediario/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


