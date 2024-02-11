bits 64
global index

section .data
    empty_string db 0
section .text

index:
    xor rax, rax
    cmp sil, 0 ; Si le char c est un \0 alors on return une string vide
    je exitEmptyString

loopMyIndex:
    cmp byte[rdi], 0 ; Si on a parser la string sans trouver de char, alors on return null
    je exitFailed

    cmp byte[rdi], sil ; Si on trouve le charactère, alors on returne la fin de la string
    je exitSuccess

    inc rdi

    jmp loopMyIndex

exitEmptyString:
    mov rax, empty_string
    ret

exitSuccess:
    mov rax, rdi
    ret

exitFailed:
    mov rax, 0
    ret
