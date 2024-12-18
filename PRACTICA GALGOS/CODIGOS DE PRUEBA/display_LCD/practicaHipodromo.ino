#include <Stepper.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// NOTAS HIMNO ESPAÑA
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

// NOTAS HIMNO EEUU
int NOTE_B0 = 31;
int NOTE_C1 = 33;
int NOTE_CS1 = 35;
int NOTE_D1 = 37;
int NOTE_DS1 = 39;
int NOTE_E1 = 41;
int NOTE_F1 = 44;
int NOTE_FS1 = 46;
int NOTE_G1 = 49;
int NOTE_GS1 = 52;
int NOTE_A1 = 55;
int NOTE_AS1 = 58;
int NOTE_B1 = 62;
int NOTE_C2 = 65;
int NOTE_CS2 = 69;
int NOTE_D2 = 73;
int NOTE_E2 = 82;
int NOTE_F2 = 87;
int NOTE_FS2 = 93;
int NOTE_G2 = 98;
int NOTE_GS2 = 104;
int NOTE_A2 = 110;
int NOTE_AS2 = 117;
int NOTE_B2 = 123;
int NOTE_C3 = 131;
int NOTE_CS3 = 139;
int NOTE_D3 = 147;
int NOTE_DS3 = 156;
int NOTE_E3 = 165;
int NOTE_F3 = 175;
int NOTE_FS3 = 185;
int NOTE_G3 = 196;
int NOTE_GS3 = 208;
int NOTE_A3 = 220;
int NOTE_AS3 = 233;
int NOTE_B3 = 247;
int NOTE_C4 = 262;
int NOTE_CS4 = 277;
int NOTE_D4 = 294;
int NOTE_DS4 = 311;
int NOTE_E4 = 330;
int NOTE_F4 = 349;
int NOTE_FS4 = 370;
int NOTE_G4 = 392;
int NOTE_GS4 = 415;
int NOTE_A4 = 440;
int NOTE_AS4 = 466;
int NOTE_B4 = 494;
int NOTE_C5 = 523;
int NOTE_CS5 = 554;
int NOTE_D5 = 587;
int NOTE_DS5 = 622;
int NOTE_E5 = 659;
int NOTE_F5 = 698;
int NOTE_FS5 = 740;
int NOTE_G5 = 784;
int NOTE_GS5 = 831;
int NOTE_A5 = 880;
int NOTE_AS5 = 932;
int NOTE_B5 = 988;
int NOTE_C6 = 1047;
int NOTE_CS6 = 1109;
int NOTE_D6 = 1175;
int NOTE_DS6 = 1245;
int NOTE_E6 = 1319;
int NOTE_F6 = 1397;
int NOTE_FS6 = 1480;
int NOTE_G6 = 1568;
int NOTE_GS6 = 1661;
int NOTE_A6 = 1760;
int NOTE_AS6 = 1865;
int NOTE_B6 = 1976;
int NOTE_C7 = 2093;
int NOTE_CS7 = 2217;
int NOTE_D7 = 2349;
int NOTE_DS7 = 2489;
int NOTE_E7 = 2637;
int NOTE_F7 = 2794;
int NOTE_FS7 = 2960;
int NOTE_G7 = 3136;
int NOTE_GS7 = 3322;
int NOTE_A7 = 3520;
int NOTE_AS7 = 3729;
int NOTE_B7 = 3951;
int NOTE_C8 = 4186;
int NOTE_CS8 = 4435;
int NOTE_D8 = 4699;
int NOTE_DS8 = 4978;

int tempo = 500;

// NOTAS HIMNO INGLATERRA
const int a4 = 440;
const int b4 = 493.88;
const int cs5 = 570;
const int d5 = 587.33;
const int e5 = 659.25;
const int fs5 = 740;
const int g5 = 784;
const int gs5 = 830.61;
const int a5 = 885;
const int as5 = 920;
const int b5 = 987.77;
const int c6 = 1046.5;
const int cs6 = 1107.73;
const int d6 = 1174.66;
const int e6 = 1318.51;
const int f6 = 1396.91;
const int fs6 = 1479.98;
const int gs6 = 1661.22;
const int as6 = 1864.66;
const int notebreak = 50;

