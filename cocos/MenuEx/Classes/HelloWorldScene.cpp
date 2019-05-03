/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/* 메뉴와 메뉴아이템 위치
	auto pMenuItem1 = MenuItemImage::create(
		"Images/btn-play-normal.png",
		"Images/btn-play-selected.png",
		CC_CALLBACK_1(HelloWorld::doClick1, this));

	pMenuItem1->setPosition(Vec2(480, 320));
	pMenuItem1->setAnchorPoint(Vec2(1, 1));

	auto pMenuItem2 = MenuItemImage::create(
		"Images/btn-highscores-normal.png",
		"Images/btn-highscores-selected.png",
		CC_CALLBACK_1(HelloWorld::doClick2, this));

	pMenuItem2->setPosition(Vec2(0, 320));
	pMenuItem2->setAnchorPoint(Vec2(0, 1));

	auto pMenuItem3 = MenuItemImage::create(
		"Images/btn-about-normal.png",
		"Images/btn-about-selected.png",
		CC_CALLBACK_1(HelloWorld::doClick3, this));

	pMenuItem3->setPosition(Vec2(480, 0));
	pMenuItem3->setAnchorPoint(Vec2(1, 0));

	auto pMenu = Menu::create(pMenuItem1, pMenuItem2, pMenuItem3, nullptr);

	//pMenu->alignItemsVertically();
	pMenu->setPosition(Vec2::ZERO);
	// 0,0 으로 맞추어 놓았기 때문에 이후 배치되는 메뉴아이템은 스프라이트를 화면에 배치할 때와 같이 일반적인 Vec2의 값으로 배치할 수 있다.

	this->addChild(pMenu);
	*/

	/* 메뉴 아이템 폰트 & Tag 사용하기
	auto pMenuItem1 = MenuItemFont::create(
		" Menu-1 ",
		CC_CALLBACK_1(HelloWorld::doClick4, this));
	pMenuItem1->setColor(Color3B(0, 0, 0));

	auto pMenuItem2 = MenuItemFont::create(
		" Menu-2 ",
		CC_CALLBACK_1(HelloWorld::doClick4, this));
	pMenuItem2->setColor(Color3B(0, 0, 0));

	auto pMenuItem3 = MenuItemImage::create(
		"Images/btn-play-normal.png",
		"Images/btn-play-selected.png",
		CC_CALLBACK_1(HelloWorld::doClick4, this));

	pMenuItem1->setTag(1);
	pMenuItem2->setTag(2);
	pMenuItem3->setTag(3);

	auto pMenu = Menu::create(pMenuItem1, pMenuItem2, pMenuItem3, nullptr);
	pMenu->alignItemsHorizontally();
	this->addChild(pMenu);
	*/

	// 태그를 이용한 스프라이트의 추가/제거
	auto pMenuItem1 = MenuItemFont::create(
		" Menu-1 ",
		CC_CALLBACK_1(HelloWorld::doClick5, this));
	pMenuItem1->setColor(Color3B(0, 0, 0));

	auto pMenuItem2 = MenuItemFont::create(
		" Menu-2 ",
		CC_CALLBACK_1(HelloWorld::doClick5, this));
	pMenuItem2->setColor(Color3B(0, 0, 0));

	pMenuItem1->setTag(1);
	pMenuItem2->setTag(2);

	auto pMenu = Menu::create(pMenuItem1, pMenuItem2, nullptr);
	pMenu->alignItemsVertically();
	this->addChild(pMenu);

    return true;
}

void HelloWorld::doClick1(Ref* pSender)
{
	log("첫 번째 메뉴가 선택되었습니다.");
}

void HelloWorld::doClick2(Ref* pSender)
{
	log("두 번째 메뉴가 선택되었습니다.");
}

void HelloWorld::doClick3(Ref* pSender)
{
	log("세 번째 메뉴가 선택되었습니다.");
}

void HelloWorld::doClick4(Ref* pSender)
{
	auto tItem = (MenuItem*)pSender;
	int tag = tItem->getTag();

	log("%d 번째 메뉴가 선택되었습니다.", tag);
}

void HelloWorld::doClick5(Ref* pSender)
{
	// 두번 연속 눌리는 것에 대한 방지 코드 추가해야함

	auto tItem = (MenuItem*)pSender;
	int tag = tItem->getTag();

	if (tag == 1)
	{
		auto pMan = Sprite::create("Images/grossini.png");

		pMan->setPosition(Vec2(100, 160));
		pMan->setTag(11);

		this->addChild(pMan);
	}
	else
	{
		auto pMan = (Sprite*)getChildByTag(11);

		this->removeChild(pMan, true);
	}
}