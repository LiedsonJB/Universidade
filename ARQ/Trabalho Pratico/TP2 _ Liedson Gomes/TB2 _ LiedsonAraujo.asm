org 100h

.stack

.data
      
    L0 db "-------------------- Menu Inicial --------------------$"  
    l db "O meu nome e: Liedson Gomes Araujo$"
    i db "A minha idade e de: $"
    L1 db "L - Imprimir o meu nome$"
    L2 db "I - Imprimir minha idade$"
    L3 db "E - Imprimir minha idade ate 0$"
    L4 db "D - Calcular soma e divisao$"
    L5 db "S - Sair$"
    L6 db "Escolha: $"
    INV db "Opcao Invalido!!!$"
    ESC db "Escolha Novamente$"
    AnoN dW 2005d
    AnoA dW 2024d
    Pr db "Primeiro numero: $"
    Pr1 db "Segundo numero: $"
    Res db "Resultado da soma: $"
    adeus db "obrigado volte sempre!!!$"
    L7 db "Minha idade ate 0: $" 
    L01 db "-------------------- Sub Menu --------------------$" 
    L02 db "1 - Somar e dividir com um numero de 1 digito$"
    L03 db "2 - Somar e dividir com um numero de 2 digito$"
    L04 db "3 - Voltar ao Menu Inicial$"
    L05 db "4 - Sair$"
    ano db " Anos$" 
    ResD db "Resultado da divisao: $"
    aux1 dw ?
    aux2 dw ?

