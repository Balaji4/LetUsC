# include <graphics.h>
# include <math.h>
# include <conio.h>
# include <iostream.h>
void DDALine(int x1,int y1,int x2,int y2,int iColor);
void main()
{
    int gDriver=DETECT,gMode;

    int x1,x2,y1,y2,iColor;

    initgraph(&gDriver,&gMode,"c:\\tc\\bgi");
    cleardevice();
    cout<<endl<<"Enter x1  : ";
    cin>>x1;
    cout<<"Enter y1  : ";
    cin>>y1;
    cout<<endl<<"Enter x2  : ";
    cin>>x2;
    cout<<"Enter y2  : ";
    cin>>y2;
    cout<<endl<<"Enter COLOR  : ";
    cin>>iColor;
    cleardevice();
    DDALine(320,1,320,480,12);
    DDALine(1,240,640,240,12);
    circle(320,240,2);
    DDALine(320+x1,240-y1,320+x2,240-y2,iColor%16);
    getch();
}

void DDALine(int x1,int y1,int x2,int y2,int iColor)
{
    float dX,dY,iSteps;
    float xInc,yInc,iCount,x,y;

    dX = x1 - x2;
    dY = y1 - y2;

    if (fabs(dX) > fabs(dY))
    {
        iSteps = fabs(dX);
    }
    else
    {
        iSteps = fabs(dY);
    }

    xInc = dX/iSteps;
    yInc = dY/iSteps;

    x = x1;
    y = y1;
    circle(x,y,1);

    for (iCount=1; iCount<=iSteps; iCount++)
    {
        putpixel(floor(x),floor(y),iColor);
        x -= xInc;
        y -= yInc;
    }
    circle(x,y,1);
    return;
}