from ultralytics import YOLO
import cv2

# carregar o modulo
modelo = YOLO("yolov8n.pt") 

# abrir a camera
cap = cv2.VideoCapture(0)

while True:
    sucesso, frame = cap.read() #ler os objetos
    
    if sucesso:
        # Detetar objetos
        resultados = modelo(frame, stream=True)
        
        # mostrar os resultados obtidos pela camera
        for r in resultados:
            
            frame_anotado = r.plot()
            cv2.imshow("Reconhecimento de objetos", frame_anotado) # titulo da minha janela

    # opcao sair do loopp
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release() # fechar a camera
cv2.destroyAllWindows() # fechar as janelas 