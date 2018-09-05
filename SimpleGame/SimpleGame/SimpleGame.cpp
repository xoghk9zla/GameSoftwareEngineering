/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"

Renderer *g_Renderer = NULL;

class Rect {
public:
	float x, y, z;
	float speed_x, speed_y, dir_x, dir_y;
	float size;

	Rect() {
		x = 0.0f, y = 0.0f, z = 0.0f;
		speed_x = 0.02f, speed_y = 0.03f;
		dir_x = 1, dir_y = 1;
		size = 40;
	};

};

Rect ob;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test

	/*
	ob.x += ob.dir_x * ob.speed_x, ob.y += ob.dir_y * ob.speed_y;

	if (ob.x > 230 || ob.x < -230)
		ob.dir_x *= -1;
	if (ob.y > 230 || ob.y < -230)
		ob.dir_y *= -1;
	*/

	g_Renderer->DrawSolidRect(ob.x, ob.y, ob.z, ob.size, 1, 0, 1, 1);

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	if (key == 'w') {
		if (ob.y < 230)
		ob.y += 5;
	}
	if (key == 's') {
		if (ob.y > -230)
		ob.y -= 5;
	}
	if (key == 'a') {
		if (ob.x > -230)
			ob.x -= 5;
	}
	if (key == 'd') {
		if (ob.x < 230)
			ob.x += 5;
	}

	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

    return 0;
}

