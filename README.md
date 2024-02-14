# JADafindor
Afinador de guitarra eléctricas mediante Arduino Uno.
# Partes del afinador
El afinador está compuesto por: amplificador, arduino, leds, alimentación general.
## Amplificador
Se ha utilizado el amplificador operacional TL082 con realimentación positiva. Este chip tiene dos entradas, una inversora y otra no inversora, la señal en la entrada inversora se compara con la señal de entrada inversora para generar una salida amplificada; es necesario tener una fuente de alimentación bipolar, es decir, que tenga voltajes tanto positivos como negativos, en nuestro caso +9 y -9; tiene una alta ganancia de voltaje, lo que significa que puede amplificar la diferencia de voltaje entre las entradas; tiene una impedancia de entrada relativamente alta, lo que presenta una carga mínima a la entrada de la señal; tiene una impedancia de salida baja, lo que ayuda a entregar la señal amplificada con mayor facilidad a cargas externas; tiene una respuesta en frecuencia ancha, lo que significa que es capaz de amplificar señales a través de un amplio rango de frecuencias. Chip de 8 pines; funcionamiento de cada pin:
1- Salida.
2- Primera entrada inversora.
3- Primera entrada no inversora.
4- GND o tierra.
5- Segunda entrada no inversora.
6- Segunda entrada inversora.
7- Segunda salida.
8- Positivo.
## Arduino
Para nuestro proyecto hemos usado un código de la siguiente página: https://www.instructables.com/Arduino-Guitar-Tuner/ . Os vamos a explicar las partes más complicadas del código: el conversor ADC de Arduino es el encargado de la conversión digital empleada en la placa, el ADC convierte un voltaje analógico de entrada en un valordigital de 10 bits a través de aproximaciones sucesivas; Multi Inputs Analog ADMUX, se interrumpe y se ejecuta cada vez que un nuevo valor analógico está listo desde A0; REFS0, ADLAR, ADPS2, ADATE, ADIE, ADEN, ADSC, son fnciones del ADC; Al comienzo del programa declara las variables, luego enciende todas las leds de forma secuencial y las apaga para mostrar el valor recibido desde la entrada de audio, en nuestro caso posicionada en el pin A0. En función de los hercios recibidos, encenderá unas leds u otras, una verde para decir que la nota está afinada, 3 rojas a la izquierda de la led verde que indican que la frecuencia está por debajo, 3 leds rojas a la derecha que indica que la frecuencia está por encima, y 6 leds que indican que nota se está tocando. Por ejemplo, queremos encender la nota LA, que para que esté afinada necesita leer el Arduino 110 Hz; entonces, si tocamos la cuerda de la guitarra, y el Arduino lee 104 Hz, encenderá las 3 leds rojas a la izquierda, si lee 106 Hz, encenderá las 2 led rojas a la izquierda, y si lee 108 Hz encenderá una sola led roja a la izquierda; si lee 110 Hz, encenderá la led verde; hará lo mismo leyendo por encima, pero encendiendo las leds rojas de la derecha en función que las necesite; además de eso, encenderá alguna de las 6 leds, indicando la nota que está detectando el Arduino en cada momento.
Se puede acceder al código de Arduino deade este enlace:
https://github.com/JADafinador/JADafindor/blob/main/FRECUENCIA.ino
## Alimentación general
Hemos optado por realizar un placa en la que posicionamos todos los componentes. Hemos puesto 4 pads para la alimentación, a los que irán conectados 2 pilas recargables de 9 voltios cada una. Hemos puesto la placa con pines necesarios para que se pueda conectar directamente con Arduino sin necesidad de tener cables de por medio. las leds serán alimentadas mediante los pines de 5 voltios y GND/tierra; las 6 leds rojas, consumirán 120 mA en total; las 6 leds de las notas, 60 mA en total; 1 led verde, 20 mA. En total, las leds consumirán 200 mA. El Arduino consume 50 mA. En total, todo el conjunto consumirá 250 mA.
Además, tenemos en la misma placa el encendido de la placa y la entrada de audio. El encendido de la placa se basa en un simple interruptor de dos posiciones, como los interruptores de toda la vida, los básicos y sencillos. Por otro lado se encuentra la entrada de audio, que se realiza mediante un cable que va desde la guitarra hasta el jack de entrada de audio.
## Entrada de audio
La entrada de audio se realizó de la siguiente manera. Primeramente, mirando el esquema que hicimos en el software Proteus Professional 8, nos dimos cuenta de que el propio chip TL082, el amplificador operacional, amplificaba la señal con valores negativos. Con esos valores negativos, el Arduino no era capaz de captar la parte de la onda que bajaba de 0 voltios, así que tuvimos que poner un divisor de tensión para trasladar la salida de audio de 2,5v/-2,5v a 5v/0v, y así el Arduino es capaz de leer la señal y visualizarla en la placa.
# Ensamblaje de la caja
Para poder transportar nuestro proyecto de manera correcta y segura, optamos por meterlo en una caja, más concretamente, en una caja para pedal de guitarra. Hicimos unos agujeros para poder meter tanto el interruptor como el jack de señal de audio.  Además de eso, para que se pudiera ver toda la parte de dentro, es decir, todo el conexionado y todos los elementos que componen nuestro proyecto, pusimos una tapa hecha de metacrilato transparente. A esa tapa transparente le hicimos unos agujeros, para que se pudieran ver las leds, y así, poder afinar correctamente nuestra guitarra eléctrica.
Además de todo eso, la alimentación, en nuestro caso las 2 pilas recargables de 9 voltios cada una, también se han metido dentro de la caja, siendo fáciles de manipular en caso de que se descarguen o dejen de funcionar.
![image](https://github.com/JADafinador/JADafindor/assets/158027588/d62bfb2a-2ff2-4268-b8da-cfd16cd8a69e)
![n](https://github.com/JADafinador/JADafindor/assets/158027588/98b10d2a-4654-4b8c-8507-3fd218fb233f)
# Problemas
Las leds necesitan sus resistencias correspondientes, pero por problemas con el espacio, no pudimos poner las resistencias que van soldadas por Through Hole, así que tuvimos que hacer el esquema de la PCB que esas resistencias fueran SMD, así, se ocupó mucho menos espacio y se pudo encajar la placa de manera correcta dentro de la placa.
# Mejoras
Es posible poner en el código de Arduino un apartado en el que avisemos con una led de otro color y en otra zona si las baterías están descargadas o han dejado de dar voltaje.
Se podría realizar una PCB algo más grande para poder realizar todas las conexiones bien, sin tener cables de por medio; por otro lado, se puede poner más rango de detección de frecuencia, así se haría todo más exacto y sería un afinador mucho más preciso.
