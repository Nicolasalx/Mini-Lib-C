bits 64

section .text

global strcspn

strcspn:
    xor rax, rax
    cmp byte [rsi], 0 ; On vérifie si la second string est vide
    je handleExit
    mov rdx, rsi ; rdx va stocker la seconde string
    xor rcx, rcx

looppmystrcspn:
    cmp byte [rdi], 0 ; On vérifie si le char qui pointe sur la première string n'est pas null
    je counterChar

    jmp loopSecondString

loopSecondString:
    cmp byte [rdx], 0 ; On vérifie si le char qui pointe sur la seconde string n'est pas null
    je endSndString

    mov al, [rdx]
    cmp al, [rdi] ; Si rdx == rdi, alors on a trouver le charactère
    je findCharacterandexit

    inc rdx ; On move sur le prochain élément de la seconde string

    jmp loopSecondString

endSndString: ; continue to next incrementation of pointer of the first string
    inc rdi
    inc rcx
    mov rdx, rsi ; On place rdx au pointeur de la seconde string

    jmp looppmystrcspn

findCharacterandexit: ; Si le char pointer de la première string est égal au char pointer de la seconde string, on exit
    mov rax, rcx
    ret
handleExit:
    xor rcx, rcx
    jmp counterChar

; Si la seconde string est vide on return la size de la première string
counterChar:
    cmp byte [rdi], 0
    je exit
    inc ecx
    inc rdi
    jmp counterChar

exit:
    mov rax, rcx
    ret
