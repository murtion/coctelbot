import serial

portSerial = serial.Serial('/dev/ttyACM0', 9600)

while True:
    if portSerial.in_waiting > 0:
        dato = portSerial.readline().decode().rstrip('\r\n')
        print("Dato recibido: ", dato)
        if dato == "1":
            print("Se cumplen las condiciones")
