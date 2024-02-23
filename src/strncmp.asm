bits 64
section .text
global strncmp

strncmp:
    xor rax, rax
    xor rcx, rcx

compareEachChar:

    movzx rax, byte [rdi] ; Copie dans rax rdi et remplis les derniers bits avec 0
    movzx rbx, byte [rsi] ; Copie dans rbx rsi et remplis les derniers bits avec 0
    mov rdx, rdx

    cmp rdx, rcx ; Si le size_t est égal au compteur on a comparer tous les char correctement sans avoir d'erreur
    je exitSuccess

    cmp byte [rdi], 0 ; Si première string est empty on va exit
    je checkSuccess

    cmp byte [rsi], 0 ; Si la seconde string est empty, ca veut dire que elle est plus courte que la première
    je errorHandle

    cmp rax, rbx
    jne errorHandle

    inc rdi
    inc rsi
    inc rcx

    jmp compareEachChar

checkSuccess:
    cmp byte [rsi], 0 ; Si la seconde string est empty, ca veut dire qu'elle fait la meme taille que la première et que c'est good
    je exitSuccess

    jmp errorHandle

exitSuccess:
    mov rax, 0
    ret

errorHandle:
    cmp byte[rdi], 0
    je firstStringEmpty

    cmp byte[rsi], 0
    je secondStringEmpty

    sub rax, rbx
    ret

; Pour la valeur de return on soustrait à 0 la valeur sur laquelle pointe la seconde string
firstStringEmpty:
    mov rax, 0
    sub rax, rbx
    ret

; Pour la valeur de return on soustrait à 0 la valeur sur laquelle pointe la seconde string
secondStringEmpty:
    mov rbx, 0
    sub rax, rbx
    ret
