bits 64
global rindex

section .data
    empty_string db 0

section .text
rindex:
    xor rcx, rcx
    xor rax, rax
    cmp sil, 0 ; Si le char c est un \0 alors on return une string vide
    je exitEmptyString

    mov rdx, rdi
    jmp computeSizeString

computeSizeString:
    cmp byte[rdx], 0
    je startRindex

    inc rcx
    inc rdx

    jmp computeSizeString

startRindex:
    xor rdx, rdx

    lea rdx, [rdi + rcx - 1] ; On déplace rdx à l'index de la fin de la string de rdi

    jmp loopMyRindex

loopMyRindex:
    cmp byte[rdx], 0 ; Si on arrive au début de la string sans avoir trouver le charactère, c'est une erreur.
    je exitFailed

    cmp byte[rdx], sil
    je exitSuccess

    dec rdx
    jmp loopMyRindex

exitEmptyString:
    mov rax, empty_string
    ret

exitSuccess:
    mov rax, rdx
    ret

exitFailed:
    mov rax, 0
    ret
