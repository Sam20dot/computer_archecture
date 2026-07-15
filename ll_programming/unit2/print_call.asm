section .data 
newline_char :db 10
codes: db '0123456789ABCDEF'
; we are going to add the values to test if the values are working as we intented to see them 
; we are going to test the little indians 
demo1: dq 0x1122334455667788
demo2:db 0x11, 0x22,0x33,0x44,0x44,0x66,0x77,0x88


; the instruction sections 
section .text 
global _start 

print_newline:
  mov rax ,1     ; system call identifier 
  mov rdi ,1     ;stdout file discriptor 
  mov rsi ,newline_char ; where do we take data from 
  mov rdx ,1            ; the size of the data 
  syscall 
  ret 
print_hex:
  mov rax,rdi
  mov rdi,1
  mov rdx,1
  mov rcx ,64

iterate:
 push rax 
 sub rcx,4
 sar rax,cl 
 and rax,0xf 
 lea rsi, [codes +rax]
 mov rax,1

 push rcx
 syscall 
 pop rcx
 pop rax
 test rcx,rcx ; if is equal to zero all digits are shown 
 jnz iterate 
 ret 


 _start:

 mov rdi, 0x1122334455667788
 call print_hex
 call print_newline


 mov rdi ,[demo1]
 call print_hex
 call print_newline

 ; and then we print those values as they are in the stored in reverse 
 mov rdi, [demo2]
 call print_hex 
 call print_newline





 mov rax,60
 xor rdi,rdi
 syscall 


