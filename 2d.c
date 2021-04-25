#include<math.h>
#include<stdio.h>
#include<GL/glut.h>
int numberOfPoints;
int count = 0;
float ox = 200, oy = 200;
float arr[20][2];

void drawPolygon(float (*arr)[2], int n, float R, float G, float B)
{
  glColor3f(R,G,B);
  glBegin(GL_LINE_LOOP);
  glLineWidth(10);
  int i;
  printf("\n Points that are marked are\n");
    for(i = 0; i < n; i++)
      { glVertex2f(arr[i][0],arr[i][1]);
      printf("%f %f", arr[i][0], arr[i][1]);
      printf("\n"); }
  glEnd();
  glFlush();
}
void transformation(float arr[][2], int n, float matrix[][3])
{
  int p,i,j,k;
  for(p = 0; p<n; p++){
    float tar[][1] = {{0},{0},{0}};
    float ar[][1] = {{arr[p][0]},{arr[p][1]},{1}};
    for(i=0;i<3;i++)
    {
        for(k=0;k<1;k++)
        {
            for(j=0;j<3;j++)
              tar[i][k] += matrix[i][j]*ar[j][k];
        }
    }
      arr[p][0] = tar[0][0];
      arr[p][1] = tar[1][0];
  }
  drawPolygon(arr,numberOfPoints, 1, 0, 0);
}


void mydisplay(void)
{ glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,0,1);
  printf("\n 2D Transformations:\n");
  while(count==-1){
    printf("\n1. Translation");
    printf("\n2. Rotation");
    printf("\n3. Scaling");
    printf("\n4. Reflection");
    printf("\n5. Shear");
    printf("\n6. Exit");
    printf("\nEnter choice:");
    int ans;
    scanf("%d",&ans);
    switch(ans)
    {
      case 1:
        {
          float tx,ty;
          printf("\nEnter value of tx and ty respectively:");
          scanf("%f %f", &tx,&ty);
          float matrix[][3] = {{1,0,tx},{0,1,ty},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
        }
        break;
      case 2:
        {
          printf("\n1.Rotation about origin");
          printf("\n2.Rotation about any arbitrary point");
          printf("\nEnter choice:");
          int choice2;
          scanf("%d",&choice2);
          float x = 1, y = 1;
          if(choice2==1)
 {
          float theta;
          printf("\nEnter value of angle in degrees in anticlockwise:");
          scanf("%f", &theta);
          theta *= (3.1415926/180);//converting degree into radians
          float sine = sin(theta);
          float cosine = cos(theta);
          printf("\n%f %f",sine,cosine);
          float matrix[][3] = {{cosine,-sine,0},{sine,cosine,0},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
  }
 else if (choice2==2)
 {
float theta,tx,ty;
printf("\n2. Enter the arbitrary point (x,y)= ");
scanf("%f%f",&tx,&ty);
          printf("\nEnter value of angle in degrees in anticlockwise:");
          scanf("%f", &theta);
          theta *= (3.1415926/180);//radians
          float sine = sin(theta);
          float cosine = cos(theta);
          printf("\n%f %f",sine,cosine);
          float matrix[][3] = {{cosine,-sine,(-tx*cosine+ty*sine)},{-sine,cosine,(tx*sine-ty*cosine+ty)},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
 }
        }
        break;
      case 3:
        {
          float sx,sy;
          printf("\nEnter value of sx and sy respectively:");
          scanf("%f %f", &sx,&sy);
          float matrix[][3] = {{sx,0,0},{0,sy,0},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
        }
        break;
      case 4:
        {
          printf("\n1. Reflection about X-axis");
          printf("\n2. Reflection about Y-axis");
 printf("\n3. Reflection about y=x");
 printf("\n4. Reflection about y=-x");
 printf("\n5. Reflection about ORIGIN");
 printf("\n6. Reflection about y=mx+c");
          printf("\nEnter choice:");
          int choice2;
          scanf("%d",&choice2);
          float x = 1, y = 1;
          if(choice2==1)
 {
float matrix[][3] = {{1,0,0},{0,-1,0},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
 }
          else if(choice2==2)
          {
  float matrix[][3] = {{-1,0,0},{0,1,0},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
 }
 else if(choice2==3)
          {
  float matrix[][3] = {{0,1,0},{1,0,0},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
 }
   else if(choice2==4)
          {
  float matrix[][3] = {{0,-1,0},{-1,0,0},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
 }
 else if(choice2==5)
          {
float matrix[][3] = {{-1,0,0},{0,-1,0},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
 }
 else if(choice2==6)
          {
  float m,c;
printf("\nEnter the value of slope of line");
scanf("%f",&m);
printf("\nEnter the value of Y-intercept of the line");
scanf("%f",&c);
  float matrix[][3] = {{((1-m*m)/(1+m*m)),(-2*m/(1+m*m)),(-2*m*c)/(1+m*m)},{(-2*m/(1+m*m)),((m*m-1)/(1+m*m)),(-2*c)/(1+m*m)},{0,0,1}};          
 }
          else
 {
            printf("\nWrong Input");
            break;
          }
        }
        break;
      case 5:
        {
          float a,b;
          printf("\nEnter value of a(shear in X-axis) and b(shear in Y-axis): ");
          scanf("%f %f", &a,&b);
          float matrix[][3] = {{1,a,0},{b,1,0},{0,0,1}};
          transformation(arr,numberOfPoints,matrix);
        }
        break;
      case 6:
exit(1);
break;
      default:
        printf("\nWrong Input");
    }
  }
  glEnd();
  glFlush();
}
void mousePlotPoint(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
  GLint wh=400;
  int x=xMouse-ox;
  int y=wh-yMouse-oy;
  if(button == GLUT_RIGHT_BUTTON && action == GLUT_UP && count != -1)
  {
    if(count == 0)
      printf("Start Plotting");
      count++;
      printf("\nPoint marked ");
      arr[count-1][0] = x;
      arr[count-1][1] = y;
  }
  else if(button == GLUT_LEFT_BUTTON && action == GLUT_UP && count != -1){
    count++;
    printf("\nFinal point marked");
    arr[count-1][0] = x;
    arr[count-1][1] = y;
    numberOfPoints = count;
    drawPolygon(arr,numberOfPoints, 1, 0, 0);
    count = -1;
    mydisplay();
  }
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(400,400);
  glutCreateWindow("Expt 8");
  glClearColor(1.0,1.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-200,200,-200,200.0);
  glutDisplayFunc(mydisplay);
  glutMouseFunc(mousePlotPoint);
  glutMainLoop();
  return 0;
}
	

