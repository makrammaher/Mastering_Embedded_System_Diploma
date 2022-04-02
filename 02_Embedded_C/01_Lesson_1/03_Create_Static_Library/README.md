# **Create Static Library**

## **```ar [option] <Library_Name> <Object_Files>```**

### **Options**

**No.**|**Option**|**Description**
-|-|-
**1**|**rcs**|Create A static Library
**2**|**r**|add another object file to libaray or replace
**3**|**d**|remove an object file from librar
**4**|**t**|view object files in libraryy
**5**|**x**|extact all object from library
---
## **Examples**

1. Create a static library called mylib.a
```
ar rcs mylib.a calculator.o
```

2. View all object files in static libray
```
ar t mylib.a
```

3. Extract akk object files in static library
```
ar x mylib.a
```