// DECLARACIÓN DE PINES Y VARIABLES
int buzzer = 53; 

int BOTON_INICIO = A0;
int botonInicioNuevo;
int botonInicioAntiguo = 1;

int BOTON_RESET = A1;
int botonResetNuevo;
int botonResetAntiguo = 1;

int contadorBoton = 0;

int LED1 = 22;
int LED2 = 23;
int LED3 = 24;
int LED4 = 25;
int LED5 = 26;
int empezar = 0;

int pasosPorRevolucion1 = 2048;
int velocidadMotor1 = 15;

int pasosPorRevolucion2 = 2048;
int velocidadMotor2 = 15;

int pasosPorRevolucion3 = 2048;
int velocidadMotor3 = 15;

long numeroAleatorio;

int contadorCaballo1 = 0;
int contadorCaballo2 = 0;
int contadorCaballo3 = 0;

int tiempoDelay = 5000;

Stepper motor1(pasosPorRevolucion1, 10, 12, 11, 13);
Stepper motor2(pasosPorRevolucion2, 6, 8, 7, 9);
Stepper motor3(pasosPorRevolucion3, 2, 4, 3, 5);

int motor1_IN1 = 13;
int motor1_IN2 = 12;
int motor1_IN3 = 11;
int motor1_IN4 = 10;

int motor2_IN1 = 9;
int motor2_IN2 = 8;
int motor2_IN3 = 7;
int motor2_IN4 = 6;

int motor3_IN1 = 5;
int motor3_IN2 = 4;
int motor3_IN3 = 3;
int motor3_IN4 = 2;

LiquidCrystal lcd(35, 34, 36, 37, 38, 39);

Servo servoMotor1;
Servo servoMotor2;
Servo servoMotor3;

// INICIALIZAMOS LOS COMPONENTES
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  motor1.setSpeed(velocidadMotor1);
  motor2.setSpeed(velocidadMotor2);
  motor3.setSpeed(velocidadMotor3);

  pinMode(BOTON_INICIO, INPUT);
  pinMode(BOTON_RESET, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  pinMode(buzzer, OUTPUT); 

  servoMotor1.attach(46);
  servoMotor2.attach(47);
  servoMotor3.attach(49);

  servoMotor1.write(0);
  servoMotor2.write(0);
  servoMotor3.write(0);
}

