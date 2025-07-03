#include <Keypad.h>            // Include Keypad library for input
#include <LiquidCrystal.h>     // Include LiquidCrystal library for 16x2 LCD
#include <math.h>              // Include math library for square root

// === Initialize LCD: RS, EN, D4, D5, D6, D7 ===
LiquidCrystal lcd(A2, A3, 4, 5, 6, 7);

// === Keypad setup ===
const byte ROWS = 4;  // 4 rows
const byte COLS = 4;  // 4 columns

// Keymap layout: each character corresponds to a key
char keys[ROWS][COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};

// Connect keypad rows and columns to these Arduino pins
byte rowPins[ROWS] = {2, 3, 8, 9};          // Rows connected to pins 2, 3, 8, 9
byte colPins[COLS] = {10, 11, 12, 13};      // Columns connected to pins 10–13

// Create keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// === Calculator state variables ===
String input = "";         // To store number input as string
float num1 = 0, num2 = 0;  // Operands for the operation
char op = '\0';            // Operator (+, -, *, /, %)
bool opEntered = false;    // True after operator is entered
bool resultShown = false;  // True after result is displayed

void setup() {
  lcd.begin(16, 2);            // Initialize the LCD (16 columns, 2 rows)
  lcd.print("Advanced Calc");  // Display welcome text
  delay(1000);                 // Wait 2 seconds
  lcd.clear();                 // Clear LCD
}

void loop() {
  char key = keypad.getKey();  // Read a key from the keypad

  if (key) {  // If a key is pressed

    if (resultShown) {
      // Clear everything if a key is pressed after result
      lcd.clear();
      input = "";
      resultShown = false;
    }

    // Handle digits and decimal point
    if ((key >= '0' && key <= '9') || key == '.') {
      input += key;        // Append digit to input string
      lcd.print(key);      // Display digit
    }

    // Handle operator input
    else if (key == '+' || key == '-' || key == '*' || key == '/' || key == '%') {
      if (!opEntered && input != "") {
        num1 = input.toFloat();  // Convert first number to float
        input = "";              // Clear input for next number
        op = key;                // Store operator
        opEntered = true;       // Set flag to indicate operator was entered
        lcd.print(key);         // Show operator on LCD
      }
    }

    // Handle square root operation (√)
    else if (key == '√') {
      if (input != "") {
        num1 = input.toFloat();    // Convert input to float

        if (num1 >= 0) {
          float result = sqrt(num1);     // Calculate square root
          lcd.clear();
          lcd.print("√"); lcd.print(num1);  // Show √number
          lcd.setCursor(0, 1);
          lcd.print("= "); lcd.print(result);  // Show result
        } else {
          lcd.clear();
          lcd.print("Invalid √ input");  // Cannot sqrt negative number
        }

        reset();                 // Reset all values
        delay(3000);            // Wait before clearing
        lcd.clear();
      }
    }

    // Handle equal (=) to evaluate the operation
    else if (key == '=') {
      if (input != "") {
        num2 = input.toFloat();    // Convert second number to float
        float result = 0;          // Store result
        bool valid = true;         // Flag to check for invalid ops

        // Perform operation based on operator
        switch (op) {
          case '+': result = num1 + num2; break;
          case '-': result = num1 - num2; break;
          case '*': result = num1 * num2; break;
          case '/':
            if (num2 != 0)
              result = num1 / num2;  // Divide if num2 ≠ 0
            else {
              lcd.clear();
              lcd.print("Divide by Zero");
              valid = false;
            }
            break;
          case '%':
            result = (num1 * num2) / 100.0;  // Percentage logic
            break;
          default:
            valid = false;
            break;
        }

        if (valid) {
          lcd.clear();
          lcd.print("Result:");
          lcd.setCursor(0, 1);
          lcd.print(result);    // Display result
        }

        resultShown = true;  // Mark that result was shown
        reset();             // Reset variables for next calculation
        delay(3000);         // Wait before clearing
        lcd.clear();
      }
    }

    // Clear/reset on pressing 'C'
    else if (key == 'C') {
      lcd.clear();
      reset();   // Reset all calculator variables
    }
  }
}

// === Function to reset calculator state ===
void reset() {
  input = "";           // Clear input string
  num1 = num2 = 0;      // Reset operands
  op = '\0';            // Clear operator
  opEntered = false;    // Clear operator flag
}
