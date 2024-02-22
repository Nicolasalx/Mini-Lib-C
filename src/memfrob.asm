bits 64
section .text
global memfrob

memfrob:
    xor rax, rax

loopmemfrob:
    mov al, byte [rdi] ; On load src dans al

    cmp byte[rdi], 0 ; On check si on est à la fin de la string
    je exit

    xor al, 42 ; J'encrypte avec la clé 42

    mov byte [rdi], al ; On met le byte encrypte dans la source

    inc rdi
    jmp loopmemfrob

exit:
    ret
