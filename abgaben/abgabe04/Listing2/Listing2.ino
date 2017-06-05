int taster = 2;
int led = 3;

void setup() {
  pinMode(taster,INPUT);
  pinMode(led,OUTPUT);

}
// Gewuenschtes Verhalten : LED leuchtet , wenn Taster gedrueckt
void loop () {
if ( taster == HIGH ) {
led = HIGH ;
} else {
led = LOW;
}
}
