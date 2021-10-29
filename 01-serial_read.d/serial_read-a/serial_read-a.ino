// program



void setup() {
#define TIMESTAMP "Sun Dec 27 22:44:24 UTC 2020"
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

int getch() {

    Serial.println("  Enter any character: ");

    while(!Serial.available());
    char p = Serial.read();
    Serial.print(p, HEX); Serial.print(" ");
    if( p != '\012') { Serial.print(p); }
    if(Serial.available() >0) { p = Serial.read(); }
    // if( p != '\012') { Serial.println("ERROR"); }
    if( p == '\012') { return -1; }
    // int s = Serial.available();
    // if (s > 1) { Serial.println("ERROR TWO"); }
    return -999; // big kludge
}

void loop() {
    int k;

    Serial.println("Entering loop(); now.");

    while(getch());

    Serial.println("Code never reaches here.");

    while(-1);
    Serial.println("TRAP");
    delay(3000);
}
