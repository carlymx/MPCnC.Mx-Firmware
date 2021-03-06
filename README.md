# Marlin Firmware 2.0.x Adaptado para la MPCnC-Mx.

Esta Modificación del famoso firmware esta destinada a controlar de manera adecuada una maquina CNC (Control Numérico Computarizado) llamada [MPCnC-Mx](https://www.thingiverse.com/thing:3218244) que es una variante para métrica Internacional de la MPCnC.

**NOTA:** Debe ser compilado con la ultima [versión 1.9.x](https://www.arduino.cc/en/Main/Software) (o superior) del Arduino IDE. 

## Características:

 - Versión del Marlin 2.0.x bugfix (11-04-2019).
 - Configurado para Arduino Mega 2560 + Ramps v1.4
 - Doble Motor en Ejes X e Y de control independiente.
 - Doble Final de Carrera en ejes X e Y para un ajuste mas preciso del punto 0.
 - 32 micropasos, definición suficiente sin perdida de Torque.
 - Pasos por vuelta configurados para el uso de husillos en el eje Z.
 - Pasos por vuelta configurados para el uso de poleas de 20 dientes y correas GT2 en los ejes X e Y.

 
** Notas importante: 
 - Este firmware es experimental y esta sujeto a múltiples posibles problemas que pueden o no, dificultar la experiencia del usuario. Tenga en cuenta támbien que el uso debido o indebido de este firmware puede dañar su maquina. USELO BAJO SU PROPIA RESPONSABILIDAD!.
 
 - Configurado para un tamaño util de trabajo de 500x900x100mm, tenga en cuenta a cambiar eso valores para el tamaño establecido por usted en su maquina (Puede calcular el tamaño de su maquina [con esta calculadora](https://jscalc.io/calc/QHWZUpKFJzyGVS2D).

 

## CHANGELOG

09-06-2019

 - Añadida configuración predeterminada para la RUMBA en **.\config\MPCnC-Default-RUMBA**

02-05-2019

 - **EEPROM** Desactivada, de momento no es necesaria y da problemas... como siempre.
 - Desactivada **#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN**, se ha dejado de usar el Final de Carrera del Z, ahora se hace por gCode.
 - Modificada **#define Z_CLEARANCE_BETWEEN_PROBES  20** para permitir bajar la broca mas alla del punto cero.
 - Invertidos **Invert the stepper direction.** para usar el punto cero de la cama en la esquina correcta.


13-04-2019

 - Actualizado a Marlin 2.0.x-11-04-2019.
 - Autolevel Bilinial.
 - Activada la Confirmación de inicio del GCode selecionado.
 - Activados los juegos (por probar).
 - Revisión de Configuración.

 
## Credits

El proyecto Original del que depende totalmente esta pequeña modificación es:

[Marlin Home Page](http://marlinfw.org/)

[GitHub](https://github.com/MarlinFirmware/Marlin)

[Wiki Page](http://reprap.org/wiki/Marlin)

The current Marlin dev team consists of:

 - Scott Lahteine [[@thinkyhead](https://github.com/thinkyhead)] - USA &nbsp; [![Flattr Scott](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=thinkhead&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)
 - Roxanne Neufeld [[@Roxy-3D](https://github.com/Roxy-3D)] - USA
 - Bob Kuhn [[@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)] - USA
 - Chris Pepper [[@p3p](https://github.com/p3p)] - UK
 - João Brazio [[@jbrazio](https://github.com/jbrazio)] - Brazil
 - Erik van der Zalm [[@ErikZalm](https://github.com/ErikZalm)] - Netherlands &nbsp; [![Flattr Erik](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
