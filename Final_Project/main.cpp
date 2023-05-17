#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"///week13-1
GLMmodel * head =NULL;///week13-1
GLMmodel * uparmR =NULL;///week13-1
GLMmodel * lowarmR =NULL;///week13-1
GLMmodel * body =NULL;///week13-1
int show[4]={1,1,1,1};///week13-3
int ID = 0;///week14 3-1 //0�Y 1���� 2�W���u 3�U���u
void keyboard(unsigned char key,int x, int y){///week13-3
    if(key=='0') ID = 0;///week14 3-1
    if(key=='1') ID = 1;///week14 3-1
    if(key=='2') ID = 2;///week14 3-1
    if(key=='3') ID = 3;///week14 3-1
    ///if(key=='0') show[0] = !show[0];
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}///��Ӫ�keyboard������
FILE * fout=NULL;///step2-2
FILE * fin =NULL;///2
float teapotX=0,teapotY=0;
float angle=0,angle2=0,angle3=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);///week13-2
        if(body==NULL){///week13-1
            head = glmReadOBJ("model/head.obj");///week13-2
            body = glmReadOBJ("model/body.obj");///week13-1
            uparmR = glmReadOBJ("model/uparmR.obj");///week13-3
            lowarmR = glmReadOBJ("model/lowarmR.obj");///week13-3
            ///glmUnitize(body);///week13-1
        }
        if(ID==0)glColor3f(1,0,0);///week14 3-1
        else glColor3f(1,1,1);///week14 3-1
        if(show[0]) glmDraw(body, GLM_MATERIAL);///week13-1

        if(ID==1)glColor3f(1,0,0);///week14 3-1
        else glColor3f(1,1,1);///week14 3-1
        if(show[1]) glmDraw(head, GLM_MATERIAL);///week13-2

        glPushMatrix();///week13-4
            glTranslatef(teapotX,teapotY,0);///week13-4

            if(ID==2)glColor3f(1,0,0);///week14 3-1
            else glColor3f(1,1,1);///week14 3-1
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///week13-3
        glPopMatrix();///week13-4

        if(ID==3)glColor3f(1,0,0);///week14 3-1
        else glColor3f(1,1,1);///week14 3-1
        if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///week13-3
    glPopMatrix();
    glutSwapBuffers();
}
int oldX=0,oldY=0;///week13-4
void motion (int x,int y){///week13-4
    teapotX += (x-oldX)/150.0;
    teapotY-= (y-oldY)/150.0;
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f,%f,0);\n",teapotX,teapotY);
    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN){
        oldX = x;///week13-4teapotX = (x-150)/150.0;
        oldY = y;///week13-4teapotY = (150-y)/150.0;
        angle =x;///week13-4
        ///if(fout==NULL)fout =fopen("file4.txt","w");week12
        ///fprintf(fout,"%f %f\n",teapotX,teapotY);
    }
    display();
}
//void keyboard(unsigned char key ,int x,int y)///2keyboard�禡
//{
//    if(fin==NULL){///2�p�G�ɮ��٨Sfopen(),�N�}�L
//        fclose(fout);///2�e����mouse�|�}fout ����,�ҥH�n����
//        fin = fopen("file4.txt","r");///2�}��
//    }
//    fscanf(fin,"%f %f",&teapotX,&teapotY);///2Ū��
//    display();///2���e�e��
//}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week13");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);///week13-4
	glutKeyboardFunc(keyboard);///2keboard�n���ƤF

    glutMainLoop();
}
