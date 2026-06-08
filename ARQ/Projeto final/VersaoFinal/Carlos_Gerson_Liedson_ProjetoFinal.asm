 TITLE: Projeto Final
;Elaborado por:
    ;Carlos Concicao LEIT
    ;Gerson Spencer LEE
    ;Liedson Araujo LEIT

.model small
.stack 100h ;incializar stack com 100h que corresponde a 256 byts

include emu8086.inc
;Incluir a biblioteca para utilizar o funcao PRINT

    macro ImprimirString msg ; macro que imprimir string 
        
        mov ah, 09h     
        lea dx, msg       
        int 21h         
        
    endm

    macro somar soma        ;macro Somatorio das notas     
        
        mov si, 00h  ; indice do vetor
        ; zerar ax e bx porque al recebe a nota e bl o somatorio
        xor ax, ax    
        xor bx, bx   
        mov cx, 10d         ; definir o contador com 10d (10 notas)
        
        somarDigito: ;Somatorio usando loop
        
            mov al, [vetor+si]  ; Mover al o valor no vetor na posicao do si
            add bl, al          ; adicionar bl com al
            inc si              ; Incrementar si
        
        loop somarDigito    ;loop somarDigito
        
        mov soma, bl        ; Mover o somatorio para variavel soma
        
    endm            
                        
    macro imprimir2Digito valor    ;macro que imprima um valor de 2 digitos
        
        xor ax, ax      ;utilizado na divisao
        
        mov al, valor   ;mover para al o contiudo da variavel valor
        mov bl, 10d     
        
        div bl         
        
        mov bl, al      ;primeiro digito
        mov bh, ah      ;segundo digito
        
        add bl, 30h     
        add bh, 30h     
        
        mov ah, 02h  ;imprimir primeiro digito   
        mov dl, bl      
        int 21h         
        
        mov dl, bh ;imprimr segundo digito     
        int 21h          
        
    endm    

    macro maiorE maior  ;macro Identifica maior nota e sua posicao

        mov si, 00h  
        mov al, [vetor+si]
        mov maior, al   
        mov cx, 9d     
        xor bx, bx  ;recebe posicao
                           
        maiorElemento:   
        
            mov ah, maior 
            inc si      ; 
            mov al, [vetor+si]   
            cmp ah, al        
            jl m ;jump if lower         
            jmp ok 
                  
            m:       
                mov maior, al  
                mov bx, si   
            ok: 
        
        loop maiorElemento 
        
        mov pos, bl ;posicao final

    endm 

    macro ReceberDigito op ;opcao

        mov ah, 01h    
        int 21h        
        mov op, al     

    endm  

    macro comparar op     ; verificar opcao

        mov ah, op
        cmp ah, 31h
        je inserirNota ;jump if equal
        cmp ah, 32h
        je MaiorNota
        cmp ah, 33h
        je MenorNota
        cmp ah, 34h
        je Q_Apr_Repro
        cmp ah, 35h
        je MediaTurma
        cmp ah, 36h
        je Nota_Media
        cmp ah, 37h
        je TabAproRepro
        cmp ah, 38h
        je ImprimirOrdenado:
        cmp ah, 39h
        je sair  
        
        limpar ;macro limpar tela
        
        print "Opcao inexistente !!!"    
        
        call NewLine  
        
        print "Escolha novamente"    
        
        call NewLine   
        
        jmp final  
        
    endm   

    macro le2Digito ;macro ler 2 digitos

        xor dx, dx
        xor bx, bx
        mov dl, 0ah
        mov count, 2h
        
        recebe:   
        
            mov ah, 01h
            int 21h  
            
            mov ah, 0h
            sub al, 30h
            mov dh, al
            
            mov al, bl
            mul dl  
            
            add al, dh
            mov bl, al 
              
            dec count
            
        cmp count, 0h  
        jne recebe 
        
    endm 

    imprimir1digito macro valor      ;macro Imprimir  um digito

        mov ah, 02h    
        mov dl, valor  
        add dl, 30h   
        int 21h 

    endm 

    macro menorE menor ; Verificar Menor valor 

        mov si, 00h
        mov al, [vetor+si]
        mov menor, al
        mov cx, 9d
        xor bx, bx
        
        menorElemento:
        
            mov ah, menor
            inc si
            mov al, [vetor+si] 
            
            cmp al, ah
            jl mm
            jmp nao 
            
            mm:
            
                mov menor, al
                mov bx, si
            
            nao:
        
        
        loop menorElemento
        mov pos, bl

    endm


    calcularMedia macro       
        
        xor ax, ax  
        xor dx, dx   
        
        mov al, soma  
        mov bl, 10d   
        div bl       
        
        mov maisS, al 
        mov menosS, ah 
        
        call NewLine 
         
        Print "Media da turma: " ;imprimir "Media da turma: "
        
        imprimir2digito maisS    
        
        mov ah, 02h      
        mov dl, 2ch     
        int 21h 
               
        imprimir1digito menosS
        
    endm 

    Apro_Repro macro apro repro  ;TOTAL de aprovados e reprovados
        
        mov si, 00h
        mov cx, 10d  
        
        percorrer:   ; Label do loop
        
            mov ah, [vetor+si]
            
            cmp ah, 9d
            jle reprov ;jump lower or equal
            cmp ah, 10d
            jge aprov ;jump greater or equal
            
            reprov:   
            
                inc reprovados
                jmp salto   
                             
            aprov:  
            
                inc aprovados 
            
            salto:
             
                inc si            
        
        loop percorrer     

    endm

    macro AbAcMedia    ; macro abaixo e acima da media   
        
        mov aprovados, 00h
        mov reprovados, 00h
        
        mov cx, 10d
        mov si, 00h 
        
        verificar:  ; Label do loop
        
            mov al, [vetor+si] 
            
            cmp al, maisS
            jle abaixo
            cmp al, maisS
            jge acima
               
            abaixo:   
            
                inc reprovados
                jmp saltos
                
            acima:
            
                inc aprovados 
                   
            saltos:
            
                inc si 
            
        loop verificar        

    endm 

    macro ordenar

        mov cx, 10d  
        xor ax, ax    
        xor bx, bx   
        ;bubble
        exterior:     
        
            mov dx, 00h 
                       
                       
            interior: 
            
                mov si, dx
                mov al, [vetor+si] ;atual
                inc si
                mov bl, [vetor+si] ;proximo
                dec si
                
                cmp al, bl
                jl trocar:
                jmp naoTrocar
                
                trocar:    ; Label do jl
                
                    xchg al, bl ;trocar valores entre registradores
                    mov [vetor+si], al
                    inc si
                    mov [vetor+si], bl
                    dec si
                
                naoTrocar:  ; Label do jmp
                
                    inc dx 
            
            cmp dx, 9d
            jl interior
            
            dec cx   
            
        jnz exterior ; enquanto cx diferente de zero        

    endm

    macro limpar

        mov ax, 600h
        mov bx, 700h 
        mov dx, 184fh
        xor cx, cx
        int 10h
        
        mov ah, 02h
        xor bx, bx
        xor cx, cx
        xor dx, dx
        int 10h   

    endm     

    macro tabela

        Print "Tabela com os alunos"   ;imprimir "Tabela com os alunos"

        call newline   
        call newline  
        
        ImprimirString tab
        
        mov cx, 10d 
        mov si, 00h
        xor dx, dx ;recebe posicao si
        
        verificar2:         ; Label do jnz
        
            mov bl, [vetor+si]
            mov i, bl
            
            cmp i, 9d
            jle okErepro
            
            mov dx, si 
            mov j, dl
            add j, 1h
             
            ; Imprimir Aprovados
            ImprimirString !0
            imprimir2digito j
            ImprimirString !1
            imprimir2digito i
            ImprimirString !2
            ImprimirString !3
            
            jmp naoSaltarOk
            
            okErepro: ;Imprimir Reprovados
            
                mov dx, si 
                mov j, dl
                add j, 1h
            
                ImprimirString !0
                imprimir2digito j
                ImprimirString !1
                imprimir2digito i
                ImprimirString !4
                ImprimirString !3               
                
            naoSaltarOk: 
            
                inc si ;proxima nota
                dec cx 
        
        jnz verificar2
        
    endm  

