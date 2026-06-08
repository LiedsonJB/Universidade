org 100h

.stack

.data

    sms1 db "Insira um numero: $"
    sms2 db "Fatorial do numero: $"
    r dw ?

.code
     
     mov ah, 09h
     lea dx, sms1
     int 21h
     
     mov ah, 01h
     int 21h
     mov cl, al
     sub cl, 30
                 
     brincar:
     
        imul r, cx
        dec cx
                  
     cmp cx, 0
     jnz brincar
     
     call newLine
     call newLine
     
     mov ah, 09h
     lea dx, sms2
     int 21h 
     
     mov ah, 02h
     add al, 30
     sub al, 8
     mov dl, al
     int 21h
     
    newLine proc
        
        mov ah, 02h
        mov dl, 0ah
        int 21h
        mov dl, 0dh
        int 21h      
        ret
              
    newLine endp     
     
end