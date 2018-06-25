/*
 * A PID is a closed loop feedback system used to reduce error. The following code represents the basic implementation of a PID system.
 */
int pin_output=3,pin_input=8;                 //Change the pin number as required.
void setup() {
  
  Serial.begin(9600);
  pinMode(pin_output,OUTPUT);
  pinMode(pin_input,INPUT);
  
}
void loop() {
  if(Serial.available()>0){
    double error,prev_error=0,desired_output,current_output,Kp,Ki,Kd,i,d,time_change,last_time=0,current_time,output;
    while(1){
      
      //Read all the values
      current_output=analogRead(pin_input);
      Serial.println("Enter the value of Kp");
      Kp=Serial.read();                       //Read the value of Kp
                                              //Directly scales the error.
      delay(1000);
      Serial.println("Enter the value of Ki");
      Ki=Serial.read();                       //Read the value of Ki
                                              //Handles errors accumulating over time.
      delay(1000);
      Serial.println("Enter the value of Kd");
      Kd=Serial.read();                       //Read the value of Kd
                                              //Controls how ths system behaves between time intervals. This will help in dampening the system to improve stability.

      //Calculate the current time and delta.
      current_time=millis();                  
      time_change=current_time-last_time;

      //Calculate the values of p,i,d
      error=desired_output - current_output;   //Proportional
      i+=error * time_change;                  //Integral
      d=(error - prev_error)/current_time;     //Derivative     
 
      output=Kp*error + Ki*i + Kd*d;           //Calculate the sum of products.
      prev_error=error;
      last_time=current_time;

      analogWrite(pin_output,output);       //Ouput the calculated value.
      delay(5000);
    }
  }
}
