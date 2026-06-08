import cv2
from ultralytics import YOLO

# Carrega o modelo
model = YOLO("yolov8n.pt")

cap = cv2.VideoCapture(0)

while cap.isOpened():
    success, frame = cap.read()
    
    if not success:
        break

    # Realiza a detecção
    results = model(frame)

    # --- A MÁGICA DA CONTAGEM AQUI ---
    for r in results:
        # Pega todos os IDs das classes detectadas
        classes = r.boxes.cls.tolist()
        
        # Conta quantos IDs são iguais a 0 (Pessoa)
        num_pessoas = classes.count(0)
        
        # Desenha na tela o resultado
        cv2.putText(frame, f"Pessoas: {num_pessoas}", (50, 50), 
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # Mostra o vídeo com a contagem
    cv2.imshow("Contador de Pessoas", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()