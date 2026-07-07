; due to we have been pointing on the wrong values when we did not put the exit point in the systems 
section .data 
message : db "hello world!",10

section .text 
global _start 

_start : 
   mov rax,1         ; the write syscall number is number which discibes the syscall function to write the function 
   mov rdi,1         ;stdout descriptor 
   mov rsi,message   ;string address where they start 
   mov rdx,14        ; the length of the file 
   syscall 


   mov rax,60        ; exit system call number 
   xor rdi,rdi
   syscall 





