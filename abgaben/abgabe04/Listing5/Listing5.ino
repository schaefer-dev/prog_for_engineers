int leds [] = {7, 8, 9};

// Gewuenschtes Verhalten : Pins 7-9 werden als OUTPUT initialisiert
// Zu initialisierende Pins sind in einem Array abgelegt

void setup () {
  int i = 0;
  while (i < 3) {
    pinMode ( leds [i++] , OUTPUT );
  }
}

void loop() {
}
