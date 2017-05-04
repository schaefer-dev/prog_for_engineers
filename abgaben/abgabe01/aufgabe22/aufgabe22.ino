int led = 13;  // led to use for output (13 is built-in)

int dit_delay = 500;           // length of a dit in ms
int dah_delay = dit_delay * 3; // length of a dah in ms

// dit() and dat() already include dit_delay
int letter_delay = dah_delay - dit_delay;

// letters already include letter delay
int word_delay   = dit_delay * 7 - letter_delay;

void dit(int LED_id) {
    Serial.print(".");

    // send a dit
    digitalWrite(LED_id, HIGH);
    delay(dit_delay);

    digitalWrite(LED_id, LOW);
    delay(dit_delay);
}

void dah(int LED_id) {
    Serial.print("-");
  
    // send a dah
    digitalWrite(LED_id, HIGH);
    delay(dah_delay);

    digitalWrite(LED_id, LOW);
    delay(dit_delay);
}

void pause_letter() {
   Serial.println("");
   delay(letter_delay);
}

void pause_word() {
   Serial.println("");
   delay(word_delay);
}

void morse_S(int LED_id) {
  dit(LED_id); dit(LED_id); dit(LED_id);
  pause_letter();
}

void morse_O(int LED_id) {
  dah(LED_id); dah(LED_id); dah(LED_id);
  pause_letter();
}

void morse_A(int LED_id){
  dit(LED_id); dah(LED_id); 
  pause_letter();
}

void morse_R(int LED_id){
  dit(LED_id); dah(LED_id); dit(LED_id);
  pause_letter();
}

void morse_L(int LED_id){
  dit(LED_id); dah(LED_id); dit(LED_id); dit(LED_id);
  pause_letter();
}

void morse_N(int LED_id){
  dah(LED_id); dit(LED_id);
  pause_letter();
}

void morse_D(int LED_id){
  dah(LED_id); dit(LED_id); dit(LED_id);
  pause_letter();
}

void morse_U(int LED_id){
  dit(LED_id); dit(LED_id); dah(LED_id);
  pause_letter();
}

void morse_I(int LED_id){
  dit(LED_id); dit(LED_id); 
  pause_letter();
}

void morse_E(int LED_id){
  dit(LED_id);
  pause_letter();
}

void morse_V(int LED_id){
  dit(LED_id); dit(LED_id); dit(LED_id); dah(LED_id);
  pause_letter();
}

void morse_T(int LED_id){
  dah(LED_id);
  pause_letter();
}

void morse_Y(int LED_id){
  dah(LED_id); dit(LED_id); dah(LED_id); dah(LED_id);
  pause_letter();
}

void morse_SOS(int LED_id) {
    morse_S(LED_id); morse_O(LED_id); morse_S(LED_id);
    pause_word();
}

void morse_Saarland(int LED_id) {
    morse_S(LED_id); morse_A(LED_id); morse_A(LED_id); morse_R(LED_id); morse_L(LED_id); 
    morse_A(LED_id); morse_N(LED_id); morse_D(LED_id);
    pause_word();
}

void morse_University(int LED_id) {
    morse_U(LED_id); morse_N(LED_id); morse_I(LED_id); morse_V(LED_id); 
    morse_E(LED_id); morse_R(LED_id); morse_S(LED_id); morse_I(LED_id); 
    morse_T(LED_id); morse_Y(LED_id);
    pause_word();
}

void setup() {
  // put your setup code here, to run once:
  
  // Configure LED as output
  pinMode(led, OUTPUT);
  
  // Use serial port as output
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  morse_Saarland(13);  
  morse_University(13);
}
