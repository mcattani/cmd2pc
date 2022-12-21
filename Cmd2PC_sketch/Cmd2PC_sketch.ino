/*
    Para este proyecto utilizaremos un Arduino Leonardo (o Pro Mini) y un módulo bluetooth HC-06 (conectado a los pines 8 y 9)
    Desde el celular enviaremos caracteres que el Arduino interpretará y ejecutará los comandos correspondientes
    en la PC. En este caso los comandos corresponden a un sistema Gnu/Linux.
    Toda la información en: https://thenerdyapprentice.blogspot.com/
    The Nerdy Apprentice
*/

// Incluimos la librería SoftwareSerial que vamos a utilizar para comunicarnos con el módulo BT
#include <SoftwareSerial.h>

#include <Keyboard.h> // Librería para emular el teclado.

SoftwareSerial BTSerial(8, 9);  // RX, TX --> Recordar que las conexiones van cruzadas RX en el Arduino -> TX en el módulo BT

// Declaramos las constantes que vamos a utilizar
const String Passsword = "";  // Ingresar aquí el password de login para la PC
char Comando;    // Comandos que recibiremos desde el móvil
int Pausa = 600; // A veces hay que ajustar este delay según la velocidad del ordenador

void setup() {

  // Inicializamos los puertos serie
  BTSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {

  if (BTSerial.available()) { // Si el puerto serie BT está disponible leemos la información entrante y la guardamos en la variable.
    Comando = BTSerial.read();
    Keyboard.begin();

    switch (Comando) { // Según el comando recibido ejecutaremos el comando correspondiente.
      
      case 'L':  // Bloquear pantalla
        Serial.println("Comando recibido");
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_F2);
        Keyboard.releaseAll();
        delay(Pausa);
        Keyboard.print("loginctl lock");
        Keyboard.write(47);
        Keyboard.println("session");
        break;

      case 'U':  // Desbloquear pantalla
        Keyboard.println(Passsword);
        break;

      case 'S':  // Suspender
        Serial.println("Comando recibido");
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_F2);
        Keyboard.releaseAll();
        delay(Pausa);
        Keyboard.println("systemctl suspend");
        break;

      case 'P':  // Apagar
        Serial.println("Comando recibido");
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_F2);
        Keyboard.releaseAll();
        delay(Pausa);
        Keyboard.println("systemctl poweroff");
        break;

      case 'R':  // Reiniciar
        Serial.println("Comando recibido");
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_F2);
        Keyboard.releaseAll();
        delay(Pausa);
        Keyboard.println("systemctl reboot");
        break;
    }
    Keyboard.end();
  }
}
