int speakerID = 3;
int ledIDs[] = {8, 9, 10, 11};
int buttonIDs[] = {4, 5, 6, 7};
int frequencies[] = {220, 440, 660, 880};
int presses[3000];

int index = 0;
int buttonTrigger = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
      pinMode(ledIDs[i], OUTPUT);
      pinMode(buttonIDs[i], INPUT);
      i++;
  }
}


void loop() {
  Serial.println("Loop started!");
  int i = 0;
  
  // repeat the sequence up until current index
  while (i < index) {
    Serial.print("Repeat index number ");
    Serial.println(i);    
    digitalWrite(ledIDs[presses[i]], HIGH);
    tone(speakerID, frequencies[presses[i]]);
    delay(500);
    noTone(speakerID);
    digitalWrite(ledIDs[presses[i]], LOW);
    i++;
  }
  
  // now allow the user to input the next button
  buttonTrigger = waitButtonID();
  digitalWrite(ledIDs[buttonTrigger], HIGH);
  tone(speakerID, frequencies[buttonTrigger]);
  delay(750);
  noTone(speakerID);
  digitalWrite(ledIDs[buttonTrigger], LOW);
  s[index] = buttonTrigger;
  Serial.print("Saved button press at ID number ")
  Serial.print(buttonTrigger+4);
  Serial.print(" at array index ");
  Serial.println(i);  
  index++;
}


// waits for button press and returns the ID of the button which was pressed
int waitButtonID() {
  int id = 0;
  while(true){
      for (int id = 0; id < 4; id++){
          if (digitalRead(buttonIDs[i])) {
              return i;
      }
    }
  }
}








