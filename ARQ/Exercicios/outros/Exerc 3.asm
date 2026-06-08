org 100h

.stack

.data
    msg1 db "Seus 3 primeiros carateres do teu nome$"
    msg db "Primeiro: $"
    msg2 db "Segundo: $"
    msg3 db "Terceiro: $"
    msg4 db "Aqui estao: $"

.code
   
    mov ah, 09h
    lea dx, msg1
    int 21h
    
    call new1
    call new1
    
    mov ah, 09h
    lea dx, msg
    int 21h
    
    mov ah, 01h
    int 21h
    
    mov bh, al
    
    call new1
    call new1          
    
    mov ah, 09h
    lea dx, msg2
    int 21h
    
    mov ah, 01h          
    int 21h
    
    mov bl, al 
    
    call new1
    call new1          
    
    mov ah, 09h
    lea dx, msg3
    int 21h
    
    mov ah, 01h          
    int 21h
    
    mov cl, al
       
    call new1
    call new1 
    
    mov ah, 09h
    lea dx, msg4
    int 21h
    
    call espaco
    
    mov ah, 02h
    mov dl, bh
    int 21h
    
    call espaco
     
    mov dl, bl
    int 21h
    
    call espaco
    
    mov dl, cl
    int 21h
        
    new1 proc
       
       mov ah, 02h
       mov dl, 0Ah
       int 21h
       mov dl, 0Dh
       int 21h  
       ret
       
    new1 endp
    
    espaco proc
        
        mov ah, 02h
        mov dl, 20h
        int 21h
        ret
        
    espaco endp
