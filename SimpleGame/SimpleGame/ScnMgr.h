#pragma once

#include "Renderer.h"
#include "Object.h"
#include "Global.h"

class ScnMgr
{
private:
	Object *m_Objects[MAX_OBJECTS];
	Renderer * m_Renderer;

	GLuint m_TestTexture = 0;
	GLuint m_TexSeq = 0;
public:
	ScnMgr();
	~ScnMgr();
	
	void RenderScene();
	void Update(float eTime);
	void ApplyForce(float x, float y, float eTime);

	void AddObject(float x, float y, float z, float sx, float sy, float vx, float vy);
	void DeleteObject(int id);

	int FindEmptyObjectSlot();

	void Shoot(int shootID);
};

