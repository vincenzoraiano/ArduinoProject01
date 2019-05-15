//Defining the variable for the green led pin.
int green=13;
//Defining the variable for red led pin.
int red=12;

//Defining the variable for the buzzer pin.
int buzzer=11;


//Defining a variable to store the avarage of the temperature.
int tempAv;
int temp;

double tempCelsius= ((temp * 0.00488) - 0.5) / 0.01;





void setup() {
  //Setting the pin mode for the green pin
  pinMode(green,OUTPUT);
  //Setting the pin mode for the red pin
  pinMode(red,OUTPUT);
  //Setting the pin mode for the buzzer pin
  pinMode(buzzer,OUTPUT);

//Open the serial port for comunicate with the serial port.
  Serial.begin(9600);

  
  //Take an average of thee temperature.
  digitalWrite(green,HIGH);
  //Storing the data from the sensor inside an int value.
  int temp =analogRead(A1);
  //Do the math for calculate the temperature in celsius
  double tempCelsius= ((temp * 0.00488) - 0.5) / 0.01;
  delay(500);
  //First Measurement
  tempCelsius+=analogRead(A1);
  delay(500);
  //Second Measurement
  tempCelsius+=analogRead(A1);
  delay(500);
  digitalWrite(green,LOW);
  //Third Measurement
  tempAv+=tempCelsius/3+4;
  Serial.print("The average of the temperature is=");
  Serial.println(tempCelsius);

 
  

}

void loop() {

  
  double tempCelsius= ((temp * 0.00488) - 0.5) / 0.01;
  //Print the message to the serial port 
  Serial.print("The temperature is equal to=");
  Serial.print(tempCelsius);
  Serial.println(" C°");
  delay(500);

  //If the temperature is less than 200 the RED led is HIGH
  //ans the red led is LOW, and the buzzer TONE is ringing
  if(tempCelsius<200){
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    tone(buzzer,220,500);
    delay(2000);
    
    
  }
  //If the temperature is less than 200 the GREEN led is HIGH
  //ans the red led is LOW, and the buzzer TONE is ringing
  else if(tempCelsius>200){
    digitalWrite(green,LOW);
    tone(buzzer,1000,500);
    digitalWrite(red,HIGH);
    delay(200);
    digitalWrite(red,LOW);
    delay(200);
  }



  

}
