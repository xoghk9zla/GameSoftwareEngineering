#pragma once

#include "Renderer.h"
#include "Object.h"

class ScnMgr
{
private:
	Renderer * m_Renderer;
	Object *m_TestObj;

	GLuint m_TestTexture;
	GLuint m_TexSeq;
public:
	ScnMgr();
	~ScnMgr();
	
	void RenderScene();
	void Update(float eTime);
	void ApplyForce(float x, float y, float eTime);
};

