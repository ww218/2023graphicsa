#include <GL/glut.h>
float angle =0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslated(0.6,0,0);///先移動再旋轉
        glRotatef( angle,0,1,0);///自轉
        glColor3f(1,1,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glPushMatrix();
        glRotatef( angle,0,1,0);///先旋轉再移動
        glTranslated(0.6,0,0);///公轉
        glColor3f(1,0,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

	glutSwapBuffers();
	angle++;
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week04");

	glutDisplayFunc(display);
	glutIdleFunc(display);
    glutMainLoop();
}
