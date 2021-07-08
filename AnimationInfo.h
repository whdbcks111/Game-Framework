#pragma once
#include "stdafx.h"
#include "RenderInfo.h"
#include "Animation.h"

//�������� ��ӹ޴� ANimationRenderer�Դϴ�
//�ִϸ��̼��� ����ϴ� ��ü�� ��쿡 �ִϸ��̼� ������ ��ü�� �����Ͽ� ����մϴ�.

class AnimationInfo :
	public RenderInfo
{
public:
	AnimationInfo();
	virtual ~AnimationInfo();
public:
	int currentState;					//���� ������� �ִϸ��̼��� state ��
	Animation* currentAnimation;		//���� ������� �ִϸ��̼� ��ü�� ������ �ּ�
	std::vector<Animation*> animations;	//��� �ִϸ��̼��� ����ִ� ����(�迭 ������ �����̳�)
public:
	void Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform);
	virtual void UpdateRenderInfo();
public:
	void ChangeAnimation(int state);			//�ִϸ��̼��� �����ϰ� ���� ��� ȣ��
	void PushBackAnimation(Animation* anim);	//���ο� �ִϸ��̼��� ����ϰ� ���� ��� ȣ��
	Animation* FindAnimationByState(int state);	//state���� �Է¹޾� �ش� Animation�� ��ȯ�մϴ�, �������� ���� ��� nullptr�� ��ȯ�մϴ�.
	virtual D2D1_RECT_F* GetSourceRect();

	virtual int  GetWidth();
	virtual int  GetHeight();
};

