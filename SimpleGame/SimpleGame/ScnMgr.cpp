#include "stdafx.h"
#include "ScnMgr.h"

ScnMgr::ScnMgr()
{	
	m_Renderer = NULL;
	m_TestObj = NULL;

	// Init Renderer
	m_Renderer = new Renderer(WIDTH, HEIGHT);

	// Load test Texture
	m_TestTexture = m_Renderer->CreatePngTexture("./textures/texture.png");

	// Init Test Obj
	m_TestObj = new Object();
	m_TestObj->SetPos(0.0f, 0.0f, 0.0f);	
	m_TestObj->SetVel(0.0f, 0.0f);
	m_TestObj->SetAcc(0.0f, 0.0f);
	m_TestObj->SetSize(1.0f, 1.0f);
	m_TestObj->SetMass(0.1f);
	m_TestObj->SetCoefFrict(1.0f);
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

	float x, y, z, sizeX, sizeY, r, g, b, a;
	m_TestObj->GetPos(&x, &y, &z);
	m_TestObj->GetSize(&sizeX, &sizeY);
	m_TestObj->GetColor(&r, &g, &b, &a);
	m_Renderer->DrawTextureRectHeight(x, y, 0.0f, sizeX * 100, sizeY * 100, r, g, b, a, m_TestTexture, z);

}

void ScnMgr::Update(float eTime)
{
	m_TestObj->Update(eTime);
}

void ScnMgr::ApplyForce(float x, float y, float eTime)
{
	m_TestObj->ApplyForce(x, y, eTime);
}
