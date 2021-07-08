#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"
#include "GameObject.h"

Scene* Scene::currentScene = nullptr;
Scene* Scene::nextScene = nullptr;

Scene::Scene(): renderingManager(nullptr)
{
}

Scene::~Scene()
{
	for (auto& i : gameObjectList)
	{
		SAFE_DELETE(i);
	}
	gameObjectList.clear();
	renderableList.clear();
	SAFE_DELETE(renderingManager);
}

void Scene::SwapScene(D2DApp* d2dApp)
{
	if (!nextScene)
		return;

	SAFE_DELETE(currentScene);
	currentScene = nextScene;
	nextScene = nullptr;

	currentScene->renderingManager = new RenderingManager(d2dApp);
	currentScene->Initialize();
}

void Scene::ChangeScene(Scene* nextScene)
{
	Scene::nextScene = nextScene;
}

Scene* Scene::GetCurrentScene()
{
	return Scene::currentScene;
}

void Scene::Initialize()
{
	GameObject* g = PushBackGameObject(new GameObject(L"a.png"));
	g->transform->SetPosition(100.0f, 100.0f);
}

void Scene::Update()
{
	//��� ������Ʈ�� Update�� ����
	for (auto& i : gameObjectList)
		if (i->isActive)
			i->Update();

	//LateUpdate ����
	for (auto& i : gameObjectList)
		if (i->isActive)
			i->LateUpdate();

	//���� ��û���� ������Ʈ ����
	auto i = destroyedObjectList.begin();
	while (i != destroyedObjectList.end())
	{
		(*i)->OnDestroy();
		gameObjectList.remove(*i);		//���ӿ�����Ʈ����Ʈ���� ����
		renderableList.remove(*i);		//�������� ����Ʈ���� ����
		GameObject* t = *i;
		SAFE_DELETE(t);				//delete
		destroyedObjectList.remove(*i);
		i = destroyedObjectList.begin();
	}
	destroyedObjectList.clear();
}

void Scene::Render()
{
	renderingManager->BeginRender();
	for (auto& i : renderableList)
		renderingManager->Render(i->renderer, i->transform);
	renderingManager->EndRender();
}

GameObject* Scene::PushBackGameObject(GameObject* gameObject)
{
	//���� ������Ʈ�� �������
	gameObjectList.push_back(gameObject);
	//�������� �̹����� �������
	//�������� ����Ʈ�� �������
	if (gameObject->renderer->GetInitialized())
	{
		renderableList.push_back(gameObject);
	}
	return gameObject;//���� ���ӿ�����Ʈ�� �״�� ��ȯ
}

void Scene::Destroy(GameObject* o)
{
	//������ ������Ʈ ����Ʈ�� �������
	destroyedObjectList.push_back(o);
}

RenderingManager* Scene::GetRenderingManager()
{
	return renderingManager;
}
