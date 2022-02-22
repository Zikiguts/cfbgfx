' FBGFX DLL Wrapper
'
extern "C"

Function cScreenRes(dx As Integer, dy As Integer, depth As Integer, pages As Integer, flags As Integer) As Integer Export
   Return ScreenRes(dx,dy,depth,pages,flags,0)
End Function

Function cWindowTitle(text as zstring ptr) As Integer Export
   WindowTitle *text
   Return 0
End Function

Function cImageCreate(dx As Integer, dy As Integer, colors As Integer,depth As integer) As Any Ptr Export
	Return ImageCreate(dx,dy,colors)
End Function
Function cImageDestroy(img As Any ptr) As Integer Export
	ImageDestroy(img)
	Return 0
End Function

Function cPset(target As Any Ptr,x As Integer, y As Integer, colors As integer) As Integer Export
   PSet target,(x,y),colors
	Return 1
End Function

Function cPoint(target As Any Ptr,x As Integer, y As Integer) As Integer Export
	Return Point(x,y,target)
End Function

Function cSleep(num As Integer) As Integer Export
   If num=0 Then Sleep Else Sleep num
	Return 1
End Function

Function cRGB(r As Integer, g As Integer, b As integer) As Integer Export
	Return RGB(r,g,b)
End Function

Function cRGBA(r As Integer, g As Integer, b As Integer, a As Integer) As Integer Export
	Return RGBA(r,g,b,a)
End Function

Function cMultikey(key As Integer) As Integer Export

	Return MultiKey(key)
End Function

Function cCircle(target As Any Ptr,x As integer,y As integer,size As integer,colors As Integer,fill As integer) As Integer Export
	If fill=0 Then Circle target,(x,y),size,colors
	If fill=1 Then Circle target,(x,y),size,colors,,,,f
	Return 0
End Function

Function cLine(target As Any Ptr,x As integer,y As Integer,x2 As integer,y2 As integer,colors As Integer,style As integer) As Integer Export
	Line target,(x, y)-(x2, y2),colors,,style
	Return 0
End Function
Function cBox(target As Any Ptr,x As integer,y As Integer,x2 As integer,y2 As integer,colors As Integer,fill As Integer,style As integer) As Integer Export
	If fill=0 Then Line target,(x, y)-(x2, y2),colors,b,style
	If fill=1 Then Line target,(x, y)-(x2, y2),colors,bf,style
	Return 0
End Function

Function cPaint(target As Any Ptr,x As integer,y As Integer,colors As Integer,border As integer) As Integer Export
	Paint target,(x, y),colors,border
	Return 0
End Function

Function cScreenlock As Integer Export
	ScreenLock
	Return 1
End Function

Function cScreenunlock As Integer Export
	ScreenUnLock
	Return 1
End Function

Function cBload(file As ZString ptr,target As Any Ptr) As Integer Export
	BLoad *file,target
	Return 0
End Function

Function cPrint(text As ZString ptr,mode As Integer) As Integer Export
   If mode=0 Then print *text
	If mode=1 Then print *text;
	Return 0
End Function

Function cLocate(row As Integer,column As Integer) As Integer Export
	locate row,column
	Return 0
End Function

Function cColor(fore As integer,back As Integer) As Integer Export
	Color fore,back
	Return 0
End Function

Function cCls As Integer Export
	Cls
	Return 1
End Function

Function cSetmouse(x as integer,y as integer,c as integer,v as integer) As Integer Export
	SetMouse x,y,c,v
	return 1
End Function

Function cGetmouse(byref mx as integer,byref my as integer,byref mw as integer,byref mb as integer) As Integer Export
	GetMouse mx,my,mw,mb
	return 1
End Function

Function cTimer As double Export
	Return timer
End Function

Function cPut(dst As Any Ptr, x As Integer, y As Integer, himage As Any Ptr, mode As Integer) As Integer Export
   Select Case mode
      Case 0
         Put dst,(x,y),himage,PSet
      Case 1
         Put dst,(x,y),himage,PReset
      Case 2
         Put dst,(x,y),himage,Trans
      Case 3
         Put dst,(x,y),himage,And
      Case 4
         Put dst,(x,y),himage,Or
      Case 5
         Put dst,(x,y),himage,Xor
      Case 6
         Put dst,(x,y),himage,Alpha
   End Select
   Return 0
End Function

End extern

