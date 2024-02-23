bits 64
section .text
global strcmp

strcmp:
    xor rax, rax

compareEachChar:
    movzx rax, byte [rdi] ; Copie dans rax rdi et remplis les derniers bits avec 0
    movzx rbx, byte [rsi] ; Copie dans rbx rsi et remplis les derniers bits avec 0

    cmp byte [rdi], 0 ; Si on a parcouru la première string alors on return 0
    je checkSuccess

    cmp byte [rsi], 0 ; Si on a parcouru la deuxième string mais pas la première alors la première est plus grande que la seconde
    je errorHandle

    cmp rax, rbx ; Si le char rax n'est pas égal à rbx alors les string ne sont pas identiques
    jne errorHandle

    inc rdi
    inc rsi

    jmp compareEachChar

checkSuccess:
    cmp byte [rsi], 0 ; Si la seconde string est aussi fini on exit sinon la première string est plus courte que la seconde
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
