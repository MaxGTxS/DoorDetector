void setup() {
  pinMode(A4, OUTPUT); //czerwona
  pinMode(A3,OUTPUT); //zolta
  pinMode(A1, OUTPUT); //zielona

}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(A1, HIGH);
  digitalWrite(A3, HIGH);
 
  
  delay(1000);
  if  ((digitalRead(A1) == HIGH) && (digitalRead(A3) == HIGH))
  {
    digitalWrite(A4, HIGH);
  }
  else
  {
    digitalWrite(A4, LOW);
  }
    
  
delay(1000);
   digitalWrite(A1, LOW); //Cykliczna zmiana stanu wyjścia
  digitalWrite(A3, LOW);
  delay(1000);
  if  ((digitalRead(A1) == HIGH) && (digitalRead(A3) == HIGH))
  {
    digitalWrite(A4, HIGH);
  }
  else
  {
    digitalWrite(A4, LOW);
  }
  delay(1000);
}

