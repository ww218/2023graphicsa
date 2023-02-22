#include <GL/glut.h>
#include <math.h>
void myCircle(float r,float x,float y)
{
    glBegin(GL_POLYGON);///畫多邊形
    for(float a=0;a<2*3.141592653589793238462632383279;a+=0.01){
        glVertex2f( r*cos(a)+x, r*sin(a)+y);
    }

    glEnd();///結束畫
}
void display()
{
    glColor3f(0,1,1); myCircle(0.6,0,0);

	glColor3f(1,0,0); myCircle( 0.3, 0.5, 0.5);///右上角
	glColor3f(0,1,0); myCircle( 0.3,-0.5, 0.5);///左上角
	glColor3f(1,1,0); myCircle( 0.3,-0.5,-0.5);///左下角
	glColor3f(0,0,1); myCircle( 0.3, 0.5,-0.5);///右下角

	glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])///特別的main()函式,有很多參數//138
{
	glutInit(&argc, argv);///把GLUT開起來//140
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	///顯示模式設定//143
	glutCreateWindow("GLUT Shapes");///要開視窗//145
	glutDisplayFunc(display);///要顯示的對應函式//148
	glutMainLoop();///最後用main迴圈//174
}