void loop() {
  // Calcular el tiempo de la carrera
  unsigned long tiempoTotal = millis();
  unsigned long segundos = tiempoTotal / 1000;
  unsigned long minutos = segundos / 60;

  segundos = segundos % 60;
  minutos = minutos % 60;
  
  // Pulsando el boton se inicializa la carrera
  botonInicioNuevo = digitalRead(BOTON_INICIO);
  delay(100);

  // Comprobamos el valor del boton y si se ha pulsado, comienza la carrera
  if ((botonInicioNuevo == 0 && botonInicioAntiguo == 1) || contadorBoton == 1) {
    contadorBoton = 1;

    // Comienza el semaforo
    if (empezar == 0) {
      digitalWrite(LED1, HIGH);
      tone(buzzer, 500);
      delay(500);
      noTone(buzzer);
      delay(500);
    
      digitalWrite(LED2, HIGH);
      tone(buzzer, 500);
      delay(500);
      noTone(buzzer);
      delay(500);
    
      digitalWrite(LED3, HIGH);
      tone(buzzer, 500);
      delay(500);
      noTone(buzzer);
      delay(500);
    
      digitalWrite(LED4, HIGH);
      tone(buzzer, 500);
      delay(500);
      noTone(buzzer);
      delay(500);
    
      digitalWrite(LED5, HIGH);
      tone(buzzer, 600);
      delay(500);
      noTone(buzzer);
      delay(500);
    
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
  
      empezar++;
    }

    // Genera y almacena el numero aleatorio
    numeroAleatorio = random(1, 4);
    Serial.println("Numero Aleatorio: " + String(numeroAleatorio));

    // Comprueba si se ha llegado a la meta con un contador de movimientos
    if (contadorCaballo1 < 5 || contadorCaballo2 < 5 || contadorCaballo3 < 5) {
      // Si sale el UNO de forma aleatoria, se activa el motor 1 y avanza la cinta con el caballo
      if (numeroAleatorio == 1) {
        Serial.println("Numero Aleatorio que es UNO: " + String(numeroAleatorio));
        Serial.println("¡Se mueve caballo UNO!");
        encender(motor1_IN1, motor1_IN2, motor1_IN3, motor1_IN4);
        motor1.step(pasosPorRevolucion1);
        apagar(motor1_IN1, motor1_IN2, motor1_IN3, motor1_IN4);
        contadorCaballo1++;
        Serial.println("Contador: "  + String(contadorCaballo1));
        delay(tiempoDelay);
      } else if (numeroAleatorio == 2) {  // Si sale el DOS de forma aleatoria, se activa el motor 2 y avanza la cinta con el caballo
        Serial.println("Numero Aleatorio que es DOS:" + String(numeroAleatorio));
        Serial.println("¡Se mueve caballo DOS!");
        encender(motor2_IN1, motor2_IN2, motor2_IN3, motor2_IN4);
        motor2.step(pasosPorRevolucion2);
        apagar(motor2_IN1, motor2_IN2, motor2_IN3, motor2_IN4);
        contadorCaballo2++;
        Serial.println("Contador: "  + String(contadorCaballo2));
        delay(tiempoDelay);
      } else {  // Si sale el TRES de forma aleatoria, se activa el motor 3 y avanza la cinta con el caballo
        Serial.println("Numero Aleatorio que es TRES:" + String(numeroAleatorio));
        Serial.println("¡Se mueve caballo TRES!");
        encender(motor3_IN1, motor3_IN2, motor3_IN3, motor3_IN4);
        motor3.step(pasosPorRevolucion3);
        apagar(motor3_IN1, motor3_IN2, motor3_IN3, motor3_IN4);
        contadorCaballo3++;
        Serial.println("Contador: "  + String(contadorCaballo3));
        delay(tiempoDelay);
      }
    }

    // Comprueba si ha ganado y comienza el protocolo de victoria, con el display, la bandera y el himno
    if (contadorCaballo1 == 5) {
      lcd.begin(16, 2);
      lcd.setCursor(0, 0);
      lcd.print("GANADOR DE");
      lcd.setCursor(0, 1);
      lcd.print("LA CARRERA");
      delay(5000);
      
      String nombre = "V. Cortinas";
      String nacionalidad = "ESP";
    
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(nombre);
      lcd.setCursor(13, 0);
      lcd.print(nacionalidad);
      lcd.setCursor(0, 1);
      lcd.print("TIEMPO:");
      lcd.setCursor(9, 1);
      if (minutos < 10) {
        lcd.print("0");
      }
      lcd.print(minutos);
      lcd.print(":");
      if (segundos < 10) {
        lcd.print("0");
      }
      lcd.print(segundos);
      
      Serial.println("¡Ha GANADO el caballo UNO!");
      for (int i = 0; i <= 90; i++) {
        servoMotor1.write(i);
        delay(100);
      }
  
      himnoEspana();
    
      contadorBoton--;
      empezar = 0;
    } 

    // Comprueba si ha ganado y comienza el protocolo de victoria, con el display, la bandera y el himno
    if (contadorCaballo2 == 5) {
      lcd.begin(16, 2);
      lcd.setCursor(0, 0);
      lcd.print("GANADOR DE");
      lcd.setCursor(0, 1);
      lcd.print("LA CARRERA");
      delay(5000);
    
      String nombre = "M. Cerejido";
      String nacionalidad = "USA";
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(nombre);
      lcd.setCursor(13, 0);
      lcd.print(nacionalidad);
      lcd.setCursor(0, 1);
      lcd.print("TIEMPO:");
      lcd.setCursor(9, 1);
      if (minutos < 10) {
        lcd.print("0");
      }
      lcd.print(minutos);
      lcd.print(":");
      if (segundos < 10) {
        lcd.print("0");
      }
      lcd.print(segundos);
          
      Serial.println("¡Ha GANADO el caballo DOS!");
      for (int i = 0; i <= 90; i++) {
        servoMotor2.write(i);
        delay(100);
      }
      
      himnoEEUU();
      
      contadorBoton--;
      empezar = 0;
    }

    // Comprueba si ha ganado y comienza el protocolo de victoria, con el display, la bandera y el himno
    if (contadorCaballo3 == 5) { 
      lcd.begin(16, 2);
      lcd.setCursor(0, 0);
      lcd.print("GANADOR DE");
      lcd.setCursor(0, 1);
      lcd.print("LA CARRERA");
      delay(5000);
    
      String nombre = "J. Haering";
      String nacionalidad = "ENG";
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(nombre);
      lcd.setCursor(13, 0);
      lcd.print(nacionalidad);
      lcd.setCursor(0, 1);
      lcd.print("TIEMPO:");
      lcd.setCursor(9, 1);
      if (minutos < 10) {
        lcd.print("0");
      }
      lcd.print(minutos);
      lcd.print(":");
      if (segundos < 10) {
        lcd.print("0");
      }
      lcd.print(segundos);
         
      Serial.println("¡Ha GANADO el caballo TRES!");
      for (int i = 0; i <= 90; i++) {
        servoMotor3.write(i);
        delay(100);
      }
  
      himnoInglaterra();
      
      contadorBoton--;
      empezar = 0;
    }
  }

  botonInicioAntiguo = botonInicioNuevo;

  // Pulsando el boton se reinician todos los valores y los caballos vuelven a la posicion de salida
  botonResetNuevo = digitalRead(BOTON_RESET);
  delay(100);

   if (botonResetNuevo == 0 && botonResetAntiguo == 1) {
      // Se resetea el motor UNO
      for (int i = 1; i <= contadorCaballo1; i++) {
        encender(motor1_IN1, motor1_IN2, motor1_IN3, motor1_IN4);
        motor1.step(-pasosPorRevolucion1);
        apagar(motor1_IN1, motor1_IN2, motor1_IN3, motor1_IN4);
      }

      // Se resetea el motor DOS
      for (int i = 1; i <= contadorCaballo2; i++) {
        encender(motor2_IN1, motor2_IN2, motor2_IN3, motor2_IN4);
        motor2.step(-pasosPorRevolucion2);
        apagar(motor2_IN1, motor2_IN2, motor2_IN3, motor2_IN4);
      }

      // Se resetea el motor TRES
      for (int i = 1; i <= contadorCaballo3; i++) {
        encender(motor3_IN1, motor3_IN2, motor3_IN3, motor3_IN4);
        motor3.step(-pasosPorRevolucion3);
        apagar(motor3_IN1, motor3_IN2, motor3_IN3, motor3_IN4);
      }

      contadorCaballo1 = 0;
      contadorCaballo2 = 0;
      contadorCaballo3 = 0;
   }

   botonResetAntiguo = botonResetNuevo;
}

