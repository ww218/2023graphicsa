///week14-3_timer_alpha_interpolation
#include <GL/glut.h>
float angle =0,oldAngle=0,newAngle=0;///2-1
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
	glutSwapBuffers();

}
void timer(int t)///1-1 �A��timer�禡,�������ʧ@
{
    if(t<100)glutTimerFunc(50,timer,t+1);///1-1///2-1�b100����,�]�w�U�@�Ӿx��
    float alpha =t/100.0;///2-1 alpha����0.00~1.00����
    angle = newAngle*alpha + (1-alpha)*oldAngle;///2-1��������
    glutPostRedisplay();///1-1���e�e��
}
void motion(int x,int y)///2-1
{
    angle = x;///�Y�ɧ�s����
    glutPostRedisplay();///���e�e��
}
void mouse(int botton,int state,int x,int y)///2-1
{
    if(state==GLUT_DOWN) oldAngle=x;///���U�h
    if(state==GLUT_UP) newAngle=x;///��}��
}
void keyboard(unsigned char key ,int x, int y)///1-2���U������}�l����
{
    glutTimerFunc(0,timer,0);
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week14");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);///2-1���U�h,��ܰ_�I
	glutMotionFunc(motion);///2-1��mouse�bmotion��,�Y�ɧ�s�e��
	glutKeyboardFunc(keyboard);///1-2��keyboard()
    glutMainLoop();
}

