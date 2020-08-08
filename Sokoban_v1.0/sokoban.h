//本类主要实现简单的推箱子游戏的类相关声明
#pragma once

#include "gl/GLAUX.H"
#include "gl/GLUT.H"

using namespace std;
#define	MAX_BUF_SIZE	(32)

//实现坐标位置的定义
typedef struct Point {
	int x, y;
}Point_S;

//当前键盘所操作的枚举选项
enum BoxDirect { 
	DIR_UP=0,//上
	DIR_DOWN,//下
	DIR_LEFT,//左
	DIR_RIGHT//右
};

//当前箱子所处的状态
enum BoxMap { 
	MAP_NONE,
	MAP_WALL,
	MAP_DEST
};

class sokoban
{
public:
	sokoban();
	~sokoban();

//地图数据的相关设置
public:
	//实现地图数据的读取
	void initMap(const char *fileName);
private:
	//初始化箱子到达的位置
	bool initBox();
private:
	//1.定义地图的数量
	int m_row;//行坐标
	int m_col;//列坐标
	int m_boxNum;
	int m_currentState;

	//2.存储地图信息
	int Map[MAX_BUF_SIZE][MAX_BUF_SIZE];

	int m_reachBox;
private:
	//1.定义箱子的位置
	Point_S  m_boxPosition[100];
	//2.定义人的位置
	Point_S  m_peoplePosition;
private:

//纹理信息的相关设置
	//1.读取BMP格式数据
	AUX_RGBImageRec * initBmpData(const char * Filename);

public:
	//2.设置纹理数据
	int		setTextures();
	GLvoid  setList();
	void    showGame();

private:
	GLuint	m_texture[3];
	GLuint	m_box, m_dest;	
	

//控制窗口视角
public:
	bool moveDown(void);
	bool moveUP(void);
	BOOL moveLeft(void);
	BOOL moveRight(void);
	void setX(GLfloat x);
	void setY(GLfloat y);
	void setZ(GLfloat z);
	BOOL isMoveOver(int Direct);
private:
	bool isBox(int i, int j);
	
	Point_S* GetBoxPosition(int i, int j);
private:
	GLfloat m_x;
	GLfloat m_y;
	GLfloat m_z;
	GLfloat zoom;

	GLfloat xpos;
	GLfloat ypos;
};


