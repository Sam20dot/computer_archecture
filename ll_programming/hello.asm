; they have what we call section becouse the single memory can be albe to separate them esier 


global_start 

section .data 

message : db 'hello world',10 ; db means bytes to mean that all the values here are bytes 


section .text 
_start :
    mov rax,1                        ; system call number should be stored in rax 
    mov rdi,1                        ;arguments #1 in rdi: where to write (discriptor)?
    mov rsi, message                 ;arguments #2 in rsi : which answer the question like where does the string start 
    mov rdx,14                       ;argements #3 in rdx: which answers how many byte to write in this case is 14
    syscall                          ; this instruction invokes a  system call in this call is write
