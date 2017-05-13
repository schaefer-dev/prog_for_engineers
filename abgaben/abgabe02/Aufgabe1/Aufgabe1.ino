int ledHaR = 22;
int ledHaGe = 24;
int ledHaGr = 26;
int ms = 1000;

void setup() {
    pinMode(ledHaGr, OUTPUT);
    pinMode(ledHaGe, OUTPUT);
    pinMode(ledHaR, OUTPUT);
    digitalWrite(ledHaR,HIGH);
}

void loop(){
    delay(1 * ms);
    HauptAmpelGelbRot();
    delay(1 * ms);
    HauptAmpelGruen();
    delay(1 * ms);
    HauptAmpelGelb();
    delay(1 * ms);
    HauptAmpelRot();
}


void HauptAmpelGruen(){
    digitalWrite(ledHaGr,HIGH);
    digitalWrite(ledHaGe,LOW);
    digitalWrite(ledHaR,LOW);
}

void HauptAmpelGelb(){
    digitalWrite(ledHaGr,LOW);
    digitalWrite(ledHaGe,HIGH);
    digitalWrite(ledHaR,LOW);
}

void HauptAmpelRot(){
    digitalWrite(ledHaGr,LOW);
    digitalWrite(ledHaGe,LOW);
    digitalWrite(ledHaR,HIGH);
}

void HauptAmpelGelbRot(){
    digitalWrite(ledHaGr,LOW);
    digitalWrite(ledHaGe,HIGH);
    digitalWrite(ledHaR,HIGH);
}
