#include <UTFT.h>

UTFT    myGLCD(ILI9341_16,38,39,40,41);

// Declare which fonts we will be using
extern uint8_t BigFont[];

int x, y;

const int pinButton1 = 10;
const int pinButton2 = 11;
const int pinButton3 = 12;

void drawButtons()
{
  //Ron
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (270,10, 225, 230);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (270, 10, 225, 230);
    myGLCD.print("Ron", 255, 95, 87);
  //Negrita
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (195,10, 150, 230);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (195, 10, 150, 230);
    myGLCD.print("Negrita", 180, 80, 87);
  //vino
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (120,10, 80, 230);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (120, 10, 80, 230);
    myGLCD.print("Vino", 110, 90, 87);
}

void setup()
{
// Initial setup
  Serial.begin(9600);
  
  pinMode(pinButton1, INPUT);
  pinMode(pinButton2, INPUT);
  pinMode(pinButton3, INPUT);
  
  myGLCD.InitLCD();
  myGLCD.clrScr();


  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 255);
  drawButtons();
}

void loop()
{
  bool final = false;
  int stateButton1 = digitalRead(pinButton1);
  int stateButton2 = digitalRead(pinButton2);
  int stateButton3 = digitalRead(pinButton3);
  
  if((stateButton1 == 0) && (stateButton2 == 1) && (stateButton3 == 1))
  {
    Serial.println("1");
    myGLCD.clrScr();
    myGLCD.print("Bebida en preparacion", 110, 90, 87);
    while(final == false)
    {
      if (Serial.available() > 0) {
        char dato = Serial.read();
        if(dato = "f")
        {
          final = true;
          myGLCD.clrScr();
          myGLCD.print("Bebida lista", 110, 90, 87);
        }
       }
        
      }
  }

  else if((stateButton1 == 1) && (stateButton2 == 0) && (stateButton3 == 1))
  {
    Serial.println("2");
  }

  else if((stateButton1 == 1) && (stateButton2 == 1) && (stateButton3 == 0))
  {
    Serial.println("3");
  }
}
