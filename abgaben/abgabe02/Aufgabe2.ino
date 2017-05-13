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
bool bewegung = true;
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
    digitalWrite(ledNaR,HIGH)
}

void loop(){
    if(digitalRead(sensor==HIGH) || bewegung)
        if(millis()-lastswitch>=20000)
            NA();
        else
            bewegung = true;
}

void Na(){
    lastbewegung = millis();
    Hagtr();
    Nartg();
    while(lastswitch-millis()<5000){
        if(digitalRead(sensor==HIGH))
            bewegung=true;
    }
    Nagtr();
    Hartg();

}

void Hartg(){
    digitalWrite(ledHaGe,HIGH);
    lastswitch = millis()
    while(millis()-lastswitch<1000){
        if(digitalRead(sensor==HIGH))
            bewegung=true;
    }
    digitalWrite(ledHaGe,LOW);
    digitalWrite(ledHaR,LOW);
    digitalWrite(ledHaGr,HIGH);
    lastswitch = millis();
    bewegung = false;
}

void Hagtr(){
    digitalWrite(ledHaGr,LOW);
    digitalWrite(ledHaGe,HIGH);
    lastswitch = millis()
    while(millis()-lastswitch<1000){
        if(digitalRead(sensor==HIGH))
            bewegung=true;
    }
    digitalWrite(ledHaGe,LOW);
    digitalWrite(ledHaR,HIGH);
    lastswitch = millis();
}
void Nartg(){
    digitalWrite(ledNaGe,HIGH);
    lastswitch = millis()
    while(millis()-lastswitch<1000){
        if(digitalRead(sensor==HIGH))
            bewegung=true;
    }
    digitalWrite(ledNaGe,LOW);
    digitalWrite(ledNaR,LOW);
    digitalWrite(ledNaGr,HIGH);
    lastswitch = millis();
}

void Nagtr(){
    digitalWrite(ledNaGr,LOW);
    digitalWrite(ledNaGe,HIGH);
    lastswitch = millis()
    while(millis()-lastswitch<1000){
        if(digitalRead(sensor==HIGH))
            bewegung=true;
    }
    digitalWrite(ledNaGe,LOW);
    digitalWrite(ledNaR,HIGH);
    lastswitch = millis();
}