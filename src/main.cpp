#include <Arduino.h>

int LED1 = 12; //Definimos led1 como 12
int LED2 = 11;
int LED3 = 10;
int PUL = 9; //Definimos el pulsador en el pin 9 fisico
int dpul = 0; //Definimos valor inicial al pulsador
int numerador = 0; //Definimos una variable de contador
int valorpul = 0; //Difinemos una variable de posición del pulsador

int foxyelmejor = 0;

void setup() {
  pinMode(LED1, OUTPUT); //Definimos el led1 como salida
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(PUL, INPUT); //Definimos el pulsador como entrada
  Serial.begin(9600); //Definimos los badaudios de transmisión con el PC

}

void parpadeoled1(){
  digitalWrite(LED1, HIGH); //El led1 se enciende
  if(digitalRead(PUL)==HIGH){
    valorpul++;
    Serial.println(valorpul);
  }
  delay(500); //Espera de medio segundo
  digitalWrite(LED1, LOW); //El led1 se apaga
  if(digitalRead(PUL)==HIGH){
    valorpul++;
    Serial.println(valorpul);
  }
  delay(500);
  numerador++; //Aumentamos numerador a una unidad
  Serial.println("caso1"); //mandamos mensaje predeterminado
  Serial.println(numerador); //mandamos el dato, que sera el numero del numerador
}

void parpadeoled2(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  if(digitalRead(PUL)==HIGH){
    valorpul++;
    Serial.println(valorpul);
  }
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  if(digitalRead(PUL)==HIGH){
    valorpul++;
    Serial.println(valorpul);
  }
  delay(500);
  numerador++;
  Serial.println("caso2");
  Serial.println(numerador);
}

void parpadeoled3(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  if(digitalRead(PUL)==HIGH){
    valorpul++;
    Serial.println(valorpul);
  }
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  if(digitalRead(PUL)==HIGH){
    valorpul++;
    Serial.println(valorpul);
  }
  delay(500);
  numerador++;
  Serial.println("caso3");
  Serial.println(numerador);
}

void estatico(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
}

void apagado(){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW); 
}

void loop() {

//hacemos un registro del estado del pulsador y lo declaramos en dpul
  if(digitalRead(PUL)==HIGH){ //Si el dato del pulsador es alto o pulsador, aumentamos 1 al valor del pulso
    valorpul++;
    Serial.println(valorpul); // Esto lo imprimimos en el serial para tener noción de lo sucedido
    delay(1000); //Incorporamos un retraso de 1 segundo para prevenir los rebotes
  }

  if(numerador>=0 && numerador<=3 && valorpul == 0){ //Si el valor de numerador esta entre 0 y 3 y el pulsador en la configuración 0, hacemos llamada del parpadeoled1
    parpadeoled1();
  }

  if(numerador>=4 && numerador<=7 && valorpul == 0){
    parpadeoled2();
  }

  if(numerador>=8 && numerador<=11 && valorpul == 0){
    parpadeoled3();
  }

  if(numerador >= 12 && valorpul == 0){ //Si el valor de numerador es igual o mayor a 12 y el pulsador en la configuración 0, se resetea el numerador.
    numerador = 0;
  }

  if(valorpul == 1){ //Si el valor de valorpul es de 1, se hace llamada a la configuración estatico
    estatico();
  }

  if(valorpul == 2){
    apagado();
  }

  if(valorpul == 3){ //Si el valor de valorpul llega a 3, se resetea a 0 para volver a la configuración inicial.
    valorpul=0;
  }

}