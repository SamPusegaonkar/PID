# PID
Manual tuned PID algorithm implemented in arduino.

**The above code is written in C language.**

**Description**: A combination of proportional, integral and derivative actions is more commonly referred as PID controller. These three basic coefficients are varied in each PID controller for specific application in order to get optimal output. It is a closed loop feedback system.
It gets the input parameter from the sensor which is referred as actual process variable (pin_input variable). It also accepts the desired actuator output (desired_output variable), which is referred as set variable, and then it calculates and combines the proportional, integral and derivative responses to compute the output for the actuator (pin_output variable).
  
**Instructions**: 
  1. Set your input and output pin numbers in line number 4 of the code.
  2. Enter your desired output.
  3. Tune the constants Ki,Kp,Kd.
  4. Repeat until a stable output is obtained.
  
   tweet @sampusegaonkar 
