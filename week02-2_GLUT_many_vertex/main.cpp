 #include <GL/glut.h>

void display()

{
    glColor3f(247/255.0,247/255.0,247/255.0);///�I���C��
	glBegin(GL_POLYGON);
        glVertex2f( 1, 1);
        glVertex2f(-1, 1);
        glVertex2f(-1,-1);
        glVertex2f( 1,-1);
    glEnd();

    glColor3f(a/255.0,209/255.0,33/255.0);///�֥d�C�C��
	glBegin(GL_POLYGON);
        glVertex2f((45-100)/100.0, -(134-100)/100.0);
        glVertex2f((36-100)/100.0, -(171-100)/100.0);
        glVertex2f((108-100)/100.0, -(179-100)/100.0);
        glVertex2f((104-100)/100.0, -(117-100)/100.0);
        ///��@�b,���@�b,Y�K�t��
    glEnd();

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
