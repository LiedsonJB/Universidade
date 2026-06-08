#start=led_display.exe#  
mov ax, 1234  
; out porto, acumulador
out 199, ax

xor ax, ax

in ax, 199


;hlt

mov ax, 6345h
mov bx, 3456h

cmp ax, bx; comparar ax com bx
jg Maior ; jump if grater

mov cx, bx
jmp Continuar

Maior:
mov cx, ax


Continuar:
inc cx


hlt; halt -> parar


; mov destino, origem
mov ah, 12h
mov al, 34h 
mov ax, 0abch

; add destino, origem
add ax, 2h ; ax=ax+2h   

;sub destino, origem
mov bl, 12h 
mov cl, 2h
sub bl, cl ; bl = bl - cl

;mul origem
mov ax, 10h
mov cl, 4h
mul cl   ; ax= ax*cl

;div divisor

mov ax, 25h
mov bl, 2h
div bl ; ax/bl -> al <- divisao inteira, ah<-resto da divisao inteira 

; dec destino
mov dx, 1234h
dec dx ; dx <- dx-1

; inc destino
inc dx ; dx <- dx+1   

; and destino, origem
mov ah, 1001b
mov al, 1100b
and ah, al ; ah <- 1000 (1001 and 1100)  

mov bh, 9h 
mov bl, 0ch 
and bh, bl

; or destino, origem
mov ah, 1001b
mov al, 1100b
or ah, al ; ah <- 1101 (1001 and 1100)    

; xor destino, origem
xor ax, ax

not bx

neg dx


