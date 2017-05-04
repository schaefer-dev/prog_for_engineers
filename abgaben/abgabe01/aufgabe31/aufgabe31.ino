int led_red = 12;
int led_green = 12 + 1;

int counter = 1;

void blink_if_even(int n) {
    if (n % 2 == 0) {// even
        digitalWrite(led_red , HIGH);
        digitalWrite(led_green , LOW);
    }
    if (n % 2 == 1) {// odd
        digitalWrite(led_red , LOW);
        digitalWrite(led_green , HIGH);
    }
}

void setup() {
    pinMode(led_red , OUTPUT);
    pinMode(led_green , OUTPUT);
}

void loop() {
    blink_if_even(counter);
    counter = counter + 1;
    delay (1000);
}
