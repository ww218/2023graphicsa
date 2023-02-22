 #include <GL/glut.h>

void display()

{
    glColor3f(247/255.0,247/255.0,247/255.0);///背景顏色
	glBegin(GL_POLYGON);
        glVertex2f( 1, 1);
        glVertex2f(-1, 1);
        glVertex2f(-1,-1);
        glVertex2f( 1,-1);
    glEnd();

    glColor3f(a/255.0,209/255.0,33/255.0);///皮卡丘顏色
	glBegin(GL_POLYGON);
        glVertex2f((45-100)/100.0, -(134-100)/100.0);
        glVertex2f((36-100)/100.0, -(171-100)/100.0);
        glVertex2f((108-100)/100.0, -(179-100)/100.0);
        glVertex2f((104-100)/100.0, -(117-100)/100.0);
        ///減一半,除一半,Y便負號
    glEnd();

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
