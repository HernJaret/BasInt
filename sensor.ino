
int DISTANCIA = 0;
int pinLed=D0;
int pinEco=D6;
int pinGatillo=D5;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  //Iniciamos el pin del emisor de reuido en salida
  pinMode(triggerPin, OUTPUT);
  //Apagamos el emisor de sonido
  digitalWrite(triggerPin, LOW);
  //Retrasamos la emision de sonido por 2 milesismas de segundo
  delayMicroseconds(2);
  // Comenzamos  a emitir sonido
  digitalWrite(triggerPin, HIGH);
  //Retrasamos la emision de sonido por 2 milesismas de segundo
  delayMicroseconds(10);
  //Apagamos el emisor de sonido
  digitalWrite(triggerPin, LOW);
  //Comenzamos a escuchar el sonido
  pinMode(echoPin, INPUT);
  // Calculamos el tiempo que tardo en regresar el sonido
  return pulseIn(echoPin, HIGH);
}

void setup() {oid setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
  Serial.begin(115200);
  //Configuramos el pin del led como salida
  pinMode(pinLed, OUTPUT);
}

void loop() {
  //Calculamos la distancia en cm
  DISTANCIA = 0.01723 * readUltrasonicDistance(pinGatillo, pinEco);
  //Mostramos la disstancia
  Serial.println(DISTANCIA);
  //Si la distancia es menor a 20 encendemos el led
  if (DISTANCIA < 10) {
    digitalWrite(pinLed, HIGH);
  }
  //Si la distancia es mayor a 20 apagamos el led
  else {
    digitalWrite(pinLed, LOW);
  }
  delay(10);
}
