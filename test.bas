screen 18
sleep 2000,1
setmouse ,,1,-1

dim as integer x,y
do
getmouse x,y
screenlock
circle (x,y),7
screenunlock

sleep 1
loop until multikey(1)
