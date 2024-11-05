int TRIG = 2;
int ECO = 4;
int DURACION;
int DISTANCIA;

#include <Stepper.h>
Stepper motor2(2048, 13, 14, 12, 27);
Stepper motor(2048, 21, 18, 19, 5);

// Declaración de la función adelante
void adelante();
void izq();
void der();

bool giro = false;


void setup() {
  // Inicialización de pines
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  
  // Establecer la velocidad de los motores
  motor2.setSpeed(10);
  motor.setSpeed(10);
  
  // Inicializar la comunicación serie
  Serial.begin(9600);
}

void loop() {
  // Medir la distancia usando el sensor ultrasónico
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);
  
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;  // Convertir tiempo en distancia
  Serial.println(DISTANCIA);

  // Si la distancia es mayor o igual a 10 cm, llamar a la función adelante
  if (DISTANCIA >= 10) {
    adelante();
  } else if (DISTANCIA <= 10 && giro == false){
    izq();
  } else if (DISTANCIA <= 10 && giro == true){
    der();
  }
}

// Función que mueve ambos motores 100 pasos hacia adelante
void adelante() {
  motor.step(4);
  motor2.step(-4);
}

void izq() {
  motor.step(512);
  motor2.step(0);
  motor.step(1000);
  motor2.step(1000);
  motor.step(512);
  motor2.step(0);
  giro = true;
}

void der() {
  motor.step(0);
  motor2.step(512);
  motor.step(1000);
  motor2.step(1000);
  motor.step(0);
  motor2.step(512);
  giro = false;
}
