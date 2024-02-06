bits 64

section .text

global mystrpbrk

mystrpbrk:
    cmp byte [rsi], 0 ; verify if the second string is empty
    je exit ; if empty exit
    mov rdx, rsi ; rdx will stock the second string
    xor rcx, rcx

looppmystrpbrk:
    cmp byte [rdi], 0 ; Verify if the actual pointer is empty of the first string
    je exit

    jmp loopSecondString ; If the first string is not empty, continue

loopSecondString:
    cmp byte [rdx], 0 ; verify if the actual pointer is empty of the second string
    je endSndString ; if the second string is finish go on next char of the first string

    mov al, [rdx]
    cmp al, [rdi] ; if a character is found
    je getAllTheCharsAfter

    inc rdx ; move to the next elem of the second string

    jmp loopSecondString

endSndString: ; continue to next incrementation of pointer of the first string
    inc rdi
    inc rcx
    mov rdx, rsi ; We set rdx at the pointer on the top of the second string

    jmp looppmystrpbrk

exit:
    mov rax, 0
    ret

getAllTheCharsAfter:
    mov rax, rdi
    ret

