/*==========================================
 * Arduino Labview Voltage Display
 * Created by zxlee (iamzxlee.wordpress.com)
 * 
 * Demonstrate how to display Arduino analog 
 * inputs, A0 and A1 to Labview using Serial
 * communication
============================================*/

#define input0 A0
#define input1 A1

unsigned long previousCount = 0;

/**==========================================
 * Constants for interval between samples
 * 50000 microseconds = 50 milliseconds
 * equivalent to 20 samples per second 
 * 
 * Sample rate is controlled using the 
 * method similar to example BlinkWithoutDelay
============================================*/

const unsigned long interval = 50000; 

void setup()
{
  Serial.begin(115200);
  delay(1000);
}

void loop()
{
  unsigned long currentCount = micros();

  //Calculates the time difference since last serial data sent
  unsigned long countDiff = currentCount - previousCount;
  
  if(countDiff >= interval)
  {
    //Create a buffer to store string
    char buffer[50];

    //Format the data into string
    sprintf(buffer, "$%d,%d,%u\r\n", analogRead(input0), analogRead(input1), countDiff);
    
    //Write string into COM port
    Serial.write(buffer);

    //Update new previous count 
    previousCount = currentCount;
  }  

}

