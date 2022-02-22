#include <string.h>
#include <cstdio>
#include "include/cfbgfx.h"


int main(int32_t argc, char **argv) {
	// Window setup:
	cScreenRes(640,480,32,GFX_OPENGL);
	cWindowTitle(strdup("Example01"));
	// print launch arguments
	for (int32_t i = 0; i <= argc; i++) {
		cPrint(argv[i]);
	}
	// Set foreground and background colors
	cColor(cRGB(10,30,10),cRGB(100,100,100));
	// Display a nice message:
	cLocate(10,20);
	cPrint(strdup("This is cfbgfx! Press any key..."));
	
	// Wait for keypress so that you can actually see the nice message.
	cSleep();
		
	// load some resources
	void * pic (cImageCreate(640,480,cRGB(255,0,255),32));
	cBload(strdup("new.bmp"),pic);
	int32_t x,y,wheel,buttons;
	char fpsw[] ("Fps: 0000");
	int32_t fps (0);
	double otime (cTimer());
	
	// make mouse invisible
	cSetmouse(-1,-1,0);
	
	/* Main loop
	 * Draws a circle at the cursor position
	 * Displays the image resource loaded above and the framerate.
	 */
	 
	while (not cMultikey(1)) { //Loop until Key 'Esc' is pressed
		cGetmouse(x,y,wheel,buttons);
		x=x-1;
		y=y-1;
		
		if (cTimer()>otime+1) {
			sprintf(fpsw,"Fps: %d",fps);
			fps=0;
			otime=cTimer();
		}
		
		fps+=1;
		cScreenlock();
		cCls();
		cPut(0,0,0,pic,PSet);
		cPset(0,x,y,cRGB(0,0,0));
		cCircle(0,x,y,10,cRGB(0,0,0));
		cDrawString(0,x-80,y-20,strdup("Press 'ESC' to quit."),cRGB(0,0,0));
		
		cPrint(fpsw);
		cScreenunlock();
		cSleep(1);
	};
	
	// Delete the resource, no memory leaks here!
	cImageDestroy(pic);
	return 0;
}
