###################################################################################
#           File: Makefile
#     Created on: Saturday 21/05/2022 10:42
#         Author: Makram Maher Makram
#        Subject: Generic Makefile For AVR
#
###################################################################################
#Project Name

PRJ_Name = ATMEGA32-TIMER0-Driver

###################################################################################
#Directories

SOURCE_DIR := ./Src
DEBUG_DIR := ./Debug

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

CFLAGS = #-std=c89 -ansi #-save-temps

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

INCS_DIRS = $(shell find ./ -type d -name 'Inc')
INCS = $(foreach dir, $(INCS_DIRS) $(C_SRC_DIRS), $(addprefix -I, $(dir)))

###################################################################################
#LIBRARIES

LIBS =

###################################################################################
#WARRNINGS

WARR = -Wall

###################################################################################
#C SOURCE FILES

C_SRC = $(shell find ./ -type f -name '*.c')
C_SRC_DIRS = $(dir $(C_SRC))

###################################################################################
#OUTPUT BINARY FILES

OUT_ELF = $(DEBUG_DIR)/$(PRJ_Name).elf
OUT_BIN = $(DEBUG_DIR)/$(PRJ_Name).bin
OUT_MAP = $(DEBUG_DIR)/mapfile.map

###################################################################################
#LINKER

LINKE = -Wl,-Map=$(OUT_MAP)

###################################################################################
#all :)

all: $(OUT_BIN)
	@echo "========================( BUILD IS DONE )========================="

###################################################################################
#Compiling Phase
$(OUT_ELF): $(C_SRC) | $(DEBUG_DIR)
	@echo ''
	@echo '--> Compiling' $(C_SRC) 
	$(CC)gcc.exe  $(CFLAGS) $(MCPU) $(DEBUG) $(INCS) $(WARR) $(LINKE) -o $@ $(C_SRC) $(LIBS)

###################################################################################
#generate .bin file

$(OUT_BIN): $(OUT_ELF)
	@echo ''
	@echo '--> Strip' $<
	$(CC)objcopy.exe -O binary $< $@

###################################################################################
#Create ./bin directory

$(DEBUG_DIR):
	@echo ''
	@echo '--> Create Directory' $(DEBUG_DIR)
	mkdir -p $(DEBUG_DIR)

###################################################################################
#Flash
.PHONY: flash
flash:
	@echo ''
	@echo '--> Flashing' $(OUT_BIN)
	avrdude.exe -p atmega32a -P usb -c usbasp -U flash:w:$(OUT_BIN)

###################################################################################
#Clean

.PHONY: clean
clean:
	@echo "============================( CLEAN )============================="
	rm -rf $(OUT_ELF)
	rm -rf $(OUT_BIN)
	rm -rf $(OUT_MAP)
	rm -rf $(DEBUG_DIR)
	@echo "========================( CLEAN IS DONE )========================="

###################################################################################
#Clean-all

.PHONY: clean-all
clean-all:
	@echo "==========================( CLEAN-ALL )==========================="
	rm -rf $(OUT_ELF)
	rm -rf $(OUT_BIN)
	rm -rf $(OUT_MAP)
	rm -rf $(DEBUG_DIR)
	@echo "======================( CLEAN-ALL IS DONE )======================="

###################################################################################
#Show-variables

.PHONY: show-variables
show-variables:
	@echo "========================( SHOW VARIABLES )========================"
	@echo '--> PRJ_Name =' $(PRJ_Name)
	@echo '--> DEBUG_DIR =' $(DEBUG_DIR)
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