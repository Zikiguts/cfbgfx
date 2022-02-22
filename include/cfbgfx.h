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

      int GFX_NULL               = -1;
      int GFX_WINDOWED         = 0x00;
      int GFX_FULLSCREEN         = 0x01;
      int GFX_OPENGL            = 0x02;
      int GFX_NO_SWITCH         = 0x04;
      int GFX_NO_FRAME         = 0x08;
      int GFX_SHAPED_WINDOW      = 0x10;
      int GFX_ALWAYS_ON_TOP      = 0x20;
      int GFX_ALPHA_PRIMITIVES   = 0x40;
      int GFX_HIGH_PRIORITY      = 0x80;

      extern int cScreenRes(int dx, int dy, int depth = 32, int pages = 0, int flags = 0);
      #define ScreenRes cScreenRes
      extern int cWindowTitle(char * text);
      extern void * cImageCreate(int x, int y, int color = 0, int depth = 32);
      extern int cImageDestroy(void * img);
      extern int cBload(char * file,void * img);
      extern int cPset(void * target,int x, int y, int color = 0);
      extern int cPoint(void * target,int x, int y);
      extern int cRGB(int r, int g, int b);
      extern int cRGBA(int r, int g, int b, int a);
      extern int cCircle(void * target, int x, int y, int size, int color=0, int fill=0);
      extern int cLine(void * target,int x1,int y1,int x2,int y2,int color=0,int style=0b1111111111111111);
	  extern int cBox(void * target,int x1,int y1,int x2,int y2,int color=0,int fill=0,int style=0b1111111111111111);
	  extern int cPrint(char * text,int mode=0);
	  #define print cPrint
	  extern int cLocate(int column, int row);
	  extern int cColor(int fore, int back);
	  extern int cPaint(void * target, int x, int y, int color, int border);
      extern int cSleep(int num = 0);
      extern int cMultikey(int key);
      extern int cScreenlock();
      extern int cScreenunlock();
      extern int cCls();
      extern int cPut(void * dest,int x,int y,void * img,int mode);
      extern int cSetmouse(int mx=-1,int my=-1,int v=-1,int c=-1);
      extern int cGetmouse(int &mx,int &my, int &mw,int &mb);
      extern double cTimer();
}
