include emu8086.inc

org 100h

.stack

.data

    cont db ?
    aux db ?
    vetor db 5 dup<?>
    
.code

;Meus Macros

    macro le2Digito 
        
        xor dx, dx
        xor bx, bx
        mov dl, 0ah
        mov aux, 2h
        
        recebe:      
        
            mov ah, 01h
            int 21h
            cmp al, 0dh
            mov ah, 0h
            sub al, 30h
            mov dh, al
            mov al, bl
            mul dl
            add al, dh
            mov bl, al   
            dec aux
            
        cmp aux, 0h   
        jnz recebe 
    endm
    
    imprimir1digito macro valor      ;macro imprimir1digito com o parametro valor
        
        mov ah, 02h    ; mover para ah 02h que e a funcao de imprimir 1 carater
        mov dl, valor   ;mover para dl o valor a ser imprimido
        add dl, 30h   ; adicionar dl com 30h para considir com o valor na tabela ASCII
        int 21h    ;realizar a funcao
        
    endm
    
    macro dive50
        mov si, 00h
        mov cont, 00h
        mov cx, 5d 
        brincar: 
            xor dx, dx
            xor ax, ax
            mov bl, [vetor+si]
            mov al, 50d
            div bl 
            cmp ah, 00h
            jz ok
            jmp ok1
            
                ok:
                    inc cont
                ok1:
            inc si
                
        loop brincar 
        
        call newline
        Print "Sao: "
        imprimir1digito cont
        
    endm
    
main:
    
    ;Ler os valores para o vetor
    mov cx, 5d            
    mov si, 0d             
    mov cont, 01h          
    
    Print "Introduza os 5 valores" 
      
    ler:
    
        call newline
          
        erro:           
             
              imprimir1digito cont   ;chamar  macro imprimir1digito com parametro cont
              Print " Valor: "    ; imprima na tela a mensagem "Nota: "   
              le2Digito           ; chamar macro le2digito
              cmp bl, 50d         ; comparar bl com 20d
              jbe aceito          ; se for menor ou igual a 20d salta para aceitar
              call NewLine     ;chama o procedimento mudanca de linha
              Print "ERRO: Escala de 0 a 50"  ; imprima na tela a mensagem "ERRO: Escala de 0 a 20"
              call NewLine   
        jmp erro          ; jmp incondicional que salta para o rotulo erro
          aceito:             ;rotulo aceito
              mov [vetor+si], bl        ; mover para vetor o valor de bl conforme o valor de si
              inc cont        ;incrimentar cont
              inc si      ;incrimentar si  
              
    loop ler 
    
    dive50
    
    NewLine proc ; procedimento mudanca de linha
        
        mov ah, 02h     ; mover para ah 02h que e a funcao de imprimir 1 carater
        mov dl, 0ah     ;mover para dl o carater mudanca linha 
        int 21h         ; realizar a funcao
        mov dl, 0dh     ; mover para dl o carater cret que coloca o pusor no inicio
        int 21h         ; realizar a funcao
        
        ret             ;retornar para o endereco onde foi chamado
    NewLine endp    
     
end main