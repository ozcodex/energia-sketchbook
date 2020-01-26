
int AX = A1;
int AY = A2;
int SW = 4;
int LED = 13;

int deadZone = 10;

void setup() {
  pinMode( SW, INPUT_PULLUP );
  Serial.begin(9600);
  deadZone = deadZone*1024/100;
}
void loop() {
  int x=analogRead(AX);
  int y=analogRead(AY);
  int s=!digitalRead(SW);
  
  if ( s )
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
  
  if (x > (512 + deadZone)) Serial.println("arriba");
  if (x < (512 - deadZone)) Serial.println("abajo");
  if (y > (512 + deadZone)) Serial.println("derecha");
  if (y < (512 - deadZone)) Serial.println("izquierda");
  if (s) Serial.println("adentro");
  delay(60);
}
