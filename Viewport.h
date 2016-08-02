//
// Viewport.h
// 

#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Common.h"

class Viewport {
public:
	// 鼠标指针是否显示
	static bool grabbed;

	// 视角宽度
	static int width;

	// 视角高度
	static int height;

	// 基本的初始化
	static void init();

	static void reshape(int w, int h);

	// 负责显示
	static void display();

	// 设置鼠标指针是否显示
	static void setGrabbed(bool value);
};

#endif /* Viewport.h */