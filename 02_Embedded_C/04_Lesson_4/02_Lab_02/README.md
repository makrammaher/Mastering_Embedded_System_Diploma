# **Debugging Toggle Led App on STM32F103Cx**

## **Debugging app on STM32F103C8 Board using builtin LED**

Enjoy debugging on physical board :)
<img src="/02_Embedded_C/04_Lesson_4/02_Lab_02/img/Physical.gif" >

in openOCD directory use this command
```
./bin/openocd.exe -f ./scripts/interface/stlink-v2.cfg -f ./scripts/board/stm32f103c8_blue_pill.cfg -c "tcl_port 10240"
```
listening on port 3333 for gdb connections
<img src="/02_Embedded_C/04_Lesson_4/02_Lab_02/img/001.jpg" >

in gdb terminal
```
arm-none-eabi-gdb.exe ./bin/toggle-led-STM32.elf
```
connect to OpenOCD Server using gdb

<img src="/02_Embedded_C/04_Lesson_4/02_Lab_02/img/002.jpg" >

Enjoy debugging Video

<img src="/02_Embedded_C/04_Lesson_4/02_Lab_02/img/Terminal.gif" >

---
## **Proteus Simulator using PORTA not PORTC**

<img src="/02_Embedded_C/04_Lesson_4/02_Lab_02/img/Proteus.gif" >

---
## **Keil UVision using PORTA not PORTC**

<img src="/02_Embedded_C/04_Lesson_4/02_Lab_02/img/Keil_UVision.gif" >
