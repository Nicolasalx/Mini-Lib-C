bits 64

section .text

global memmove

; rdi : destination
; rsi : source
; ecx : size_t n

memmove:
    xor rax, rax
    xor rcx, rcx ; compteur à 0

loop_memmove:
    cmp rsi, rdi ; Compare les adresses de src et destination
    jbe backward_move ; Si src <= dest, on copie de l'avant vers l'arrière

    jmp forward_move ; Si source est avant dest

forward_move: ; Copie avant vers fin
    cmp rdx, 0
    je exit

    mov r15b, byte[rsi + rcx]
    mov byte[rdi + rcx], r15b
    inc rcx

    dec rdx

    jmp forward_move

backward_move: ; Copie fin vers avant
    cmp rdx, 0
    je exit

    dec rdx
    mov r15b, byte[rsi + rdx]
    mov byte[rdi + rdx], r15b

    jmp backward_move

exit:
    mov rax, rdi
    ret
