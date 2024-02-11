bits 64

section .text

global strstr

; rdi -> meule de foin
; rsi -> aiguille

strstr:
    xor rax, rax
    xor rcx, rcx

    cmp byte[rdi], 0
    je exit

    cmp byte[rsi], 0
    je exitFinalSuccess

    mov rbx, rsi
    jmp mystrlen ; Calculer la taille de la string "aiguille"

mystrlen:
    cmp byte [rsi], 0
    je endstrlen
    inc rcx
    inc rsi
    jmp mystrlen

endstrlen:
    mov rdx, rcx ; On stocke la valeur de la taille de aiguille dans rdx
    xor rcx, rcx ; On réinitialise rcx pour pouvoir l'utiliser par la suite
    mov rsi, rbx ; On reset rsi à sa valeur d'origine qui a été modifié par strlen
    jmp loopMyStrStr

loopMyStrStr:
    cmp rdi, 0 ; On check si la string meule de foin n'arrive pas au null byte
    je exit

    ; On va venir checker si l'élément de rdi est égal à l'élément de rsi[index]
    ; meule_de_foin[i] == aiguille[index]
    ; index est incrémenté quand on tombe sur une la bonne valeur dans l'aiguille
    ; Sinon il est reset à 0

    mov al, byte [rdi] ; On met le caractère de al dans haystack
    mov bl, byte [rsi + rcx] ; On met le caractère de bl dans needle
    cmp al, bl ; On compare meule_de_foin[i] == aiguille[index]
    je charIsIndexOfAiguille

    jmp charIsNotIndexOfAguille ; Si on a pas trouvé on continue

; Permet de vérifier si toute la string n'a pas été trouvé
; Sinon on vient implémenter l'index du ptr de aiguille

charIsIndexOfAiguille:
    inc rcx

    cmp rcx, rdx
    je exitSuccess

    jmp endFirstLoop

charIsNotIndexOfAguille:
    xor rcx, rcx ; On réinitialise si on a pas trouvé le charactère correspondant
    jmp endFirstLoop

endFirstLoop:
    inc rdi ; On passe au prochain élément de meule_de_foin
    jmp loopMyStrStr

exitSuccess:
    xor rdx, rdx
    cmp rcx, 1
    je exitFinalSuccess
    sub rcx, 1
    jmp loopAndDecremFinal

loopAndDecremFinal:
    dec rdi
    inc rdx

    cmp rdx, rcx
    je exitFinalSuccess

    jmp loopAndDecremFinal

exitFinalSuccess:
    mov rax, rdi
    ret

exitEmpty:
    cmp byte[rsi], 0
    je exitLast

    mov rax, 0
    ret

exitLast:
    mov rax, rdi
    ret

exit:
    cmp byte[rsi], 0
    jmp exitEmpty

    mov rax, 0 ; Si une erreur est détecté on return un null byte
    ret
