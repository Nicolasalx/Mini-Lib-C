bits 64
section .text
global memcpy

memcpy:
    xor rax, rax ; intialisation de rax
    xor rcx, rcx ; initialize the counter
    ; counter will be compare with the size_t n
    ; if both are equal else the nb chars copied in destination are done
    mov rdx, rdx ;

loopmemcpy:
    cmp byte [rsi], 0 ; Check if rsi has reached the end of the string
    je memCpyExit

    cmp rcx, rdx ; Check if counter and n are equal / if both are equal else the nb chars copied in destination are done
    je memCpyExit

    mov al, [rsi] ; Move the byte at [rsi] into al
    mov [rdi], al ; Move the byte from al to [rdi]

    inc rsi ; Increment the source for go on next ptr
    inc rdi ; Increment destination for the emplacment of the nextptr of source

    inc rcx
    jmp loopmemcpy
memCpyExit:
    ret
