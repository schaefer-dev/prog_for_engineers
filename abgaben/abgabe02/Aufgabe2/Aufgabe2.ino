int ledHaR = 22;
int ledHaGe = 24;
int ledHaGr = 26;
int ledNaR = 28;
int ledNaGe = 30;
int ledNaGr = 32;
int sensor = 40;
int ms = 1000;
long lastswitch = 0;
long lastNa = 0;
long lastbewegung = 0;
bool bewegung = false;
int phase = 1;


void setup() {
    pinMode(ledHaGr, OUTPUT);
    pinMode(ledHaGe, OUTPUT);
    pinMode(ledHaR, OUTPUT);
    pinMode(ledNaGr, OUTPUT);
    pinMode(ledNaGe, OUTPUT);
    pinMode(ledNaR, OUTPUT);
    pinMode(sensor,INPUT);
    digitalWrite(ledHaGr,HIGH);
    digitalWrite(ledNaR,HIGH);
}

void loop(){
    if(digitalRead(sensor)==HIGH || bewegung)
        if(millis() - lastswitch >= (20 * ms))
            NebenAmpelTrigger();
        else
            bewegung = true;
}

void NebenAmpelTrigger(){
    bewegung = false;
    lastswitch = millis();
    HauptAmpelGelb();
    // using delay until the Nebenampel is Yellow, because registering a person now does not make sense, because it is getting green already
    delay(1 * ms);
    HauptAmpelRot();
    delay(1 * ms);
    NebenAmpelGelbRot();
    delay(1 * ms);
    NebenAmpelGruen();
    delay(5 * ms);
    NebenAmpelGelb();
    waitAndCheck(1);
    NebenAmpelRot();
    waitAndCheck(1);
    HauptAmpelGelbRot();
    waitAndCheck(1);
    HauptAmpelGruen();
    waitAndCheck(1);
 
}

void waitAndCheck(int x){
  lastswitch = millis();
  while(millis()-lastswitch < (x * ms)){
        if(digitalRead(sensor)==HIGH)
            bewegung=true;
    }
}

void NebenAmpelGruen(){
    digitalWrite(ledNaGr,HIGH);
    digitalWrite(ledNaGe,LOW);
    digitalWrite(ledNaR,LOW);
}

void NebenAmpelGelb(){
    digitalWrite(ledNaGr,LOW);
    digitalWrite(ledNaGe,HIGH);
    digitalWrite(ledNaR,LOW);
}

void NebenAmpelRot(){
    digitalWrite(ledNaGr,LOW);
    digitalWrite(ledNaGe,LOW);
    digitalWrite(ledNaR,HIGH);
}

void NebenAmpelGelbRot(){
    digitalWrite(ledNaGr,LOW);
    digitalWrite(ledNaGe,HIGH);
    digitalWrite(ledNaR,HIGH);
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
