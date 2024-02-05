bits 64
section .text
global strcmp

strcmp:
    xor rax, rax

compareEachChar:
    movzx rax, byte [rdi]
    movzx rbx, byte [rsi]

    cmp byte [rdi], 0
    je checkSuccess

    cmp byte [rsi], 0
    je errorHandle

    cmp rax, rbx
    jne errorHandle

    inc rdi
    inc rsi

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
