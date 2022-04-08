#
#           File: Makefile
#     Created on: Thursday 07/04/2022 19:09
#         Author: Makram Maher Makram
#        Subject: Generic Makefile
#

#Project Name
PRJ_Name = toggle-led

#First Part of toolchain
#Ex:
#	arm-none-eabi-gcc.exe
#	arm-none-eabi-as.exe
#	arm-none-eabi-ld.exe
#	arm-none-eabi-objcopy.exe
#	arm-none-eabi-objdump.exe
#	arm-none-eabi-nm.exe
#
#	CC = arm-none-eabi-
CC = arm-none-eabi-

#CFLAGS
CFLAGS = -std=c89 -ansi

#MCPU
#Ex:
#	MCPU = -mcpu=arm926ej-s
#	MCPU = -mcpu=cortex-m3
MCPU = -mcpu=cortex-m3

#DEBUG
#EX
#	DEBUG = -g
#	DEBUG = -gdwrf-2
#	DEBUG =				(No debugging information)
DEBUG = -gdwarf-2

#INCLUDES
INCS = -I .

#LIBRARIES
LIBS =

#LINKER SCRIPT FILE NAME
LINKER_SCR = linker_script.ld


#C SOURCE FILES
C_SRC = $(wildcard *.c)
C_OBJ = $(C_SRC:.c=.o)

#ASSEMBLY SOURCE FILE
AS_SRC = $(wildcard *.s)
AS_OBJ = $(AS_SRC:.s=.o)


all: $(PRJ_Name).bin
	@echo "========================( BUILD IS DONE )========================="

%.o: %.s
	@echo ''
	@echo '--> Assemble' $<
	$(CC)as.exe $(MCPU) $(DEBUG) $< -o $@

%.o: %.c
	@echo ''
	@echo '--> Complie' $<
	$(CC)gcc.exe -c $(CFLAGS) $(MCPU) $(DEBUG) $(INCS) $< -o $@

$(PRJ_Name).elf: $(C_OBJ) $(AS_OBJ)
	@echo ''
	@echo '--> Linking' $(C_OBJ) $(AS_OBJ)
	$(CC)ld.exe -T $(LINKER_SCR) $(C_OBJ) $(AS_OBJ) -o $@ -Map=mapfile.map

$(PRJ_Name).bin: $(PRJ_Name).elf
	@echo ''
	@echo '--> Strip' $<
	$(CC)objcopy.exe -O binary $< $@

clean:
	@echo "============================( CLEAN )============================="
	rm -rf *.elf
	rm -rf *.bin
	@echo "========================( CLEAN IS DONE )========================="

clean-all:
	@echo "==========================( CLEAN-ALL )==========================="
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.bin
	@echo "======================( CLEAN-ALL IS DONE )======================="


show-variables:
	@echo "========================( SHOW VARIABLES )========================"
	@echo '--> PRJ_Name =' $(PRJ_Name)
	@echo '--> CC =' $(CC)
	@echo '--> CFLAGS =' $(CFLAGS)
	@echo '--> MCPU =' $(MCPU)
	@echo '--> DEBUG =' $(DEBUG)
	@echo '--> LINKER_SCR =' $(LINKER_SCR)
	@echo '--> INCS =' $(INCS)
	@echo '--> LIBS =' $(LIBS)
	@echo '--> C_SRC =' $(C_SRC)
	@echo '--> C_OBJ =' $(C_OBJ)
	@echo '--> AS_SRC =' $(AS_SRC)
	@echo '--> AS_OBJ =' $(AS_OBJ)
	@echo "====================( SHOW VARIABLES IS DONE )===================="