.code
     
     ciclo:
      
        mov ah, 09h
                   
        lea dx, L0
        int 21h           
                   
        call newLine
        call newLine 
        
        call tab
        
        mov ah, 09h
        lea dx, L1
        int 21h
        
        call newLine 
        call tab
        
        mov ah, 09h
        lea dx, L2
        int 21h 
        
        call newLine
        call tab
        
        mov ah, 09h
        lea dx, L3
        int 21h
        
        call newLine
        call tab
        
        mov ah, 09h
        lea dx, L4
        int 21h
        
        call newLine
        call tab
        
        mov ah, 09h
        lea dx, L5
        int 21h
        
        call newLine
        call tab 
        
        mov ah, 09h
        lea dx, L6
        int 21h
        
        mov ah, 01h
        int 21h
        mov bl, al
        
        call newLine
        
        cmp bl, 4cH
        je nome
        cmp bl, 49H
        je Idade
        cmp bl, 45h
        je Imprimir
        cmp bl, 44h
        je calcular
        cmp bl, 53H
        je fim  
        
        call newLine
        
        mov ah, 09h
        lea dx, INV
        int 21h 
                
        call newLine
                
        mov ah, 09h        
        lea dx, ESC
        int 21h    
        
        call newLine
        call newLine
        
    jmp ciclo
        
        nome:
            
            call newLine
            
            mov ah, 09h
            lea dx, l
            int 21h
            
            call newLine 
            call newLine

    jmp ciclo
            
        idade:
        
            call newLine
            
            mov ah, 09h
            lea dx, i
            int 21h
            
            mov bx, AnoN
            mov cx, AnoA
            
            sub cx, bx
            
            mov ax, cx 
            mov bx, 0ah
            xor dx, dx
            div bx
            
            mov cl, al
            mov ch, dl
            add cl, 30h
            add ch, 30h
            
            mov ah, 02h
            mov dl, cl
            int 21h
            mov dl, ch
            int 21h
            
            mov ah, 09h
            lea dx, ano
            int 21h
             
            call newLine
            call newLine 
            
    jmp ciclo 
            
        Imprimir:
        
            call newLine
        
            mov ah, 09h
            lea dx, L7
            int 21h
            
            call newLine
        
            mov cx, 10d 
            mov bl, 39h 
            
            brincar1:
                 
                call newLine 
                call tab        
                mov ah, 02h
                mov dl, 31h
                int 21h
                mov dl, bl
                int 21h
                dec bl
                             
            loop brincar1
            
            mov cx, 10d
            mov bl, 39h 
            
            brincar2:
                         
                call newLine 
                call tab        
                mov ah, 02h
                mov dl, bl 
                int 21h
                dec bl         
            
            loop brincar2
            
            call newLine
            call newLine   
          
    jmp ciclo
        
        calcular: 
        
            errado:
        
                call newLine
                call newLine
                
                mov ah, 09h
                lea dx, L01
                int 21h
                
                call newLine 
                call newLine
                call tab
    
                mov ah, 09h
                lea dx, L02
                int 21h
                
                call newLine
                call tab
                 
                mov ah, 09h
                lea dx, L03
                int 21h
                
                call newLine
                call tab
                mov ah, 09h
                lea dx, L04
                int 21h
                
                call newLine
                call tab
                
                mov ah, 09h
                lea dx, L05
                int 21h
                
                call newLine
                call tab
    
                mov ah, 09h
                lea dx, L6
                int 21h 
                
                mov ah, 01h
                int 21h 
                mov bl, al
                   
                call newLine
                call newLine
                
                cmp bl, 31h
                je Umdigito
                cmp bl, 32h
                je Doisdigito
                cmp bl, 33h
                je ciclo
                cmp bl, 34h
                je fim
                
                call newLine
                call newLine
        
                mov ah, 09h
                lea dx, INV
                int 21h 
                       
                call newLine
                       
                mov ah, 09h       
                lea dx, ESC
                int 21h    
                
                call newLine
                call newLine 
            
            jmp errado
                  
            Umdigito:  
            
                call newLine
                call newLine
            
                mov ah, 09h
                lea dx, Pr
                int 21h 
                    
                mov ah, 01h
                int 21h
                mov bl, al
                       
                call newLine       
                       
                mov ah, 09h
                lea dx, Pr1
                int 21h 
                 
                mov ah, 01h
                int 21h
                mov bh, al
                
                sub bl, 30h
                sub bh, 30h
                
                mov cx, bx
                           
                call newLine
                
                add bl, bh
                add bl, 30h
                
                call newLine
                
                mov ah, 09h
                lea dx, Res
                int 21h
                
                mov ah, 02h
                mov dl, bl
                int 21h
                
                call newLine
                
                mov ah, 09h
                lea dx, ResD
                int 21h
                
                xor ax, ax
                mov al, cl
                mov cl, ch
                div cl      
                
                add al, 30h
                add ah, 30h
                
                mov bx, ax
                
                mov ah, 02h
                mov dl, bl
                int 21h
                mov dl, 2ch
                int 21h
                mov dl, bh
                int 21h
                
                call newLine
                call newLine
            
    jmp ciclo    
            
            Doisdigito: 
            
            call newLine
            call newLine
            call ler2Num 
            
            mov aux1, bx
            mov aux2, cx
                        
            add bx, cx 
            
            add bl, 30h
            add bh, 30h
                       
            call newLine
            call newLine           
                       
            mov ah, 09h
            lea dx, Res
            int 21h
            
            mov ah, 02h
            mov dl, bh
            int 21h
            mov dl, bl
            int 21h
            
            call newLine
            
            mov ah, 09h
            lea dx, ResD
            int 21h
            
            mov ax, aux1
            mov bx, aux2
            xor dx, dx
            div bx
            
            mov bl, al
            mov bh, dl
            
            add bl, 30h
            add bh, 30h
            
            mov ah, 02h
            mov dl, bl
            int 21h
            mov dl, 2ch
            int 21h
            mov dl, bh
            int 21h
            
            call newLine
            call newLine
            
    jmp ciclo          
                        
    newLine proc
        
        mov ah, 02h
        mov dl, 0AH
        int 21h
        mov dl, 0Dh
        int 21h
        ret 
        
    newLine endp 
    
    tab proc
            
        mov ah, 02h
        mov dl, 09h
        int 21h
        ret    
            
    tab endp
    
    ler2Num proc
        
        mov ah, 09h
        lea dx, Pr
        int 21h
        
        mov ah, 01h
        int 21h
        mov bh, al 
        sub bh, 30h
        int 21h
        mov bl, al
        sub bl, 30h
        
        call newLine
        
        mov ah, 09h
        lea dx, Pr1
        int 21h
        
        mov ah, 01h
        int 21h
        mov ch, al
        sub ch, 30h
        int 21h
        mov cl, al
        sub cl, 30h
        
        ret
        
    ler2Num endp
    
    fim:
    
        call newLine
        call newLine
        
        mov ah, 09h
        lea dx, adeus
        int 21h
    
end