#include <GL/glut.h>
#include <stdio.h>
float X=0 ,Y=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    glPushMatrix();
        glTranslatef( X, Y,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glBegin(GL_POLYGON);
    glVertex2f(-0.504, -0.684);
    glVertex2f(-0.652, -0.524);
    glVertex2f(-0.700, -0.356);
    glVertex2f(-0.564, -0.272);
    glVertex2f(-0.452, -0.280);
    glVertex2f(-0.176, -0.320);
    glVertex2f(-0.144, -0.464);
    glVertex2f(-0.160, -0.576);
    glVertex2f(-0.268, -0.644);
    glVertex2f(-0.352, -0.672);
    glVertex2f(-0.504, -0.684);
    glEnd();
	glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    float X=(x-250)/250.0;
    float Y=-(y-250)/250.0;
    if(state==GLUT_DOWN){///按下mouse時,才印出,避免有兩行一樣
        printf("    glVertex2f(%.3f, %.3f);\n",X,Y);
    }
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("week03");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);///用mouse
    glutMainLoop();
}
