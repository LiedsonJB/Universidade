
org 100h

    mov ah, 01h
    int 21h
    
    mov bl, al
    
    sub bl, 30h
    
    mov cl, bl
    add cl, 1H
    
    mov ah, 02H  
    
    mov dl, al
    
    brincar:
          
        int 21h
        dec dl
        
    loop brincar

ret




