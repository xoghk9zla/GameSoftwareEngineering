#include "stdafx.h"
#include "ScnMgr.h"

int g_Seq = 0;

ScnMgr::ScnMgr()
{	
	// Init Objects List
	for (int i = 0; i < MAX_OBJECTS; ++i) {
		m_Objects[i] = NULL;
	}

	// Creat Hero Object
	m_Objects[HERO_ID] = new Object();
	m_Objects[HERO_ID]->SetPos(0.0f, 0.0f, 0.0f);
	m_Objects[HERO_ID]->SetVel(0.0f, 0.0f);
	m_Objects[HERO_ID]->SetAcc(0.0f, 0.0f);
	m_Objects[HERO_ID]->SetSize(1.0f, 1.0f);
	m_Objects[HERO_ID]->SetMass(0.1f);
	m_Objects[HERO_ID]->SetCoefFrict(1.0f);
	m_Objects[HERO_ID]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Objects[HERO_ID]->SetKind(KIND_HERO);


	m_Renderer = NULL;
	m_Objects[HERO_ID] = NULL;

	// Init Renderer
	m_Renderer = new Renderer(WIDTH, HEIGHT);

	// Load test Texture
	m_TexSeq = m_Renderer->CreatePngTexture("./textures/sprite.png");
	//m_TestTexture = m_Renderer->CreatePngTexture("./textures/textures.png");

}
	
ScnMgr::~ScnMgr()
{
	if (m_Renderer) {
		delete m_Renderer;
		m_Renderer = NULL;
	}

	if (m_Objects[HERO_ID]) {
		delete m_Objects[HERO_ID];
		m_Objects[HERO_ID] = NULL;
	}
}

void ScnMgr::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test

	float x, y, z, sizeX, sizeY, r, g, b, a;
	m_Objects[HERO_ID]->GetPos(&x, &y, &z);
	m_Objects[HERO_ID]->GetSize(&sizeX, &sizeY);
	m_Objects[HERO_ID]->GetColor(&r, &g, &b, &a);
	//m_Renderer->DrawTextureRectHeight(x, y, 0.0f, sizeX * 100, sizeY * 100, r, g, b, a, m_TestTexture, z);

	int seqX, seqY;

	seqX = g_Seq % 4;
	seqY = (int)g_Seq / 2;
	g_Seq++;

	if (g_Seq > 7) {
		g_Seq = 0;
	}
	m_Renderer->DrawTextureRectSeqXY(x, y, 0.0f, sizeX * 100, sizeY * 100, r, g, b, a, m_TexSeq, seqX, seqY, 4, 2);

}

void ScnMgr::Update(float eTime)
{
	m_Objects[HERO_ID]->Update(eTime);
}

void ScnMgr::ApplyForce(float x, float y, float eTime)
{
	m_Objects[HERO_ID]->ApplyForce(x, y, eTime);
}

void ScnMgr::Shoot(int shootID)
{
	float amount = 3.0f;
	float bvX, bvY;

	if (shootID == SHOOT_NONE) {
		return;
	}

	bvX = 0.0f;
	bvY = 0.0f;

	switch (shootID)
	{
	case SHOOT_UP:
		bvX = 0.0f;
		bvY = amount;
		break;
	case SHOOT_DOWN:
		bvX = 0.0f;
		bvY = -amount;
		break;
	case SHOOT_LEFT:
		bvX = -amount;
		bvY = 0.0f;
		break;
	case SHOOT_RIGHT:
		bvX = amount;
		bvY = 0.0f;
		break;

	default:
		break;
	}

	float pX, pY, pZ;

	float vX, vY;

}
