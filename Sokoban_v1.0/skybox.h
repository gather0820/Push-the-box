//������Ҫʵ�ּ򵥵���պеĹ���

#include "gl/GLAUX.H"
#include "gl/GLUT.H"
#include <windows.h>
#include <stdio.h>
#include "gl/GL.H"
#include "gl/GLU.H"
#include "math.h"

//�����������
#define MAX_TEXTURE_NUM	(10)

#pragma once
class skybox
{
public:
	skybox();
	~skybox();
	
//�ⲿ�ӿ�ʵ��ʵʱ��Ⱦ
public:
	void renderSkyBox();
	int setTextures(const char *Filename);
private:

//������Ϣ���������
	//��ȡBMP��ʽ����
	AUX_RGBImageRec * initBmpData(const char * Filename);

//��ر����ĳ�ʼ��
private:
	//�洢��������
	GLuint	 m_texture[MAX_TEXTURE_NUM];
	//������ʾ�б�
	int		 m_listnum;
};

