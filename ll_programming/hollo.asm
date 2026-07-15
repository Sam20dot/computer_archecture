section .data 

message :db "hello world ",10

section .text
global_start 

_start :
   
   mov rax, 1
   mov rdi, 1
   mov rsi,message
   mov rdx,14
   syscall

; if we dont terminate this we will go outside the eginve place which couses the segimentation foult 
   mov rax,60
   xor rdi,rdi
   syscall 




