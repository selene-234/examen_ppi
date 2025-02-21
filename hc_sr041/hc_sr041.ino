const int Trigger = 10;   // Pin digital 10 para el Trigger del sensor
const int Echo = 11;      // Pin digital 11 para el Echo del sensor
const int Led = 13;       // Pin digital 13 para el LED

void setup() {
  Serial.begin(9600);      // Iniciamos la comunicación serie
  pinMode(Trigger, OUTPUT);// Pin Trigger como salida
  pinMode(Echo, INPUT);    // Pin Echo como entrada
  pinMode(Led, OUTPUT);    // Pin LED como salida
  digitalWrite(Trigger, LOW); // Inicializamos el Trigger en LOW
}

void loop() {
  long t; // Tiempo que demora en llegar el eco
  long d; // Distancia en centímetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);   // Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); // Obtenemos el ancho del pulso
  d = t / 59;              // Convertimos el tiempo a distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.println(" cm");

  if (d <= 10) {
    digitalWrite(Led, HIGH);  // Enciende el LED si la distancia es menor o igual a 10 cm
  } else {
    digitalWrite(Led, LOW);   // Apaga el LED si la distancia es mayor a 10 cm
  }

  delay(100);  // Pequeña pausa de 100ms
}
