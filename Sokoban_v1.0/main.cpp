#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include "gl/GL.H"
#include "gl/GLU.H"
#include "gl/GLUT.H"
#include  "gl/GLAUX.H"
#include  "math.h"

#include "sokoban.h"
#include "skybox.h"

sokoban m_sokoban;
skybox  m_skyBox;

#define PI 3.141592
float mov;
float x_pos = 0, y_pos = 0, z_pos = -20;
float x_view = 0, y_view = 0, z_view = 0;
float theta = 0, angle;
GLfloat fog_density = 0.005;


//设置雾化的颜色
GLfloat fogColor[4] = { 0.90f, 0.70f, 0.0f, 1.0f };


//实现渲染效果的显示
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFogf(GL_FOG_DENSITY, fog_density);
	m_sokoban.showGame();
	m_skyBox.renderSkyBox();

	glutSwapBuffers();
}

//定时器刷新实现
void dilution(int value)
{
	if (fog_density>0)
	{
		fog_density -= 0.00007;
		glutPostRedisplay();
		glutTimerFunc(100, dilution, 0);
	}
}

//初始化相关的类效果
void init(void)
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);

	//1.0设置天空盒相关初始化
	m_skyBox.setTextures("Data/Front.bmp");
	m_skyBox.setTextures("Data/Right.bmp");
	m_skyBox.setTextures("Data/Left.bmp");
	m_skyBox.setTextures("Data/Top.bmp");
	m_skyBox.setTextures("Data/Bottom.bmp");
	m_skyBox.setTextures("Data/Back.bmp");

	//2.初始化推箱子相关数据初始化
	if (!m_sokoban.setTextures())
	{
		printf("LoadGLTextures()");
		return;
	}
	//地图
	m_sokoban.initMap("Data/map.txt");
	//箱子
	m_sokoban.setList();

	//3.设置雾化效果
	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, fog_density);
	glHint(GL_FOG_HINT, GL_NICEST);
	glFogf(GL_FOG_START, 100.0);
	glFogf(GL_FOG_END, -100.0);
	glEnable(GL_FOG);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	//4.播放音乐
	PlaySound("Data/skyCity.wav", NULL, SND_ASYNC| SND_LOOP);
}

void myReshape(int w, int h)
{
	//窗口移动
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, float(w) / float(h), 1, 9999);//视角大小，窗口的比例，近点，远点
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case  'w':
		if (m_sokoban.isMoveOver(DIR_UP))
		{
			m_sokoban.moveUP();
		}
		break;
	case  'a':
		if (m_sokoban.isMoveOver(DIR_LEFT))
		{
			m_sokoban.moveLeft();
		}
		break;
	case  'd':
		if (m_sokoban.isMoveOver(DIR_RIGHT))
		{
			m_sokoban.moveRight();
		}
		break;
	case  's':
		if (m_sokoban.isMoveOver(DIR_DOWN))
		{
			m_sokoban.moveDown();
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void special_func(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		x_view += 2.0f;
		m_sokoban.setX(x_view);
		break;
	case GLUT_KEY_DOWN:
		x_view -= 2.0f;
		m_sokoban.setX(x_view);
		break;
	case GLUT_KEY_LEFT:
		y_view += 1.0f;
		m_sokoban.setY(y_view);
		break;
	case GLUT_KEY_RIGHT: 
		y_view -= 1.0f;
		m_sokoban.setY(y_view);
		break;
	case GLUT_KEY_PAGE_UP:
		z_view += 2.0f;
		m_sokoban.setZ(z_view);
		break;
	case GLUT_KEY_PAGE_DOWN:
		z_view -= 2.0f;
		m_sokoban.setZ(z_view);
		break;
	case GLUT_KEY_END:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);//创建窗口的时候，指定其显示模式的类型
 
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100); 
	glutCreateWindow("Sokoban");
	 
	init();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special_func);
	glutTimerFunc(100, dilution, 0);
	glutMainLoop();
	return 0;
}

