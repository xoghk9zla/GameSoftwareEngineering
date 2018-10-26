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

	void AddObject(float pX, float pY, float pZ, float sX, float sY, float sZ);

	void Shoot(int shootID);
};

