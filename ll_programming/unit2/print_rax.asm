; to print out the values of the rax values 
section .data 
codes : 
   db '123456789ABCDEF' ; those are hexadecimals values 

 ; then we go on the section of text as the instruction for showing the values within the rax 
section .text 
  
global _start 

_start:
  mov rax , 0x112233
  mov rdi , 1
  mov rdx ,1
  mov rcx , 64
  ; each 4 bits should be output as one headecimals digits 
  ;use shift and bitwice tAND TO isolate them 
  ; then result is the offset of codes array

  ; then we define the function which is called loop as local function with .
  .loop :
    push rax
    sub rcx,4
    ; is the simallest part of the s
    sar rax,cl 
    and rax,0xf

    ; then load the values from the rax and codes 
    lea rsi, [codes+rax]
    mov rax,1 

    push rcx
    syscall
    pop rcx

    pop rax

    test rcx,rcx

    ; after testing we can see if the what was the ouput 
    jnz .loop
    mov rax,60
    xor rdi, rdi
    syscall 

