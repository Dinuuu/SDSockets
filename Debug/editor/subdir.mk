################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../editor/comun.c \
../editor/editor.c \
../editor/edsu_comun.c \
../editor/test_editor.c \
../editor/test_editor_avanz.c 

OBJS += \
./editor/comun.o \
./editor/editor.o \
./editor/edsu_comun.o \
./editor/test_editor.o \
./editor/test_editor_avanz.o 

C_DEPS += \
./editor/comun.d \
./editor/editor.d \
./editor/edsu_comun.d \
./editor/test_editor.d \
./editor/test_editor_avanz.d 


# Each subdirectory must supply rules for building sources it contributes
editor/%.o: ../editor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


