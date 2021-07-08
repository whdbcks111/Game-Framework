#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
Bullet::Bullet(const wchar_t* imagePath)
	:GameObject(imagePath)
{
	col = new AABBCollider(
		transform,
		renderer->GetWidth() * (-0.5f),
		renderer->GetWidth() * 0.5f,
		renderer->GetHeight() * (-0.5f),
		renderer->GetHeight() * 0.5f
	);
	speed = 0.0f;
	speedRate = 0.0f;
	angle = 0.0f;
	angleRate = 0.0f;
	damage = 0.0f;
}
void Bullet::Move()
{
	float rad = angle * PI / 180;

	transform->position.x
		+= (speed * cos(rad) * TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed * sin(rad) * TimeManager::GetDeltaTime());

	speed += speedRate * TimeManager::GetDeltaTime();
	speed = max(minSpeed, speed);
	angle += angleRate * TimeManager::GetDeltaTime();
}

Bullet::~Bullet() {
	SAFE_DELETE(col);
}


void Bullet::OnDestroy() {
}

bool Bullet::CheckOutOfScreen()
{
	//�Ѿ��� �����ǰ�, �Ѿ��� �̹��� ũ�⸦ ����ؼ�
	//�Ѿ��� �ۿ� ������ �� �������־�� ��.
	int sw = WinApp::GetScreenWidth();					//�������� ���� ����
	int sh = WinApp::GetScreenHeight();					//�������� ���� ����
	int bw = renderer->GetWidth() * (int)transform->scale.x;	//�̹����� ���� ����*������
	int bh = renderer->GetHeight() * (int)transform->scale.y;//�̹����� ���� ����*������

	return transform->position.x<bw * (-1.0f) ||	//�Ѿ��� ���� ���� �����ų�
		transform->position.x>bw + sw ||			//�Ѿ��� ���� ���� �����ų�
		transform->position.y<bh * (-1.0f) ||		//�Ѿ��� ���� ���� �����ų�
		transform->position.y>bh + sh;				//�Ѿ��� �Ʒ� ���� �����ų�
}

void Bullet::Update()
{
	Move();
}

