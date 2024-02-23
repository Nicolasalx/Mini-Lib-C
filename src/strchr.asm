bits 64
section .text
global strchr

global index

strchr:
    xor rax, rax
    cmp sil, 0 ; Si le char c est Null on jmp
    je handleNullByte

counterChar:
    cmp byte [rdi], 0 ; Si le pointeur sur la 
    je handleError

    cmp byte [rdi], sil ; Si on trouve le char dans la string on met rdi dans rax
    je handleSuccess

    inc rdi
    jmp counterChar


secondPartCounterChar:
    inc rdi
    jmp counterChar

handleSuccess:
    mov rax, rdi
    ret

; On return la string entière et on exit
handleNullByte:
    cmp byte[rdi], 0
    je exitNullByte
    inc rdi
    jmp handleNullByte

exitNullByte:
    mov rax, rdi
    ret

handleError:
    mov rax, 0
    ret

index equ strchr
