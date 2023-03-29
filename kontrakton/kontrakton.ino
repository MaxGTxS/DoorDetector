#define KONTAKTRON 8

void setup() 
{
  pinMode(KONTAKTRON, INPUT_PULLUP); //Kontaktron jako wejście
  pinMode(A3, OUTPUT);  //Ustawienie pinu jako wyjście
 
}
 
void loop() 
{
  if  (digitalRead(KONTAKTRON) == HIGH) //Jeśli czujnik zwarty
    { 
      digitalWrite(A3, HIGH); //Stan OK - dioda zielona
     
    }                 
    else
    {
      digitalWrite(A3, LOW);
     
    }
}