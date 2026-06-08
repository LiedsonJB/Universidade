org 100h

.stack

.data
  
    msg db "Um carater em hexa maiuscula (A ate F): $"
    msg1 db "Seu Valor em decimal: $"    
            
.code

    brincar:
       
        erro:
            
            mov ah, 09H
            lea dx, msg
            int 21h
        
            mov ah, 01h
            int 21h
        
            mov bl, al
            
            call new
            call new
            
        cmp bl, 40h
        jg ok
        jmp erro
        
        ok:
            cmp bl, 47h
            jb ok1
            jmp erro
       
        ok1:            
           
            mov ah, 09h
            lea dx, msg1
            int 21h 
            mov ah, 02h
            mov dl, 31h
            int 21h
            sub bl, 11h
            mov dl, bl
            int 21h
            
            call new
            call new
            
    jmp brincar      
       
    new proc
               
        mov ah, 02H       
        mov dl, 0AH
        int 21h
        mov dl, 0Dh
        int 21h
        ret
      
    new endp 