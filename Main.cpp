/*************************************************************
 * 1. Name:
 *      Jacob Morgan & Brandon Price
 * 2. Assignment Name:
 *      Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include "uiInteract.h" // for INTERFACE
#include "position.h"      // for POINT
#include "Simulator.h"

#ifndef NDEBUG
#include "test.h"
#endif

using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* _pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator* pSimulator = (Simulator*)p;
   pSimulator->update();
   pSimulator->draw();
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
#ifndef NDEBUG
   testRunner();
#endif
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1200.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL, "Orbital Simulator", ptUpperRight);

   // Initialize the demo
   Simulator demo(ptUpperRight, ui);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
