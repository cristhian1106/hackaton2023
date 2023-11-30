import cv2
import serial
import time

puerto_serie = serial.Serial('COM3', 9600, timeout=1)

def enviar_letra_a_arduino():
    try:
        # Configurar el puerto serie (ajusta el número del puerto según sea necesario)
        

        # Esperar un breve momento para permitir que el Arduino se inicialice
        ##time.sleep(2)

        # Enviar la letra 'P' al Arduino
        puerto_serie.write(b'P')
        
        # Cerrar el puerto serie
        

        print("Letra 'P' enviada con éxito al Arduino.")

    except Exception as e:
        print(f"Error al enviar la letra 'P' al Arduino: {e}")

face_cascade = cv2.CascadeClassifier('haarcascade_profileface.xml')

cap=cv2.VideoCapture(0)
count = 0,

while True:
    _, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces=face_cascade.detectMultiScale(gray,1.1,6)
    for(x,y,w,h) in faces: 
        if count < 1:
            count += 1
            enviar_letra_a_arduino()
        cv2.rectangle(img,(x,y),(x+h,y+h),(2550,0),2)
    cv2.imshow('img',img)
    k= cv2.waitKey(30)
    count =0
    if k==27:
        break
puerto_serie.close()
cap.release()