org 100h

.stack

.data
    
    msg db "Escreva um carater: $"
    msg1 db "Carater convertido: $"
    msg2 db "Insira um numero(1): $"
    msg3 db "Insira um numero(1): $"

.code

    mov ah, 09h
    lea dx, msg
    int 21h
    
    mov ah, 01h
    int 21h
    
    mov bl, al
    
    call new
    call new
    
    mov ah, 09h
    lea dx, msg1
    int 21h
    
    sub bl, 20h
              
    mov ah, 02h          
    mov dl, bl
    int 21h    
        
    new proc
       
       mov ah, 02h
       mov dl, 0Ah
       int 21h
       mov dl, 0Dh
       int 21h  
       ret
       
    new endp 
    
