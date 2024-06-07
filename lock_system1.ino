// Button initialization
const int button1 = 2; 
const int button2 = 3; 
const int button3 = 4; 
const int button4 = 5; 
const int button5 = 6; 
const int button6 = 7; 
const int LED[] = {14, 15, 16, 17, 18, 19}; // Array of LED pins

const int Red = 8; 
const int Green = 9;
void checkEntered1(int button);

int code[] = {1, 5, 5, 2, 3, 2}; // Code to be entered

int entered[7]; // Array to store entered code

void setup() { 
  Serial.begin(9600); 

  // Set button pins as inputs with pull-up resistors
  pinMode(button1, INPUT_PULLUP); 
  pinMode(button2, INPUT_PULLUP); 
  pinMode(button3, INPUT_PULLUP); 
  pinMode(button4, INPUT_PULLUP); 
  pinMode(button5, INPUT_PULLUP); 
  pinMode(button6, INPUT_PULLUP); 

  pinMode(Red, OUTPUT); 
  pinMode(Green, OUTPUT); 

  digitalWrite(Red, LOW); 

  // Set LED pins as outputs
  for (int i = 0; i < 6; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() { 
  // Check each button for press
  if (digitalRead(button1) == LOW) {
    checkEntered1(1); // Call checkEntered and pass it a 1
    delay(250); 
  }
  else if (digitalRead(button2) == LOW) {
    checkEntered1(2); 
    delay(250); 
  }
  else if (digitalRead(button3) == LOW) { 
    checkEntered1(3); 
    delay(250); 
  }
  else if (digitalRead(button4) == LOW) { 
    checkEntered1(4); 
    delay(250); 
  }
  else if (digitalRead(button5) == LOW) { 
    checkEntered1(5); 
    delay(250); 
  }
  else if (digitalRead(button6) == LOW) { 
    checkEntered1(6); 
    delay(250); 
  }
}

void checkEntered1(int button) { 
  // Turn on corresponding LED
  digitalWrite(LED[button - 1], HIGH);
  // Check if button has already been pressed
  if (entered[0] != 0) {
    checkEntered2(button); // Move on to checkEntered2, passing it "button"
  }
  else if (entered[0] == 0) { 
    entered[0] = button;
    Serial.print("1: ");
    Serial.println(entered[0]);
  } 
}

void checkEntered2(int button) { 
  digitalWrite(LED[button - 1], HIGH);
  if (entered[1] != 0) { 
    checkEntered3(button); 
  }
  else if (entered[1] == 0) { 
    entered[1] = button;
    Serial.print("2: ");
    Serial.println(entered[1]); 
  }
}

void checkEntered3(int button) {  
  digitalWrite(LED[button - 1], HIGH);
  if (entered[2] != 0) { 
    checkEntered4(button); 
  }
  else if (entered[2] == 0) { 
    entered[2] = button; 
    Serial.print("3: ");
    Serial.println(entered[2]); 
  }
}

void checkEntered4(int button) {  
  digitalWrite(LED[button - 1], HIGH);
  if (entered[3] != 0) { 
    checkEntered5(button); 
  }
  else if (entered[3] == 0) { 
    entered[3] = button; 
    Serial.print("4: ");
    Serial.println(entered[3]); 
  }
}

void checkEntered5(int button) { 
  digitalWrite(LED[button - 1], HIGH);
  if (entered[4] != 0) { 
    checkEntered6(button);
  }
  else if (entered[4] == 0) { 
    entered[4] = button; 
    Serial.print("5: ");
    Serial.println(entered[4]); 
  }
}

void checkEntered6(int button) { 
  digitalWrite(LED[button - 1], HIGH);
  if (entered[5] == 0) { 
    entered[5] = button; 
    Serial.print("6: ");
    Serial.println(entered[5]); 
    delay(100); 
    validate(); 
  }
}

void validate() { 
  if ((entered[0] == code[0]) && (entered[1] == code[1]) && (entered[2] == code[2]) && (entered[3] == code[3]) && (entered[4] == code[4]) && (entered[5] == code[5])) { 
    digitalWrite(Red, LOW); 
    digitalWrite(Green, HIGH);
    delay(2000);
    Serial.println("Access Granted!!");
    digitalWrite(Green, LOW); 
  }
  else { 
    digitalWrite(Red, HIGH);
    delay(2000);
    digitalWrite(Red, LOW);
    Serial.println("Access Denied!!");
  }
  close_all();
}

void close_all() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(LED[i], LOW);
  }
}
