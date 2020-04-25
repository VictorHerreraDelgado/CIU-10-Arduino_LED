# CIU-10-Arduino_LED
## Introducción
Como una forma de introducirse a la programación usando Arduino, se ha realizado un sencillo programa teniendo un componente LED conectado a una placa Arduino uno (o una simulación de ambos componentes) como elementos hardware de la práctica. Con estos componentes se realiza un programa que genera una señal senoidal, de tal forma que el valor de su función en un momento de tiempo será la frecuencia con la cual el LED conectado parpadeará, siendo el valor máximo de la señal senoidal correspondiente a la frecuencia máxima y su valor mínimo correspondiente a la frecuencia mínima.

## Herramientas.
Tanto para la simulación de la placa Arduino y LED así como para la escritura del código se usó Tinkercad [1] . Se uso documentación tanto de Tinkercad [1] como del Guión de prácticas [2] y  la documentación de Arduino [3].  
Puede encontrar el proyecto en Tinkercad en el siguiente enlace:  
https://www.tinkercad.com/things/3FW134c6sbp-led-sinblink


## Desarrollo
La simulación realizada en Tinkercad[1] se basó en la información del ejemplo de blink de la documentación de Arduino[3,4].

En cuanto al código, en primer lugar, se han definido los elementos estáticos que tendrán gran relevancia en el programa: Las frecuencias límites del parpadeo del LED, la frecuencia de la señal senoidal, la constante PI y el valor w que inicializaremos en setup(). Las frecuencias límites si bien no parecen tener una diferencia significativa, son lo suficientemente variadas como para ser diferenciables. Además, a partir del valor 0.5, la diferencia en el parpadeo es imperceptible e incluso ineficiente al tener que cambiar la placa Arduino tan rápido entre encendido y apagado .Por otro lado, la frecuencia de la señal senoidal ha sido elegida de tal manera que es visible por el espectador del LED sin ser lo suficientemente lento el cambio como para esperar demasiado. 

Estando el programa escrito en Arduino y siendo de tal simpleza, este únicamente cuenta con dos métodos: setup() y loop(). 
En setup() nos limitamos a iniciar la variable w, la conexión al LED e iniciar el puerto serial para las pruebas pertinentes.

Por otro lado, en loop() se realiza la mayor parte del código. En primer lugar, calculamos el valor de la función senoidal en función a la información disponible de la función senoidal[5] usando el tiempo de ejecución obtenido con la función millis() pasado a segundos. Posteriormente realizamos el mapeamiento del valor de la senoidal de acuerdo a los límites de frecuencia definidos para el parpadeo del LED. Se ha realizado el cálculo a mano ya que en pruebas anteriores, la función map() no parecía mostrar la suficiente precisión en decimales para su mapeado.
A continuación, realizamos el proceso de parpadeo, encendiendo o apagando el LED y sacando el periodo a partir de la frecuencia obtenida (teniendo que multiplicarla para que su valor sea más adecuado)  para usarlo con la función delay() y producir el efecto de parpadeo hasta el siguiente apagado o encendido del LED.

Se comprobó también durante la realización de la práctica que la transformación del valor de la senoidal a frecuencia de parpadeo era efectiva, pues usando un bloque de código (que se puede ver comentado en la versión completa de github) se obtuvo el tiempo que tomaba el led en cada etapa, siendo este aproximadamente igual para cada uno.

## Referencias.
 [1] Tinkercad:  https://www.tinkercad.com/  
 [2] Guión de Prácticas:    
https://cv-aep.ulpgc.es/cv/ulpgctp20/pluginfile.php/126724/mod_resource/content/35/CIU_Pr_cticas%20-1920.pdf  
[3] Documentación de Arduino: https://www.arduino.cc/en/main/docs  
[4] Conexión Arduino-LED: https://www.arduino.cc/en/tutorial/blink  
[5] Artículo de la senoidal/sinusoide:  https://es.wikipedia.org/wiki/Sinusoide  


