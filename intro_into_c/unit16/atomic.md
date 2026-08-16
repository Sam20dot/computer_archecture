# ATOMIC METHODS IN PROGRAMMING 
in physics or science atom means a part of matter that can not be divisible 
or distoryed 
so the same in programming we have stolen that concept but we have used it 
in different aspect
in programming 
**atomic datatypes** is used to prevent the ***race condition***, that occurs when 
two or more thread try to access the same shared data 

### where they came from or which header that provide that ability 
oooh that fine and good questions 
it is provided by header which is called 

```c #include <stdatomic.h>``` to mean that all data types like 
```c _atomic ``` and others is where they found 
so we will expore more its capability let began within the actual code



other things which is amazing is the function which are used within the atomic calculations 

** _atomic_fetch_key (const voltile *obj,M arg) **
this function has the following behavior 
|key|operation|computation 
|----| ----|-----|
|add | +   |addition|
|sub | -   |substraction|
|or  | |   |bitwise exculsive or |
|xor |     |bitwise exculsive nor|
|and | &   |bitwise and          |



## THANK YOU TO BE WITH ME TILL NOW THE BEGINNING OF THE UNIT 16  IN THE INTIRE BOOK 

