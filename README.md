 En esta ocasión traigo este interesante proyecto; se trata de una aplicación para *Android* hecha en Mit App Inventor que permite ejecutar determinados comandos en la PC. 

A través de *bluetooth* la aplicación envía caracteres que serán recibidos por un **Pro Micro** con un módulo *HC-06* conectado a él. 

El microcontrolador entonces interpretará estos caracteres y ejecutará los comandos asociados en la PC. 

Utilizaremos la librería **SoftwareSerial.h** para realizar la conexión con el módulo HC-06 y la librería **Keyboard.h** para emular el teclado.

Para este proyecto elegí los siguientes comandos que el Pro Micro *escribirá* en la pc: 

- *systemctl poweroff* (apaga la pc)
- *systemctl reboot* (reinicia el sistema)
- *systemctl suspend* (pone la pc en estado de suspensión)
- *loginctl lock-session* (bloquea el sistema)
- *loginctl unlock-session* (desbloquea el sistema)

El Pro Micro envía primero la instrucción **ALT+F2** para poder luego ingresar cualquiera de los comandos arriba enumerados. 

El funcionamiento de la app es muy sencilla cada botón tiene asignada una acción que es la de enviar un caracter "L-U-S-P-R" (bloquear, desbloquear, suspender, apagar y reniciar correspondientemente) vía bluetooth al Pro Micro. 

Pueden encontrar más información en: [https://thenerdyapprentice.blogspot.com/](https://thenerdyapprentice.blogspot.com/) 
