TITLE: Projeto Final
;Elaborado por:
;Carlos LEIT
;Gerson LEE
;Liedson Araujo LEIT

.model small ;   
.stack 100h ;incializar stack com 100h que corresponde a 256 byts

include emu8086.inc
;Incluir a biblioteca para utilizar o funcao PRINT

    macro ImprimirString msg ; macro que imprimir string 
        
        mov ah, 09h     ;mover a funcao imprimir string para ah 
        lea dx, msg     ;ler para dx o endereco   
        int 21h         ;realizar a funcao com o int 21h 
        
    endm  ;fechar macro

    macro somar soma        ;macro que calcula a soma num dado vetor      
        
        mov si, 00h         ; si e utilizado como indice do vetor
        xor ax, ax          ; Zerado porque al e utilizado para receber o valor de cada posicao do vetor 
        xor bx, bx          ; Zerardo porque bl e utilizado para receber e guarda a soma acomulada dos elementos de um vet
        mov cx, 10d         ; definir o contador com 10d
        
        somarDigito:   ; Label do loop somarDigito que funciona da seguinte maneira percorre movendo o valor para al e adicionando com bl
        
            mov al, [vetor+si]  ; Mover al o valor no vetor na posicao do si
            add bl, al          ; adicionar bl com al
            inc si              ; Incrementar si
        
        loop somarDigito    ;loop somarDigito
        
        mov soma, bl        ; Mover para a variavel soma o contiudo de bl
        
    endm  ;fechar macro                    
                        
    macro imprimir2Digito valor    ;macro que imprima um valor de 2 digito
        
        xor ax, ax      ;zerar ax porque e utilizado na divisao
        
        mov al, valor   ;mover para al o contiudo da variavel valor
        mov bl, 10d     ;mover para bl 10d
        
        div bl          ;dividir ax por bl, em que o resto e guardado em ah e a parte inteira em al
        
        mov bl, al      ;mover para bl o valor mais significativo da divisao
        mov bh, ah      ;mover para bh o valor menos significativo da divisao
        
        add bl, 30h     ;adicionar 30h ao registador bl
        add bh, 30h     ;adicionar 30h ao registador bh
        
        mov ah, 02h     ;mover a funcao imprimir 1 carater para ah
        mov dl, bl      ;mover dl, o valor bl
        int 21h         ;realizar a funcao com o int 21h 
        
        mov dl, bh      ;mover dl, o valor bh
        int 21h         ;realizar a funcao com o int 21h 
        
    endm   ;fechar macro 

    macro maiorE maior  ;macro que permite verificar qual e o maior elemento de um dado vetor

        mov si, 00h  ; mover para si 00h
        mov al, [vetor+si] ; mover para al o valor do vetor
        mov maior, al   ; mover para a variavel maior o valor em al
        mov cx, 9d     ; definir o contador com 9d
        xor bx, bx     ; zerar bx porque e utilizado para receber a posicao onde encontra o maior elemento
        maiorElemento:   ; nome ou label do meu loop
        
        mov ah, maior ;mover para al, o valor da variavel maior
        inc si      ; incrementar si
        mov al, [vetor+si]   ; mover para ah, o valor do vetor na posicao que se encontra o si
        cmp ah, al        ; comparar ah com al
        jl m          ; saltar para m caso al maior que ah
        jmp ok        ; caso falso para saltar para ok
            m:        ; label m
                mov maior, al  ;mover para maior o valor de al
                mov bx, si     ;mover para bx a posicao que esse elemento se encontra
            ok:      ; label ok
        
        loop maiorElemento ; meu loop com o label maiorElemento
        mov pos, bl    ; mover para pos o valor de bl ou seja a posicao onde ta o maior elemento

    endm  ;fechar macro

    macro ReceberDigito op   ; macro receber1digito com o parametro op

        mov ah, 01h    ; mover para ah 01h que e a funcao de ler 1 carater do teclado
        int 21h        ;realizar a funcao com o int 21h
        mov op, al     ; mover o carater para a variavel op

    endm  ;fechar macro

    macro comparar op     ; macro comparar com parametro op

        mov ah, op
        cmp ah, 31h
        je inserirNota
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
        
        limpar    ; chamar macro limpar
        
        print "Opcao errada !!!"  ; imprimir "Opcao errada !!!"  
        
        call NewLine      ;chama o procedimento mudanca de linha  
        
        print "Escolha novamente"   ; imprimir "Escolha novamente" 
        
        call NewLine   ;chamar o procedimento
        
        jmp final  
        
    endm   ;fechar macro

    macro le2Digito 

        xor dx, dx
        xor bx, bx
        mov dl, 0ah
        mov count, 2h
        
        recebe:   ; Label do jne   
        
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
        
    endm  ;fechar macro

    imprimir1digito macro valor      ;macro imprimir1digito com o parametro valor

        mov ah, 02h    ; mover para ah 02h que e a funcao de imprimir 1 carater
        mov dl, valor   ;mover para dl o valor a ser imprimido
        add dl, 30h   ; adicionar dl com 30h para considir com o valor na tabela ASCII
        int 21h    ;realizar a funcao com o int 21h

    endm ;fechar macro

    macro menorE menor      ;macro menorE como o parametro menor

        mov si, 00h
        mov al, [vetor+si]
        mov menor, al
        mov cx, 9d
        xor bx, bx
        
        menorElemento:  ; Label do loop
        
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

    endm ;fechar macro


    calcularMedia macro       
        
        xor ax, ax  ;zerar ax
        xor dx, dx  ;zerar dx 
        
        mov al, soma  
        mov bl, 10d   
        div bl       
        
        mov maisS, al 
        mov menosS, ah 
        
        call NewLine   ;chama o procedimento mudanca de linha
         
        Print "Media da turma: " ;imprimir "Media da turma: "
        
        imprimir2digito maisS    
        
        mov ah, 02h      ;mover para ah 02h que e uma funcao imprimir 1 carater
        mov dl, 2ch      ;mover o carater a ser imprimido para dl porque o carater tem que estar em dl
        int 21h ;realizar a funcao com o int 21h 
               
        imprimir1digito menosS ; chamar macro imprimir1digito que imprima o valor da var menosS
        
    endm ;fechar macro

    Apro_Repro macro apro repro
        
        mov si, 00h
        mov cx, 10d  
        
        percorrer:   ; Label do loop
        
            mov ah, [vetor+si]
            
            cmp ah, 9d
            jle reprov
            cmp ah, 10d
            jge aprov
            
            reprov:   
            
                inc reprovados
                jmp salto   
                             
            aprov:  
            
                inc aprovados 
            
            salto:
             
                inc si            
        
        loop percorrer     

    endm ;fechar macro

    macro AbAcMedia    ; macro abaixo e acima da media   
        
        mov aprovados, 00h
        mov reprovados, 00h
        
        mov cx, 10d
        mov si, 00h 
        
        brincar:  ; Label do loop
        
            mov al, [vetor+si] 
            
            cmp al, maisS
            jle reprova
            cmp al, maisS
            jge aprova 
               
            reprova:   
            
                inc reprovados
                jmp saltos
                
            aprova:
            
                inc aprovados 
                   
            saltos:
            
                inc si 
            
        loop brincar        

    endm ;fechar macro

    macro ordenar

        mov cx, 10d    ; mover para cx 10d
        xor ax, ax      ; zerar ax
        xor bx, bx      ; zerar bx
        
        exterior:     ; Label do jnz  
        
            mov dx, 00h         ;mover para dx 00h
                       
                       
            interior:    ; Label do jl
            
                mov si, dx
                mov al, [vetor+si] 
                inc si
                mov bl, [vetor+si]
                dec si
                
                cmp al, bl
                jl trocar:
                jmp naoTrocar
                
                trocar:    ; Label do jl
                
                    xchg al, bl
                    mov [vetor+si], al
                    inc si
                    mov [vetor+si], bl
                    dec si
                
                naoTrocar:  ; Label do jmp
                
                    inc dx 
            
            cmp dx, 9d
            jl interior
            
            dec cx   
            
        jnz exterior        

    endm  ;fechar macro

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
        int 10h   ;realizar a funcao com o int 10h

    endm      ;fechar macro

    macro tabela

        Print "Tabela com os alunos"   ;imprimir "Tabela com os alunos"

        call newline   ;chamar o procedimento
        call newline   ;chamar o procedimento
        
        ImprimirString tab
        
        mov cx, 10d 
        mov si, 00h
        xor dx, dx
        
        brincar2:         ; Label do jnz
        
            mov bl, [vetor+si]
            mov i, bl
            
            cmp i, 9d
            jle okErepro
            
                mov dx, si 
                mov j, dl
                add j, 1h
                
                ImprimirString !0
                imprimir2digito j
                ImprimirString !1
                imprimir2digito i
                ImprimirString !2
                ImprimirString !3
            
            jmp naoSaltarOk
            
            okErepro:      ; Label do jle
            
            mov dx, si 
            mov j, dl
            add j, 1h
            
                ImprimirString !0
                imprimir2digito j
                ImprimirString !1
                imprimir2digito i
                ImprimirString !4
                ImprimirString !3               
                
            naoSaltarOk:   ; Label do jmp
            
                inc si
                dec cx 
        
        jnz brincar2
        
    endm    ;fechar macro

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
        
        infinito:     ; Label do jmp
        
            imprimirString Menu      ; chamar macro imprimirString com o paramentro Menu
            receberDigito op         ;  chamar macro receberDigito com o paramentro op
            comparar op       ; chamar macro comparar com o paramentro op
            
            inserirNota:    ; Label da comparacao
                         
                limpar     ; chamar macro limpar
                
                mov controlo, 01h
                call NewLine           ;chama o procedimento mudanca de linha
                
                mov cx, 10d            ; mover para cx 10 em decimal
                mov si, 0d             ; mover para si 00h
                mov cont, 01h          ; mover para cont 01h
                
                Print "Introduza as notas" ;imprimir "Introduza as notas"
                 
                call newline     ;chamar o procedimento
                
                ler:   ; Label do loop
                 
                    erro:         ; Label do jmp  
                    
                        call NewLine    ;chama o procedimento mudanca de linha 
                        
                        cmp cont, 09h   ; comparar cont com 9h
                        jg maior9       ; saltar para maior se cont for maior
                        
                        imprimir1digito cont   ;chamar  macro imprimir1digito com parametro cont 
                        
                        jmp saltar              ;jmp incondicional para saltar evitando fazer as intrucoes abiaxo
                        
                        maior9:          ; Label do jg
                        
                            imprimir2digito cont     ; chamar macro imprimir2digito com parametro cont  
                        
                        saltar:     ; Label do jmp
                                
                            Print " Nota: "    ; imprimir " Nota: "
                               
                            le2Digito           ; chamar macro le2digito
                            
                            cmp bl, 20d         ; comparar bl com 20d
                            jbe aceito          ; se for menor ou igual a 20d salta para aceitar
                            
                            call NewLine    ;chamar o procedimento
                            
                            Print "ERRO: Escala de 0 a 20" ;imprimir " ERRO: Escala de 0 a 20 "
                               
                    jmp erro          ; jmp incondicional que salta para o rotulo erro
                    
                    aceito:           ; Label do jbe
                    
                        mov [vetor+si], bl ; mover para vetor o valor de bl conforme o valor de si
                        inc cont        ;incrimentar cont
                        inc si      ;incrimentar si
                    
                loop ler            ; loop com o rotulo ler e faz de acordo com o valor de cx a cx for 0
                
                call newline     ;chamar o procedimento
                call newline     ;chamar o procedimento       
            
            jmp final
            
            MaiorNota:       ; Label da comparacao   
            
                cmp controlo, 00h
                je okE0
            
                limpar      ; chamar macro limpar
            
                maiorE maior     ;chamar o procedimento
                
                call NewLine       ;chamar o procedimento
                
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
                
                limpar    ; chamar macro limpar
                
                menorE menor  
                
                call NewLine      ;chama o procedimento mudanca de linha 
                
                Print "Aluno: "   ;imprimir "Aluno: "
                
                add pos, 01h  
                
                imprimir2digito pos  
                
                Print " com a nota: "  ;imprimir " com a nota: "
                
                imprimir2digito menor   
                    
                call newline  ;chamar o procedimento
            
            jmp final
            
            MediaTurma:    ; Label da comparacao
            
                cmp controlo, 00h
                je okE0 
                
                limpar    ; chamar macro limpar
                
                somar soma
                calcularMedia
                
                call newline 
                
            jmp final
            
            Q_Apr_Repro:     ; Label da comparacao
            
                cmp controlo, 00h
                je okE0  
                
                limpar
                
                Apro_Repro aprovados reprovados
                
                call NewLine    ;chamar o procedimento  
                
                Print "Numero de aprovados: "   ;imprimir "Numero de aprovados: "
                
                imprimir2digito aprovados 
                
                call NewLine   ;chamar o procedimento 
                
                call newline  ;chamar o procedimento
                
                Print "Numero de reprovados: "  ;imprimir "Numero de reprovados: "
                
                imprimir2digito reprovados  
                
                call newline  ;chamar o procedimento
            
            jmp final
            
            Nota_Media:    ; Label da comparacao
            
                cmp controlo, 00h
                je okE0     
                
                AbAcMedia
                
                limpar    ; chamar macro limpar
                
                Print "Notas Acima e abaixo da media" ; imprimir "Notas Acima e abaixo da media" 
                
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
            
            TabAproRepro:     ; Label da comparacao
            
                cmp controlo, 00h
                je okE0
            
                limpar    ; chamar macro limpar
                
                tabela
            
            jmp final
            
            ImprimirOrdenado:     ; Label da comparacao
            
                cmp controlo, 00h
                je okE0    
            
                limpar
                
                ordenar
                
                mov cx, 10d
                mov si, 00h 
                
                call NewLine ;chamar o procedimento
                    
                Print "Notas por ordem decrescente" ;imprimir "Notas por ordem decrescente" 
                
                call NewLine ;chamar o procedimento
                call newline  ;chamar o procedimento  
                
             rodar:    ; Label do loop
             
                    mov dl, [vetor+si] 
                    
                    imprimir2digito dl 
                    
                    call newline
                    
                    inc si 
                    
            loop rodar 
            
            jmp final
            
            okE0:      ; Label do je
            
                limpar     ; chamar macro limpar
                
                call NewLine ;chamar o procedimento
                
                Print "Sem notas"  ;imprimir "Sem notas"
                
                call NewLine ;chamar o procedimento
                
            jmp final                                                    
            
            final:     ; Label do jmp
            
                call NewLine ;chamar o procedimento 
                
                Print "Press any key to continue... " ; imprimir "Press any key to continue... " 
                
                mov ah, 01h
                int 21h ;realizar a funcao com o int 21h
            
                limpar      ; chamar macro limpar
            
            jmp infinito
            
            
            NewLine proc ; inicializar procedimento mudanca de linha
            
                mov ah, 02h     ; mover para ah 02h que e a funcao de imprimir 1 carater
                mov dl, 0ah     ;mover para dl o carater mudanca linha 
                int 21h         ;realizar a funcao com o int 21h
                
                mov dl, 0dh     ; mover para dl o carater cret que coloca o pusor no inicio
                int 21h         ;realizar a funcao com o int 21h
                
                ret         ;retornar para onde foi chamado
                           
            NewLine endp        ; fechar o procedimento
            
            sair:         ; Label da comparacao
                    
                limpar    ; chamar macro limpar
                
                Print "Obrigado & volte sempre"     ; imprimir "Obrigado & volte sempre"
        
end main      ; fim do codigo