#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define round(a) ((int)(a+0.5))
int k;
float xmin,ymin,xmax,ymax,arr[20],m;
void clipl(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 >= xmin && x2 >= xmin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1 < xmin && x2 >= xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1 >= xmin  && x2 < xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        k+=2;
    }
}

void clipt(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 <= ymax && y2 <= ymax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1 > ymax && y2 <= ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1 <= ymax  && y2 > ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        k+=2;
    }
}

void clipr(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 <= xmax && x2 <= xmax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1 > xmax && x2 <= xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1 <= xmax  && x2 > xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        k+=2;
    }
}

void clipb(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 >= ymin && y2 >= ymin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1 < ymin && y2 >= ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1 >= ymin  && y2 < ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        k+=2;
    }
}
 
void main()
{
    int gdriver=DETECT,gmode,n,poly[20];
    float xi,yi,xf,yf,polyy[20];
    /*printf("Coordinates of rectangular clip window :\nxmin,ymin             :");
    scanf("%d%d",&xmin,&ymin);
    printf("xmax,ymax             :");
    scanf("%d%d",&xmax,&ymax);*/

    // co-rodinates of rectangular window
    xmin = 100;
    ymin = 100;
    xmax = 300;
    ymax = 300;
	int i;
    /*printf("\n\nPolygon to be clipped :\nNumber of sides       :");
    scanf("%d",&n);
    printf("Enter the coordinates :");
    for(int i=0;i < 2*n;i++)
		cin>>polyy[i];*/
    // co-ordinates of poylgon to be clipped
    n = 10;
   /* polyy[0]=300;
  	polyy[1]=100;
	polyy[2]=350;
	polyy[3]=290;
	polyy[4]=430;
	polyy[5]=300;
	polyy[6]=360;
	polyy[7]=320;
	polyy[8]=380;
	polyy[9]=450;
	polyy[10]=300;
	polyy[11]=340;
	polyy[12]=250;
	polyy[13]=450;
	polyy[14]=280;
	polyy[15]=320;
	polyy[16]=160;
	polyy[17]=300;
	polyy[18]=280;
	polyy[19]=300;*/
	polyy[0] = 200; polyy[1] = 50;
	polyy[2] = 270; polyy[3] = 150;
	polyy[4] = 330; polyy[5] = 150;
	polyy[6] = 270; polyy[7] = 190;
	polyy[8] = 330; polyy[9] = 270;
	polyy[10] = 200; polyy[11] = 230;
	polyy[12] = 70; polyy[13] = 270;
	polyy[14] = 130; polyy[15] = 190;
	polyy[16] = 70; polyy[17] = 150;
	polyy[18] = 130; polyy[19] = 150;
	i=2*n;
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    for(i=0;i < 2*n+2;i++)
		poly[i]=round(polyy[i]);
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
    setcolor(RED);
    rectangle(xmin,ymax,xmax,ymin);
    printf("\t\tUNCLIPPED POLYGON");
    setcolor(WHITE);
    //fillpoly(n,poly);
    drawpoly(n+1,poly);
	getch();
    cleardevice();
    k=0;
    for(i=0;i < 2*n;i+=2)
		clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i < k;i++)
		polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0;i < 2*n;i+=2)
		clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i < k;i++)
		polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0;i < 2*n;i+=2)
		clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i < k;i++)
		polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0;i < 2*n;i+=2)
		clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    for(i=0;i < k;i++)
		poly[i]=round(arr[i]);
    //if(k)
		//fillpoly(k/2,poly);
	drawpoly(k/2,poly);
    setcolor(RED);
    rectangle(xmin,ymax,xmax,ymin);
    printf("\tCLIPPED POLYGON");
    getch();
    closegraph();
}
