bits 64
section .text
global memcpy

memcpy:
    xor rcx, rcx ; compteur à 0

loopMemcpy:
    cmp rcx, rdx ; On compare si le compteur est égal au size_t n
    je exit

    mov r15b, byte[rsi + rcx]
    ; On stocke un octet par un octet, soit 8 bit
    ; Donc nous chargerons le résulat dans r15b
    ; La partie de droite est la valeur au pointeur de la source + compteur
    ; Chaque incrémentation le ptr se déplace

    mov byte [rdi + rcx], r15b
    ; On stocke à l'adresse du ptr (incrémenter par le compteur), l'octet précédemment calculé

    inc rcx ; Incrémentation du compteur

    jmp loopMemcpy


exit:
    mov rax, rdi ; On déplace le ptr de rdi dans rax
    ret
