bits 64
section .text
global strchr

strchr:
    xor rax, rax

counterChar:
    cmp byte [rdi], 0
    je handleError

    cmp byte [rdi], sil
    je handleSuccess

    inc rdi
    jmp counterChar


secondPartCounterChar:
    inc rdi
    jmp counterChar

handleSuccess:
    mov rax, rdi
    ret

handleError:
    mov rax, 0
    ret
