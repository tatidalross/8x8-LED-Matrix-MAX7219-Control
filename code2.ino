#include <LedControl.h>

int DIN = 11;
int CS = 10;
int CLK =  13;


int row=0;
int col=0;
int temp=0;
int data=0;

LedControl lc=LedControl(DIN,CLK,CS,1);

void setup()
{
 lc.shutdown(0,false);       
 lc.setIntensity(0,5);
 lc.clearDisplay(0);
 Serial.begin(9600);
}




void loop()
{ 
   if(Serial.available() > 0)      
   {
      data = Serial.read();// it returns ascii value if we send one in the phone                
      if(data < 96)
      {
       if(temp==0)
       {
        row=data-48;
        temp=1;
       }
       else
       col=data-48;
      }
    
       else if(data=='n')
       {
         lc.setLed(0,row,col,true);
        Serial.println('n');
       Serial.println(row);
       Serial.println(col);
         temp=0;
       }
       else if(data=='f')
       {
         lc.setLed(0,row,col,false);
         Serial.println('f');
         Serial.println(row);
         Serial.println(col);
         temp=0;
       }

       else if(data=='r')
       lc.clearDisplay(0);
    }

    
}