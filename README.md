![image](https://github.com/Xxproner/Arduino_blue/assets/150460572/ad86f6d5-ee8d-4752-bd5f-be4fd41f4340)
![image](https://github.com/Xxproner/Arduino_blue/assets/150460572/a7f55eb9-e0ed-4546-a50e-1773c4ac6045)

Bluetooth модуль ZS-040:
Подключение:![image](https://github.com/Xxproner/Arduino_blue/assets/150460572/38d84a70-19da-4f79-aed9-5ce0075000bf)
Имеет 6 контактов, используется только центральные 4.
GND - земля
VCC - питание (5V)
TXD - линия передачи данных (на ПК или телефон)
RXD - линия приёма данных (с ПК или телефон). Подключается через делитель напряжения
Для работы необходимо подключить нужную библиотеку //#include <SoftwareSerial.h>//, затем необходимо обозначить, какие пины будут использоваться в качестве
TXD и RXD //SoftwareSerial BTserial(8, 9);// В setup(){} прописать //BTserial.begin(9600);//. Для передачи данных с компьютера необходимо прописать в loop (){}
 //while (BTserial.available() == 0) {}// - происходит зацикливание до тех пор, пока что-то не передастя по bluetooth, //String command = BTserial.readString();// - считывание команды с ПК/телефона, //command.trim();// - удаление лишних пробелов в команде.
 Более подробная информация - http://arduino.on.kg/bluetooth-modul-zs-040.
