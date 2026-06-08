org 100h

    xor dx , dx
    xor bx , bx
    mov dl , 0ah
    mov cx , 2h
    
    meu_loop: 
    
        mov ah , 01h
        int 21h
        cmp al , 0dh
        je fim
        mov ah , 0h
        sub al , 30h
        mov dh , al
        mov al , bl
        mul dl
        add al , dh
        mov bl , al

    loop meu_loop  
    
    fim :

ret

;a) codigo para ler 2 numero
;b) 