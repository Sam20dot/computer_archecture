# FILE INPUT AND OUTPUT 
in linux systems file means: a squence of character or bytes 
 
in unix and linux the operation which occurs on the files are mostly done with five function 
### those functions are 
1. open  ()
2. creat ()
3. read  ()
4. write ()
5. lseek ()
6. close ()

as listed above someone may say why do we have six function instead of five is becouse all functionality the ```c creat ()```
function was able to do has been shifted all can be done by the ```c open ()``` function alone 

in file systems all opened or created file is exposed or discribed by what we call file discriptor 
### **what is file discriptor **

**file discritpor** : are non negative number (positive number ) which which is used by the kenel to indentify the opened file to 
the process 
to mean that when we create or open file we have to return this non- negitive number so that the process can know the open file 
and those file discriptor can be used for other operations like reading the file, writing the file and so on 

> **NOTE**
   file discriptors, there are the one which are used by defoult by the processes, that contains 
   1. `0` this stands for `standard input of process ` 
   2. `1` this stands for `standard ouput of process `
   3. `2` this stands for `standard error of process ` 
also they can be defined by the constant which are mostly found in the header which is called `unistd.h`
and thos marcos are 
> **MACROS_FD*
  1.  STDIN_FILENO
  2. STDOUT_FILENO
  3. STDERR_FILENO
there use has been added in the file called showing the marcos `showMarcos.c`

### **what is the file discriptor one process can open ?**
good question about the amount of the file discriptor one process can open are specified within the 
header called `unistd.h`
in ealy days the file ***POSIX unix machine*** machine had the maximum of 20 file per process but now they have increase 
based on the machine we can use macros called `OPEN_MAX-1` to see actual file let use also the same file showmarcos to show that 

>**NOTE**
 to get those all values like the limits the file can open we had to use the following codes 
 ```c 
   long variable_name= sysconf (_SC_OPEN_MAX) // here we have seen that one process can open about 1024 files and thier file 
  // discriptors  also indicated within the file `showMacros`


 ```





