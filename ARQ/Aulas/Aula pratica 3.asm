org 100h

.stack
 
.data 

    M db "maior que: $"
    me db "menor que: $"
    i db "e igual a$"
    P db "Primeiro: $"
    S db "Segundo: $"
          
.code

    mov ah, 09H
    lea dx, P
    int 21h  
             
    call ler
    mov cl, al
              
    lea dx, S
    int 21h          
              
    call ler
    mov ch, al
    
    cmp ch, cl
    jg maior
    jz iguais
    jb menor
       
    maior: 
        
        mov ah, 02H
        mov dl, ch
        int 21h
        mov dl, 20H
        int 21h 
        
        mov ah, 09H
        lea dx, M
        
        int 21H
        
        mov ah, 02H
        mov dl, 20H
        
        int 21h
        
        mov dl, ch
        int 21h
        hlt
        
     iguais:
        
        mov ah, 02H
        mov dl, ch
        int 21h
        mov dl, 20H
        int 21h 
        
        mov ah, 09H
        lea dx, i
        
        int 21H
        
        mov ah, 02H
        mov dl, 20H
        
        int 21h
        
        mov dl, ch
        int 21h
        hlt
        
     menor:
        
        mov ah, 02H
        mov dl, ch
        int 21h
        mov dl, 20H
        int 21h 
        
        mov ah, 09H
        lea dx, me
        
        int 21H
        
        mov ah, 02H
        mov dl, 20H
        
        int 21h
        
        mov dl, ch
        int 21h
        hlt  
        
   newline proc
            
        mov ah, 02H       
        mov dl, 0AH
        int 21h
        mov dl, 0Dh
        int 21h
        ret
        
    newline endp
     
    ler proc
        
        mov ah,01h
        int 21h
        ret
        
    ler endp

end     