// Funcion para ENCENDER el motor stepper cada vez que se utiliza
void encender (int in1, int in2, int in3, int in4) {
  digitalWrite (in1, HIGH);
  digitalWrite (in2, HIGH);
  digitalWrite (in3, HIGH);
  digitalWrite (in4, HIGH);
}

// Funcion para APAGAR el motor stepper cada vez que se deja de utilizar
void apagar (int in1, int in2, int in3, int in4) {
  digitalWrite (in1, LOW);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, LOW);
}

// Funcion para generar las notas del HIMNO DE ESPAÑA
void himnoEspana() {
     Serial.println("¡Ha GANADO el caballo UNO!");
     tone(buzzer, SOL , a);
     delay(500);
     noTone(buzzer);
     tone(buzzer, RE , a);
     delay(500);
     noTone(buzzer);
     tone(buzzer, SI , a);
     delay(500);
     noTone(buzzer);
     tone(buzzer, SOL , b);
     delay(500);
     noTone(buzzer);
     tone(buzzer, RE2 , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, DO2 , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, SI , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, LA , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, SOL , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, SOL , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, FAS , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, MI , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, RE , b);
     delay(400);
     noTone(buzzer);
     tone(buzzer, SOL , a);
     delay(500);
     noTone(buzzer);
     tone(buzzer, LA , a);
     delay(500);
     noTone(buzzer);
     tone(buzzer, SI , 1500);
     delay(1000);
     noTone(buzzer);
     tone(buzzer, RE2 , b);
     delay(400);
     tone(buzzer, DO2 , b);
     delay(400);
     tone(buzzer, SI , b);
     delay(400);
     tone(buzzer, LA , b);
     delay(400);
     tone(buzzer, SOL , b);
     delay(400);
     tone(buzzer, RE2 , 2000);
     delay(1000);
     //--------------------- SEGUNDA PARTE 
     tone(buzzer, RE2 , a);
     delay(500);
     tone(buzzer, SI , 250);
     delay(500);
     tone(buzzer, RE2 , 250);
     delay(400);
     tone(buzzer, DO2 , a);
     delay(400);
     tone(buzzer, LA , 250);
     delay(500);
     tone(buzzer, DO2 , 250);
     delay(400);
     tone(buzzer, SI , a);
     delay(500);
     tone(buzzer, SOL , 250);
     delay(400);
     tone(buzzer, SI , 250);
     delay(400);
     tone(buzzer, LA , b);
     delay(400);
     tone(buzzer, RE , b);
     delay(400);
     tone(buzzer, MI , b);
     delay(400);
     tone(buzzer, FAS , b);
     delay(400);
     tone(buzzer, SOL , a);
     delay(500);
     tone(buzzer, LA , a);
     delay(500);
     tone(buzzer, SI , 250);
     delay(500);
     tone(buzzer, DO2 , 250);
     delay(400);
     tone(buzzer, RE2 , b);
     delay(400);
     tone(buzzer, DO2 , b);
     delay(400);
     tone(buzzer, SI , a);
     delay(500);
     tone(buzzer, LA , a);
     delay(500);
     tone(buzzer, SOL , 2000);
     delay(1000);
}