.data 

                    ; Declaracao de variaveis

    
    Menu db "----------------------- Menu Inicial -----------------------"; variavel menu do tipo db
    db 0ah, 0dh, 0ah, 0dh, 09h, "1 - Inserir notas (0 a 20)"
    db 0ah, 0dh, 09h, "2 - Numero e nota do aluno com nota mais alta"    
    db 0ah, 0dh, 09h, "3 - Numero e nota do aluno com nota mais baixa"
    db 0ah, 0dh, 09h, "4 - Quantidade de aprovados e Reprovados"
    db 0ah, 0dh, 09h, "5 - Media das notas da Turma"
    db 0ah, 0dh, 09h, "6 - Quantidade de notas acima e abaixo da media"
    db 0ah, 0dh, 09h, "7 - Tabela com numero de alunos com nota e se foi aprovado ou reprovado"
    db 0ah, 0dh, 09h, "8 - Notas em ordem decrescente"
    db 0ah, 0dh, 09h, "9 - Sair"
    db 0ah, 0dh, 0ah, 0dh, "Escolha: $"   
    cont db ?       ;cont utilizado para imprimir na tela o numero de nota ex: "1 Nota: "
    soma db ?        ; variavel soma que recebe o valor total da soma
    maior db ?      ;variavel maior que recebe a maior nota
    menor db ?      ;variavel menor que recebe o menor nota
    pos db ?        ;variavel que guarda a posicao onde ta o maior e o menor das notas
    op db ?         ;variavel op que armazena a escolha obtida pelo utilizador
    count db ?      ;count utilizado na macro ler2digito onde controla o fluxo
    maisS db ?      ;maisS armazena o valor mais significativo da div
    menosS db ?     ;menosS armazena o valor mais significativo da div
    Aprovados db ?  ;aprovados que conta o numero de aprovados
    Reprovados db ? ;reprovados que conta o numero de reprovados 
    controlo db ?  
    i db ?
    j db ?
    
                ;Estrutura das tabelas
    !5  db " ------ --------------- ",0ah,0dh,"$"
    
    !6   db "  | Acima da media  |",0ah,0dh,"$"  
    
    !7    db "  | Abaixo da media |",0ah,0dh, "$"
    
    !8   db " ------ ----------------- ",0ah,0dh,"$" 
    !9  db "|  $" 
    
    tab db    " _______ ______ _______________",0ah,0dh, 
    
    db     "| Aluno | Nota | Classificacao |",0ah,0dh,    
    
    db    " ======= ====== =============== ",0ah,0dh,"$"  
    
    !0   db   "|  $"   
    !1    db       "   |  $"
    !2   db                "  |    Aprovado   |",0ah,0dh,"$"
    !3  db " ------- ------ --------------- ",0ah,0dh,"$" 
    !4 db                  "  |   Reprovado   |",0ah,0dh,"$" 
    
    vetor db 10 dup<?> ;vetor que recebe as notas     
    
