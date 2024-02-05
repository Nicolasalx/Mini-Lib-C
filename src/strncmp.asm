bits 64
section .text
global strncmp

strncmp:
    xor rax, rax
    xor rcx, rcx

compareEachChar:

    movzx rax, byte [rdi]
    movzx rbx, byte [rsi]
    mov rdx, rdx

    cmp rdx, rcx
    je exitSuccess

    cmp byte [rdi], 0
    je checkSuccess

    cmp byte [rsi], 0
    je errorHandle

    cmp rax, rbx
    jne errorHandle

    inc rdi
    inc rsi
    inc rcx

    jmp compareEachChar

checkSuccess:
    cmp byte [rsi], 0
    je exitSuccess

    jmp errorHandle

exitSuccess:
    mov rax, 0
    ret

errorHandle:
    cmp byte[rdi], 0
    je firstStringEmpty

    cmp byte[rsi], 0
    je secondStringEmpty

    sub rax, rbx
    ret

firstStringEmpty:
    mov rax, 0
    sub rax, rbx
    ret

secondStringEmpty:
    mov rbx, 0
    sub rax, rbx
    ret
