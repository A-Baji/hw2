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
  * Inspired by the shine sprites from Super Mario Sunshine
  

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
  * Allows for the view to be rotated left or right by clicking and dragging with the mouse


*keyboard:*
* Type: void
* Params: unsigned char key, int x, int y
* Use: Used as the parameter for glutKeyboardFunc to set the keyboard callback
  * Allows for the render to be switched between problem 1-3 by pressing 1, 2, or 3 on the keyboard. Press q, Q, or ESC to exit the program


*reshape:*
* Type: void
* Params: int width, int height
* Use: Used as the parameter for glutReshapeFunc to set the reshape callback
  * Allows for the window to be resized while scaling and centering the render


*main:*
* Type: int
* Params: int argc, char** argv
* Use: Calls all the functions needed to intialize and create the window and render

**Report**

*Problems:*

For problem 1, I had to create a circle of teapots that are equidistant from each other and rotated according to their angle to the x axis. To do this, first the necessary theta is calculated by dividing 2pi by the number of teapots. Then in a for loop that iterates for each pot, the angle for the current teapot is calculated in radians and degrees. Then the current matrix is translated to its point using the angle in radians, then rotated using the angle in degrees, and then the teapot is rendered with this matrix.

For problem 2, I had to create a series of steps with slightly increasing height. First the overall matrix is translated to the left so that the 15 steps are centered. Then there are two nested for loops. The first one iterates for every step, and the second one iterates until the current step number. So if we are on step three in the outer loop, the inner loop will iterate three times. For every step after the first, we render multiple cubes according to the step number, increasing the height of each consecutive cube to form a column.

For problem 3, I created a sun-like figure with a happy face inspired by the shrine sprites from Super Mario Sunshine. First I created a sphere in the center. Then I used the same technique as problem 1 to put cones around the surface of the sphere, and then I put smaller spheres at the points of those cones. This creates the sun shape. For the face I used three tori. The first two are rotated 90 degree around the y axis and brought forward on the z axis until they are slightly sticking out of the sphere, creating eye shapes. The third torus is larger, and slightly tilted on the x axis, and then brought forward on the z axis until it is slightly sticking out of the sphere, creating a smile.

*Display:*

