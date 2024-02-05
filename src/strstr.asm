bits 64

section .text

global strstr

strstr:
    xor rax, rax ; initialize rax
    cmp byte [rsi], 0 ; verify if the second string is empty
    je handleExit ; if empty exit
    mov rdx, rsi ; rdx will stock the second string
    xor rcx, rcx

looppmystrcspn:
    cmp byte [rdi], 0 ; Verify if the actual pointer is empty of the first string
    je charNotFound

    jmp loopSecondString ; If the first string is not empty, continue

loopSecondString:
    cmp byte [rdx], 0 ; verify if the actual pointer is empty of the second string
    je endSndString ; if the second string is finish go on next char of the first string

    mov al, [rdx]
    cmp al, [rdi]
    je findCharacterandexit

    inc rdx ; move to the next elem of the second string

    jmp loopSecondString

endSndString: ; continue to next incrementation of pointer of the first string
    inc rdi
    inc rcx
    mov rdx, rsi ; We set rdx at the pointer on the top of the second string

    jmp looppmystrcspn

findCharacterandexit: ; if the char in first string is equal to char of second string -> exit
    mov rax, rdi
    ret

charNotFound:
    mov rax, 0
    ret

handleExit:
    mov rax, rdi
    ret
