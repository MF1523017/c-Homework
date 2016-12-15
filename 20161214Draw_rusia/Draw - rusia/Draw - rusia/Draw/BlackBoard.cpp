#include "stdafx.h"

#include <math.h>
#include <iostream>

#include "GL/glut.h"

#include "BlackBoard.h"
#include<windows.h>

using std::cout;
using std::endl; 

void BlackBoard::InitCommandLine(int *argc, char **argv)
{
	glutInit(argc, argv); 
	base = 0;
	//BuildFont();
	
}

void BlackBoard::InitWindowSize(int width, int height) 
{ 
	_width = width; 
	_height = height; 

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(_width, _height);
	glutCreateWindow("BlackBoard");
	
}

void BlackBoard::UpdateWindowSize(int width, int height)
{
	_width = width;
	_height = height; 

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


void BlackBoard::InitDisplayCallback(CallbackFunction callback) 
{ 
	glutDisplayFunc(callback);
} 

void BlackBoard::InitKeyboardCallback(KeyboardFunction callback) 
{ 
	glutKeyboardFunc(callback);
} 

void BlackBoard::InitReshapeCallback(ReshapeFunction callback)
{
	glutReshapeFunc(callback); 
}

void BlackBoard::InitMouseButtonCallback(MouseButtonFunction callback)
{
	glutMouseFunc(callback);
}

void BlackBoard::InitMouseMotionCallback(MouseMotionFunction callback)
{
	glutMotionFunc(callback);
}

void BlackBoard::InitIdleCallback(IdleFunction callback)
{
	glutIdleFunc(callback);
}

void BlackBoard::InstallTimerCallback(unsigned int millis, TimerFunction callback, int value)
{
	glutTimerFunc(millis, callback, value);
}

void BlackBoard::Show()
{
	glutMainLoop();
}

void BlackBoard::SetColor(double r, double g, double b)
{
	glColor3f(r, g, b);
}

void BlackBoard::Update()
{
	glutPostRedisplay();
}

void BlackBoard::DrawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glVertex2f(GLfloat(x1) / _width * 2, GLfloat(y1) / _height * 2);
	glVertex2f(GLfloat(x2) / _width * 2, GLfloat(y2) / _height * 2);
	glEnd();
}


void BlackBoard::DrawCircle(int x, int y, int r)
{
	const int CIRCLE_SEGMENTATION = 360; 
	const GLfloat Pi = 3.1415926536f;

	GLfloat x0 = GLfloat(x) / _width * 2;
	GLfloat y0 = GLfloat(y) / _height * 2;

	glBegin(GL_LINE_LOOP);
	for(int i = 0; i < CIRCLE_SEGMENTATION; ++i)
	{
		glVertex2f(x0 + GLfloat(r) * cos(2 * Pi * i / CIRCLE_SEGMENTATION) / _width * 2, y0 + GLfloat(r) * sin(2 * Pi * i / CIRCLE_SEGMENTATION) / _height * 2);
	}
	glEnd();
}

void BlackBoard::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);   
}

void BlackBoard::Flush()
{
	glFlush();
}

//void BlackBoard::BuildFont()
//{
//	HFONT font;		// 字体句柄
//	HFONT oldfont;
//
//	base = glGenLists(256);		// 创建96个显示列表
//	font = CreateFont(-24,		// 字体高度
//		0,		// 字体宽度
//		0,		// 字体的旋转角度
//		0,		// 字体底线的旋转角度
//		FW_BOLD,// 字体重量
//		FALSE,	// 是否使用斜体
//		FALSE,	// 是否使用下划线
//		FALSE,	// 是否使用删除线
//		ANSI_CHARSET,	// 设置字符集
//		OUT_TT_PRECIS,	// 输出精度
//		CLIP_DEFAULT_PRECIS,	// 剪裁精度
//		ANTIALIASED_QUALITY,	// 输出质量
//		FF_DONTCARE | DEFAULT_PITCH,
//		"Courier New");	// 字体名称
//	oldfont = (HFONT)SelectObject(wglGetCurrentDC(), font);	// 选择我们需要的字体
//	wglUseFontBitmaps(wglGetCurrentDC(), 0, 256, base);		// 创建96个显示列表，绘制从ASCII码为32-128的字符
//	SelectObject(wglGetCurrentDC(), oldfont);
//	DeleteObject(font);
//}
//void BlackBoard::glPrint(const char *pstr)
//{
//	glPushAttrib(GL_LIST_BIT);	// 把显示列表属性压入属性堆栈
//	glListBase(base - 0);		// 设置显示列表的基础值
//	glCallLists(strlen(pstr), GL_UNSIGNED_BYTE, pstr);	// 调用显示列表绘制字符串
//	glPopAttrib();				// 弹出属性堆栈
//}
//void BlackBoard::DrawString()
//{
//	glTranslatef(0.0f, 0.0f, -1.0f);
//	glColor3f(0.0f, 1.0f, 0.0f); // 颜色
//	glRasterPos2f(0.0f, 0.00f); // 输出位置
//	glPrint("Active OpenGL Text With NeHe - %7.2f");  // 输出文字到屏幕
//	glutSwapBuffers();
//}
//
//
