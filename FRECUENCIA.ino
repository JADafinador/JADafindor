// Parámetros de la señal sinusoidal
float frecuencia = 82.4;  // Frecuencia en Hz
int amplitud = 127;      // Amplitud de la señal PWM (0-255)
float fase = 0.0;        // Fase inicial en radianes

void setup() {
  // No es necesario realizar ninguna configuración en el setup
}

void loop() {
  // Generar una señal sinusoidal mediante PWM
  float valorSin = sin(2 * PI * frecuencia * millis() / 1000.0 + fase);
  int valorPWM = int((valorSin + 1.0) / 2.0 * amplitud);

  analogWrite(9, valorPWM);  // Salida PWM en el pin 9

  // Puedes ajustar la frecuencia, amplitud y fase según tus necesidades
}