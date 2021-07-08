#pragma once
#include "Animation.h"

//���� �̹����� �޾Ƽ� �ִϸ��̼��� �����մϴ�.

class ListAnimation
	:public Animation
{
public:
	ListAnimation(const int state, float fps); //�ʱ�ȭ �ܰ迡�� PushBackSprite�� list �ϼ�
	virtual ~ListAnimation();
public:
	std::list<Sprite*> sprites;
	std::list<Sprite*>::iterator iter;			//���� Sprite��

public:
	//�����ӿ�ũ ���������� �۵��ϴ� �Լ��Դϴ�.
	virtual Sprite* UpdateAnim();

public:
	virtual Sprite* GetCurrentSprite();			//���� Sprite ��ȯ
	virtual Vector2 GetAnimationSize();			//�ִϸ��̼��� ��ǥ �̹��� ������ ��ȯ
	virtual int GetAnimationWidth();
	virtual int GetAnimationHeight();
	virtual void Reset();						//�ִϸ��̼� ���� ��Ȳ �ʱ�ȭ
	void PushBackSprite(Sprite* sprite);		//�̹��� ���
	void PushBackSprite(const wchar_t* path);	//�̹��� ���
};

