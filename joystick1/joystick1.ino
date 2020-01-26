
int AX = A1;
int AY = A2;
int SW = 4;
int LED = 12;

void setup() {
  pinMode( SW, INPUT_PULLUP );
  Serial.begin(9600);
}
void loop() {
  Serial.print("status: ");
  Serial.print(analogRead(AX)*0.09765625);
  Serial.print("%, ");
  Serial.print(analogRead(AY)*0.09765625);
  Serial.print("%, ");
  Serial.print(!digitalRead(SW));
  Serial.print("\n");
  delay(60);
}
