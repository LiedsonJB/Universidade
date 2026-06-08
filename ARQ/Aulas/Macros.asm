org 100h

.stack

.data

    sms1 db "Introduza um digito: $"  
    sms2 db 0dh, 0ah,"Seu dobro: $"  

.code 

    macro Receber 
         
        mov ah, 01h
        int 21h
        sub al, 30h 
        mov cl, al
        
    endm
    
    macro Dobro var
        
        mov ax, 2d
        mov cl, var
        mul cl
        mov cx, ax
    
    endm
    
    macro imprimir var
    
        mov ah, 02h
        mov dl, var 
        add dl, 30h
        int 21h    
        
    endm  
    
    macro ImpSrt sms
        
        mov ah, 09h
        lea dx, sms
        int 21h
        
    endm

main:  
     
    ImpSrt sms1
   
    Receber
           
    Dobro cl           
           
    ImpSrt sms2 
    
    imprimir cl

end main