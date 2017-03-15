# include <stdio.h>
 # include <graphics.h>

 # include     <math.h>

 # define  f                 0.3
 # define  projection_angle   45


 void show_screen( );

 void apply_zx_reflection(int[5][3]);
 void multiply_matrices(float[4],float[4][4],float[4]);

 void draw_pyramid(int [5][3]);
 void get_projected_point(int*,int*,int*);

 void Line(int,int,int,int);


 int main( )
    {
       int driver=VGA;
       int mode=VGAHI;

       initgraph(&driver,&mode,"..\\Bgi");

       show_screen( );

       int pyramid[5][3]={
                {290,200,30},      //  base front left
                {350,200,30},      //  base front right
                {350,200,-30},     //  base back right
                {290,200,-30},     //  base back left
                {320,110,0}        //  top
             };

      setcolor(15);
     draw_pyramid(pyramid);

       setcolor(15);
       //settextstyle(0,0,1);
     outtextxy(50,415,"*** Press any key to see the 3D Reflection along zx-plane.");

       apply_zx_reflection(pyramid);

       getch( );

       setcolor(10);
     draw_pyramid(pyramid);

       getch( );
       return 0;
    }


 /*************************************************************************///-------------------------  apply_zx_reflection( )  --------------------///*************************************************************************/
 void apply_zx_reflection(int edge_points[5][3])
    {
        int count;
       for(count=0;count<5;count++)
      {
         float matrix_a[4]={edge_points[count][0],edge_points[count][1],
                            edge_points[count][2],1};
         float matrix_b[4][4]={
                    { 1,0,0,0 } ,
                    { 0,-1,0,0 } ,
                    { 0,0,1,0 } ,
                    { 0,0,0,1 }
                  };

         float matrix_c[4]={0};

         multiply_matrices(matrix_a,matrix_b,matrix_c);

         edge_points[count][0]=(int)(matrix_c[0]+0.5);
         edge_points[count][1]=(int)(matrix_c[1]+0.5+480);
         edge_points[count][2]=(int)(matrix_c[2]+0.5);
      }
    }

 /************************************************************************///----------------------  multiply_matrices( )  ------------------------///************************************************************************/
 void multiply_matrices(float matrix_1[4],
                  float matrix_2[4][4],float matrix_3[4])
    {
        int count_1,count_2;
       for(count_1=0;count_1<4;count_1++)
      {
         for(count_2=0;count_2<4;count_2++)
        matrix_3[count_1]+=
               (matrix_1[count_2]*matrix_2[count_2][count_1]);
      }
    }

 /************************************************************************///--------------------------  draw_pyramid( )  -------------------------///************************************************************************/
 void draw_pyramid(int points[5][3])
    {
       int i,edge_points[5][3];

       for(i=0;i<5;i++)
      {
         edge_points[i][0]=points[i][0];
         edge_points[i][1]=points[i][1];
         edge_points[i][2]=points[i][2];

         get_projected_point(&edge_points[i][0],
                    &edge_points[i][1],&edge_points[i][2]);
      }

       Line(edge_points[0][0],edge_points[0][1],
                      edge_points[1][0],edge_points[1][1]);
       Line(edge_points[1][0],edge_points[1][1],
                      edge_points[2][0],edge_points[2][1]);
       Line(edge_points[2][0],edge_points[2][1],
                      edge_points[3][0],edge_points[3][1]);
       Line(edge_points[3][0],edge_points[3][1],
                      edge_points[0][0],edge_points[0][1]);

       Line(edge_points[0][0],edge_points[0][1],
                      edge_points[4][0],edge_points[4][1]);
       Line(edge_points[1][0],edge_points[1][1],
                      edge_points[4][0],edge_points[4][1]);
       Line(edge_points[2][0],edge_points[2][1],
                      edge_points[4][0],edge_points[4][1]);
       Line(edge_points[3][0],edge_points[3][1],
                      edge_points[4][0],edge_points[4][1]);
    }

 /************************************************************************///---------------------  get_projected_point( )  -----------------------///************************************************************************/
 void get_projected_point(int  *x,int *y,int *z)
    {
       float fcos0=(f*cos(projection_angle*(M_PI/180)));
       float fsin0=(f*sin(projection_angle*(M_PI/180)));

       float Par_v[4][4]={
                {1,0,0,0},
                {0,1,0,0},
                {fcos0,fsin0,0,0},
                {0,0,0,1}
             };

       float xy[4]={*x,*y,*z,1};
       float new_xy[4]={0};

       multiply_matrices(xy,Par_v,new_xy);

       *x=(int)(new_xy[0]+0.5);
       *y=(int)(new_xy[1]+0.5);
       *z=(int)(new_xy[2]+0.5);
    }

 /*************************************************************************///-------------------------------  Line( )  -----------------------------///*************************************************************************/
 void Line(int x_1,int y_1,int x_2,int y_2)
    {
       int color=getcolor( );

       int x1=x_1;
       int y1=y_1;

       int x2=x_2;
       int y2=y_2;

       if(x_1>x_2)
      {
         x1=x_2;
         y1=y_2;

         x2=x_1;
         y2=y_1;
      }

       int dx=abs(x2-x1);
       int dy=abs(y2-y1);
       int inc_dec=((y2>=y1)?1:-1);

       if(dx>dy)
      {
         int two_dy=(2*dy);
         int two_dy_dx=(2*(dy-dx));
         int p=((2*dy)-dx);

         int x=x1;
         int y=y1;

         putpixel(x,y,color);

         while(x<x2)
        {
           x++;

           if(p<0)
              p+=two_dy;

           else
              {
             y+=inc_dec;
             p+=two_dy_dx;
              }

           putpixel(x,y,color);
        }
      }

       else
      {
         int two_dx=(2*dx);
         int two_dx_dy=(2*(dx-dy));
         int p=((2*dx)-dy);

         int x=x1;
         int y=y1;

         putpixel(x,y,color);

         while(y!=y2)
        {
           y+=inc_dec;

           if(p<0)
              p+=two_dx;

           else
              {
             x++;
             p+=two_dx_dy;
              }

           putpixel(x,y,color);
        }
      }
    }

 /*************************************************************************///--------------------------  show_screen( )  ---------------------------///*************************************************************************/
 void show_screen( )
    {
        int count;
       //setfillstyle(1,1);
     bar(194,26,436,38);

       //settextstyle(0,0,1);
     setcolor(15);
       /*outtextxy(5,5,"******************************************************************************");
       outtextxy(5,17,"*-**************************************************************************-*");
       outtextxy(5,29,"*---------------------                                 ----------------------*");
       outtextxy(5,41,"*-**************************************************************************-*");
       outtextxy(5,53,"*-**************************************************************************-*");*/

     setcolor(11);
       outtextxy(200,29,"3D Reflection along zx-plane");

     setcolor(15);

       for(count=0;count<=30;count++)
          outtextxy(5,(65+(count*12)),"*-*                                                                        *-*");

       /*outtextxy(5,438,"*-**************************************************************************-*");
       outtextxy(5,450,"*-------------------------                          -------------------------*");
       outtextxy(5,462,"******************************************************************************");*/

     setcolor(12);
       outtextxy(229,450,"Press any Key to exit.");
    }

