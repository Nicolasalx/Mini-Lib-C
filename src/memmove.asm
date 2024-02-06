bits 64

section .text

global memmove

memmove:
    xor rax, rax ; Initialize rax
    xor rcx, rcx ; Initialize counter
    mov rdx, rdx ; Initialize rdx with the size_t n

    cmp rsi, rdi ; At start if src and dest ptr are the same we exit
    je memmoveExit

    cmp rsi, rdi ; Check if the destination is before the source and they overlap
    jg caseOfOverlap

beforeCopy:
    cmp rcx, rdx ; if the counter is equal to the size_t n -> exit
    je memmoveExit

    mov al, [rsi]
    mov [rdi], al ; We move the rsi in rdi

    inc rsi
    inc rdi
    inc rcx

    jmp beforeCopy

caseOfOverlap:
    ; Move source and destination pointers to the end
    lea rsi, [rsi + rdx - 1]
    lea rdi, [rdi + rdx - 1]

afterLoop: ; if dest is before src
    ; (Il y a un chevauchement des deux zones mémoires)
    cmp rcx, rdx
    je memmoveExit

    mov al, [rsi]
    mov [rdi], al

    dec rsi
    dec rdi

    inc rcx

    jmp afterLoop

memmoveExit:
    ret

