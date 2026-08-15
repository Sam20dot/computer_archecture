# MUTEX USAGE IN PRALLEL PROGRAMMING 
in prallel programming we have a concept which is called **race condition**
to mean that one thread can read and other maybe delete or doing other things on that file 
so there will be the time all thread can works on the same data at the same time 
sometime becouse of electronics delay its hard to know what can came first 
to solve that we use what we call mutex to prevent that to happen 


**mutex** :
      ``it act as the process by which no two thread can access the same global data 
      at the same time 
      we have three things one is :
    ``
    **lock**: before we call the thread we lock that data so that only that 
              thread can access that data at that time and when it finish 
              we call 
    **unlock**: to allow other thread to access it
## where the mutex cames from ?
this word was created by **E. W. DIJXSTRA** in 1965 mutex cames from two words 
which has been joined together which are 
***mature*** and ***exculsion*** and as  from mathematics,
that has been explained in the paper published in septemeber in 1965 whose the title 
## **Solution of a Problem in Concurrent Programming Control**  
as the way we can allow two thread to access the same data but by using the boolean values to 
store the locks if one thread takes that lock other thread will wait until it finish 
when it unlock it other can use it 



