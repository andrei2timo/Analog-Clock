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
    initwindow(600,600,"CEAS ANALOG - PROIECT INFORMATICA");///Crearea ferestrei grafice
    outtextxy(250,50,"CEAS ANALOG - PROIECT INFORMATICA");
    FreeConsole();///Ascunde consola in timpul rularii programului. (#include <windows.h>)
    ///Coordonatele orelor,minutelor,secundelor.
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

    ///Variabile necesare pentru timp. (ora sistemului)
    time_t rawTime;
    struct tm*currentTime;
    char a[100];///Numarul de rotatii.

    ///Coordonatele centrului cercului.
    int midX=getmaxx()/2;///Returneaza valoarea coordonatei X a pozitiei curente a cursorului
    int midY=getmaxy()/2;///Returneaza valoarea coordonatei Y a pozitiei curente a cursorului
    int IMS;
    while(1)///Imi cicleaza la infinitg
    {
        rawTime=time(NULL);
        currentTime=localtime(&rawTime);
        setlinestyle(0,3,3);
        setcolor(5);
        circle(midX,midY,200);///Deseneaza Cercul
        setcolor(15);
        ///Afisarea cifrelor de la 1...12 pe cerc
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

        ///"Crearea" orarului,minutarului si a secundarului.
        ///Setarea culorii pentru linie.


        ///Orarul
        strftime(a,100,"%I",currentTime);
        sscanf(a,"%d",&IMS);
        setcolor(14);
        line(midX,midY,midX+coordsForHourX[IMS-1],midY+coordsForHourY[IMS-1]);

        ///Minutarul
        strftime(a,100,"%M",currentTime);
        sscanf(a,"%d",&IMS);
        setcolor(11);
        line(midX,midY,midX+coordsForMinSecX[IMS],midY+coordsforMinSecY[IMS]);

        ///Secundarul
        strftime(a,100,"%S",currentTime);
        sscanf(a,"%d",&IMS);
        setcolor(4);
        line(midX,midY,midX+coordsForMinSecX[IMS],midY+coordsforMinSecY[IMS]);

        Beep(900,100);
        delay(1000);///Opreste timp de o secunda pentru a putea suprapune culoarea fondului.
        cleardevice();///Suprapune cu ajutorul culorii fondului (pt a nu se observa liniile din urma).
        ///Sterge ecranul grafic cu culoarea fondului
        outtextxy(250,50,"CEAS ANALOG - PROIECT INFORMATICA");
    }
    return 0;
}
