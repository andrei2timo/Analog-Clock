#include <iostream>
#include <graphics.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
///Ceas
///Munteanu Georgiana & Timo Andrei. Clasa 9E
using namespace std;

int main()
{
    initwindow(600,600,"ANALOG CLOCK - PROJECT");///Creating the graphical window
    outtextxy(250,50,"ANALOG CLOCK - PROJECT");
    FreeConsole();///Hide the console while running the program.(#include <windows.h>)
    ///Coordinates of hours, minutes, seconds.

    int coordsForHourX[12]= {50,87,100,87,50,0,-50,-87,-100,-85,-50,0};
    int coordsForHourY[12]= {-87,-50,0,50,87,100,87,50,0,-50,-87,-100};

    int coordsForMinSecX[60]= {0,18,35,53,69,85,100,114,126,138,147,155,162,
                               166,169,170,169,166,162,155,147,138,126,114,100,
                               85,69,53,35,18,0,-35,-53,-69,-85,-100,-114,-126,
                               -138,-147,-155,-162,-166,-166,-169,-170,-169,-166,
                               -162,-155,-147,-138,-126,-114,-100,-85,-69,-53,-35,-18};

    int coordsforMinSecY[60]= {-170,-169,-166,-162,-155,-147,-138,-126,-114,-100,-85,
                               -69,-53,-35,-18,0,18,35,53,69,85,100,114,126,138,
                               147,155,162,166,169,170,169,166,162,155,147,138,126,114,100,85,
                               69,53,35,18,0,-18,-35,-53,-69,-85,-100,-114,-126,-138,-147,
                               -155,-162,-166,-169};
    ///Variables required for time. (system time)
    time_t rawTime;
    struct tm*currentTime;
    char a[100];///Number of rotations.

    ///The coordinates of the center of the circle.
    int midX=getmaxx()/2;///Returns the X coordinate value of the current cursor position
    int midY=getmaxy()/2;///Returns the Y coordinate value of the current cursor position
    int IMS;
    while(1)///Cycles indefinitely
    {
        rawTime=time(NULL);
        currentTime=localtime(&rawTime);
        setlinestyle(0,3,3);
        setcolor(5);
        circle(midX,midY,200);///Draw the circle
        setcolor(15);
        ///Display numbers from 1 ... 12 per circle, taking into account one-dimensional arrays
        /// determined and explained previously
        outtextxy(midX+95+(-5),midY-165+(-5),"1");
        outtextxy(midX+165+(-5),midY-95+(-5),"2");
        outtextxy(midX+190+(-5),midY+0+(-7),"3");
        outtextxy(midX+165+(-7),midY+95+(-7),"4");
        outtextxy(midX+95+(-5),midY+165+(-10),"5");
        outtextxy(midX+0+(-3),midY+190+(-10),"6");
        outtextxy(midX-95+(0),midY+165+(-10),"7");
        outtextxy(midX-165+(-2),midY+95+(-10),"8");
        outtextxy(midX-190+(-3),midY+0+(-7),"9");
        outtextxy(midX-165+(-5),midY-95+(-3),"10");
        outtextxy(midX-95+(-5),midY-165+(-5),"11");
        outtextxy(midX+0+(-6),midY-190+(-5),"12");

        ///"Creating" the schedule, the timer and the secondary.
        ///Setting the color for the line.

        ///The schedule
        strftime(a,100,"%I",currentTime);
        sscanf(a,"%d",&IMS);
        setcolor(14);
        line(midX,midY,midX+coordsForHourX[IMS-1],midY+coordsForHourY[IMS-1]);

        ///The Timer
        strftime(a,100,"%M",currentTime);
        sscanf(a,"%d",&IMS);
        setcolor(11);
        line(midX,midY,midX+coordsForMinSecX[IMS],midY+coordsforMinSecY[IMS]);

        ///The Secondaryg
        strftime(a,100,"%S",currentTime);
        sscanf(a,"%d",&IMS);
        setcolor(4);
        line(midX,midY,midX+coordsForMinSecX[IMS],midY+coordsforMinSecY[IMS]);

        Beep(900,100);///Emits a sound each time the secondary changes position
        delay(1000);///Stop for one second to overlap the background color.
        cleardevice();///Overlap with the background color (so as not to notice the last lines).
        ///Delete the graphic screen with the background color
        outtextxy(250,50,"ANALOG CLOCK - PROJECT");
    }
    return 0;
}
