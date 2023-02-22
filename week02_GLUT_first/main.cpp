#include <GL/glut.h>
void display()
{

	glBegin(GL_POLYGON);///畫多邊形
        glColor3f(1,0,1); glVertex2f( 0, 1);///頂點Vertex
        glColor3f(0,1,1); glVertex2f(-1,-1);
        glColor3f(1,1,0); glVertex2f(+1,-1);
    glEnd();///結束畫

    glColor3f(0,1,1);///藍色
	glutSolidTeapot( 0.3 );///劃出一個實心的茶壺,它的大小0.3
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
