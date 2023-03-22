#include <GL/glut.h>
float angle =0;
void drawHand()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);///跑よ遏
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///も羥
        glTranslatef(0.25,0,0);///本
        glRotatef(angle,0,0,1);
        glTranslatef(0.25,0,0);
        drawHand();///礶も
        glPushMatrix();
            glTranslatef(0.25,0,0);///本
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            drawHand();///礶も
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///オも羥
        glTranslatef(-0.25,0,0);///本
        glRotatef(angle,0,0,1);
        glTranslatef(-0.25,0,0);
        drawHand();///礶も
        glPushMatrix();
            glTranslatef(-0.25,0,0);///本
            glRotatef(angle,0,0,1);
            glTranslatef(-0.25,0,0);
            drawHand();///礶も
        glPopMatrix();
    glPopMatrix();

	glutSwapBuffers();
	angle++;
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week06");

	glutDisplayFunc(display);
	glutIdleFunc(display);
    glutMainLoop();
}
