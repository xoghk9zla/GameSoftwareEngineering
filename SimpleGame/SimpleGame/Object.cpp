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

void Object::GetAcc(float * x, float * y)
{
	*x = m_AccX;
	*y = m_AccY;
}

void Object::SetAcc(float x, float y)
{
	m_AccX = x;
	m_AccY = y;
}

void Object::GetMass(float * x)
{
	*x = m_Mass;
}

void Object::SetMass(float x)
{
	m_Mass = x;
}

void Object::Update(float eTime)
{
	// Cal Velocity
	m_VelX = m_VelX + m_AccX * eTime;
	m_VelY = m_VelY + m_AccY * eTime;

	// Cal Position
	m_PosX = m_PosX + m_VelX * eTime;
	m_PosY = m_PosY + m_VelY * eTime;
}

void Object::ApplyForce(float x, float y, float eTime)
{
	//Calc Acc a = f/m
	m_AccX = x / m_Mass;
	m_AccY = y / m_Mass;

	m_VelX = m_VelX + m_AccX * eTime;
	m_VelY = m_VelY + m_AccY * eTime;

	m_AccX = 0.0f;
	m_AccY = 0.0f;
}