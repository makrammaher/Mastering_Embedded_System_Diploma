# **Debugging Simple UART Transmitter Versatilepb Board (ARM926ej-s) Using GNU-GBD**

<img src="/02_Embedded_C/03_Lesson_3/04_Lab_03/img/Video.gif" >

## **Prepare Versatilepb Borad on QEMU**
using this command to start Versatilepb Board waiting for gdb.
```
qemu-system-arm.exe -M versatilepb -m 128M -nographic -s -S -kernel simple-uart.elf
```
---
## **Prepare GNU GDB**
using this command to start GNU GBD for arm-none-eabi- toolchain
```
arm-none-eabi-gdb.exe simple-uart.elf
```
<img src="/02_Embedded_C/03_Lesson_3/04_Lab_03/img/gdb-wait.jpg" >

to connect to QEMU Versatilepb board using this command in (gbd)
```
target remote localhost:1234
```
---
## **Most Popular GDB Commands**

**No.**|**GDB command**|**Description**
-|-|-
**1**|**b \ break**|Puts a breakpoint at the current line
**2**|**b main**|Puts a breakpoint at the beginning of main function
**3**|**b file.c:18**|Puts a breakpoint at line 18 in file.c file
**4**|**b N**|Puts a breakpoint at line N in current file
**5**|**b +N**|Puts a breakpoint at N lines down from the current line
**6**|**b \*N**|Puts a breakpoin at addredd N
**7**|**info breakpoints**|Show all breakpoints list
**8**|**delete N**|Deletes breakpoint number N
**9**|**enable N**|Enable a disabled breakpoint number N
**10**|**disable N**|Disable an enabled breakpoint number N
**11**|**clear**|Clear all breakpoints
**12**|**run \ r**|Runs the program until a breakpoint or error
**13**|**continue \ c**|Continues running the program untik the next breakpoint
**14**|**finish \ f**|Runs until the current function is finshed
**15**|**step \ s**|Runs the next line of the program
**16**|**s N**|Runs the next N lines of the program
**17**|**si**|Runs the next assembly instruction.
**18**|**next \ n**|Like s, but it does not step into funstions
**19**|**kill**|Kills the running program
**20**|**backtrace \ where**|Shows call stack
**21**|**backtrace full \ where full**|Shows call stack,also print the local variables in each frame
**22**|**u**|Goes up a level in the stack
**23**|**d**|Goes down a level in the stack
**24**|**print Var \ p Var**|Prints the current value of the variable 'Var'
**25**|**display Var**|Like print, but it print the information after each stepping instruction
**26**|**enable display N**|Enable a disabled display number N
**27**|**disable display N**|Disable an enabled display number N
**28**|**x/nfu address**|Print memory|
|||n: How many units to print |
|||f: format character|
|||u: unit (b: Byte, h:Half-word, w:Word, g:Gaint-word)|
**29**|**watch Var**|Watch on the variable Var
**30**|**list \ l**|Prints source code of current line
**31**|**l N**|Prints source code of line N
**32**|**l S,N**|Prints source code from line S to line N
**33**|**l file.c:N**|Prints source code of line N in file.c
**34**|**target remote localhost:1234**|to connect with qemu
**35**|**help**|Prints help classes
**36**|**help X**|Prints help of class X