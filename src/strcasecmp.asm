bits 64
section .text
global strcasecmp

strcasecmp:
    xor rax, rax
    cmp byte [rdi], 0 ; On check si la première string n'est pas empty
    je firstStringEmptyAtStart

compareEachChar:
    movzx rax, byte [rdi] ; Copie dans rax rdi et remplis les derniers bits avec 0
    movzx rbx, byte [rsi] ; Copie dans rbx rsi et remplis les derniers bits avec 0

    cmp rax, 0 ; On check que le pointeur sur la première string n'est pas null
    je errorHandle

    cmp rbx, 0 ; On check que le pointeur sur la deuxième string n'est pas null
    je errorHandle

    jmp compareSecondParts

compareSecondParts:
    jmp transformCharFirstString

compareThirdParts:
    cmp rax, rbx
    jne errorHandle

    ; On incrémente les deux string
    inc rdi
    inc rsi

    jmp compareEachChar

; On check si c'est en higger case pour mettre en lower case pour la première string
transformCharFirstString:
    cmp rax, 65 ; Si c'est inférieur à 65 on ajoute pas 32
    jl transformCharSecondString

    cmp rax, 90 ; Si c'est supérieur à 90 on ajoute pas 32
    jg transformCharSecondString

    add rax, 32
    jmp transformCharSecondString

; On check si c'est en higger case pour mettre en lower case pour la seconde string
transformCharSecondString:
    cmp rbx, 65 ; Si c'est inférieur à 65 on ajoute pas 32
    jl compareThirdParts

    cmp rbx, 90 ; Si c'est supérieur à 90 on ajoute pas 32
    jg compareThirdParts

    add rbx, 32
    jmp compareThirdParts

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

firstStringEmptyAtStart: ; Si la première string est vide au start on soustrait au premier charactère de la seconde string
    movzx rbx, byte[rsi]
    mov rax, 0
    sub rax, rbx

    cmp rbx, 65
    jl exitFinal

    cmp rbx, 90
    jg exitFinal

    sub rax, 32
    ret

secondStringEmpty: ; Si la seconde string est vide au start on ajoute au premier charactère de la première string
    sub rax, rbx

    cmp byte[rdi], 65
    jl exitFinal

    cmp byte[rdi], 90
    jg exitFinal

    add rax, 32
    jmp exitFinal

exitFinal:
    ret
