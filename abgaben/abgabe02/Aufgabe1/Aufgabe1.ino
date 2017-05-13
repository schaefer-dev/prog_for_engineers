int ledHaGr = 22;
int ledHaGe = 24;
int ledHaR = 26;
int ms = 1000;

void setup() {
    pinMode(ledHaGr, OUTPUT);
    pinMode(ledHaGe, OUTPUT);
    pinMode(ledHaR, OUTPUT);
    digitalWrite(ledHaR,HIGH);
}

void loop(){
    delay(ms);
    rtg();
    delay(ms);
    gtr();
}

void rtg(){
    digitalWrite(ledHaGe,HIGH);
    delay(ms);
    digitalWrite(ledHaGe,LOW);
    digitalWrite(ledHaR,LOW);
    digitalWrite(ledHaGr,HIGH);
}

void gtr(){
    digitalWrite(ledHaGr,LOW);
    digitalWrite(ledHaGe,HIGH);
    delay(ms);
    digitalWrite(ledHaGe,LOW);
    digitalWrite(ledHaR,HIGH);
}