#pragma once
class Object
{
private:
	float m_PosX, m_PosY;
	float m_SizeW, m_SizeH;
	float m_ColorR, m_ColorG, m_ColorB, m_ColorA;
	float m_VelX, m_VelY;
	float m_AccX, m_AccY;

public:
	Object();
	~Object();

	void GetPos(float *x, float *y);
	void SetPos(float x, float y);

	void GetSize(float *w, float *h);
	void SetSize(float w, float h);

	void GetColor(float *r, float *g, float *b, float *a);
	void SetColor(float r, float g, float b, float a);

	void GetVel(float *x, float *y);
	void SetVel(float x, float y);

	void GetAcc(float *x, float *y);
	void SetAcc(float x, float y);

	void Update(float eTime);
	
};

