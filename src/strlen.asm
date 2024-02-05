bits 64
section .text
global strlen

strlen:
    xor rax, rax
    xor rcx, rcx

counterChar:
    cmp byte [rdi], 0
    je exit
    inc rcx
    inc rdi
    jmp counterChar

exit:
    mov rax, rcx
    ret
