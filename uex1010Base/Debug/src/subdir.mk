################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PruebaTablero.cpp \
../src/PruebasCasilla.cpp \
../src/PruebasEntorno.cpp \
../src/PruebasPieza.cpp \
../src/PruebasTadJuego.cpp \
../src/TadCasilla.cpp \
../src/TadJuego.cpp \
../src/TadPieza.cpp \
../src/TadTablero.cpp \
../src/entorno.cpp \
../src/uex1010.cpp 

OBJS += \
./src/PruebaTablero.o \
./src/PruebasCasilla.o \
./src/PruebasEntorno.o \
./src/PruebasPieza.o \
./src/PruebasTadJuego.o \
./src/TadCasilla.o \
./src/TadJuego.o \
./src/TadPieza.o \
./src/TadTablero.o \
./src/entorno.o \
./src/uex1010.o 

CPP_DEPS += \
./src/PruebaTablero.d \
./src/PruebasCasilla.d \
./src/PruebasEntorno.d \
./src/PruebasPieza.d \
./src/PruebasTadJuego.d \
./src/TadCasilla.d \
./src/TadJuego.d \
./src/TadPieza.d \
./src/TadTablero.d \
./src/entorno.d \
./src/uex1010.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


