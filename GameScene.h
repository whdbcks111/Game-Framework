#pragma once
#include "Scene.h"
#include "Player.h"		
#include "Enemy.h"
#include "Hpbar.h"
#include "PlayerHpbar.h"

//4,5���� ���� �ð��� �Բ� ������ Scene�Դϴ�.

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	virtual void Initialize();

	GameObject* background;	//��� �̹���
	Player* player;		//�÷��̾�
	Enemy* enemy;		//��
	Hpbar* hpbar;
	PlayerHpbar* phpbar;
};

