# **Toggle LED ARM-Cortex-M3**
Using "startup.c"
1. Copy .data section from FLASH to SRAM
2. Reserve Space for .BSS and initialize it to Zeros
3. Call main()
<img src="/02_Embedded_C/03_Lesson_3/03_Lab_02/img/Video.gif" >

## **Show sections headers for .elf file**
```
arm-none-eabi-objdump.exe -h toggle-led.elf
```
<img src="/02_Embedded_C/03_Lesson_3/03_Lab_02/img/objdump-h.jpg" >

## **Show symbols for .elf file**
```
arm-none-eabi-nm.exe toggle-led.elf
```
<img src="/02_Embedded_C/03_Lesson_3/03_Lab_02/img/nm.jpg" >

## **Show elf information in readelf.txt**
```
arm-none-eabi-readelf.exe -a toggle-led.elf >> readelf.txt
```
<img src="/02_Embedded_C/03_Lesson_3/03_Lab_02/img/readelf.jpg" >
