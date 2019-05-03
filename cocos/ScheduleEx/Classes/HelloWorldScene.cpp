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

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	/* ½ºÄÉÁì
	nNum = 0;

	this->schedule(schedule_selector(HelloWorld::callEveryFrame));
	this->schedule(schedule_selector(HelloWorld::myTick), 1.0f);
	this->scheduleOnce(schedule_selector(HelloWorld::myTickOnce), 3.0);
	*/

	/* ½ºÄÉÁìÀÇ Á¤Áö/Àç½ÃÀÛ

	auto item1 = MenuItemFont::create(
		"start",
		CC_CALLBACK_1(HelloWorld::doStart, this));
	item1->setColor(Color3B::BLACK);

	auto item2 = MenuItemFont::create(
		"pause",
		CC_CALLBACK_1(HelloWorld::doPause, this));
	item2->setColor(Color3B::BLACK);

	auto item3 = MenuItemFont::create(
		"resume",
		CC_CALLBACK_1(HelloWorld::doResume, this));
	item3->setColor(Color3B::BLACK);

	auto item4 = MenuItemFont::create(
		"change",
		CC_CALLBACK_1(HelloWorld::doChange, this));
	item4->setColor(Color3B::BLACK);

	auto item5 = MenuItemFont::create(
		"stop",
		CC_CALLBACK_1(HelloWorld::doStop, this));
	item5->setColor(Color3B::BLACK);

	auto pMenu = Menu::create(item1, item2, item3, item4, item5, nullptr);
	pMenu->alignItemsVertically();
	this->addChild(pMenu);

	nNum = 0;
	bChange = false;
	*/

	auto item2 = MenuItemFont::create(
		" pause ",
		CC_CALLBACK_1(HelloWorld::doClick, this));
	item2->setColor(Color3B::BLACK);

	auto item3 = MenuItemFont::create(
		" resume ",
		CC_CALLBACK_1(HelloWorld::doClick, this));
	item3->setColor(Color3B::BLACK);

	item2->setTag(1);
	item3->setTag(2);

	auto pMenu = Menu::create(item2, item3, nullptr);
	pMenu->setPosition(Vec2(240, 80));
	pMenu->alignItemsHorizontally();
	this->addChild(pMenu);

	auto pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(140, 200));
	this->addChild(pMan);

	auto myActionForward = MoveBy::create(2, Vec2(200, 0));
	auto myActionBack = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBack, nullptr);
	auto rep = RepeatForever::create(myAction);
	pMan->runAction(rep);

	return true;
}


void HelloWorld::callEveryFrame(float f)
{
	nNum++;
	if (nNum > 60)
	{
		nNum = 1;
	}

	log("fps..%d", nNum);
}

void HelloWorld::myTick(float f)
{
	log("tick ***********************");
}

void HelloWorld::myTickOnce(float f)
{
	log("tickOnce after delay");
}

void HelloWorld::doStart(Ref* pSender)
{
	this->schedule(schedule_selector(HelloWorld::tick1), 1.0f);
	this->schedule(schedule_selector(HelloWorld::tick2), 2.0f);
}

void HelloWorld::doPause(Ref* pSender)
{
	Director::getInstance()->getScheduler()->pauseTarget(this);
}

void HelloWorld::doResume(Ref* pSender)
{
	Director::getInstance()->getScheduler()->resumeTarget(this);
}

void HelloWorld::doChange(Ref* pSender)
{
	if (bChange)
	{
		bChange = false;

		this->unschedule(schedule_selector(HelloWorld::tick2));
		this->schedule(schedule_selector(HelloWorld::tick2), 2.0f);
	} 
	else
	{
		bChange = true;

		this->unschedule(schedule_selector(HelloWorld::tick2));
		this->schedule(schedule_selector(HelloWorld::tick2), 3.0f);
	}
}

void HelloWorld::doStop(Ref* pSender)
{
	this->unschedule(schedule_selector(HelloWorld::tick1));
	this->unschedule(schedule_selector(HelloWorld::tick2));
}

void HelloWorld::tick1(float f)
{
	log("tick1");
}

void HelloWorld::tick2(float f)
{

	log("tick2");
}

void HelloWorld::doClick(Ref* pSender)
{
	auto tItem = (MenuItem*)pSender;
	int i = tItem->getTag();

	if (i == 1)
	{
		Director::getInstance()->pause();
	}
	else
	{
		Director::getInstance()->resume();
	}
}