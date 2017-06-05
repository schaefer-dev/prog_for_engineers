int taster = 2;
int led = 3;
int tasterGedrueckt = 0;
int zaehler = 0 ;
 // Gewuenschtes Verhalten : LED leuchtet , wenn Taster
 // zwischen einschl . 6x und einschl . 9x gedrueckt

 void setup (){
   pinMode(taster, INPUT);
   pinMode(led, OUTPUT);
 }
 
 
 void loop () {
   tasterGedrueckt = digitalRead(taster);if 
   (tasterGedrueckt = 1) { zaehler ++ ;
 } 
 if (5 < zaehler < 10) {
   digitalWrite(led , HIGH);
 } else {
   digitalWrite(led , LOW);
}
}
