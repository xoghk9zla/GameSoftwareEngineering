#pragma once

#include "Renderer.h"
#include "Object.h"

class ScnMgr
{
public:
	ScnMgr();
	~ScnMgr();
	
	void RenderScene();

private:
	Renderer * m_Renderer;
	Object *m_TestObj;
};

