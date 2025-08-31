#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'N','/','*','-'},   
  {'7','8','9','+'},
  {'4','5','6','1'},   
  {'2','3','E','0'}   
};

byte rowPins[ROWS] = {2, 3, 4, 5};  
byte colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int extraKeyPin = 10; 

void setup() {
  pinMode(extraKeyPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  char key = keypad.getKey();
  if (key) sendKey(key);

  if (digitalRead(extraKeyPin) == LOW) {
    Keyboard.press(KEY_DELETE);
    delay(50);
    Keyboard.release(KEY_DELETE);
  }
}

void sendKey(char key) {
  switch (key) {
    case '0'...'9': Keyboard.write(key); break;

    case 'N': 
      Keyboard.press(KEY_NUM_LOCK); Keyboard.release(KEY_NUM_LOCK);
      break;

    case '/': Keyboard.write('/'); break;
    case '*': Keyboard.write('*'); break;
    case '-': Keyboard.write('-'); break;
    case '+': Keyboard.write('+'); break;

    case 'E': 
      Keyboard.press(KEY_RETURN); Keyboard.release(KEY_RETURN);
      break;
  }
}
