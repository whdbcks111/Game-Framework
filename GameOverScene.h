#pragma once
#include "Scene.h"
#include "EnterWMain.h"

class GameOverScene :
	public Scene
{
public:
	GameOverScene();
	~GameOverScene();

	virtual void Initialize();

	GameObject* background;	//��� �̹���
	EnterWMain* ew;
};

