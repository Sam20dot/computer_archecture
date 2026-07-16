# signal 

are generated when an interupts are recieved so signals can also called 
### interupter signals 

but someone may ask what is signals and what are interuppters 
 # interrupts :
     are abornmal behavior can occur within the systems like deviding with zero, terminate the signals like 
     ctr+c and others 

# TYPES OF INTERRUPTERS :

interupters are generated or signals by two categories 
 1. Hardware interrupts 
 2. software interrupts 

 ## how does interrupts are being resolved 
 when interrupter happen , signals detected and action may happen depends on the other predefined 
 functions for handling that part 
 depends on operting system we can have a number of predefined number of signals parameters 
 Default action: (e.g., SIGSEGV terminates the process and dumps core, SIGCHLD is ignored).

Ignore the signal: The process acts like nothing happened (except for SIGKILL and SIGSTOP, which cannot be ignored).

Catch the signal: The CPU pauses your program, jumps to a custom function you wrote (a signal handler), executes it, and then jumps back to where your program was.


the whole signals which are in the following on linux which are 64 now 
 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
63) SIGRTMAX-1  64) SIGRTMAX
 
