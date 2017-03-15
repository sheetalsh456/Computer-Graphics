#include<stdio.h>
#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	int tx;
	printf("\nEnter value of tx = ");
	scanf("%d",&tx);
	initgraph(&gd,&gm,"");
	int j,k,i;
	for(j=0;j<=tx;j++)
	{
		cleardevice();

		// the base line
		line(0,250,600,250); 

		// the 4 circles of the 2 wheels and the pedal part
		circle(100+j,200,50); // back wheel
		circle(300+j,200,50); // front wheel
		circle(100+j,200,10); // back wheel small circle
		circle(200+j,200,15); // pedal part

		// spokes of back wheel
		for(i=0;i<=360;i+=60)
			line(300+j,200,300+50*cos((15*j+i)*3.14/180)+j,200+50*sin((15*j+i)*3.14/180));
		
		// spokes of front wheel
		for(i=k;i<=360;i+=60)
			line(100+10*cos((15*j+i)*3.14/180)+j,200+10*sin((15*j+i)*3.14/180),100+50*cos((15*j+i)*3.14/180)+j,200+50*sin((15*j+i)*3.14/180));

		// the chains between back wheel and pedal
		line(100+j,190,200+j,185);
		line(100+j,210,200+j,215);

		// the 4 connecting shafts
		// the down slant line at front wheel
		line(265+j,125,300+j,200);
		// the down slant line at back wheel
		line(125+j,125,100+j,190);
		// the right upwards diagonal line from pedal to handle
		line(200+j,185,265+j,125);
		// seat horizontal line
		line(125+j,125,265+j,125); 

		// the small vertical line near the seat
		line(125+j,125,125+j,105);

		// the small vertical line near the hands
		line(265+j,125,265+j,115);

		// the small seat horizontal line 
		line(115+j,115,135+j,115);

		// circle of the head
		circle(200+j,50,15);

		// the line indicating the body from head to seat
		line(125+j,105,200+j,65);

		// the hands
		line(325/2+j,170/2,260+j,110);
		line(325/2+j,170/2,270+j,120);

		// the cycle handle
		line(260+j,110,270+j,120);

		// the legs
		line(200+j,185,125+j,105);
		line(200+j,185,125+j,125);

		delay(10);

	}
	
	getch();
}
            
         
