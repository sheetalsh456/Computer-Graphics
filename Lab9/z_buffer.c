#include<graphics.h>
#include<stdio.h>

typedef struct point_s{
  int x, y;
  int depth; //higher the depth, closer to viewer is point
  int color;
} point_t;

void drawBox(point_t box[], int n){
  int i;
  for(i=0;i<n;i++)
    line(box[i].x, box[i].y, box[ (i+1)%n ].x, box[ (i+1)%n ].y);
}

void input(point_t box[], int d, int c){
  point_t top, bottom;
  printf("Enter the left-top co-ordinate of the background box : ");
  scanf("%d %d", &top.x, &top.y);
  printf("Enter the right-bottom co-ordinate of the background box : ");
  scanf("%d %d", &bottom.x, &bottom.y);
  box[0] = top; box[2] = bottom;
  box[1].x = bottom.x; box[1].y = top.y;
  box[3].x = top.x; box[3].y = bottom.y;
  int i;
  for(i=0;i<4;i++){
    box[i].depth = d;
    box[i].color = c;
  }
}

void input1(point_t box[], int d, int c){
  point_t top, bottom;
  printf("Enter the left-top co-ordinate of the foreground box : ");
  scanf("%d %d", &top.x, &top.y);
  printf("Enter the right-bottom co-ordinate of the foreground box : ");
  scanf("%d %d", &bottom.x, &bottom.y);
  box[0] = top; box[2] = bottom;
  box[1].x = bottom.x; box[1].y = top.y;
  box[3].x = top.x; box[3].y = bottom.y;
  int i;
  for(i=0;i<4;i++){
    box[i].depth = d;
    box[i].color = c;
  }
}

void update_buffer(int depth_buffer[640][480],int color_buffer[640][480], point_t box[4]){
  point_t top = box[0];
  point_t bottom = box[2];
  int i,j;
  int depth = box[0].depth;
  int color = box[0].color;

  for( i=top.x; i<bottom.x; i++ )
    for( j=top.y; j<bottom.y; j++ ){
      if( depth > depth_buffer[i][j] ){
        depth_buffer[i][j] = depth;
        color_buffer[i][j] = color;
      }
    }

}

void z_buffer(point_t box1[], point_t box2[]){

  int depth_buffer[640][480], color_buffer[640][480];
  int i,j;
  for(i=0; i<640; i++) for(j=0; j<480; j++){ depth_buffer[i][j] = 0; color_buffer[i][j] = BLACK;}

  update_buffer(depth_buffer, color_buffer, box1);
  update_buffer(depth_buffer, color_buffer, box2);

  for(i=0; i<640; i++)
    for(j=0; j<480; j++)
      putpixel(i,j, color_buffer[i][j]);

}

int main(int argc, char const *argv[]) {
  int gd=DETECT, gm;
  point_t box1[4], box2[4];
  input(box1, 1, YELLOW);
  input1(box2, 2, BROWN);
  initgraph(&gd, &gm, NULL);
  drawBox(box1, 4);
  drawBox(box2, 4);
  //delay(5000);
  getch();
  z_buffer(box1, box2);
  delay(5000);
  closegraph();
  return 0;
}
