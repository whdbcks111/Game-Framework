#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "Enemy.h"
class BulletManager :
	public GameObject
{
public:
	std::list<Bullet*> bulletList;	//�Ѿ� ���� ����Ʈ

	Enemy* enemy;					//�� ���
									//�ʿ��ϴٸ� List��
									//EnemyManager ������ ���� ����

	void CheckCollision();				//�浹 Ȯ��
	Bullet* PushBackBullet(Bullet* b);	//�Ѿ� ������ ���ֱ�
	void Destroy(Bullet* b);			//�Ѿ� ���� �Լ�
	
	virtual void LateUpdate();
private:
	std::list<Bullet*> destroyed;
	void RemoveDestroyed();				//���� �Ѿ� ���� ó��

public:
	BulletManager();
	~BulletManager();
};

