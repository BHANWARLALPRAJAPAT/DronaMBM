#define mA 2
#define mB 3
void setup() {
  pinMode(mA, OUTPUT);
  pinMode(mB, OUTPUT);
}

void loop() {

  digitalWrite(mA, HIGH);
  digitalWrite(mB, LOW);
  delay(2000);

  digitalWrite(mA, LOW);
  digitalWrite(mB, LOW);
  delay(2000);

  digitalWrite(mA, LOW);
  digitalWrite(mB, HIGH);
  delay(2000);
}
