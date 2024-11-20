int TRIG = 2;
int ECO = 4;
int DURACION;
int DISTANCIA;

int output1 = 5;
int output2 = 18;


void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  
  if (DISTANCIA > 10)
  {
    pinWrite(output1, HIGH);
    pinWrite(output2, LOW);
    
  } else{
    pinWrite(output1, LOW;
    pinWrite(output2, LOW);
  }
  
}
