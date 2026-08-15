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
