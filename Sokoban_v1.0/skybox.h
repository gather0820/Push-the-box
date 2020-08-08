//本类主要实现简单的天空盒的功能

#include "gl/GLAUX.H"
#include "gl/GLUT.H"
#include <windows.h>
#include <stdio.h>
#include "gl/GL.H"
#include "gl/GLU.H"
#include "math.h"

//最大纹理索引
#define MAX_TEXTURE_NUM	(10)

#pragma once
class skybox
{
public:
	skybox();
	~skybox();
	
//外部接口实现实时渲染
public:
	void renderSkyBox();
	int setTextures(const char *Filename);
private:

//纹理信息的相关设置
	//读取BMP格式数据
	AUX_RGBImageRec * initBmpData(const char * Filename);

//相关变量的初始化
private:
	//存储纹理索引
	GLuint	 m_texture[MAX_TEXTURE_NUM];
	//创建显示列表
	int		 m_listnum;
};

