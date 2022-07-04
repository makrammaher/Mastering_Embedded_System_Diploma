###################################################################################
#           File: Makefile
#     Created on: Wednesday 04/05/2022 20:42
#         Author: Makram Maher Makram
#        Subject: Generic Makefile
#
###################################################################################
#Project Name

PRJ_Name = MCU-SPI-Driver-Slave

###################################################################################
#Directories

SOURCE_DIR := ./Src
DEBUG_DIR := ./Debug

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

CFLAGS = -std=c89 -ansi #-save-temps

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

INCS_DIRS = $(shell find ./ -type d -name 'Inc')
INCS = $(foreach dir, $(INCS_DIRS) $(C_SRC_DIRS), $(addprefix -I, $(dir)))


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

C_SRC = $(shell find ./ -type f -name '*.c')
C_SRC_DIRS = $(dir $(C_SRC))
C_OBJ_D := $(subst $(SOURCE_DIR),$(DEBUG_DIR),$(C_SRC_DIRS))
C_OBJ_DIRS := $(subst ./Startup/,./Debug/Startup/,$(C_OBJ_D))
C_OB = $(subst $(SOURCE_DIR),$(DEBUG_DIR),$(C_SRC:.c=.o))
C_OBJ = $(subst ./Startup/,./Debug/Startup/,$(C_OB))
C_DEPS = $(C_OBJ:.o=.d)

###################################################################################
#ASSEMBLY SOURCE FILES

AS_SRC = $(shell find ./ -type f -name '*.s')
AS_SRC_DIRS = $(dir $(AS_SRC))
AS_OBJ_D := $(subst $(SOURCE_DIR),$(DEBUG_DIR),$(AS_SRC_DIRS))
AS_OBJ_DIRS := $(subst ./Startup/,./Debug/Startup/,$(AS_OBJ_D))
AS_OB = $(subst $(SOURCE_DIR),$(DEBUG_DIR),$(AS_SRC:.s=.o))
AS_OBJ = $(subst ./Startup/,./Debug/Startup/,$(AS_OB))
AS_DEPS = $(AS_OBJ:.o=.d)

# Add this list to VPATH, the place make will look for the source files
VPATH = $(C_SRC_DIRS) $(AS_SRC_DIRS)
###################################################################################
#OUTPUT BINARY FILES

OUT_ELF = $(DEBUG_DIR)/$(PRJ_Name).elf
OUT_AXF = $(DEBUG_DIR)/$(PRJ_Name).axf
OUT_BIN = $(DEBUG_DIR)/$(PRJ_Name).bin
OUT_MAP = $(DEBUG_DIR)/mapfile.map


define C_File_Rule
$(1)%.o: %.c | $(C_OBJ_DIRS)
	@echo ''
	@echo '--> Complie' $$<
	$(CC)gcc.exe -c $$(CFLAGS) $$(MCPU) $$(DEBUG) $$(INCS) $$(WARR) $$< -o $$@ -MMD
endef

define AS_File_Rule
$(1)%.o: %.s | $(AS_OBJ_DIRS)
	@echo ''
	@echo '--> Assemble' $$<
	$(CC)as.exe $$(MCPU) $$(DEBUG) $$(WARR) $$< -o $$@ -MMD
endef

###################################################################################
#all :)

.PHONY: all
all: $(OUT_BIN)
	@echo "========================( BUILD IS DONE )========================="

###################################################################################
#generate .bin file

$(OUT_BIN): $(OUT_ELF) 
	@echo ''
	@echo '--> Strip' $<
	$(CC)objcopy.exe -O binary $< $@

###################################################################################
#Linking Phase

$(OUT_ELF): $(C_OBJ) $(AS_OBJ)
	@echo ''
	@echo '--> Linking' $(C_OBJ) $(AS_OBJ)
	$(CC)ld.exe -T $(LINKER_SCR) $(C_OBJ) $(AS_OBJ) -o $@ -Map=$(OUT_MAP)
	cp $(OUT_ELF) $(OUT_AXF)

###################################################################################
#Compiling Phase

-include $(C_DEPS)
# Generate rules
$(foreach targetdir,$(C_OBJ_DIRS),$(eval $(call C_File_Rule,$(targetdir))))

###################################################################################
#Assembling Phase

-include $(AS_DEPS)

$(foreach targetdir,$(AS_OBJ_DIRS),$(eval $(call AS_File_Rule,$(targetdir))))


###################################################################################
#Create directories

$(C_OBJ_DIRS):
	@echo ''
	@echo '--> Create Directory' $(C_OBJ_DIRS)
	mkdir -p $(C_OBJ_DIRS)

$(AS_OBJ_DIRS):
	@echo ''
	@echo '--> Create Directory' $(AS_OBJ_DIRS)
	mkdir -p $(AS_OBJ_DIRS)

###################################################################################
#Clean

.PHONY: clean
clean:
	@echo "============================( CLEAN )============================="
	rm -rf $(OUT_ELF)
	rm -rf $(OUT_BIN)
	rm -rf $(OUT_MAP)
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
	rm -rf $(C_DEPS) $(AS_DEPS)
	rm -rf $(C_OBJ_DIRS) $(AS_OBJ_DIRS)
	rm -rf $(DEBUG_DIR)
	@echo "======================( CLEAN-ALL IS DONE )======================="

###################################################################################
#Show-variables

.PHONY: show-variables
show-variables:
	@echo "========================( SHOW VARIABLES )========================"
	@echo '--> PRJ_Name =' $(PRJ_Name)
	@echo '--> CC =' $(CC)
	@echo '--> CFLAGS =' $(CFLAGS)
	@echo '--> MCPU =' $(MCPU)
	@echo '--> DEBUG =' $(DEBUG)
	@echo '--> WARR =' $(WARR)
	@echo '--> LINKER_SCR =' $(LINKER_SCR)
	@echo '--> INCS =' $(INCS)
	@echo '--> LIBS =' $(LIBS)
	@echo ''
	@echo '--> C_SRC =' $(C_SRC)
	@echo '--> C_SRC_DIRS =' $(C_SRC_DIRS)
	@echo '--> C_OBJ_DIRS =' $(C_OBJ_DIRS)
	@echo '--> C_OBJ =' $(C_OBJ)
	@echo '--> C_DEPS =' $(C_DEPS)
	@echo ''
	@echo '--> AS_SRC =' $(AS_SRC)
	@echo '--> AS_SRC_DIRS =' $(AS_SRC_DIRS)
	@echo '--> AS_OBJ_DIRS =' $(AS_OBJ_DIRS)
	@echo '--> AS_OBJ =' $(AS_OBJ)
	@echo '--> AS_DEPS =' $(AS_DEPS)
	@echo ''
	@echo '--> VPATH =' $(VPATH)
	@echo '--> OUT_ELF =' $(OUT_ELF)
	@echo '--> OUT_BIN =' $(OUT_BIN)
	@echo '--> OUT_MAP =' $(OUT_MAP)
	@echo "====================( SHOW VARIABLES IS DONE )===================="

###################################################################################