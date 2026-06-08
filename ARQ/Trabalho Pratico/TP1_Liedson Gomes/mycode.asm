#start=led_display.exe#

; Exercicio 1

; LIEDSON GOMES ARAUJO, LEIT, 20230015   

;------------------------------------; 
       
; Exercicio 2

    ; a) Code_Aluno-20230015 ____ 134AF7F
    
    ; b) CNI-20051215 _____ 131F50F  
    
    ; c) Ano-2005 __________ 7d5  
    
;------------------------------------; 
    
; Exercicio 3

    mov bx, 134Ah

;------------------------------------; 
    
; Exercicio 4

    mov cx, 1215h   

;------------------------------------; 


; Exercicio 5  

    mov ax, 7d5h
    mov dx, 10d
    mul dx
       

;------------------------------------;

; Exercicio 6

    mul cx
    mov cx, ax

;------------------------------------;
    
; Exercicio 7
    
    xor ax, bx

;------------------------------------; 
    
; Exercicio 8

    cmp cx, bx
    jg maior
    sub bx, cx
    
    maior: 
      sub cx, bx

;------------------------------------; 
      
; Exercicio 9

    mov dx, 7d5h
    or dx, ax

;------------------------------------; 
    
; Exercicio 10      
        
    and cl, ch 
    
;------------------------------------;     
    
; Exercicio 11

  mov dx, 134h
  mov cx, 50Fh
  add dx, cx
  mov ax, dx   

;------------------------------------;     
    
; Exercicio 12
    mov ax, 0ffh      
    mov cx, 5d
    div cx
    
    cmp ah, dh
    jg ok
     
    mov ax, 5555d
    out 199, ax
    ok:
        mov ax, 1111d
        out 199, ax    