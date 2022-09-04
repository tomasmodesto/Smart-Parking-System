# Smart-Parking-System

- Summary
  - In this one, we present the idea of a car park, which consists of counting and presenting the number of available and occupied spaces as a form of information           adjacent to users.

- Detailed description of the entry system
  - The entry system is performed via the left lane, when the first ultrasonic distance sensor detects an object less than 9.35 cm, it repeats a “while” cycle that aims   to open the cancellation. As the car advances on the lane, the code will come out in a cycle that allows canceling the same cart, thus not allowing the car to advance.   Still on the left, we have the second ultrasonic away device that aims to add 1 to the occupied variable and remove 1 from the variable (variables previously declared   in the code) and then display both variables on the lcd visible on the front of the park.
  When the car park is full (or is occupied = 4 and = 0) if there is another car that you wish to enter, you will be informed through the LCD that the car park is full     and that you will have to wait for a car that has already been parked to leave .
  
- Detailed description of the output system
  - The output system is exactly the same as the input system, but with two differences. The first is about now moving on the right lane and the second corresponds to     the changes in the variables. That is, when the ultrasonic distance sensor 1 finds an object at a distance greater than 9.35 cm and less than the road limit,             automatically one unit will be removed from optional operations and one unit will be added to the free variable.
  The car park is optimized for unexpected cases, such as when the car park is empty but instantly a car was able to enter the car park without going through the gate.     If that same car tries to leave through the gate, it will not open as it is an “intruder”.
  
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 - Eletronics
    - Arduino Uno R3
    - Ultrasonic Distance Sensor
    - LCD 16x2 1602 I2C IIC
    - Micro Servo Motor 9G SG90
    - Red LED
    - 100 ohm resistor
    - Jumper Wires male to male
    - Jumper Wires male to female
    
  

