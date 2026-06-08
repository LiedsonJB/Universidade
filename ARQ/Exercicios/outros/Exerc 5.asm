org 100h

.stack

.data

    sms1 db "Introduza um digito: $"  
    sms2 db 0dh, 0ah,"Seu dobro: $"  
    meu_array db 1,2,3,4,5
    meu_array2 db 5 dup<?>; dub duplicar o tamanho transformado em um v[]

.code 

    macro Receber num
         
        mov ah, 01h
        int 21h
        sub al, 30h 
        mov num, al
        
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
     
    mov si, 0h;si para posicao
    
    imprimir [meu_array+si];array+si aceder o vetor e si para incrementar 
    
    Receber [meu_array2+si]  
    imprimir [meu_array2+si] 

end main