iint led = 13;

void setup () {
    pinMode(led ,OUTPUT);
}

void loop () {
    digitalWrite(led , HIGH);
    delay (2500);
    digitalWrite(led , LOW);
    delay (2500);
}
