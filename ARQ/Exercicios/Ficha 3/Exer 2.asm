org 100h

.stack 

.data
     
    sms db "Imprimir de A ate Z: $" 
    sms1 db "O de loop: $"
    sms2 db "O de saltos: $"
     
.code
      
    mov ah, 09h
    lea dx, sms
    int 21h
    
    call newLine
    call newLine
    
    mov ah, 09H
    lea dx, sms2
    int 21h
    call newLine
    call newLine
    
    mov ah, 02h
    mov cl, 41H   
    
    brincar:
        
        call tab
        mov dl, cl
        int 21h
        call newLine
        inc cl
    
    cmp cl, 5Ah
    jbe brincar
    
    call newLine
    call newLine 
                
    mov ah, 09h            
    lea dx, sms2
    int 21h
    
    call newLine
    call newLine             
    mov ah, 02h
    mov cx, 26d
    mov bl, 41h
                     
                 
    brincar1:
        
        call tab     
        mov dl, bl     
        int 21h
        call newLine
        inc bl
    
    loop brincar1           
               
    newLine proc
        
        mov ah, 02h
        mov dl, 0ah
        int 21h
        mov dl, 0dh
        int 21h      
        ret
              
    newLine endp
    
    tab proc
        
        mov ah, 02h
        mov dl, 09h
        int 21h 
        ret
        
    tab endp    

end