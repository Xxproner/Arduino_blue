Bluetooth модуль ZS-040:
Подключение:
Bluetooth модуль ZS-040 имеет 6 контактов, но используются только центральные 4:
GND: земля.
VCC: питание (5V).
TXD: линия передачи данных (к ПК или телефону).
RXD: линия приёма данных (с ПК или телефона, подключается через делитель напряжения).
Для работы необходимо подключить нужную библиотеку //#include <SoftwareSerial.h>//, затем необходимо обозначить, какие пины будут использоваться в качестве
TXD и RXD //SoftwareSerial BTserial(8, 9);// В setup(){} прописать //BTserial.begin(9600);//. Для передачи данных с компьютера необходимо прописать в loop (){} //while (BTserial.available() == 0) {}// - происходит зацикливание до тех пор, пока что-то не передастя по bluetooth, //String command = BTserial.readString();// - считывание команды с ПК/телефона, //command.trim();// - удаление лишних пробелов в команде. Команды отпарвки сообщений на ПК аналогичны командам вывода в терминале: //BTserial.print("The space temperature = "); // //BTserial.println(Thermistor(analogRead(temp_pin)));//
Более подробная информация - http://arduino.on.kg/bluetooth-modul-zs-040 .
![image](https://github.com/Xxproner/Arduino_blue/assets/150460572/b0461996-025d-4988-b49e-ef48d474af4a)

Датчик температуры KY - 013:
Датчик температуры имеет три контакта:
GND: земля.
VCC: питание (5V).
OUT: выход.
Следующая функция преобразует сигнал от датчика в температуру по цельсию: 
//double Thermistor(int RawADC) {
  return 20.0 - (RawADC - 560) / 5.7;
}//
Более подробная информация – https://arduino-tex.ru/news/48/ky-013-modul-analogovogo-datchika-temperatury.html .
![image](https://github.com/Xxproner/Arduino_blue/assets/150460572/ab738b3e-e58a-4d22-ae03-0ee3328c49ca)

Датчик дистанции IR - 08H:
Датчик дистанции имеет 4 контакта, но используются только 3:
GND: земля.
VCC: питание (5V).
OUT: выход.
Датчик работает по принципу: один диод посылает ИК излучение, и если оно отражается и регистрируется вторым, датчик подаёт сигнал. Чёрные поверхности не отражают ИК излучение, в то время как белые поверхности лучше всего его регистрируют.
Более подробная информация –  https://arduino-site.ru/datchik-prepyatstviya/.
![image](https://github.com/Xxproner/Arduino_blue/assets/150460572/c373e8c2-4313-4068-8925-9aceafcbbd42)

Датчик присутствия SR505:
Датчик присутствия имеет три контакта:
GND: земля.
VCC: питание (5V).
OUT: выход.
Датчик реагирует на изменения в ИК окружающей среды и подаёт сигнал при их обнаружении. После этого в течение 8 секунд не принимает новые сигналы.
Более подробная информация –https://iarduino.ru/shop/Sensory-Datchiki/infrakrasnyy-datchik-dvizheniya-sr505.html .
![image](https://github.com/Xxproner/Arduino_blue/assets/150460572/5eb9093f-3b23-4ad1-b699-bfb6d6eee738)

Датчик шума KY - 038:
Датчик шума имеет 4 контакта, используются только 3:
GND: земля.
VCC: питание (5V).
OUT: выход.
Датчик регистрирует сигнал при колебаниях мембраны. Работает лучше всего, если на него направлен поток воздуха, вызывающий колебания мембраны.
Более подробная информация – https://www.yourduino.ru/blogs/blog/ky038urok .
![image](https://github.com/Xxproner/Arduino_blue/assets/150460572/7a82e408-f419-4296-b724-b9189a7fb1b0)

