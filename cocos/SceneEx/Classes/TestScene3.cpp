#include "TestScene3.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* TestScene3::createScene()
{
	return TestScene3::create();
}

bool TestScene3::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B(255, 255, 0, 255));
	this->addChild(wlayer);

	auto item1 = MenuItemFont::create("Close Scene 3", CC_CALLBACK_1(TestScene3::doClose, this));
	item1->setColor(Color3B::BLACK);

	auto pMenu = Menu::create(item1, nullptr);
	pMenu->setPosition(Vec2(240, 50));
	this->addChild(pMenu);

	return true;
}

void TestScene3::doClose(Ref* pSender)
{
	auto pScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(pScene);
}