.code

    main:

        mov ax, @data
        mov ds, ax 
        mov controlo, 00h
        
        infinito:   
        
            imprimirString Menu      
            receberDigito op     
            comparar op    
            
            inserirNota:    
                         
                limpar  
                
                mov controlo, 01h
                call NewLine      
                
                mov cx, 10d      
                mov si, 0d   
                mov cont, 01h 
                
                Print "Introduza as notas" 
                 
                call newline  
                
                ler:  
                 
                    validarNota: 
                    
                        call NewLine 
                        
                        cmp cont, 09h 
                        jg maior9       
                        
                        imprimir1digito cont    
                        
                        jmp saltar        
                        
                        maior9: 
                        
                            imprimir2digito cont  
                        
                        saltar:
                                
                            Print " Nota: "    ; imprimir " Nota: "
                               
                            le2Digito          
                            
                            cmp bl, 20d       
                            jbe aceito          ; nota valida
                            
                            call NewLine   
                            
                            Print "ERRO: Escala de 0 a 20"
                               
                    jmp validarNota        
                    
                    aceito: 
                    
                        mov [vetor+si], bl 
                        inc cont  ;proxima nota    
                        inc si    
                    
                loop ler    
                
                call newline    
                call newline          
            
            jmp final
            
            MaiorNota:   
            
                cmp controlo, 00h
                je okE0
            
                limpar   
            
                maiorE maior   
                
                call NewLine  
                
                Print "Aluno: "     ;imprimir "Aluno: "
                
                add pos, 01h  
                
                imprimir2digito pos 
                
                Print " com a nota: "   ;imprimir " com a nota: "
                
                imprimir2digito maior  
                
                call newline   ;chamar o procedimento   
                
            jmp final
                
            MenorNota:       ; Label da comparacao
            
                cmp controlo, 00h
                je okE0
                
                limpar  
                
                menorE menor  
                
                call NewLine    
                
                Print "Aluno: "  
                
                add pos, 01h  
                
                imprimir2digito pos  
                
                Print " com a nota: "  ;imprimir " com a nota: "
                
                imprimir2digito menor   
                    
                call newline 
            
            jmp final
            
            MediaTurma: 
            
                cmp controlo, 00h
                je okE0 
                
                limpar  
                
                somar soma
                calcularMedia
                
                call newline 
                
            jmp final
            
            Q_Apr_Repro:  
            
                cmp controlo, 00h
                je okE0  
                
                limpar
                
                Apro_Repro aprovados reprovados
                
                call NewLine     
                
                Print "Numero de aprovados: "  
                
                imprimir2digito aprovados 
                
                call NewLine   
                
                call newline 
                
                Print "Numero de reprovados: " 
                
                imprimir2digito reprovados  
                
                call newline 
                
                
            jmp final
            
            Nota_Media: 
            
                cmp controlo, 00h
                je okE0     
                
                AbAcMedia
                
                limpar 
                
                Print "Notas Acima e abaixo da media" 
                
                call newline
                call newline
                
                imprimirString !8
                imprimirString !9 
                imprimir2digito aprovados
                imprimirString !6
                
                imprimirString !8
                imprimirString !9
                imprimir2digito reprovados
                imprimirString !7
                imprimirString !8
            
            jmp final
            
            TabAproRepro:     
            
                cmp controlo, 00h
                je okE0
            
                limpar    
                
                tabela
            
            jmp final
            
            ImprimirOrdenado:  
            
                cmp controlo, 00h
                je okE0    
            
                limpar
                
                ordenar
                
                mov cx, 10d
                mov si, 00h 
                
                call NewLine
                    
                Print "Notas por ordem decrescente"  
                
                call NewLine
                call newline   
                
             imprime: 
             
                    mov dl, [vetor+si] 
                    
                    imprimir2digito dl 
                    
                    call newline
                    
                    inc si 
                    
            loop imprime 
            
            jmp final
            
            okE0: ;vazio 
            
                limpar  
                
                call NewLine 
                
                Print "Nenhuma nota introduzida"  
                
                call NewLine 
                
            jmp final                                                    
            
            final:  
            
                call NewLine  
                
                Print "Press any key to continue... "  
                
                mov ah, 01h
                int 21h 
            
                limpar   
            
            jmp infinito
            
            
            NewLine proc ; procedimento nova linha
            
                mov ah, 02h     
                mov dl, 0ah     
                int 21h         
                
                mov dl, 0dh     
                int 21h         
                
                ret         
                           
            NewLine endp       
            
            sair:        
                    
                limpar  
                
                Print "Obrigado & volte sempre"  
        
end main      ; final