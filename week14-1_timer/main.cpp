///week14-1
#include <GL/glut.h>
float angle =0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
	glutSwapBuffers();

}
void timer(int t)///1-1 你的timer函式,做對應動作
{
    glutTimerFunc(500,timer,t+1);///1-1
    angle += 90;///1-1增加90度
    glutPostRedisplay();///1-1重畫畫面
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week14");

	glutDisplayFunc(display);
	glutTimerFunc(2000,timer,0);///1-1設定timer函式
    glutMainLoop();
}
