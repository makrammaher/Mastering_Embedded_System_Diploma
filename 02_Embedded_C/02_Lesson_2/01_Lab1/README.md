# **Lab 1 Embedded System From Scratch**

## First thing i create .c and .h files
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/001.jpg" >

---
## Compile app.c and uart.c --> app.o and uart.o
```
arm-none-eabi-gcc.exe -ansi -c -I . -g -mcpu=arm926ej-s app.c -o app.o
```
```
arm-none-eabi-gcc.exe -ansi -c -I . -g -mcpu=arm926ej-s uart.c -o uart.o
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/002.jpg" >

---

## Show Sections header of app.o and uart.o
```
arm-none-eabi-objdump.exe -h uart.o
```
```
arm-none-eabi-objdump.exe -h app.o
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/003.jpg" >
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/004.jpg" >

---

## Remove all debug sections from app.o and uart.o
Powershell commands of strip debug sections
```
arm-none-eabi-strip.exe -g uart.o -o uart.o
```
```
arm-none-eabi-strip.exe -g app.o -o app.o
```
Powershell commands of show sections header
```
arm-none-eabi-objdump.exe -h uart.o
```
```
arm-none-eabi-objdump.exe -h app.o
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/005.jpg" >

---

Powershell commands of show content of each section

```
arm-none-eabi-objdump.exe -s uart.o
```
```
arm-none-eabi-objdump.exe -s app.o
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/006.jpg" >

---

## Create startup.s file and assemble it and get startup.o file
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/007.jpg" >

Powershell commands of Assemble startup.s
```
arm-none-eabi-as.exe -mcpu=arm926ej-s startup.s -o startup.o
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/008.jpg" >

---
Powershell commands of show sections header of startup.o
```
arm-none-eabi-objdump.exe -h startup.o
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/009.jpg" >

---

## Create linker_script.ld file and use linker to create excutable file .elf
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/010.jpg" >

Powershell commands of link all .o files to create an executale image .elf and .map
```
arm-none-eabi-ld.exe -T linker_script.ld -Map out.map startup.o app.o uart.o -o learn-in-depth.elf
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/011.jpg" >

---

## Showing information about executable file .elf

Powershell commands of show all information using readelf of learn-in-depth.elf
```
arm-none-eabi-readelf.exe -a learn-in-depth.elf
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/012.jpg" >

---
Powershell commands of show sections header of learn-in-depth.elf
```
arm-none-eabi-objdump.exe -h learn-in-depth.elf
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/013.jpg" >

---
Powershell commands of show disassemble of learn-in-depth.elf
```
arm-none-eabi-objdump.exe -d learn-in-depth.elf
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/014.jpg" >

---

## **Show all symbols of startup.o, app.o, uart.o, learn-in-depth.elf**
```
arm-none-eabi-nm.exe startup.o, app.o, uart.o, learn-in-depth.elf
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/015.jpg" >

---
## **create burn image .bin (binary image)**
```
arm-none-eabi-objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/016.jpg" >


---
## **Run .bin file using QEMU**
```
qemu-system-arm.exe -M versatilepb -m 128M -nographic -kernel learn-in-depth.bin
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/017.jpg" >