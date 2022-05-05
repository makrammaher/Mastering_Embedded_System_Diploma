# **First Term Project 1: High Pressure Detection System**
## **Project Report**: [**Click Here**](https://drive.google.com/drive/folders/1JGhN-RgvbcJBY-D6e57OH7A0ZVvnv5O5?usp=sharing)

## **Project Video**: [**Click Here**](https://youtu.be/nzHynFw-XT4) 

## **Proteus Simulation**
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/Video.gif" >

---

## **Compile using ARM Cross-tool chain**

```
make
```
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/Build.gif" >

---
## **Symbol Table And Binary Headers**

```
arm-none-eabi-nm.exe ./bin/*.elf ./obj/*.o >> Symbols.txt
arm-none-eabi-nm.exe ./bin/*.elf
```
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/Symbol.jpg" >

```
arm-none-eabi-objdump.exe ./bin/high-pressure-detector.elf -h
```
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/objDump.jpg" >

---

## **UML**
**Unified Modeling Language**

### Requirement Diagram
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/ReqDiagram.png" >

---
### Usecase Diagram
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/UseCase.png" >

---
### Activity Diagram
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/ActivityDiag.png" >

---
### Sequence Diagram
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/SequenceDiag.png" >

---
### Block Diagram
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/BlockDiagram.png" >

---
### Pressure Sensor State Machine Diagram
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/PS_States.png" >

---
### Alarm Actuator State Machine Diagram
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/AA_States.png" >

---
### High Pressure Detector State Machine Diagram
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/HPD_States.png" >

---
### Interactive Simulation
<img src="/04_First_Term_Projects/01_High_Pressure_Detection/img/UML/Interactive_Simulation.png" >

---