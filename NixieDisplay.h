/*
 *                             _____  _____  _    _ _____ _   _  ____                
 *                       /\   |  __ \|  __ \| |  | |_   _| \ | |/ __ \               
 *                      /  \  | |__) | |  | | |  | | | | |  \| | |  | |              
 *                     / /\ \ |  _  /| |  | | |  | | | | | . ` | |  | |              
 *                    / ____ \| | \ \| |__| | |__| |_| |_| |\  | |__| |              
 *   _   _ _______   /_/____\_\_|__\_\_____/_\____/|_____|_|_\_|\____/      __     __
 *  | \ | |_   _\ \ / /_   _|  ____| |  __ \_   _|/ ____|  __ \| |        /\\ \   / /
 *  |  \| | | |  \ V /  | | | |__    | |  | || | | (___ | |__) | |       /  \\ \_/ / 
 *  | . ` | | |   > <   | | |  __|   | |  | || |  \___ \|  ___/| |      / /\ \\   /  
 *  | |\  |_| |_ / . \ _| |_| |____  | |__| || |_ ____) | |    | |____ / ____ \| |   
 *  |_| \_|_____/_/ \_\_____|______| |_____/_____|_____/|_|    |______/_/    \_\_|   
 *                 |  ____|         |__ \  |__   __|  | |                            
 *                 | |__ ___  _ __     ) |    | |_   _| |__   ___  ___               
 *                 |  __/ _ \| '__|   / /     | | | | | '_ \ / _ \/ __|              
 *                 | | | (_) | |     / /_     | | |_| | |_) |  __/\__ \              
 *                 |_|  \___/|_|    |____|    |_|\__,_|_.__/ \___||___/ 
 *
 *               
 *    
 *    Copyright (C) 2021  David Weijzen
 *    
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

 
#include "Arduino.h"
#include "NixieTube.h"
class NixieDisplayPair{


  private:
  NixieTube tube1;
  NixieTube tube2;
  byte numberOnDisplay;
  byte brightness;
  bool decimalPoint1;
  bool decimalPoint2;
  unsigned long previousMillis;
  unsigned int timeDelay;
  bool currentNumberDisplayed;
  bool displayPower;
  byte highVoltagePowerAdres;

  public:
  NixieDisplayPair();
  
  DisplayInit(byte driverPinA, byte driverPinB, byte driverPinC, byte driverPinD, byte tube1Annode, byte tube2Annode, byte decimalPointTube1PinIn, byte decimalPointTube2PinIn, byte highVoltagePowerAdresIn);
  DisplaySixtyNine();
  DisplayExecute();
  SetTimeDelay(unsigned int timeDelayIn);
  SetNumberToDisplay(byte numberIn);
  SetBrightness(byte brightnessIn);
  PowerOff();
};
