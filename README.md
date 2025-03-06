# Ultrasonic Machine Learning Traffic Light Project
This project ties an existing TensorFlow Lite Micro AI Model to an Arduino kit. It detects a people and allowed objects a the camera and makes the lights act accordingly. The general code changes the lights based on the sensor and its distance, and halts all potential traffic in case of a person or "people" being started. Some parts of the project were created using information from Youtube. If you are just starting out with circuits, I strongly encourage you to go to Tinkercad and experiment with the circuits there.

# Software Used
For this project, I used:
- Python 3.12 on VSCode
- Arduino IDE
- Teachable Machines with Google ~ Image Model
- TensorFlow ~ keras

# Hardware Used
In the project, all components can be found in ELEGOO Mega 2560 the Most Complete Starter Kits
-  Arduino Mega 2560 ~ Arduino circuit/controller board
-  A Large Breadboard
-  HC-SR04 ~ an Ultrasonic Sensor
-  Converter Cable ~ I used the USB cable provided in the kit, but those with Mac or other OS can find alternatives (provided code also changes based on converter)
-  3 different color LED lights ~ Red, Yellow, and Green
-  3 Resistors
-  +12 wires ~ amount may vary based on design and personal prefernce
-  USB Convertor Cable
   
## Assembly
You're gonna want to have Arduino IDE installed and your Arduino kit ready. The other software used comes in later, but it is not necessary to have them at this time. 
### Preperation 
You're gonna need your Arduino circuit, breadboard, and 2 long wires (preferrably one red and one black to represent the power/charges). Connect one end of each wire to one of the bottom 2 rows of the breadboard, the ones with (-) and (+). Connect the ends of these wires to the GND and 5V pins located on the Arduino circuit by the pins labelled "Power". Having these wires here provides power to the whole row and allows you to power other aspects of your project without crowding your circuit board. 
### The Sensor
You are gonna want to grab your Arduino Control Board, Ultrasonic Sensor, Breadboard, and 4 wires (2 small and 2 long). On the breadboard, place the Ultrasonic Sensor in close radius to the Arduino circuit. Then place the 4 wires in the within the same column as the sensor. Place the 2 long wires on the inside under the Echo and Trig pins, and the 2 short wires on the outside under the Vcc and GND pins. For the short wires, connect the one under Vcc to the bottom (+) row, and the one under the GND pin to the (-) row. Since you already esablished power to these rows, it provides power to the wires in them. place the remaining 2 wires under the Echo and Trig pins and place them in pins 9 and ~10 located under the PWM label on your Arduino board. 
### The LED Lights 
Grab your 3 LEDs, 3 resistors, 3 short black wires, and 3 long wires (color doesn't matter). Find somewhere on your breadboard with ample space and space out your LEDs. For reference all of my LEDs are in row j of the breadboard. I placed my red LED in columns 1-2 (shorter prong in 1 and longer one in 2, etc.), yellow in columns 15-16, and green in columns 30-31. Next take your resistors and place one side within the same row as the longest prong of your LEDs (i.e. columns 2, 16, and 31) with the other end in a different column. Get the long wires and the short black wires for the next step. Place one side of the short wire under the side of the LED without the resistor and then place the other end of the wire in the bottom (-) row, then place one end of the long wire under the side of the resistor away from the LED (repeat these steps for the other 2). For the red LED, I placed the free end in pin 12, yellow in pin 4 and green in pin 2. 

## Next
At this point, if you haven't, get the required software including Python 3.12 
### Code Changes
Here's what you're goin to need to change in the Python 3.12 code:
- `port = "COM3"  # Replace with your serial port`
  - In your Arduino IDE and go under "Tools" and "Port" it should tell you the name of your port
- `# Load the model
model = load_model(
    "C:/Users/kemcg/Downloads/converted_keras(1)/keras_model.h5",
    compile=False,
    custom_objects={"DepthwiseConv2D": CustomDepthwiseConv2D}
)` 
  - Change to your file path
- `# Load the labels
class_names = open("C:/Users/kemcg/Downloads/converted_keras(1)/labels.txt", "r").readlines()`
  - Change to your file path
 
