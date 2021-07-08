#pragma once
#include "GameObject.h"
#include "BulletManager.h"
#include "AABBCollider.h"

class Player :
	public GameObject
{
public:
	Player(const wchar_t* imagePath, float hp = 100.0f);
	~Player();

	BulletManager* bm;		//�Ѿ� ������ Ŭ����
	float moveSpeed;		//�̵� �ӵ�
	AABBCollider* col;
	float hp, max_hp, add_hp;

	virtual void Update();	//������Ʈ ó��
	virtual void LateUpdate();
	void Move();
	void Shoot();
	void Hit(float damage);
};

