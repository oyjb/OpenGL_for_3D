//
// Viewport.cpp
// TinyCS
// 

#include "Viewport.h"

int Viewport::width = 0;
int Viewport::height = 0;

bool Viewport::grabbed = false;

void Viewport::init()
{
	// 设置 GLUT 回调函数
	glutReshapeFunc(Viewport::reshape);
	glutDisplayFunc(Viewport::display);
	glutIdleFunc(Viewport::display);

	// 启用深度测试，根据坐标的远近自动隐藏被遮住的图形
	glEnable(GL_DEPTH_TEST);

	// 启用二维纹理
	glEnable(GL_TEXTURE_2D);

	// 配置鼠标是否直接被OpenGL全局捕获并显示
	grabbed ? Viewport::setGrabbed(true) : Viewport::setGrabbed(false);
}

void Viewport::setGrabbed(bool value)
{
	grabbed = value ? true : false;

	if (grabbed) {
		// 设置当前窗口的光标样式，现在为禁用光标
		glutSetCursor(GLUT_CURSOR_NONE);
	}
	else {
		// 继承系统光标
		glutSetCursor(GLUT_CURSOR_INHERIT);
	}
}

// 处理当窗口长度发生变化时候的渲染
void Viewport::reshape(int w, int h)
{
	width = w;
	height = h;
	if (h <= 0) h = 1;
	// 计算长宽比
	float ratio = (float) w / h;

	// 在视图进行调整时，要切换矩阵模式
	glMatrixMode(GL_PROJECTION);

	//将 PROJECTION 矩阵加载为单位阵
	glLoadIdentity();
	glViewport(0, 0, w, h);

	// 适当调整透视角
	gluPerspective(45, ratio, 0.01, 1000);

	// 切回 GL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
}

void Viewport::display()
{
	// 清空当前 Viewport 中的缓冲
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 重置为单位矩阵
	glLoadIdentity();

	// 绘制一个三角形
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-1.0, 0.0, -3.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 2.0, -3.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(1.0, 0.0, -3.0);
	glEnd();
	// 将缓冲区的图像交换给显卡进行渲染
	// 我们在 Main.cpp 中注册了显示 GLUT_DOUBLE 双缓冲显示模式
	glutSwapBuffers();
}
