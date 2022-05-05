###################################################################################
#           File: Makefile
#     Created on: Wednesday 04/05/2022 20:42
#         Author: Makram Maher Makram
#        Subject: Generic Makefile
#
###################################################################################
#Project Name

PRJ_Name = high-pressure-detector

###################################################################################
#Directories

OUT_DIR_BIN = ./bin
OUT_DIR_OBJ = ./obj

###################################################################################
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

###################################################################################
#CFLAGS

CFLAGS = -std=c89 -ansi

###################################################################################
#MCPU
#Ex:
#	MCPU = -mcpu=arm926ej-s
#	MCPU = -mcpu=cortex-m3
#	MCPU = -mcpu=cortex-m4

MCPU = -mcpu=cortex-m3

###################################################################################
#DEBUG
#EX
#	DEBUG = -g
#	DEBUG = -gdwarf-2
#	DEBUG =				(No debugging information)

DEBUG = -gdwarf-2

###################################################################################
#INCLUDES

INCS = -I .

###################################################################################
#LIBRARIES

LIBS =

###################################################################################
#WARRNINGS

WARR = -Wall

###################################################################################
#LINKER SCRIPT FILE NAME

LINKER_SCR = linker_script.ld

###################################################################################
#C SOURCE FILES

C_SRC = $(wildcard *.c)
C_OBJ = $(C_SRC:%.c=$(OUT_DIR_OBJ)/%.o)

###################################################################################
#ASSEMBLY SOURCE FILES

AS_SRC = $(wildcard *.s)
AS_OBJ = $(AS_SRC:%.s=$(OUT_DIR_OBJ)/%.o)

###################################################################################
#OUTPUT BINARY FILES

OUT_ELF = $(OUT_DIR_BIN)/$(PRJ_Name).elf
OUT_AXF = $(OUT_DIR_BIN)/$(PRJ_Name).axf
OUT_BIN = $(OUT_DIR_BIN)/$(PRJ_Name).bin
OUT_MAP = $(OUT_DIR_BIN)/mapfile.map


###################################################################################
#all :)

all: $(OUT_BIN)
	@echo "========================( BUILD IS DONE )========================="

###################################################################################
#Assembling Phase

$(OUT_DIR_OBJ)/%.o: %.s | $(OUT_DIR_OBJ)
	@echo ''
	@echo '--> Assemble' $<
	$(CC)as.exe $(MCPU) $(DEBUG) $(WARR) $< -o $@

###################################################################################
#Compiling Phase

$(OUT_DIR_OBJ)/%.o: %.c | $(OUT_DIR_OBJ)
	@echo ''
	@echo '--> Complie' $<
	$(CC)gcc.exe -c $(CFLAGS) $(MCPU) $(DEBUG) $(INCS) $(WARR) $< -o $@

###################################################################################
#Linking Phase

$(OUT_ELF): $(C_OBJ) $(AS_OBJ) | $(OUT_DIR_BIN)
	@echo ''
	@echo '--> Linking' $(C_OBJ) $(AS_OBJ)
	$(CC)ld.exe -T $(LINKER_SCR) $(C_OBJ) $(AS_OBJ) -o $@ -Map=$(OUT_MAP)
	cp $(OUT_ELF) $(OUT_AXF)

###################################################################################
#generate .bin file

$(OUT_BIN): $(OUT_ELF)
	@echo ''
	@echo '--> Strip' $<
	$(CC)objcopy.exe -O binary $< $@

###################################################################################
#Create ./bin directory

$(OUT_DIR_BIN):
	@echo ''
	@echo '--> Create Directory' $(OUT_DIR_BIN)
	mkdir -p $(OUT_DIR_BIN)

###################################################################################
#Create ./obj directory

$(OUT_DIR_OBJ): 
	@echo ''
	@echo '--> Create Directory' $(OUT_DIR_OBJ)
	mkdir -p $(OUT_DIR_OBJ)

###################################################################################
#Clean

.PHONY: clean
clean:
	@echo "============================( CLEAN )============================="
	rm -rf $(OUT_ELF)
	rm -rf $(OUT_BIN)
	rm -rf $(OUT_MAP)
	rm -rf $(OUT_DIR_BIN)
	@echo "========================( CLEAN IS DONE )========================="

###################################################################################
#Clean-all

.PHONY: clean-all
clean-all:
	@echo "==========================( CLEAN-ALL )==========================="
	rm -rf $(OUT_ELF)
	rm -rf $(OUT_BIN)
	rm -rf $(OUT_MAP)
	rm -rf $(C_OBJ) $(AS_OBJ)
	rm -rf $(OUT_DIR_OBJ) $(OUT_DIR_BIN)
	@echo "======================( CLEAN-ALL IS DONE )======================="

###################################################################################
#Show-variables

.PHONY: show-variables
show-variables:
	@echo "========================( SHOW VARIABLES )========================"
	@echo '--> PRJ_Name =' $(PRJ_Name)
	@echo '--> OUT_DIR_BIN =' $(OUT_DIR_BIN)
	@echo '--> OUT_DIR_OBJ =' $(OUT_DIR_OBJ)
	@echo '--> CC =' $(CC)
	@echo '--> CFLAGS =' $(CFLAGS)
	@echo '--> MCPU =' $(MCPU)
	@echo '--> DEBUG =' $(DEBUG)
	@echo '--> WARR =' $(WARR)
	@echo '--> LINKER_SCR =' $(LINKER_SCR)
	@echo '--> INCS =' $(INCS)
	@echo '--> LIBS =' $(LIBS)
	@echo '--> C_SRC =' $(C_SRC)
	@echo '--> C_OBJ =' $(C_OBJ)
	@echo '--> AS_SRC =' $(AS_SRC)
	@echo '--> AS_OBJ =' $(AS_OBJ)
	@echo '--> OUT_ELF =' $(OUT_ELF)
	@echo '--> OUT_BIN =' $(OUT_BIN)
	@echo '--> OUT_MAP =' $(OUT_MAP)
	@echo "====================( SHOW VARIABLES IS DONE )===================="

###################################################################################