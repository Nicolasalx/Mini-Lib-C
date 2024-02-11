bits 64
section .text
global strcasecmp

strcasecmp:
    xor rax, rax
    cmp byte [rdi], 0
    je firstStringEmptyAtStart

compareEachChar:
    movzx rax, byte [rdi]
    movzx rbx, byte [rsi]

    cmp rax, 0
    je checkSuccess

    cmp rbx, 0
    je errorHandle

    jmp compareSecondParts

compareSecondParts:
    jmp transformCharFirstString

compareThirdParts:
    cmp rax, rbx
    jne errorHandle

    inc rdi
    inc rsi

    jmp compareEachChar

transformCharFirstString:
    cmp rax, 65
    jl transformCharSecondString

    cmp rax, 90
    jg transformCharSecondString

    add rax, 32
    jmp transformCharSecondString

transformCharSecondString:
    cmp rbx, 65
    jl compareThirdParts

    cmp rbx, 90
    jg compareThirdParts

    add rbx, 32
    jmp compareThirdParts

checkSuccess:
    cmp rax, 0
    je exitSuccess

    jmp errorHandle

exitSuccess:
    mov rax, 0
    ret

errorHandle:
    cmp rax, 0
    je firstStringEmpty

    cmp rbx, 0
    je secondStringEmpty

    sub rax, rbx
    ret

firstStringEmpty:
    mov rax, 0
    sub rax, rbx
    ret

firstStringEmptyAtStart:
    movzx rbx, byte[rsi]
    mov rax, 0
    sub rax, rbx

    cmp rbx, 65
    jl exitFinal

    cmp rbx, 90
    jg exitFinal

    sub rax, 32
    ret

secondStringEmpty:
    sub rax, rbx

    cmp byte[rdi], 65
    jl exitFinal

    cmp byte[rdi], 90
    jg exitFinal

    add rax, 32
    jmp exitFinal

exitFinal:
    ret
