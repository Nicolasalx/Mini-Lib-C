bits 64

section .text

global ffs

ffs:
    cmp edi, 48
    je exitFailure

    mov rcx, 1

loopffs:
    cmp edi, 0 ; Si tous les bits ont été vérifiés ont exit
    je exitFailure

    test edi, 1 ; Si on trouve le bit de poids faible on return la position du compteur
    jnz exitSuccess ; si edi n'est pas null on exitSuccess

    shr edi, 1 ; On décale le bit dans edi à droite
    inc rcx ; On incrémente la position du bit
    jmp loopffs

exitSuccess:
    mov rax, rcx ; On return la position du bit 1 trouvé le plus à droite
    ret

exitFailure:
    mov rax, 0 ; Si tous les bits ont été vérifiés ou que index == 0
    ret
