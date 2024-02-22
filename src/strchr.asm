bits 64
section .text
global strchr

global index

strchr:
    xor rax, rax
    cmp sil, 0
    je handleNullByte

counterChar:
    cmp byte [rdi], 0
    je handleError

    cmp byte [rdi], sil
    je handleSuccess

    inc rdi
    jmp counterChar


secondPartCounterChar:
    inc rdi
    jmp counterChar

handleSuccess:
    mov rax, rdi
    ret

handleNullByte:
    cmp byte[rdi], 0
    je exitNullByte
    inc rdi
    jmp handleNullByte

exitNullByte:
    mov rax, rdi
    ret

handleError:
    mov rax, 0
    ret

index equ strchr
