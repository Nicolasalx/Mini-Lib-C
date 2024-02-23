bits 64

section .text

global strpbrk

strpbrk:
    cmp byte [rsi], 0 ; On check si la seconde string n'est pas empty
    je exit
    mov rdx, rsi ; On stock la seconde string dans rdx
    xor rcx, rcx

looppmystrpbrk:
    cmp byte [rdi], 0 ; On check si le pointeur sur la première string n'est pas null
    je exit

    jmp loopSecondString

loopSecondString:
    cmp byte [rdx], 0 ; On check si le pointeur sur la première string n'est pas null
    je endSndString ; Si la seconde string est fini on va au prochain char de la pre if the second string is finish go on next char of the first string

    mov al, [rdx]
    cmp al, [rdi] ; Si le character n'a pas été trouver
    je getAllTheCharsAfter

    inc rdx ; On se déplace au prochain élément de la seconde string

    jmp loopSecondString

endSndString: ; On continue à la prochaine incrémentation du pointer de la première string
    inc rdi
    inc rcx
    mov rdx, rsi ; On set rdx au pointer de la seconde string

    jmp looppmystrpbrk

exit:
    mov rax, 0
    ret

getAllTheCharsAfter:
    mov rax, rdi
    ret

