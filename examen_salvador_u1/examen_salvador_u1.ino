int pin1 = 13;
int pin2 = 12;
int pin3 = 11;
int pin4 = 10;

void setup() {
  Serial.begin(9600);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
}

void loop() {
  // Leer el estado de cada pin
  bool estadoPin1 = digitalRead(pin1);
  bool estadoPin2 = digitalRead(pin2);
  bool estadoPin3 = digitalRead(pin3);
  bool estadoPin4 = digitalRead(pin4);

  // Enviar el carácter correspondiente si un pin está en HIGH
  if (estadoPin1 == HIGH) {
    Serial.print('a');
  }
  if (estadoPin2 == HIGH) {
    Serial.print('b');
  }
  if (estadoPin3 == HIGH) {
    Serial.print('c');
  }
  if (estadoPin4 == HIGH) {
    Serial.print('d');
  }

  delay(300);  // Esperar 1 segundo antes de la siguiente lectura
}