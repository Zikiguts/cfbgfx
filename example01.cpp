#include <string.h>
#include <cstdio>
#include "include/cfbgfx.h"


int main(int argc, char **argv) {
	// Window setup:
	cScreenRes(640,480,32,GFX_OPENGL);
	cWindowTitle(strdup("Test Program"));
	cColor(cRGB(255,0,255),cRGB(255,255,255));
	cCls();

	int i;
	for (i = 0; i <= argc; i++) {
		cPrint(argv[i]);
		cLocate(i+2,0);
	}
	// Display a nice message:
	print(strdup("hello"));
	
	// Wait for keypress so that you can actually see the nice message.
	cSleep();
		
	// load some resources
	void * pic (cImageCreate(640,480,cRGB(255,0,255),32));
	cBload(strdup("new.bmp"),pic);
	int x,y,wheel,buttons;
	char fpsw[] ("hi");
	int fps (0);
	double otime (cTimer());
	
	/* Main loop
	 * Draws a box at the cursor position
	 * Displays the image resource loaded above and the framerate.
	 */
	 
	while(not cMultikey(1)) {
		cGetmouse(x,y,wheel,buttons);
		x=x-1;
		y=y-1;
		
		if (cTimer()>otime+1) {
			sprintf(fpsw,"%d",fps);
			fps=0;
			otime=cTimer();
		}
		
		fps+=1;
		cScreenlock();
		cCls();
		cPut(0,0,0,pic,PSet);
		cPset(0,x,y,cRGB(255,0,255));
		cCircle(0,x,y,10,cRGB(0,0,0));
		cBox(0,x,y,x+10,y+10,cRGB(255,0,255));
		print(fpsw);
		cScreenunlock();
		cSleep(1);
	};
	
	// Delete the resource, no memory leaks here!
	cImageDestroy(pic);
	return 0;
}
