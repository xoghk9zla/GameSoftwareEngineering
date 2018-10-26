#pragma once
class Object
{
private:
	float m_PosX, m_PosY, m_PosZ;
	float m_SizeW, m_SizeH;
	float m_ColorR, m_ColorG, m_ColorB, m_ColorA;
	float m_VelX, m_VelY;
	float m_AccX, m_AccY;
	float m_Mass;
	float m_CoefFrict;

	int m_Kind;
public:
	Object();
	~Object();

	void GetPos(float *x, float *y, float* z);
	void SetPos(float x, float y, float z);

	void GetSize(float *w, float *h);
	void SetSize(float w, float h);

	void GetColor(float *r, float *g, float *b, float *a);
	void SetColor(float r, float g, float b, float a);

	void GetVel(float *x, float *y);
	void SetVel(float x, float y);

	void GetAcc(float *x, float *y);
	void SetAcc(float x, float y);

	void GetMass(float *x);
	void SetMass(float x);

	void GetCoefFrict(float *x);
	void SetCoefFrict(float x);
	
	void SetKind(int Kind);
	void GetKind(int *Kind);

	void Update(float eTime);

	void ApplyForce(float x, float y, float eTime);
	
};