// Funcion para generar las notas del HIMNO DE EEUU
void himnoEEUU() {
     Serial.println("¡Ha GANADO el caballo DOS!");
     tone(buzzer, NOTE_G5);
     delay(tempo);
     tone(buzzer, NOTE_E5);
     delay(tempo / 3);
     tone(buzzer, NOTE_C5);
     delay(tempo);
     tone(buzzer, NOTE_E5);
     delay(tempo);
     tone(buzzer, NOTE_G5);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo * 2);
     tone(buzzer, NOTE_E6);
     delay(tempo);
     tone(buzzer, NOTE_D6);
     delay(tempo / 3);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_E5);
     delay(tempo);
     tone(buzzer, NOTE_FS5);
     delay(tempo);
     tone(buzzer, NOTE_G5);
     delay(tempo * 2);
     tone(buzzer, NOTE_G5);
     delay(tempo / 3);
     tone(buzzer, NOTE_E6);
     delay(tempo * 1.5);
     tone(buzzer, NOTE_D6);
     delay(tempo / 3);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_B5);
     delay(tempo);
     tone(buzzer, NOTE_A5);
     delay(tempo);
     tone(buzzer, NOTE_B5);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_G5);
     delay(tempo);
     tone(buzzer, NOTE_E5);
     delay(tempo);
     tone(buzzer, NOTE_C5);
     delay(tempo);
     tone(buzzer, NOTE_E6);
     delay(tempo);
     tone(buzzer, NOTE_E6);
     delay(tempo / 3);
     tone(buzzer, NOTE_E6);
     delay(tempo);
     tone(buzzer, NOTE_F6);
     delay(tempo / 3);
     tone(buzzer, NOTE_G6);
     delay(tempo);
     tone(buzzer, NOTE_G6);
     delay(tempo);
     tone(buzzer, NOTE_F6);
     delay(tempo / 2);
     tone(buzzer, NOTE_E6);
     delay(tempo / 2);
     tone(buzzer, NOTE_D6);
     delay(tempo * 2);
     tone(buzzer, NOTE_E6);
     delay(tempo / 3);
     tone(buzzer, NOTE_F6);
     delay(tempo);
     tone(buzzer, NOTE_F6);
     delay(tempo);
     tone(buzzer, NOTE_F6);
     delay(tempo);
     tone(buzzer, NOTE_E6);
     delay(tempo);
     tone(buzzer, NOTE_D6);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_B5);
     delay(tempo);
     tone(buzzer, NOTE_A5);
     delay(tempo);
     tone(buzzer, NOTE_B5);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_G5);
     delay(tempo);
     tone(buzzer, NOTE_E5);
     delay(tempo);
     tone(buzzer, NOTE_C5);
     delay(tempo);
     tone(buzzer, NOTE_G5);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo / 2);
     tone(buzzer, NOTE_B5);
     delay(tempo / 2);
     tone(buzzer, NOTE_A5);
     delay(tempo);
     tone(buzzer, NOTE_A5);
     delay(tempo);
     tone(buzzer, NOTE_A5);
     delay(tempo);
     tone(buzzer,NOTE_D6);
     delay(tempo);
     tone(buzzer, NOTE_F6);
     delay(tempo / 2);
     tone(buzzer,NOTE_E6);
     delay(tempo / 2);
     tone(buzzer,NOTE_D6);
     delay(tempo / 2);
     tone(buzzer, NOTE_C6);
     delay(tempo / 2);
     tone(buzzer, NOTE_C6);
     delay(tempo);
     tone(buzzer, NOTE_B5);
     delay(tempo * 4);
     tone(buzzer, NOTE_G5);
     delay(tempo);
     tone(buzzer, NOTE_G5);
     delay(tempo);
     tone(buzzer, NOTE_C6);
     delay(tempo * 2);
     tone(buzzer, NOTE_D6);
     delay(tempo / 2);
     tone(buzzer, NOTE_E6);
     delay(tempo / 2);
     tone(buzzer, NOTE_F6);
     delay(tempo / 2);
     tone(buzzer, NOTE_G6);
     delay(tempo * 6);
     tone(buzzer, NOTE_C6);
     delay(tempo * 1.5);
     tone(buzzer, NOTE_D6);
     delay(tempo * 1.5);
     tone(buzzer, NOTE_E6);
     delay(tempo * 2);
     tone(buzzer, NOTE_F6);
     delay(tempo);
     tone(buzzer, NOTE_D6);
     delay(tempo * 2.5);
     tone(buzzer, NOTE_C6);
     noTone(buzzer);
}

