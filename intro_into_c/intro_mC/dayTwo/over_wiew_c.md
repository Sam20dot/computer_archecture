 # THIS IS THE OVER VIEW OF THE C PROGRAM FROM THE BOOK WHICH IS CALLED THE MODERN C PROGRAMMING 


yesterday we have learned about c programming from its standards 
## C99 STANDARD :

this is where was the introduction of following libraries 

1.  <complex.h>
this library helped in solving complex numbers arithematics points 
2. <fenv.h> 
this library helped for floating point enviroments 
3. <stdint.h>
formats for fixed-width integer data types this helps on machine where we spefiy the size of integer accross the same machine no matter what or the compiler hundler that with its abstractions 
## example:
to program the hardware like arduino with the microcontroller which is ATmega328P where int hold about 16 bit so when we use that exact codes on the esp32 where the int occupy about 32 bit it become hard so that why we use the this library for writing the codes which are consitance accross the platiform without the conflict about the underying machine 


4. <stdbool.h>
is macros for boolean data type 
macros is like the replacement of the data which are defined before the compilation, where the compiler replace those values on the preprocessor as the first stage of compilations 
those works like true or false 
## the example :

#include <stdbool.h>

bool isEngineRunning = true;
this codes will be translated into the following 


_bool isEngineRunning=1

5. <inttype.h>
 this header makes shure that the data stay the same zise accross the machine and other devices 
 example if i want to send the data across the different device i want it to be constant accross the devices, no matter the archecture of the hardware if my data size is 32 bit it will ajust it self on the hardware if on the arduino is long int and on esp is int the data will stay the same  


6. <tgmath.h>
this header allowed the type-generalic math 
this header allow to write the generlic function where the compuler find the corresponding values which fit with that complex values 

and in c99 there was the introductions of new builtin datatype as follow 
## those are 
long long , unsigned long long ,
_bool,
_complex,
_imagniary
inline, restrict 
## C11 STANDARD:

introduced some header which cames to improve the c standard 
those was most for supporting the parallel programming like thread and also the actomic 

# the added librarys are the following 
1. <stdalign.h>

alignas and alignof marcos 
2.<stdatomic.h>

atomic operations 

3.<stdnoreturn.h>

it helps for no return macros 

4.<thread.h>
the thread functions for parallel programming 

5.<uchar.h> 

UTF-16 and UTF-32 encoding 
after this realease it allowed the programmer to write the programs to run on the parallel processors and cpu with thread functions and also to control the race conditions which alise from the parallel programming from using the atomic data type 



the datatype introduced and keyword was introduced 


_alignas ,_alignof ,_Atomic ,_Generic, Noreturn, _static_asserts, _THread_local 


## C17 STANDARD :
 this standard has been released in 2018 but becouse the developer has arleady adopted to say about C17 in this editions or the standard there were no new things has been introduced expect about improving the C11 and fix some minor defects 


## C23 STANDARD:

this is the last editions currently which has been relaeased in 2023 
and what is doing is was mostly adding two headers which are 
1.<stdchdint.h> functions and macros for checked integer arthematics 

2.<stdbit.h>

functionf for bit manipulations 
the purpose of those two headers for improving the hardware as efficent as possible 


those what was besically studied last day and today what i am going to do is to just to revise also the part of the number representatiosn and conversions which has been learned but on the language converations i will deal with tha part for 
data type and the data convestions 


# in Unit one we have learned the following 


we have learned the numerical conversions like translating from integer into the hexadecimals and also the data type and to see thier values using devison methods 


other things learned is how data are stored in memory
so we first learned the first basic memory concept which is register 

## register :
is a simple block of memory which are made up of cells which are consist of filp-flop to mean that as flip flop can keep one values at the time the register is collections of them and based on the number it hold that determines the name of the register liek 
8-bit registers where it can store about 8 bit or 1byte 
in general it can do the following 
## store the two values of hexa decimal like 0xff 
which are eqaul 
## 0b 1111 1111 

from that we build the memory by combining the many registers and here we add other crusal things which is 
## address :

in memory we store each address also in the other register memory address part which is responsible for storing those registers 

the other things amazing things we learned is how integers are stored in machines there are two ways :
## LITTLE INDIAN :

the least signaficant bit is what is writen in the memory first 
example: 

## 100011: here the number which will be the first in the memory will be 1 then 1 ,0,0,0,1 to mean that here will use the right shift register with serial in and serial out 

## BIG INDIAN : 
the most signficant bit which can be reverse of the number there 
i think this one can be hard becouse they can need to revise them after reaching on the ouput 

## also yesterday we have achieved to cover the unit 2 in the book which is called 

# UNIT 2 : DATA TYPE AND OPERATORS 


where we started writing a simple lines of codes like 
int main() {
 //setatment

 return 0;
}

they explained that instead of int someone may use void 
and someone may omit the return 


from there we have talked about the header 
#include <stdio.h>

as the preprocessor directive which replaced by thier actual codes in compilations time and header for stdio.h for allowing the input and ouput of the data 


other thing learned was data type :

## DATA TYPE :
int : which spacify the integer numbers with 4byte of memory
char : which occupy about 8 bit which are equal to the 1 byte 
double : which also can contain the same as 32 
but long double: can contains almost 8byte which are equual to the 64 bits 


## data type declarations :
how the data are being declared where by using the data type 
as follow

DATATYPE VAIABLENAME;


and how to use the printf functions for displaying the those numbers and that function 
## prinf() :
that is the function from the header stdio.h which helps for printing the things on the screen 


it has two parameters the string which contains the formats for showing or displaying those numbers on the screen the second one is order of what is going to be dispayed 

printf ("the things to print % formats ", valiable_name,baliable_name1) and so on 

for showing different data type we use the following 

%d for integers 
%c for characters 
%lu for long unisigned numbers 
%f for floating numbers 
%u unisgned numbers 
%#x for hexadecimals 
%#o octal numbers 

## sizeof operator in c


this used to show all the size a single data type can hold in the memory to use that we use the specifier which is 
%ld 

## the other things we have learned is 


## UNISGNED CHAR DATA TYPE 

the minimum integers are for 
0000 0000 the maximum signed int are 
1111 1111 and those numbers are equal to 
2^power 8 -1 in total which is about 255 


## the last concept for last day concept for shift operators 

we have two shift operators which are the following 
## << shift left operator :
which are used to shift on the left which are equal to multiple by two example 

0000 0101 which is 5
when i shift on the left with one it will be like 
0001 010 this will be ten

## shift right operator :

this also acts as diving with two as shown above to today what i learned will be written in the following part of the discribution where i learned the unit one of the computer organization and design and also the unit one of the computer sytems on programmer percipective and i have wake up at 5:00 am now is at 1:45 as the time at home then after noone i will learn a little on c and then take sport and then rest 


and i will end up at night writing the summary of what i have done now accoring to what i have written is about 225,120







