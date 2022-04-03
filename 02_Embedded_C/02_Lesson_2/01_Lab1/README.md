# **Lab 1 Embedded System From Scratch**

## First thing i create .c and .h files
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/001.jpg" >

## Compile app.c and uart.c --> app.o and uart.o
> Powershell Commands
```
arm-none-eabi-gcc.exe -ansi -c -I . -g -mcpu=arm926ej-s app.c -o app.o
arm-none-eabi-gcc.exe -ansi -c -I . -g -mcpu=arm926ej-s uart.c -o uart.o
```
<img src="/02_Embedded_C/02_Lesson_2/01_Lab1/img/002.jpg" >