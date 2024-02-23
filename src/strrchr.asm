bits 64

section .text

global strrchr

global rindex

strrchr:
    xor rax, rax
    xor rcx, rcx
    cmp sil, 0 ; Si le char est null alors on va exit
    je handleNullByte

loopmystrrchr:
    cmp byte [rdi], 0 ; Si le pointer de la première string est null
    je handleError

    cmp byte [rdi], sil ; Si on trouve le charactère
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
    mov rax, rdi ; Je return le dernier character trouver
    ret

handleError:
    ret

rindex equ strrchr
