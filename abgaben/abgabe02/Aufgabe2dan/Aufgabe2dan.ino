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
        if(millis()-lastswitch>=5000)
            NebenAmpelTrigger();
        else
            bewegung = true;
}

void NebenAmpelTrigger(){
    lastswitch = millis();
    HauptAmpelGelb();
    delay(1000);
    HauptAmpelRot();
    delay(1000);
    NebenAmpelGelbRot();
    delay(1000);
    NebenAmpelGruen();
    delay(5000);
    NebenAmpelGelb();
    waitAndCheck();
    NebenAmpelRot();
    waitAndCheck();
    HauptAmpelGelbRot();
    waitAndCheck();
    HauptAmpelGruen();
    waitAndCheck();
 
}

void waitAndCheck(){
  lastswitch = millis();
  while(millis()-lastswitch<1000){
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
