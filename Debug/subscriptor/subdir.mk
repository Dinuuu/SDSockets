################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../subscriptor/comun.c \
../subscriptor/edsu_comun.c \
../subscriptor/subscriptor.c \
../subscriptor/test_subscriptor.c \
../subscriptor/test_subscriptor_avanz.c 

OBJS += \
./subscriptor/comun.o \
./subscriptor/edsu_comun.o \
./subscriptor/subscriptor.o \
./subscriptor/test_subscriptor.o \
./subscriptor/test_subscriptor_avanz.o 

C_DEPS += \
./subscriptor/comun.d \
./subscriptor/edsu_comun.d \
./subscriptor/subscriptor.d \
./subscriptor/test_subscriptor.d \
./subscriptor/test_subscriptor_avanz.d 


# Each subdirectory must supply rules for building sources it contributes
subscriptor/%.o: ../subscriptor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


