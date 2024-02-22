bits 64

section .text

global strrchr

global rindex

strrchr:
    xor rax, rax
    xor rcx, rcx
    cmp sil, 0
    je handleNullByte

loopmystrrchr:
    cmp byte [rdi], 0
    je handleError

    cmp byte [rdi], sil
    je handleEqual

    jmp incrementPointer

incrementPointer:
    inc rdi
    jmp loopmystrrchr

handleEqual:
    mov rax, rdi
    jmp incrementPointer

handleNullByte:
    cmp byte[rdi], 0
    je exitNullByte
    inc rdi
    jmp handleNullByte

exitNullByte:
    mov rax, rdi
    ret

handleError:
    ret

rindex equ strrchr
