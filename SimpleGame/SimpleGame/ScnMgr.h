#pragma once

#include "Renderer.h"
#include "Object.h"

class ScnMgr
{
private:
	Renderer * m_Renderer;
	Object *m_TestObj;
public:
	ScnMgr();
	~ScnMgr();
	
	void RenderScene();
	void Update();

};

