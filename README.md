MeggyJr_Rotate
==============

Rotates contents of screen 90 degrees.

This sketch supports a number of functions:

SaveScreen() copies the current contents of the screen into a buffer (a two-dimensional array).
RotateScreen(int angle) takes a parameter of 90 degrees or -90 degrees to indicate the direction the screen should be rotated.
PrintScreen() is an optional method (not currently called in loop() ) that prints the contents of the screen array to the Serial Monitor. Handy for debugging.
