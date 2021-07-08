#pragma once
#include "Component.h"
#include "Vector2.h"

//��ġ����, ȸ������, ũ�� ������ ����
class Transform :
	public Component
{
public:
	Transform(Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f, 1.0f));
	virtual ~Transform();

public:
	virtual void Update() {};

	Vector2 position;			//��ġ���� (x,y)
	float rotatingAngle;	//ȸ�� ����
	Vector2 scale;			//ũ��

	Vector2 positioningCenter;	//��ġ ���� ����(�⺻ ���� �̹��� �����)
	Vector2 rotatingCenter;		//ȸ����
	Vector2 scalingCenter;		//ũ�� ��ȯ��

public:
	void SetPosition(float x, float y);
	void SetRotation(float angle);
	void SetScale(float x, float y);
};

