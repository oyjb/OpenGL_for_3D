//
// main.cpp
// TInyCS
//
// 在下面的代码还不能通过编译，因为有一个东西是我们需要继续讨论的Viewport::init()
// 我们知道，在OpenGL中需要注册display回调，所以我们还需要实现这部分的代码
// 在实现这部分代码之前，先要考虑一下类的设计
#include <iostream>
#include "Common.h"
#include "Viewport.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const char *WINDOW_TITLE = "Shi yan lou TIny CS";

int main(int argc, char *argv[])
{
	// init GLUT and OpenGL
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	// Create OpenGL
	glutCreateWindow(WINDOW_TITLE);

	// Create ViewPort
	Viewport::init();

	// Enter main loop
	glutMainLoop();

	return 0;
}
