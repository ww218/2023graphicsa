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
void timer(int t)///1-1 你的timer函式,做對應動作
{
    if(t<100)glutTimerFunc(50,timer,t+1);///1-1///2-1在100之內,設定下一個鬧鐘
    float alpha =t/100.0;///2-1 alpha介於0.00~1.00之間
    angle = newAngle*alpha + (1-alpha)*oldAngle;///2-1內插公式
    glutPostRedisplay();///1-1重畫畫面
}
void motion(int x,int y)///2-1
{
    angle = x;///即時更新角度
    glutPostRedisplay();///重畫畫面
}
void mouse(int botton,int state,int x,int y)///2-1
{
    if(state==GLUT_DOWN) oldAngle=x;///按下去
    if(state==GLUT_UP) newAngle=x;///放開來
}
void keyboard(unsigned char key ,int x, int y)///1-2按下任何鍵開始播放
{
    glutTimerFunc(0,timer,0);
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week14");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);///2-1按下去,表示起點
	glutMotionFunc(motion);///2-1當mouse在motion時,即時更新畫面
	glutKeyboardFunc(keyboard);///1-2用keyboard()
    glutMainLoop();
}

