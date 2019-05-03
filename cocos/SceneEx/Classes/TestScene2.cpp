#include "TestScene2.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* TestScene2::createScene()
{
	return TestScene2::create();
}

bool TestScene2::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B(0, 255, 0, 255));
	this->addChild(wlayer);

	/* 장면 전환
	auto item1 = MenuItemFont::create("Close Scene 2", CC_CALLBACK_1(TestScene2::doClose, this));
	item1->setColor(Color3B::BLACK);
	*/

	auto item1 = MenuItemFont::create("Scene2 -> Scene1", CC_CALLBACK_1(TestScene2::doChangeScene, this));
	item1->setColor(Color3B::BLACK);

	auto pMenu = Menu::create(item1, nullptr);
	pMenu->setPosition(Vec2(240, 50));
	this->addChild(pMenu);

	log("TestScene2 :: init");

	return true;
}

void TestScene2::doClose(Ref* pSender)
{
	Director::getInstance()->popScene();
}

void TestScene2::doChangeScene(Ref* pSender)
{
	auto pScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(pScene);
}

void TestScene2::onEnter()
{
	Scene::onEnter();

	log("TestScene2 :: onEnter");
}

void TestScene2::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();

	log("TestScene2 :: onEnterTransitionDidFinish");
}

void TestScene2::onExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();

	log("TestScene2 :: onExitTransitionDidStart");
}

void TestScene2::onExit()
{
	Scene::onExit();

	log("TestScene2 :: onExit");
}

TestScene2::~TestScene2()
{
	log("TestScene2 :: dealloc");
}
