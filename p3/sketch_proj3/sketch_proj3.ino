#include <LEDStrip.h> //Include LED Strip library
#include <SoftwareSerial.h> //Include RFID library



#define rxPin 2 //pin 2 on arduino is used for receiving tagID from RFID reader
#define txPin 6 //Not required for reading, you could ignore this

#define STRIP_LENGTH 72 //40 LEDs on the strip
#define WHITE 0xffffff // WHITE
#define BLACK 0x000000 // BLACK

int enable = 3; //pin 3 on arduino is used for enabling and disabling RFID reader
int valid;
SoftwareSerial RFID = SoftwareSerial(rxPin, txPin); //Initializing Software serial communication. RFID is a object of SoftwareSerial constructor
int SDI = 4; //Red wire (not the red SV wire!)
int CKI = 5; //Green wire
LEDStrip strip1(SDI, CKI, STRIP_LENGTH);



void setup() {
  Serial.begin(9600); //This is necessary to see your outpt on your laptop screen
  pinMode(enable, OUTPUT); //Initializing enable(pin 3 on arduino) pin as output. It is used to enable or disable the RFID reader
  RFID.RFIDinit(); //Initializing RFID reader
  
  for(int i=0;i<STRIP_LENGTH;i++)
    {
     strip1.setLED(i, BLACK);
    }
    strip1.post_frame();
    
  strip1.setLED(3, WHITE);
  strip1.setLED(2, WHITE);
  strip1.setLED(1, WHITE);
  strip1.post_frame();
}


void loop() //this loop will run forever
{
  RFID.RFIDinit(); //Initializing RFID reader once again. This is necessary before reading the tag
  valid = RFID.Readtag(); //Read the tagID
  if (valid == 1) //if there is a tag the valid will be 1 else it will be -1
  {
    Serial.print("ID: "); //Print out RFID code
    Serial.println(RFID.rfidArray); //After reading the tag. TagID will be stored in rfidArray
    RFID.disableRFID(enable); //Deactivate reader 
    
    
    if(strncmp(RFID.rfidArray,"2900AE1295",10)==0){
      strip1.setLED(12, WHITE);
      strip1.setLED(11, WHITE);
      strip1.setLED(10, WHITE);
      
      strip1.setLED(9, BLACK);
      strip1.setLED(8, BLACK);
      strip1.setLED(7, BLACK);
      
      strip1.setLED(3, BLACK);
      strip1.setLED(2, BLACK);
      strip1.setLED(1, BLACK);
      
      strip1.setLED(61, BLACK);
      strip1.setLED(60, BLACK);
      strip1.setLED(59, BLACK);
      
      strip1.setLED(65, BLACK);
      strip1.setLED(66, BLACK);
      strip1.setLED(67, BLACK);
      
      strip1.post_frame();
      delay(10);
    }
    else if(strncmp(RFID.rfidArray,"2900AE2112",10)==0){
      strip1.setLED(12, BLACK);
      strip1.setLED(11, BLACK);
      strip1.setLED(10, BLACK);
      
      strip1.setLED(9, WHITE);
      strip1.setLED(8, WHITE);
      strip1.setLED(7, WHITE);
      
      strip1.setLED(3, BLACK);
      strip1.setLED(2, BLACK);
      strip1.setLED(1, BLACK);
      
      strip1.setLED(61, BLACK);
      strip1.setLED(60, BLACK);
      strip1.setLED(59, BLACK);
      
      strip1.setLED(65, BLACK);
      strip1.setLED(66, BLACK);
      strip1.setLED(67, BLACK);
      
      strip1.post_frame();
      delay(10);
    }
    else if(strncmp(RFID.rfidArray,"2900AE21A3",10)==0){
      strip1.setLED(61, WHITE);
      strip1.setLED(60, WHITE);
      strip1.setLED(59, WHITE);
      
      strip1.setLED(65, BLACK);
      strip1.setLED(66, BLACK);
      strip1.setLED(67, BLACK);
      
      strip1.post_frame();
      delay(10);
      
    }
    else if(strncmp(RFID.rfidArray,"2900ADFE7B",10)==0){
      strip1.setLED(61, BLACK);
      strip1.setLED(60, BLACK);
      strip1.setLED(59, BLACK);
      
      strip1.setLED(65, WHITE);
      strip1.setLED(66, WHITE);
      strip1.setLED(67, WHITE);
      
      strip1.post_frame();
      delay(10);
    }
    else if(strncmp(RFID.rfidArray,"2900AE4968",10)==0){
      strip1.setLED(12, BLACK);
      strip1.setLED(11, BLACK);
      strip1.setLED(10, BLACK);
      
      strip1.setLED(9, BLACK);
      strip1.setLED(8, BLACK);
      strip1.setLED(7, BLACK);
      
      strip1.setLED(3, WHITE);
      strip1.setLED(2, WHITE);
      strip1.setLED(1, WHITE);
      
      strip1.setLED(61, BLACK);
      strip1.setLED(60, BLACK);
      strip1.setLED(59, BLACK);
      
      strip1.setLED(65, BLACK);
      strip1.setLED(66, BLACK);
      strip1.setLED(67, BLACK);
      
      strip1.post_frame();
      delay(10);
    }
    
    //strip1.post_frame(); //Activate LED settings
     
    delay(1000); //1 second delay
    RFID.flush(); //flush out previous data
    RFID.enableRFID(enable); //activate the reader again;
  }
}



