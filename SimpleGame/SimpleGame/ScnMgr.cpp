#include "stdafx.h"
#include "ScnMgr.h"

int g_Seq = 0;

ScnMgr::ScnMgr()
{	
	m_Renderer = NULL;

	// Init Objects List
	for (int i = 0; i < MAX_OBJECTS; ++i) {
		m_Objects[i] = NULL;
	}

	// Init Renderer
	m_Renderer = new Renderer(500, 500);

	// Load test Texture
	m_TexSeq = m_Renderer->CreatePngTexture("./textures/texture.png");
	//m_TestTexture = m_Renderer->CreatePngTexture("./textures/texture.png");

	// Creat Hero Object
	m_Objects[HERO_ID] = new Object();
	m_Objects[HERO_ID]->SetPos(0.0f, 0.0f, 0.5f);
	m_Objects[HERO_ID]->SetVel(0.0f, 0.0f);
	m_Objects[HERO_ID]->SetAcc(0.0f, 0.0f);
	m_Objects[HERO_ID]->SetSize(1.0f, 1.0f);
	m_Objects[HERO_ID]->SetMass(0.15f);
	m_Objects[HERO_ID]->SetCoefFrict(0.5f);
	m_Objects[HERO_ID]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Objects[HERO_ID]->SetKind(KIND_HERO);

	// Test AddObject
	AddObject(1.5f, 0.0f, 1.0f, 1.3f, 1.3f, 0.0f, 0.0f);

	
}
	
ScnMgr::~ScnMgr()
{
	if (m_Renderer) {
		delete m_Renderer;
		m_Renderer = NULL;
	}

	if (m_Objects[HERO_ID]) {
		delete[] m_Objects;
		for (int i = 0; i < HERO_ID; ++i) {
			m_Objects[i] = NULL;
		}
	}
}

void ScnMgr::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	for (int i = 0; i < MAX_OBJECTS; ++i) {
		if (m_Objects[i] != NULL) {
			float x, y, z, sizeX, sizeY, r, g, b, a;
			m_Objects[i]->GetPos(&x, &y, &z);
			m_Objects[i]->GetSize(&sizeX, &sizeY);
			m_Objects[i]->GetColor(&r, &g, &b, &a);

			float newX, newY, newZ, newW, newH;
			
			newX = x * 100;
			newY = y * 100;
			newZ = z * 100;

			newW = sizeX * 100;
			newH = sizeY * 100;

			m_Renderer->DrawTextureRectHeight(
				newX, newY, 0.0f,
				newW, newH,
				r, g, b, a,
				m_TexSeq, z
			);
		}
	}
}

void ScnMgr::Update(float eTime)
{
	for (int i = 0; i < MAX_OBJECTS; ++i) {
		if (m_Objects[i] != NULL) {
			m_Objects[i]->Update(eTime);
		}
	}
}

void ScnMgr::GarbageCollector()
{
	for (int i = 0; i < MAX_OBJECTS; ++i) {
		if (m_Objects[i] != NULL) {
			float x, y, z;
			m_Objects[i]->GetPos(&x, &y, &z);
			if (x > 2.5f || x < -2.5f || y > 2.5f || y < -2.5f) {
				DeleteObject(i);
			}
		}
	}
}


void ScnMgr::ApplyForce(float x, float y, float eTime)
{
		if (m_Objects[HERO_ID] != NULL) {
			m_Objects[HERO_ID]->ApplyForce(x, y, eTime);
		}
	
}

void ScnMgr::AddObject(float x, float y, float z, float sx, float sy, float vx, float vy)
{
	int id = FindEmptyObjectSlot();

	if (id < 0) {
		return;
	}

	m_Objects[id] = new Object();

	m_Objects[id]->SetPos(x, y, z);
	m_Objects[id]->SetVel(vx, vy);
	m_Objects[id]->SetAcc(0.0f, 0.0f);
	m_Objects[id]->SetSize(sx, sy);
	m_Objects[id]->SetMass(0.15f);
	m_Objects[id]->SetCoefFrict(0.5f);
	m_Objects[id]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Objects[id]->SetKind(KIND_BULLET);
}

void ScnMgr::DeleteObject(int id)
{
	if (m_Objects[id] != NULL) {
		delete m_Objects[id];
		m_Objects[id] = NULL;
	}
}

int ScnMgr::FindEmptyObjectSlot()
{
	for (int i = 0; i < MAX_OBJECTS; ++i) {
		if (m_Objects[i] == NULL) {
			return i;
		}
	}
	std::cout << "No more empty slot!" << std::endl;
	return -1;
}

void ScnMgr::Shoot(int shootID)
{
	if (shootID == SHOOT_NONE) {
		return;
	}

	float amount = 20.0f;
	float bvX, bvY;

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
	m_Objects[HERO_ID]->GetPos(&pX, &pY, &pZ);

	float vX, vY;
	m_Objects[HERO_ID]->GetVel(&vX, &vY);

	bvX = bvX + vX;
	bvY = bvY + vY;

	AddObject(pX, pY, pZ, 0.2f, 0.2f, bvX, bvY);
}

void ScnMgr::DoCollisionTest()
{

	for (int i = 0; i < MAX_OBJECTS; ++i) {

		if (m_Objects[i] == NULL) {
			continue;
		}

		for (int j = 0; j < MAX_OBJECTS; ++j) {

			if (m_Objects[j] == NULL) {
				continue;
			}
			if (i == j) {
				continue;
			}

			// i object
			float pX, pY, pZ;
			float sX, sY;
			float minX, minY, maxX, maxY;
			int kind;

			m_Objects[i]->GetPos(&pX, &pY, &pZ);
			m_Objects[i]->GetSize(&sX, &sY);
			m_Objects[i]->GetKind(&kind);
			minX = pX - sX / 2.f;
			maxX = pX + sX / 2.f;
			minY = pY - sY / 2.f;
			maxY = pY + sY / 2.f;

			// j object
			float pX1, pY1, pZ1;
			float sX1, sY1;
			float minX1, minY1, maxX1, maxY1;
			int kind1;

			m_Objects[j]->GetPos(&pX1, &pY1, &pZ1);
			m_Objects[j]->GetSize(&sX1, &sY1);
			m_Objects[j]->GetKind(&kind1);
			minX1 = pX1 - sX1 / 2.f;
			maxX1 = pX1 + sX1 / 2.f;
			minY1 = pY1 - sY1 / 2.f;
			maxY1 = pY1 + sY1 / 2.f;

			if (RRCollision(minX, minY, maxX, maxY, minX1, minY1, maxX1, maxY1)) {
				std::cout << "Collision" << std::endl;
			}
		}
	}
}

bool ScnMgr::RRCollision(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1)
{
	if (maxX < minX1) return false;
	if (maxX1 < minX) return false;
	if (maxY < minY1) return false;
	if (maxY1 < minY) return false;

	return true;
}
