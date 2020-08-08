//������Ҫʵ�ּ򵥵���������Ϸ�����������
#pragma once

#include "gl/GLAUX.H"
#include "gl/GLUT.H"

using namespace std;
#define	MAX_BUF_SIZE	(32)

//ʵ������λ�õĶ���
typedef struct Point {
	int x, y;
}Point_S;

//��ǰ������������ö��ѡ��
enum BoxDirect { 
	DIR_UP=0,//��
	DIR_DOWN,//��
	DIR_LEFT,//��
	DIR_RIGHT//��
};

//��ǰ����������״̬
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

//��ͼ���ݵ��������
public:
	//ʵ�ֵ�ͼ���ݵĶ�ȡ
	void initMap(const char *fileName);
private:
	//��ʼ�����ӵ����λ��
	bool initBox();
private:
	//1.�����ͼ������
	int m_row;//������
	int m_col;//������
	int m_boxNum;
	int m_currentState;

	//2.�洢��ͼ��Ϣ
	int Map[MAX_BUF_SIZE][MAX_BUF_SIZE];

	int m_reachBox;
private:
	//1.�������ӵ�λ��
	Point_S  m_boxPosition[100];
	//2.�����˵�λ��
	Point_S  m_peoplePosition;
private:

//������Ϣ���������
	//1.��ȡBMP��ʽ����
	AUX_RGBImageRec * initBmpData(const char * Filename);

public:
	//2.������������
	int		setTextures();
	GLvoid  setList();
	void    showGame();

private:
	GLuint	m_texture[3];
	GLuint	m_box, m_dest;	
	

//���ƴ����ӽ�
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


