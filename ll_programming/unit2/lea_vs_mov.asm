; rsi <- address of lable 'codes' a number 
mov rsi ,codes

; memory content starting with the 'codes ' address 
;8 concective bytes are takesn becouse rsi is 8bytes long 

mov rsi,[codes]
; rsi <- address of 'codes'
; this is the equavalent to mov rsi, codes

; this one load the values or address of those pointed values 

lea rsi , [codes]

mov rsi [codes +rax]
; this is equal to 
; mov rsi ,codes
; add rsi,rax
; we can do this with single move 

lea  rsi , [codes+rax]


