; we are going to write the assembly languages which display hello world on terminal using the systems call 
; writes and the stdout as it has the file discriptor which is one 

section .data 
 message :db "hello world",10

 ; the sections for the instructions 
 section .text 
 global _start 
 _start:
   mov rax,1
   mov rdi,1
   mov rsi, message
   mov rdx,14
   syscall

   ; we can add the section of doing the addition or multplications section and then display them on the screen
   mov r10,43
   mov r9,433
   sub r10,r9

   mov rax,1
   mov rdi,1
 
   mov rsi,r10
   mov rdx,21
   syscall 


; then we have to let it allow it to terminate or exit correctly withougt accessing the segmentaion foults 
  mov rax,60 ; as the systems for exit() to go out of the systems 
  xor rdi,rdi,
  syscall

