#include <GL/glut.h>
void display()
{

	glBegin(GL_POLYGON);///�e�h���
        glColor3f(1,0,1); glVertex2f( 0, 1);///���IVertex
        glColor3f(0,1,1); glVertex2f(-1,-1);
        glColor3f(1,1,0); glVertex2f(+1,-1);
    glEnd();///�����e

    glColor3f(0,1,1);///�Ŧ�
	glutSolidTeapot( 0.3 );///���X�@�ӹ�ߪ�����,�����j�p0.3
	glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
int main(int argc, char *argv[])///�S�O��main()�禡,���ܦh�Ѽ�//138
{
	glutInit(&argc, argv);///��GLUT�}�_��//140
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	///��ܼҦ��]�w//143
	glutCreateWindow("GLUT Shapes");///�n�}����//145
	glutDisplayFunc(display);///�n��ܪ������禡//148
	glutMainLoop();///�̫��main�j��//174
}