void playNote(int note, int time){
  tone(buzzer, note, time);
  delay(time + notebreak);
}

// Funcion para generar las notas del HIMNO DE INGLATERRA
void himnoInglaterra() {
  Serial.println("¡Ha GANADO el caballo TRES!");
  const int q = 300; 
  const int c = 600;  
  const int qb = q + notebreak; 
  const int cb = c + notebreak; 
  
  playNote(g5, c);
  playNote(g5, c);
  playNote(a5, c);
  
  playNote(fs5, c + q);
  playNote(g5, q);
  playNote(a5, c);
  
  playNote(b5, c);
  playNote(b5, c);
  playNote(c6, c);

  playNote(b5, c + q);
  playNote(a5, q);
  playNote(g5, c);
  
  playNote(a5, c);
  playNote(g5, c);
  playNote(fs5, c);
  
  playNote(g5, c);
  playNote(g5, q);
  playNote(a5, q);
  playNote(b5, q);
  playNote(c6, q);
  
  playNote(d6, c);
  playNote(d6, c);
  playNote(d6, c);

  playNote(d6, c + q);
  playNote(c6, q);
  playNote(b5, c);

  playNote(c6, c);
  playNote(c6, c);
  playNote(c6, c);

  playNote(c6, c + q);
  playNote(b5, q);
  playNote(a5, c);
  
  playNote(b5, c);
  playNote(c6, q);
  playNote(b5, q);
  playNote(a5, q);
  playNote(g5, q);

  playNote(b5, c + q);
  playNote(c6, q);
  playNote(d6, c);
  
  playNote(e6, q);
  playNote(c6, q);
  playNote(b5, c);
  playNote(a5, c);
  
  playNote(g5, (c * 3));
}
