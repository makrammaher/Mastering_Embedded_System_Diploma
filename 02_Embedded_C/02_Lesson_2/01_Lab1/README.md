# **Lab 1 Embedded System From Scratch**

## First thing i create .c and .h files
> app.c & uart.c & uart.h Files
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/001.jpg" >

## Compile app.c and uart.c --> app.o and uart.o
> Powershell commands of compiling .c files
```
arm-none-eabi-gcc.exe -ansi -c -I . -g -mcpu=arm926ej-s app.c -o app.o
```
```
arm-none-eabi-gcc.exe -ansi -c -I . -g -mcpu=arm926ej-s uart.c -o uart.o
```
> Output files
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/002.jpg" >

## Show Sections header of app.o and uart.o
> Powershell commands of show sections header
```
arm-none-eabi-objdump.exe -h uart.o
```
```
arm-none-eabi-objdump.exe -h app.o
```
> Powershell Output
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/003.jpg" >
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/004.jpg" >

## Remove all debug sections from app.o and uart.o
> Powershell commands of strip debug sections
```
arm-none-eabi-strip.exe -g uart.o -o uart.o
```
```
arm-none-eabi-strip.exe -g app.o -o app.o
```
> Powershell commands of show sections header
```
arm-none-eabi-objdump.exe -h uart.o
```
```
arm-none-eabi-objdump.exe -h app.o
```
> Powershell Output
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/005.jpg" >
> Powershell commands of show content of each section
```
arm-none-eabi-objdump.exe -s uart.o
```
```
arm-none-eabi-objdump.exe -s app.o
```
> Powershell Output
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/006.jpg" >
