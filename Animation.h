#pragma once
#include "RenderingManager.h"

//�ϳ��� �ִϸ��̼��� ������ ��ü�Դϴ�.
//�߻� Ŭ�����Դϴ�.
//���� ���۽ÿ� ListAnimation, SheetAnimation�� ����մϴ�.
//���̷��� �ִϸ��̼��� �������� �ʾ�����, �ش� Ŭ������ ������ �����ϼž� �մϴ�.
class Animation
{
public:
	Animation(const int state, float fps);
public:
	const int state;		//�ִϸ��̼��� state number
	int currentFrame;			//���� frame number
	float frameTime;		//���� �ִϸ��̼��� �ð�
	int length;				//�ִϸ��̼��� ������ ����
protected:
	float fps;				//�ִϸ��̼��� ������ fps
	float reciprocalFPS;	//1/fps

public:
	void SetFPS(float fps);
	float GetFPS(float fps);
public:
	virtual Sprite* UpdateAnim() = 0;
	virtual Sprite* GetCurrentSprite() = 0;
	virtual int GetAnimationWidth() = 0;
	virtual int GetAnimationHeight() = 0;
	virtual D2D1_RECT_F* GetSourceRect();
	virtual void Reset();
};

