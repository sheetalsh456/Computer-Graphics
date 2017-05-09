 #include<stdio.h>
#include<graphics.h>
#define ROUND(a)((int)(a+0.5))
int cliptest(float p,float q,float *u1,float *u2)
{
            float r;
            int retval=1;
            if(p<0.0)
            {
                        r=q/p;
                        if(r>*u2)
                                    retval=0;
                        if(r>*u1)
                                    *u1=r;
            }
            else if(p>0.0)
            {
                        r=q/p;
                        if(r<*u1)
                                    retval=0;
                        if(r<*u2)
                                    *u2=r;
            }
            else if(q<0.0)
                        retval=0;
            return(retval);
}
void clipline(int minx,int miny,int maxx,int maxy,int x1,int y1,int x2,int y2)
{
            float u1=0.0,u2=1.0,dx=x2-x1,dy;
            if(cliptest(-dx,x1-minx,&u1,&u2))
                        if(cliptest(dx,maxx-x1,&u1,&u2))
                        {
                                    dy=y2-y1;
                                    if(cliptest(-dy,y1-miny,&u1,&u2))
                                                if(cliptest(dy,maxy-y1,&u1,&u2))
                                                {
                                                            if(u2<1.0)
                                                            {
                                                                        x2=x1+u2*dx;
                                                                        y2=y1+u2*dy;
                                                            }
                                                            if(u1>0.0)
                                                            {
                                                                        x1+=u1*dx;
                                                                        y1+=u1*dy;
                                                            }
                                                            line(x1,y1,x2,y2);
                                                }
                        }
}
void main()
{
            int gdriver=DETECT,gmode,x1,y1,x2,y2,minx,miny,maxx,maxy;
            initgraph(&gdriver,&gmode,"");
            //clrscr();
            /*printf("Enter the min & max x values: ");
            scanf("%d %d",&minx,&maxx);
            printf("Enter the min & max y values: ");
            scanf("%d %d",&miny,&maxy);
            printf("Enter the first endpoint: ");
            scanf("%d %d",&x1,&y1);
            printf("Enter the second endpoint: ");
            scanf("%d %d",&x2,&y2);*/
	    minx = 100;
	    maxx = 250;
	    miny = 100;
	    maxy = 250;

	    // Line through rectangle
	    x1 = 120;
	    y1 = 50;
	    x2 = 175;
	    y2 = 275;

	    // line inside rectangle
	    /*x1 = 150;
	      y1 = 150;
	      x2 = 200;
	      y2 = 200;*/

	    // line outside rectangle
	    /*x1 = 275;
	      y1 = 125;
	      x2 = 295;
	      y2 = 200;*/
            //clrscr();
            printf("Before Clipping");
            line(x1,y1,x2,y2);
            rectangle(minx,maxy,maxx,miny);
            getch();
            //clrscr();
	    cleardevice();
            printf("After Clipping");
            clipline(minx,miny,maxx,maxy,x1,y1,x2,y2);
            rectangle(minx,maxy,maxx,miny);
            getch();
}
