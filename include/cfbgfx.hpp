#include <inttypes.h>
extern "C" {
        enum RasterOp
        {
            PSet    = 0,
            PReset  = 1,
            Trans   = 2,
            And     = 3,
            Or      = 4,
            Xor     = 5,
            Alpha   = 6
        };

      int32_t GFX_NULL               = -1;
      int32_t GFX_WINDOWED         = 0x00;
      int32_t GFX_FULLSCREEN         = 0x01;
      int32_t GFX_OPENGL            = 0x02;
      int32_t GFX_NO_SWITCH         = 0x04;
      int32_t GFX_NO_FRAME         = 0x08;
      int32_t GFX_SHAPED_WINDOW      = 0x10;
      int32_t GFX_ALWAYS_ON_TOP      = 0x20;
      int32_t GFX_ALPHA_PRIMITIVES   = 0x40;
      int32_t GFX_HIGH_PRIORITY      = 0x80;

      extern int32_t cScreenRes(int32_t dx, int32_t dy, int32_t depth = 32, int32_t pages = 0, int32_t flags = 0);
      #define ScreenRes cScreenRes
      extern int32_t cWindowTitle(char * text);
      extern void * cImageCreate(int32_t x, int32_t y, uint32_t color = 0, int32_t depth = 32);
      extern int32_t cImageDestroy(void * img);
      extern int32_t cBload(char * file,void * img);
      extern int32_t cPset(void * target,int32_t x, int32_t y, uint32_t color = 0);
      extern uint32_t cPoint32_t(void * target,int32_t x, int32_t y);
      extern uint32_t cRGB(int32_t r, int32_t g, int32_t b);
      extern uint32_t cRGBA(int32_t r, int32_t g, int32_t b, int32_t a);
      extern int32_t cCircle(void * target, int32_t x, int32_t y, int32_t size, uint32_t color=0, int32_t fill=0);
      extern int32_t cLine(void * target,int32_t x1,int32_t y1,int32_t x2,int32_t y2,uint32_t color=0,int32_t style=0b1111111111111111);
	  extern int32_t cBox(void * target,int32_t x1,int32_t y1,int32_t x2,int32_t y2,uint32_t color=0,int32_t fill=0,int32_t style=0b1111111111111111);
	  extern int32_t cPrint(char * text,int32_t mode=0);
	  #define Print cPrint
	  extern int32_t cLocate(int32_t column, int32_t row);
	  extern int32_t cColor(uint32_t fore, uint32_t back);
	  extern int32_t cPaint32_t(void * target, int32_t x, int32_t y, uint32_t color, uint32_t border);
      extern int32_t cSleep(int32_t num = 0);
      extern int32_t cMultikey(int32_t key);
      extern int32_t cScreenlock();
      extern int32_t cScreenunlock();
      extern int32_t cCls();
      extern int32_t cPut(void * dest,int32_t x,int32_t y,void * img,int32_t mode);
      extern int32_t cSetmouse(int32_t mx=-1,int32_t my=-1,int32_t v=-1,int32_t c=-1);
      extern int32_t cGetmouse(int32_t &mx,int32_t &my, int32_t &mw,int32_t &mb);
      extern int32_t cDrawString(void * target,int32_t x,int32_t y, char * text, uint32_t col);
      extern double cTimer();
}
