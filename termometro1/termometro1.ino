// C++ code
//
void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int lectura, temp;
  //Obtengo la medicion del sensor
  lectura = analogRead(A0);
  Serial.print("Lectura: ");
  Serial.print(lectura);
  //Imprimo la temperatura
  Serial.print(", temperatura: ");
  temp = (lectura * (500.0 / 1023.0))-50.0;//Convierto la mediciondel sensor a temperatura en Cº
  Serial.print(temp);
  Serial.println(",");

}