' FBGFX DLL Wrapper
'
extern "C"

Function cScreenRes(dx As long, dy As long, depth As long, pages As long, flags As long) As long Export
   Return ScreenRes(dx,dy,depth,pages,flags,0)
End Function

Function cWindowTitle(text as zstring ptr) As long Export
   WindowTitle *text
   Return 0
End Function

Function cImageCreate(dx As long, dy As long, colors As ulong,depth As long) As Any Ptr Export
	Return ImageCreate(dx,dy,colors)
End Function
Function cImageDestroy(img As Any ptr) As long Export
	ImageDestroy(img)
	Return 0
End Function

Function cPset(target As Any Ptr,x As long, y As long, colors As ulong) As long Export
   PSet target,(x,y),colors
	Return 1
End Function

Function cPoint(target As Any Ptr,x As long, y As long) As ulong Export
	Return Point(x,y,target)
End Function

Function cSleep(num As long) As long Export
   If num=0 Then Sleep Else Sleep num
	Return 1
End Function

Function cRGB(r As long, g As long, b As long) As ulong Export
	Return RGB(r,g,b)
End Function

Function cRGBA(r As long, g As long, b As long, a As long) As ulong Export
	Return RGBA(r,g,b,a)
End Function

Function cMultikey(key As long) As long Export

	Return MultiKey(key)
End Function

Function cCircle(target As Any Ptr,x As long,y As long,size As long,colors As ulong,fill As long) As long Export
	If fill=0 Then Circle target,(x,y),size,colors
	If fill=1 Then Circle target,(x,y),size,colors,,,,f
	Return 0
End Function

Function cLine(target As Any Ptr,x As long,y As long,x2 As long,y2 As long,colors As ulong,style As long) As long Export
	Line target,(x, y)-(x2, y2),colors,,style
	Return 0
End Function
Function cBox(target As Any Ptr,x As long,y As long,x2 As long,y2 As long,colors As ulong,fill As long,style As long) As long Export
	If fill=0 Then Line target,(x, y)-(x2, y2),colors,b,style
	If fill=1 Then Line target,(x, y)-(x2, y2),colors,bf,style
	Return 0
End Function

Function cPaint(target As Any Ptr,x As long,y As long,colors As ulong,border As ulong) As long Export
	Paint target,(x, y),colors,border
	Return 0
End Function

Function cScreenlock As long Export
	ScreenLock
	Return 1
End Function

Function cScreenunlock As long Export
	ScreenUnLock
	Return 1
End Function

Function cBload(file As zString ptr,target As Any Ptr) As long Export
	BLoad *file,target
	Return 0
End Function

Function cPrint(text As zString ptr,mode As long) As long Export
   If mode=0 Then print *text
	If mode=1 Then print *text;
	Return 0
End Function

Function cLocate(row As long,column As long) As long Export
	locate row,column
	Return 0
End Function

Function cColor(fore As ulong,back As ulong) As long Export
	Color fore,back
	Return 0
End Function

Function cCls As long Export
	Cls
	Return 1
End Function

Function cSetmouse(x as long=-1,y as long=-1,v as long=-1,c as long=-1) As long Export
	if x=-1 then
	setmouse ,,v,c
	else
	SetMouse x,y,v,c
	end if
	return 1
End Function

Function cGetmouse(byref mx as long,byref my as long,byref mw as long,byref mb as long) As long Export
	GetMouse mx,my,mw,mb
	return 1
End Function

Function cTimer As double Export
	Return timer
End Function

Function cPut(dst As Any Ptr, x As long, y As long, himage As Any Ptr, mode As long) As long Export
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

Function cDrawString(dst As Any Ptr, x As long, y As long, text As zstring Ptr,col as ulong) As long Export
	draw string dst,(x,y),*text,col
	return 1
End Function

End extern
