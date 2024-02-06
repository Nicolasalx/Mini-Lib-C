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

    mov [rdi], sil ; Move the byte from sil to [rdi] (sil is the int n)

    inc rdi ; Increment destination for the emplacment of the nextptr of source
    inc rcx

    jmp loopmemset

memsetExit:
    ret
