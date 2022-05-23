###################################################################################
#           File: Makefile
#     Created on: Saturday 21/05/2022 10:42
#         Author: Makram Maher Makram
#        Subject: Generic Makefile For AVR
#
###################################################################################
#Project Name

PRJ_Name = GPIO-01-Assginment

###################################################################################
#Directories

OUT_DIR_BIN = ./bin

###################################################################################
#First Part of toolchain
#Ex:
#	avr-gcc.exe
#	avr-as.exe
#	avr-ld.exe
#	avr-objcopy.exe
#	avr-objdump.exe
#	avr-nm.exe
#
#	CC = avr-

CC = avr-

###################################################################################
#CFLAGS

CFLAGS = -std=c89 -ansi #-save-temps

###################################################################################
#MCPU
#Ex:
#	MMPU = -mcpu=atmega32a
#	MMPU = -mcpu=atmega128
#	MMPU = -mcpu=atmega328

MCPU = -mmcu=atmega32a

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
#C SOURCE FILES

C_SRC = $(wildcard *.c)

###################################################################################
#OUTPUT BINARY FILES

OUT_ELF = $(OUT_DIR_BIN)/$(PRJ_Name).elf
OUT_BIN = $(OUT_DIR_BIN)/$(PRJ_Name).bin
OUT_MAP = $(OUT_DIR_BIN)/mapfile.map

###################################################################################
#LINKER

LINKE = -Wl,-Map=$(OUT_MAP)

###################################################################################
#all :)

all: $(OUT_BIN)
	@echo "========================( BUILD IS DONE )========================="

###################################################################################
#Compiling Phase
$(OUT_ELF): $(C_SRC) | $(OUT_DIR_BIN)
	@echo ''
	@echo '--> Compiling' $<
	$(CC)gcc.exe  $(CFLAGS) $(MCPU) $(DEBUG) $(INCS) $(WARR) $(LINKE) -o $@ $< $(LIBS)

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
	rm -rf $(OUT_DIR_BIN)
	@echo "======================( CLEAN-ALL IS DONE )======================="

###################################################################################
#Show-variables

.PHONY: show-variables
show-variables:
	@echo "========================( SHOW VARIABLES )========================"
	@echo '--> PRJ_Name =' $(PRJ_Name)
	@echo '--> OUT_DIR_BIN =' $(OUT_DIR_BIN)
	@echo '--> CC =' $(CC)
	@echo '--> CFLAGS =' $(CFLAGS)
	@echo '--> MCPU =' $(MCPU)
	@echo '--> DEBUG =' $(DEBUG)
	@echo '--> WARR =' $(WARR)
	@echo '--> INCS =' $(INCS)
	@echo '--> LIBS =' $(LIBS)
	@echo '--> C_SRC =' $(C_SRC)
	@echo '--> OUT_ELF =' $(OUT_ELF)
	@echo '--> OUT_BIN =' $(OUT_BIN)
	@echo '--> OUT_MAP =' $(OUT_MAP)
	@echo "====================( SHOW VARIABLES IS DONE )===================="

###################################################################################