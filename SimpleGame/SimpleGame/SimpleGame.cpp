/*

Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.

*/

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "Global.h"
#include "ScnMgr.h"

ScnMgr *g_ScnMgr = NULL;

DWORD g_PrevTime = 0;

BOOL g_KeyW = FALSE;
BOOL g_KeyA = FALSE;
BOOL g_KeyS = FALSE;	
BOOL g_KeyD = FALSE;

int g_Shoot = SHOOT_NONE;

void RenderScene(void){

	// 키입력 테스트
	std::cout << "w: " << g_KeyW << ", a: " << g_KeyA << ", s: " << g_KeyS << ", d: " << g_KeyD << std::endl;

	// Calc Elapsed Time
	if (g_PrevTime == 0) {
		g_PrevTime = GetTickCount();
		return;
	}
	DWORD CurTime = GetTickCount();
	DWORD ElapsedTime = CurTime - g_PrevTime;
	g_PrevTime = CurTime;
	float eTime = (float)ElapsedTime / 1000.0f;
	if (eTime <= 0) {
		eTime = 0.015f;
	}
	 //std::cout << eTime << std::endl;
	
	// Apply Force
	float forceX = 0.0f;
	float forceY = 0.0f;

	if (g_KeyW) {
		forceY += 1.0f;
	}
	if (g_KeyS) {
		forceY -= 1.0f;
	}
	if (g_KeyA) {
		forceX -= 1.0f;
	}
	if (g_KeyD) {
		forceX += 1.0f;
	}

	g_ScnMgr->ApplyForce(forceX, forceY, eTime);


	// Update
	g_ScnMgr->Update(eTime);

	// Render
	g_ScnMgr->RenderScene();

	g_ScnMgr->Shoot(g_Shoot);

	glutSwapBuffers();
}

void Idle(void){
	RenderScene(); 
}

void MouseInput(int button, int state, int x, int y){
	RenderScene();
}

void KeyDownInput(unsigned char key, int x, int y){
	if (key == 'w') {
		g_KeyW = TRUE;
	}
	if (key == 's') {
		g_KeyS = TRUE;
	}
	if (key == 'a') {
		g_KeyA = TRUE;
	}
	if (key == 'd') {
		g_KeyD = TRUE;
	}
}

void KeyUpInput(unsigned char key, int x, int y) {
	if (key == 'w') {
		g_KeyW = FALSE;
	}
	if (key == 's') {
		g_KeyS = FALSE;
	}
	if (key == 'a') {
		g_KeyA = FALSE;
	}
	if (key == 'd') {
		g_KeyD = FALSE;
	}
}

void SetKeyRepeat() {

}


void SpecialKeyDownInput(int key, int x, int y){

	switch (key)
	{
	case GLUT_KEY_UP:
		g_Shoot = SHOOT_UP;
		break;
	case GLUT_KEY_DOWN:
		g_Shoot = SHOOT_DOWN;
		break;
	case GLUT_KEY_LEFT:
		g_Shoot = SHOOT_LEFT;
		break;
	case GLUT_KEY_RIGHT:
		g_Shoot = SHOOT_RIGHT;
		break;
	default:
		break;
	}

}

void SpecialKeyUpInput(int key, int x, int y) {
	g_Shoot = SHOOT_NONE;
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
	glutKeyboardFunc(KeyDownInput);
	glutKeyboardUpFunc(KeyUpInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyDownInput);
	glutSpecialUpFunc(SpecialKeyUpInput);

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	// Init ScnMgr
	g_ScnMgr = new ScnMgr();

	glutMainLoop();

	delete g_ScnMgr;

	return 0;

}