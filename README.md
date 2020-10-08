# hw2
COSC 4370 Homework 2

PSID: 1776794

**Environment:**
* OS: Windows 10

* Language: C++

* IDE: Visual Studio


**Functions:**

*problem1:*
* Type: void
* Params: none
* Use: Renders a circle of angled teapots as shown in example 1


*problem2:*
* Type: void
* Params: none
* Use: Renders a series of steps as shown in example 2


*problem3:*
* Type: void
* Params: none
* Use: Renders a sun-like figure with a happy face
- Inspired by the shine sprites from Super Mario Sunshine


*display:*
* Type: void
* Params: none
* Use: Sets up the window, projection matrix, and model-view matrix, then renders an object from problem1-3


*mouse:*
* Type: void
* Params: int button, int state, int x, int y
* Use: Used as the parameter for glutMouseFunction to set the mouse callback


*mouseMoved:*
* Type: void
* Params: int x, int y
* Use: Used as the parameter for glutMotionFunc to set the motion callback
- Allows for the view to be rotated left or right by clicking and dragging with the mouse


*keyboard:*
* Type: void
* Params: unsigned char key, int x, int y
* Use: Used as the parameter for glutKeyboardFunc to set the keyboard callback
- Allows for the render to be switched between problem 1-3 by pressing 1, 2, or 3 on the keyboard. Press q, Q, or ESC to exit the program


*reshape:*
* Type: void
* Params: int width, int height
* Use: Used as the parameter for glutReshapeFunc to set the reshape callback
- Allows for the window to be resized while scaling and centering the render


*main:*
* Type: int
* Params: int argc, char** argv
* Use: Calls all the functions needed to intialize and create the window and render
