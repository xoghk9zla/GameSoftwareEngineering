#include "stdafx.h"
#include "ScnMgr.h"

ScnMgr::ScnMgr()
{	
	m_Renderer = NULL;
	m_TestObj = NULL;

	// Init Renderer
	m_Renderer = new Renderer(WIDTH, HEIGHT);

	// Init Test Obj
	m_TestObj = new Object();
	m_TestObj->SetPos(0.0f, 0.0f);
	m_TestObj->SetVel(0.f, 0.f);
	m_TestObj->SetSize(1.0f, 1.0f);
	m_TestObj->SetColor(1.0f, 1.0f, 1.0f, 1.0f);


}

ScnMgr::~ScnMgr()
{
	if (m_Renderer) {
		delete m_Renderer;
		m_Renderer = NULL;
	}

	if (m_TestObj) {
		delete m_TestObj;
		m_TestObj = NULL;
	}
}

void ScnMgr::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test

	float x, y, sizeX, sizeY, r, g, b, a;
	m_TestObj->GetPos(&x, &y);
	m_TestObj->GetSize(&sizeX, &sizeY);
	m_TestObj->GetColor(&r, &g, &b, &a);

	m_Renderer->DrawSolidRect(x, y, 0, sizeX * 100, sizeY * 100, r, g, b, a);
}

void ScnMgr::Update()
{
	m_TestObj->Update();

}
