#include "stdafx.h"
#include "Object.h"


Object::Object(){
	
}

Object::~Object()
{
}

void Object::GetPos(float * x, float * y)
{
	*x = m_PosX;
	*y = m_PosY;
}

void Object::SetPos(float x, float y)
{
	m_PosX = x;
	m_PosY = y;
}

void Object::GetSize(float * w, float * h)
{
	*w = m_SizeW;
	*h = m_SizeH;
}

void Object::SetSize(float w, float h)
{
	m_SizeW = w;
	m_SizeH = h;
}

void Object::GetColor(float * r, float * g, float * b, float * a)
{
	*r = m_ColorR;
	*g = m_ColorG;
	*b = m_ColorB;
	*a = m_ColorA;
}

void Object::SetColor(float r, float g, float b, float a)
{
	m_ColorR = r;
	m_ColorG = g;
	m_ColorB = b;
	m_ColorA = a;
}

void Object::GetVel(float * x, float * y)
{
	*x = m_VelX;
	*y = m_VelY;
}

void Object::SetVel(float x, float y)
{
	m_VelX = x;
	m_VelY = y;
}

void Object::Update()
{
	m_PosX = m_PosX + m_VelX * (1.f / 60.f);
	m_PosY = m_PosY + m_VelY * (1.f / 60.f);
}
