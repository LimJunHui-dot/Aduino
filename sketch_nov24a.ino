


//Global Variables
int sensorPin = 0;          //pin number to use the ADC
int sensorValue = 0;        //initialization of sensor variable, equivalent to EMA Y
 
float EMA_a_low = 0.05;     //initialization of EMA alpha (cutoff-frequency)
float EMA_a_high = 0.4;
 
int EMA_S_low = 0;          //initialization of EMA S
int EMA_S_high = 0;
 
int highpass = 0;
int bandpass = 0;
int bandstop = 0;
 
void setup(){
  Serial.begin(115200);                     //setup of Serial module, 115200 bits/second
   
  EMA_S_low = analogRead(sensorPin);        //set EMA S for t=1
  EMA_S_high = analogRead(sensorPin);
}
 
void loop(){
  sensorValue = analogRead(sensorPin);      //read the sensor value using ADC
   
  EMA_S_low = (EMA_a_low*sensorValue) + ((1-EMA_a_low)*EMA_S_low);          //run the EMA
  EMA_S_high = (EMA_a_high*sensorValue) + ((1-EMA_a_high)*EMA_S_high);
   
  bandpass = EMA_S_high - EMA_S_low;        //find the band-pass as before
 
  bandstop = sensorValue - bandpass;        //find the band-stop signal
 
  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.print(EMA_S_low);
  Serial.print(" ");
  Serial.println(bandstop);
   
  delay(20);      
  }                          //20ms delay