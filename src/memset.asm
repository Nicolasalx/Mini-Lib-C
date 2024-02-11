bits 64
section .text
global memset

memset:
    xor rax, rax ; intialisation de rax
    xor rcx, rcx ; initialize the counter
    ; counter will be compare with the size_t n
    ; if both are equal else the nb chars copied in destination are done
    mov rdx, rdx ;

loopmemset:
    cmp rcx, rdx ; Check if counter and n are equal / if both are equal else the nb chars copied in destination are done
    je memsetExit

    mov byte [rdi + rcx], sil ; Move the int (c) at the pos of rid + compteur

    inc rcx

    jmp loopmemset

memsetExit:
    mov rax, rdi
    ret
