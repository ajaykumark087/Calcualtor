🔢 Arduino Advanced Calculator : 
This is an advanced calculator project built using an Arduino, 4x4 Keypad, and 16x2 LCD. It supports basic arithmetic operations (+, -, *, /, %) and square root (√) functionality. It's a great learning project for handling input/output devices, string manipulation, and math operations in embedded systems.

📦 Components Required : 
            Component	Quantity
            Arduino Uno/Nano	1
            4x4 Matrix Keypad	1
            16x2 LCD (with pins)	1
            Jumper wires	As needed
            Breadboard	1

🔌 Circuit Connections : 
            LCD (16x2):
            LCD Pin	Arduino Pin
            [RS	A2],
            [EN	A3],
            [D4	4],
            [D5	5],
            [D6	6],
            [D7	7],

Keypad (4x4):
Keypad Pins	Arduino Pins
{[Row 1	2]
[Row 2  3]
[Row 3	8]
[Row 4	9]}
{[Col 1	10]
[Col 2	11]
[Col 3	12]
[Col 4	13]}

🧠 Features : 
Supports Addition, Subtraction, Multiplication, Division, Percentage

Performs Square Root (√) (via √ key)

Handles division by zero

Displays real-time input on LCD

Includes reset/clear functionality (C key)

Displays result and resets automatically after 3 seconds

🧾 Keypad Layout : 

[ 7 ] [ 8 ] [ 9 ] [ / ]
[ 4 ] [ 5 ] [ 6 ] [ * ]
[ 1 ] [ 2 ] [ 3 ] [ - ]
[ C ] [ 0 ] [ = ] [ + ]
(To use square root, you can map a keypad button to '√' if supported or assign it to a combination.)

🔧 How to Use : 
Upload the code to your Arduino using the Arduino IDE.

Power the board and press numbers and operations using the keypad.

Press = to see the result.

Press C anytime to reset.

For square root, enter a number and press the √ key (must be mapped in hardware).

📄 Code Explanation : 
The code:

Uses the Keypad library for input reading.

Uses the LiquidCrystal library to control the LCD.

Uses String to build input and perform operations.

Handles floating point values and edge cases like divide-by-zero.

📁 File: calculator.ino
Paste the .ino code you provided into a file named calculator.ino.

📚 Libraries Used
Keypad

LiquidCrystal

Make sure you install them via Arduino Library Manager.
