/*
  MeggyJr_Rotate.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Test code to rotate the screen 90 degrees to the right or the left.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int screen[8][8] = { // This gets drawn sideways because the origin here is in a different place.
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,1,1,1,1,0,0},
{0,1,1,1,1,1,1,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,0,0,0,0,0}
};

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  ClearSlate();
  CheckButtonsPress();
  if (Button_A)
  {
 // SaveScreen();
    RotateScreen(90);
  }
  
  if (Button_B)
  {
//  SaveScreen();
    RotateScreen(-90);
  }
  DisplayScreen();
  DisplaySlate();
}

void SaveScreen() // Takes whatever is on the screen and copies it into screen[][] which is an 8x8 2D array.
{
  for (int x = 0; x < 8; x++)
  {
    for (int y = 0; y < 8; y++)
    {
      screen[x][y] = ReadPx(x,y); // The color of each pixel is saved in its corresponding location in screen[][].
    }
  }
}

void RotateScreen(int angle) // Proceeds through screen[][] and copies everything into a temp array to rotate it.
{
  int temp[8][8]; // create temp array to hold rotated coords
  
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (angle == 90)
        temp[j][7-i] = screen[i][j];
      else
        temp[i][j] = screen[j][7-i];
    }
  }
  // copy everything from temp array over to screens array
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      screen[i][j] = temp[i][j];
    }
  }
  PrintScreen();
}

void DisplayScreen()
{
  ClearSlate();
  for (int x = 0; x < 8; x++)
  {
    for (int y = 0; y < 8; y++)
    {
      DrawPx(x,y,screen[x][y]);
    }
  }
}

void PrintScreen() // Call this whenever you want to see the cointents of the screen array.
{
  for (int x = 0; x < 8; x++)
  {
    for (int y = 0; y < 8; y++)
    {
      Serial.print(screen[x][y]);
      Serial.print(" ");
    }
    Serial.println();
  }
}

