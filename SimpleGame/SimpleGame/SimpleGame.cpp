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
#include "ScnMgr.h"

ScnMgr *g_ScnMgr = NULL;

void RenderScene(void){

	// Update
	g_ScnMgr->Update();

	// Render
	g_ScnMgr->RenderScene();

	glutSwapBuffers();
}

void Idle(void){
	RenderScene();
}

void MouseInput(int button, int state, int x, int y){
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y){
	/*if (key == 'w') {
		float x, y;
		g_TestObj->GetPos(&x, &y);
			y += 5;
		g_TestObj->SetPos(x, y);
	}
	if (key == 's') {
		float x, y;
		g_TestObj->GetPos(&x, &y);
			y -= 5;
		g_TestObj->SetPos(x, y);
	}
	if (key == 'a') {
		float x, y;
		g_TestObj->GetPos(&x, &y);
			x -= 5;
		g_TestObj->SetPos(x, y);
	}
	if (key == 'd') {
		float x, y;
		g_TestObj->GetPos(&x, &y);
			x += 5;
		g_TestObj->SetPos(x, y);
	}
*/
	RenderScene();

}

void SpecialKeyInput(int key, int x, int y){
	RenderScene();
}

int main(int argc, char **argv){

	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HEIGHT);

	glutCreateWindow("Game Software Engineering KPU");

	glewInit();

	if (glewIsSupported("GL_VERSION_3_0")){
		std::cout << " GLEW Version is 3.0\n ";
	}
	else{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	// Init ScnMgr
	g_ScnMgr = new ScnMgr();

	glutMainLoop();

	delete g_ScnMgr;

	return 0;

}