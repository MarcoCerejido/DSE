#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("GANADOR DE");
  lcd.setCursor(0, 1);
  lcd.print("LA CARRERA");
  delay(5000);
}

void loop() {
  String nombre = "V. Cortinas";
  String nacionalidad = "ESP";
  String tiempo = "1:09:38";
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(nombre);
  lcd.setCursor(13, 0);
  lcd.print(nacionalidad);
  lcd.setCursor(0, 1);
  lcd.print("TIEMPO:");
  lcd.setCursor(9, 1);
  lcd.print(tiempo);
  delay(5000);
}

/*#include <LiquidCrystal.h>

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(16, 2);
  // Escribimos el Mensaje en el LCD.
  lcd.print("Hola Mundo");
}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.setCursor(0, 1);
   // Escribimos el número de segundos trascurridos
  lcd.print(millis()/1000);
  lcd.print(" Segundos");
  delay(100);
}*/
