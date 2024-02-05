bits 64

section .text

global strrchr

strrchr:
    xor rax, rax
    xor rcx, rcx

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

handleError:
    ret




