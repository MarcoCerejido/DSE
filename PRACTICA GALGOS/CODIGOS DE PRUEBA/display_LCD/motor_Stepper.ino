#include <Stepper.h>

#define DO 523.25
#define RE 587.33
#define MI 659.26
#define FA 698.46
#define SOL 783.99
#define LA 880
#define SI 987.77
#define RE2 1174.66
#define DO2 1062
#define DoS 554.37
#define RES 622.25
#define FAS 739.99
#define SOLS 830.61
#define FAS2 1479.98
#define a 1000
#define b 500

int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 7;
int empezar = 0;

int pasosPorRevolucion = 2048;
int velocidadMotor = 15;

long numeroAleatorio;

int contadorCaballo0 = 0;
int contadorCaballo1 = 0;
int contadorCaballo2 = 0;

int tiempoDelay = 5000;

Stepper motor(pasosPorRevolucion, 6, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  motor.setSpeed(velocidadMotor);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  
  pinMode(8, OUTPUT);
}

void loop() {
  if (empezar == 0) {
    digitalWrite(LED1, HIGH);
    delay(1000);
  
    digitalWrite(LED2, HIGH);
    delay(1000);
  
    digitalWrite(LED3, HIGH);
    delay(1000);
  
    digitalWrite(LED4, HIGH);
    delay(1000);
  
    digitalWrite(LED5, HIGH);
    delay(1000);
  
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);

    empezar++;
  }
  
  
  
  numeroAleatorio = random(0, 3);
  Serial.println("Numero Aleatorio: " + String(numeroAleatorio));

  if (contadorCaballo0 < 5 || contadorCaballo1 < 5 || contadorCaballo2 < 5) {
    if (numeroAleatorio == 0) {
      Serial.println("Numero Aleatorio que es CERO: " + String(numeroAleatorio));
      Serial.println("¡Se mueve caballo CERO!");
      //motor.step(pasosPorRevolucion);
      contadorCaballo0++;
      Serial.println("Contador: " + String(contadorCaballo0));
      delay(tiempoDelay);
    } else if (numeroAleatorio == 1) {
      Serial.println("Numero Aleatorio que es UNO: " + String(numeroAleatorio));
      Serial.println("¡Se mueve caballo UNO!");
      //motor.step(pasosPorRevolucion);
      contadorCaballo1++;
      Serial.println("Contador: "  + String(contadorCaballo1));
      delay(tiempoDelay);
    } else {
      Serial.println("Numero Aleatorio que es DOS:" + String(numeroAleatorio));
      Serial.println("¡Se mueve caballo DOS!");
      //motor.step(pasosPorRevolucion);
      contadorCaballo2++;
      Serial.println("Contador:"  + String(contadorCaballo2));
      delay(tiempoDelay);
    }
  }

  if (contadorCaballo0 == 5) {
    Serial.println("¡Ha GANADO el caballo CERO!");
    tone(8, SOL , a);
    delay(500);
    noTone(8);
    tone(8, RE , a);
    delay(500);
     noTone(8);
     tone(8, SI , a);
     delay(500);
     noTone(8);
     tone(8, SOL , b);
     delay(500);
     noTone(8);
     tone(8, RE2 , b);
     delay(400);
     noTone(8);
     tone(8, DO2 , b);
     delay(400);
     noTone(8);
     tone(8, SI , b);
     delay(400);
     noTone(8);
     tone(8, LA , b);
     delay(400);
     noTone(8);
     tone(8, SOL , b);
     delay(400);
     noTone(8);
     tone(8, SOL , b);
     delay(400);
     noTone(8);
     tone(8, FAS , b);
     delay(400);
     noTone(8);
     tone(8, MI , b);
     delay(400);
     noTone(8);
     tone(8, RE , b);
     delay(400);
     noTone(8);
     tone(8, SOL , a);
     delay(500);
     noTone(8);
     tone(8, LA , a);
     delay(500);
     noTone(8);
     tone(8, SI , 1500);
     delay(1000);
     noTone(8);
     tone(8, RE2 , b);
     delay(400);
     tone(8, DO2 , b);
     delay(400);
     tone(8, SI , b);
     delay(400);
     tone(8, LA , b);
     delay(400);
     tone(8, SOL , b);
     delay(400);
     tone(8, RE2 , 2000);
     delay(1000);
     //--------------------- SEGUNDA PARTE 
     tone(8, RE2 , a);
     delay(500);
     tone(8, SI , 250);
     delay(500);
     tone(8, RE2 , 250);
     delay(400);
     tone(8, DO2 , a);
     delay(400);
     tone(8, LA , 250);
     delay(500);
     tone(8, DO2 , 250);
     delay(400);
     tone(8, SI , a);
     delay(500);
     tone(8, SOL , 250);
     delay(400);
     tone(8, SI , 250);
     delay(400);
     tone(8, LA , b);
     delay(400);
     tone(8, RE , b);
     delay(400);
     tone(8, MI , b);
     delay(400);
     tone(8, FAS , b);
     delay(400);
     tone(8, SOL , a);
     delay(500);
     tone(8, LA , a);
     delay(500);
     tone(8, SI , 250);
     delay(500);
     tone(8, DO2 , 250);
     delay(400);
     tone(8, RE2 , b);
     delay(400);
     tone(8, DO2 , b);
     delay(400);
     tone(8, SI , a);
     delay(500);
     tone(8, LA , a);
     delay(500);
     tone(8, SOL , 2000);
     delay(1000);
     delay(1000000000);
  } 
  
  if (contadorCaballo1 == 5) {
    Serial.println("¡Ha GANADO el caballo UNO!");
    tone(8, SOL , a);
   delay(500);
   noTone(8);
   tone(8, RE , a);
   delay(500);
   noTone(8);
   tone(8, SI , a);
   delay(500);
   noTone(8);
   tone(8, SOL , b);
   delay(500);
   noTone(8);
   tone(8, RE2 , b);
   delay(400);
   noTone(8);
   tone(8, DO2 , b);
   delay(400);
   noTone(8);
   tone(8, SI , b);
   delay(400);
   noTone(8);
   tone(8, LA , b);
   delay(400);
   noTone(8);
   tone(8, SOL , b);
   delay(400);
   noTone(8);
   tone(8, SOL , b);
   delay(400);
   noTone(8);
   tone(8, FAS , b);
   delay(400);
   noTone(8);
   tone(8, MI , b);
   delay(400);
   noTone(8);
   tone(8, RE , b);
   delay(400);
   noTone(8);
   tone(8, SOL , a);
   delay(500);
   noTone(8);
   tone(8, LA , a);
   delay(500);
   noTone(8);
   tone(8, SI , 1500);
   delay(1000);
   noTone(8);
   tone(8, RE2 , b);
   delay(400);
   tone(8, DO2 , b);
   delay(400);
   tone(8, SI , b);
   delay(400);
   tone(8, LA , b);
   delay(400);
   tone(8, SOL , b);
   delay(400);
   tone(8, RE2 , 2000);
   delay(1000);
   //--------------------- SEGUNDA PARTE 
   tone(8, RE2 , a);
   delay(500);
   tone(8, SI , 250);
   delay(500);
   tone(8, RE2 , 250);
   delay(400);
   tone(8, DO2 , a);
   delay(400);
   tone(8, LA , 250);
   delay(500);
   tone(8, DO2 , 250);
   delay(400);
   tone(8, SI , a);
   delay(500);
   tone(8, SOL , 250);
   delay(400);
   tone(8, SI , 250);
   delay(400);
   tone(8, LA , b);
   delay(400);
   tone(8, RE , b);
   delay(400);
   tone(8, MI , b);
   delay(400);
   tone(8, FAS , b);
   delay(400);
   tone(8, SOL , a);
   delay(500);
   tone(8, LA , a);
   delay(500);
   tone(8, SI , 250);
   delay(500);
   tone(8, DO2 , 250);
   delay(400);
   tone(8, RE2 , b);
   delay(400);
   tone(8, DO2 , b);
   delay(400);
   tone(8, SI , a);
   delay(500);
   tone(8, LA , a);
   delay(500);
   tone(8, SOL , 2000);
   delay(1000);
    delay(1000000000);
  }

  if (contadorCaballo2 == 5) {
    Serial.println("¡Ha GANADO el caballo DOS!");
    tone(8, SOL , a);
   delay(500);
   noTone(8);
   tone(8, RE , a);
   delay(500);
   noTone(8);
   tone(8, SI , a);
   delay(500);
   noTone(8);
   tone(8, SOL , b);
   delay(500);
   noTone(8);
   tone(8, RE2 , b);
   delay(400);
   noTone(8);
   tone(8, DO2 , b);
   delay(400);
   noTone(8);
   tone(8, SI , b);
   delay(400);
   noTone(8);
   tone(8, LA , b);
   delay(400);
   noTone(8);
   tone(8, SOL , b);
   delay(400);
   noTone(8);
   tone(8, SOL , b);
   delay(400);
   noTone(8);
   tone(8, FAS , b);
   delay(400);
   noTone(8);
   tone(8, MI , b);
   delay(400);
   noTone(8);
   tone(8, RE , b);
   delay(400);
   noTone(8);
   tone(8, SOL , a);
   delay(500);
   noTone(8);
   tone(8, LA , a);
   delay(500);
   noTone(8);
   tone(8, SI , 1500);
   delay(1000);
   noTone(8);
   tone(8, RE2 , b);
   delay(400);
   tone(8, DO2 , b);
   delay(400);
   tone(8, SI , b);
   delay(400);
   tone(8, LA , b);
   delay(400);
   tone(8, SOL , b);
   delay(400);
   tone(8, RE2 , 2000);
   delay(1000);
   //--------------------- SEGUNDA PARTE 
   tone(8, RE2 , a);
   delay(500);
   tone(8, SI , 250);
   delay(500);
   tone(8, RE2 , 250);
   delay(400);
   tone(8, DO2 , a);
   delay(400);
   tone(8, LA , 250);
   delay(500);
   tone(8, DO2 , 250);
   delay(400);
   tone(8, SI , a);
   delay(500);
   tone(8, SOL , 250);
   delay(400);
   tone(8, SI , 250);
   delay(400);
   tone(8, LA , b);
   delay(400);
   tone(8, RE , b);
   delay(400);
   tone(8, MI , b);
   delay(400);
   tone(8, FAS , b);
   delay(400);
   tone(8, SOL , a);
   delay(500);
   tone(8, LA , a);
   delay(500);
   tone(8, SI , 250);
   delay(500);
   tone(8, DO2 , 250);
   delay(400);
   tone(8, RE2 , b);
   delay(400);
   tone(8, DO2 , b);
   delay(400);
   tone(8, SI , a);
   delay(500);
   tone(8, LA , a);
   delay(500);
   tone(8, SOL , 2000);
   delay(1000);
    delay(100000000000);
  }

  //motor.step(-pasosPorRevolucion);
}
