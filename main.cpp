#include "stdafx.h"
#include "Framework.h"
#include "MainScene.h"

int main()
{
	Framework* f = new Framework;
	//���� Scene, ���� Ÿ��Ʋ, �ػ�(����, ����), â��� ���θ� �����մϴ�.
	f->Run(new MainScene(),L"R��UNDIST", 1000,700, false);
	SAFE_DELETE(f);

	return 0;
}