void setup() {
  pinMode(A5, OUTPUT); //Konfiguracja A5 jako wyjście  
  pinMode(A3,OUTPUT);
  pinMode(A1, OUTPUT);
}
 
void loop() {
  digitalWrite(A5, LOW); //Cykliczna zmiana stanu wyjścia
  digitalWrite(A3, LOW);
  digitalWrite(A1, HIGH);
  delay(1000);
  digitalWrite(A5, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A1, LOW);
  delay(1000);
}
