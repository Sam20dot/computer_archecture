# UNIT 13 
 this unit was teaching how we can fix integer values so that they can remain as they on each machine or arthecture 
 by using the following sytax 
  ## intN_t
      which is good for telling the compiler to revercce only that space of the bytes on machine 
 
 but there is a away we can say ok we want to use this machine on what ever the space you can provide but 
 at least we need this amount of bit to be represented 

 to do that we use the following 
 syntax :
## int_leastN_t 
     to mean that this can help us when we are doing somethings which can either takes many values but which also can not 
     go in the minimum length of the values 


but what if we want to increase the spead without carrying about the ram size 
we can also do that where we can tell a compiler that look at the machine beneath you and then tell us 
what is capable for being fast what is the data type it can use to be fast no matter the size we want what is fast 
at this moment we ues the following 
syntax :
## int_fastN_t 
      to mean that we can have at least 8 bit or 16 bit for better machine friendly we it can be apped into 64-bit size 




! althought this is good for spead but that fast occupy much memory so we do that for specific part like through arrays 
but for many numbers like array we have to use the easier part like int8_t like if we are on the emmded systems like esp or other 
board we can use the uint or atleast to preseve the space and then maximize the speed 



