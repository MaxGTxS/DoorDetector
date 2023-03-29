#include <LiquidCrystal.h> //Dołączenie bilbioteki
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Informacja o podłączeniu nowego wyświetlacza
#define trigPin 12
#define echoPin 11
#define KONTAKTRON 8

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  pinMode(A5, OUTPUT); //Wyjście dla buzzera
  pinMode(A1, OUTPUT); // wyjscie dla diody kolor zolty
  pinMode(KONTAKTRON, INPUT_PULLUP); //Kontaktron jako wejście
  pinMode(A3, OUTPUT);  //podpiecie diody jako wyjscie kolor zielony
  pinMode(A4, OUTPUT); // podpiecie jako wyjscie diody kolor czerwony
  lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print("Odleglosc w cm:"); //Wyświetlenie tekstu
}
 
void loop() { 
  lcd.setCursor(0, 1); //Ustawienie kursora
  lcd.print("      "); //Wyświetlenie tekstu
  Serial.print(zmierzOdleglosc()); //wyswietlanie na monitorze wielkosci mierzonej
  Serial.println(" cm"); // dospisywanie do wartosci cm
  
   delay(500);//opoznienie 0.5s
  zakres(50); //Włącz alarm, jeśli w odległości 50cm jest przekroczona 
   delay(100);//opoznienie 0.1s
   if  (digitalRead(KONTAKTRON) == HIGH) //Jeśli czujnik zwarty
    { 
      digitalWrite(A3, HIGH); //Stan OK - dioda zielona
     
    }                 
    else
    {
      digitalWrite(A3, LOW); // dioda wylaczona
     
    }
    if  ((digitalRead(A1) == HIGH) && (digitalRead(A3) == HIGH)) // jesli swieci sie dioda zielona i pomaranczowa
  {
    digitalWrite(A4, HIGH); // zapala sie czerwona dioda
     // buzzer zaczyna wydawac dzwieki
    tone(A5, 4000);
    delay(500);
    noTone(A5);
    
  }
  else
  {
    digitalWrite(A4, LOW); // gasnie czerwona dioda
    digitalWrite(A5, LOW); // buzzer konczy wydawac dzwieki
  }
} 
 
int zmierzOdleglosc() { // funkca odpowiadajaca za zmierzenie odleglosci
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58; // obliczenie czasu jaki pokonuje i zamienienie go na centymetry przez podzielenie
  lcd.setCursor(0,1); //Ustawienie kursora
  lcd.print(dystans); //Wyświetlenie tekstu
  return dystans;
}
 
void zakres(int a) { // funcka czytajaca czy odleglosc na czujnika zostala przekroczona
  int jakDaleko = zmierzOdleglosc();
  if (jakDaleko > a) {
      
      digitalWrite(A1, HIGH); //wlaczamy diode
  } else {
     
      digitalWrite(A1, LOW); //wylaczamy diode
  }
}
