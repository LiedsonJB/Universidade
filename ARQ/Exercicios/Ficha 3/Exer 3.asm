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



;a) codigo para ler 2 numero
;b)  
  
  mov ah, 02h
  add bl, 
  mov dl, bl
  int 21h
  

ret