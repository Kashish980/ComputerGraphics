
//#include <stdafx.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;//to set the radius of the circle


 
void display()
{

    glMatrixMode(GL_MODELVIEW);//clears the identity matrix
    glClear(GL_COLOR_BUFFER_BIT);//clears the buffer drawing

    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0,0.0,-5.0);
    
    glColor3f(1.0, 0.0, 0); // Red color used to draw.
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    
    glRotatef(yRotated,0.0,1.0,0.0);// rotation about Y axis
    
    glRotatef(zRotated,0.0,0.0,1.0);// rotation about Z axis
    
    glScalef(1.0,1.0,1.0);// scaling transfomation 
    // NOTE: built-in (glut library) function , draw you a sphere.
    glutSolidSphere(radius,20,20);
    
     
    glFlush();  // This makes the drawing happen as soon as possible      
   
}

void init(int x, int y)
{
/*        GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
*/
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering

}
int main (int argc, char **argv)
{
    glutInit(&argc, argv); 
    glutInitWindowSize(500,500);
    glutCreateWindow("3D Sphere");
    xRotated = yRotated = zRotated = 30.0;
    //xRotated=43;
    //yRotated=50;
 
    glutDisplayFunc(display);
    glutReshapeFunc(init);
    glutMainLoop();
    return 0;
}
 
