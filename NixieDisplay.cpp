#include "NixieDisplay.h"
 
  //constructor
  NixieDisplayPair::NixieDisplayPair(){
  }


  //methods
  NixieDisplayPair::DisplayInit(byte driverPinA, byte driverPinB, byte driverPinC, byte driverPinD, byte tube1Annode, byte tube2Annode, byte decimalPointTube1PinIn, byte decimalPointTube2PinIn, byte highVoltagePowerAdresIn){
    tube1.init(driverPinA, driverPinB, driverPinC, driverPinD, tube1Annode, decimalPointTube1PinIn);
    tube2.init(driverPinA, driverPinB, driverPinC, driverPinD, tube2Annode, decimalPointTube2PinIn);
    highVoltagePowerAdres = highVoltagePowerAdresIn;
    pinMode(highVoltagePowerAdres, OUTPUT);
    digitalWrite(highVoltagePowerAdres, HIGH);
    displayPower = true;
  }

  NixieDisplayPair::DisplaySixtyNine(){
    digitalWrite(highVoltagePowerAdres, HIGH);
    tube1.setNumberToDisplay(6, LOW, 255);
    delay(500);
    tube1.Off();
    tube2.setNumberToDisplay(9, LOW, 255);
    delay(500);
    tube2.Shutdown();
    digitalWrite(highVoltagePowerAdres, LOW);
  }

  NixieDisplayPair::DisplayExecute(){
    if(displayPower){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= timeDelay){
      if(currentNumberDisplayed){
        byte numberOnTube = numberOnDisplay / 10;
        tube2.Off();
        tube1.setNumberToDisplay(numberOnTube, decimalPoint1, brightness);
        currentNumberDisplayed = !currentNumberDisplayed;

      }else{
        byte numberOnTube = numberOnDisplay % 10;
        tube1.Off();
        tube2.setNumberToDisplay(numberOnTube, decimalPoint2, brightness);
        currentNumberDisplayed = !currentNumberDisplayed;
      } 
      previousMillis = currentMillis;
    }
    }
  }
  
  NixieDisplayPair::SetTimeDelay(unsigned int timeDelayIn){
    timeDelay = timeDelayIn;
  }

  NixieDisplayPair::SetNumberToDisplay(byte numberIn){
    numberOnDisplay = numberIn;
    displayPower = true;
    digitalWrite(highVoltagePowerAdres, HIGH);
  }

  NixieDisplayPair::SetBrightness(byte brightnessIn){
    brightness = brightnessIn;
  }
NixieDisplayPair::PowerOff(){
  tube2.Shutdown();
  tube1.Shutdown();
  displayPower = false;
  digitalWrite(highVoltagePowerAdres, LOW);
}
  
  
