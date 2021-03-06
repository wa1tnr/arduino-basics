void setup() {
#define TIMESTAMP "Sun Dec 27 22:41:31 UTC 2020"
  char p;
  int k;
  Serial.begin(9600);
  while(!Serial); delay(333);
  Serial.println("online.");
  Serial.println("Press ENTER now.");
  while(!Serial.available());
  char t = Serial.peek();
  Serial.println(t, HEX);
  p = Serial.read();
  Serial.print("Read character was: ");
  Serial.println(p, HEX);
  Serial.println(" ");
  Serial.println(TIMESTAMP);
  Serial.println(" ");

  Serial.println("Regular program entry point.");
  Serial.println("Type any character followed by ENTER, now: ");
  while(!Serial.available());
  p = Serial.read();
  Serial.print(" character typed was: ");
  Serial.print(p, HEX);
  Serial.println(" , in hexadecimal.");
  k = Serial.available();
  Serial.print(" waiting character count is: ");
  Serial.println(k);
  t = '\000' ; t = Serial.peek();
  Serial.print(" waiting character, in hex, is: ");
  Serial.println(t, HEX);
  p = '\000' ; p = Serial.read();
  Serial.print(" just-cleared char, a line-ending, is, in hex: ");
  Serial.println(p, HEX);
}

void loop() {
    Serial.println("Entering loop(); now - NO MORE - END of PROGRAM.");
    while(-1);
    Serial.println("TRAP");
    delay(3000);
}
