org 100h

.stack

.data

.code
         
    mov ah, 02H
    mov dl, 31H
         
    brincar:
    
        int 21h
        inc dl
         
    cmp dl, 3AH
    jnz brincar
                
                
                
                
                
                
                
      
    mov cx, 9d
    mov dl, 31H
    
    brincar2:
    
        int 21h
        inc dl  
        
    loop brincar2
           
        
        
end        