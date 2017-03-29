#include<graphics.h>
#include<stdio.h>

typedef struct p{
  double x,y;
}p;

p mkpt(double x, double y){
  p p1;
  p1.x = x;
  p1.y = y;
  return p1;
}

p m(double t, p p1){
  p1.x *= t;
  p1.y *= t;
  return p1;
}

p a(p a, p b){
  p c = mkpt(a.x + b.x, a.y + b.y);
  return c;
}

p bezier(double t, int i, int j, p p1[], int n){
  if(i==j)
    return p1[i];

  p t1, t2, t3, t4, ans;
  t1 = bezier(t, i, j-1, p1, n);
  t2 = bezier(t, i+1, j, p1, n);
  t3 = m(1-t, t1);
  t4 = m(t, t2);
  ans = a(t3, t4);
  return ans;
}

int main(){
  int n, i,j;
  p pd[100];
  printf("Enter the number of control points - ");
  scanf("%d", &n);
  printf("Enter the points: \n");
  for(i=0; i<n; i++){
    scanf("%lf %lf", &pd[i].x, &pd[i].y);
  }
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  double t = 0;
  for(t=0.0; t<1.0; t+= 0.001){
    p p1 = bezier(t, 0, n-1, pd, n);
    putpixel( p1.x, p1.y, 11);
  }

  delay(5000);
  closegraph();
  return 0;

}
