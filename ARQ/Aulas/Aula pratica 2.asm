org 100h

.stack 


.data
        
    msg db "Entre com um carater: $"        

.code
    
    mov ah, 09h;mover para ah 09h para imprimir
    lea dx, msg
    int 21h
    
    mov ah, 01h
    int 21h
    
    mov bl, al
    
    call new
        
        mov ah, 02h
        mov dl, bl
        int 21h
        
    new proc 
        
        mov ah, 02h
        mov dl, 0Ah
        int 21h
        mov ah, 02h 
        mov dl, 0Dh
        int 21h
        ret
        
    new endp   
    