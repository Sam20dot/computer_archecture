cmp rax, 42
jl yes 
mov rbx ,0

jmp ex

yes:
  mov rbx,1
ex:
; for sign fag we use this one js or jns and for zero flag we use jF and jnF 

; also we can use those for jumping when the values is above like 
; ja (jump if above )\(jump if bellow)jb after comparing with unsing values with comp 

; for signed 
; we use the following 
; jg (jump if greater ) jl (jump if less ) for signed 

;jae (jump if above or equal ) jle (jump if less or equal )

