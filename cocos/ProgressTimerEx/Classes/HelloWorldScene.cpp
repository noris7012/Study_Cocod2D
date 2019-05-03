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

	/* 스프라이트 애니메이션
	pWoman1 = Sprite::create("Images/grossinis_sister1.png");
	pWoman2 = Sprite::create("Images/grossinis_sister2.png");

	// SpriteProgressToRadial();
	// SpriteProgressToHorizontal();
	// SpriteProgressToVertical();
	// SpriteProgressToRadialMidpointChnaged();
	// SpriteProgressBarVarious();
	// SpriteProgressBarTintAndFade();
	*/

	auto sprite = Sprite::create("Images/grossinis_sister1.png");

	pt = ProgressTimer::create(sprite);
	pt->setType(ProgressTimer::Type::RADIAL);
	pt->setPosition(Vec2(240, 160));
	this->addChild(pt);

	nNum = 0;

	this->schedule(schedule_selector(HelloWorld::myTick), 0.1f);

    return true;
}

void HelloWorld::SpriteProgressToRadial()
{
	auto to1 = ProgressTo::create(2, 100);
	auto to2 = ProgressTo::create(2, 100);

	auto left = ProgressTimer::create(pWoman1);
	left->setType(ProgressTimer::Type::RADIAL);
	left->setPosition(Vec2(140, 160));
	this->addChild(left);
	left->runAction(to1);

	auto right = ProgressTimer::create(pWoman2);
	right->setType(ProgressTimer::Type::RADIAL);
	right->setReverseProgress(true);
	right->setPosition(Vec2(340, 160));
	this->addChild(right);
	right->runAction(to2);
}

void HelloWorld::SpriteProgressToHorizontal()
{
	auto to1 = ProgressTo::create(2, 100);
	auto to2 = ProgressTo::create(2, 100);

	auto left = ProgressTimer::create(pWoman1);
	left->setType(ProgressTimer::Type::BAR);
	left->setMidpoint(Vec2(0, 0));
	left->setBarChangeRate(Vec2(1, 0));
	left->setPosition(Vec2(140, 160));
	this->addChild(left);
	left->runAction(to1);

	auto right = ProgressTimer::create(pWoman2);
	right->setType(ProgressTimer::Type::BAR);
	right->setMidpoint(Vec2(1, 0));
	right->setBarChangeRate(Vec2(1, 0));
	right->setPosition(Vec2(340, 160));
	this->addChild(right);
	right->runAction(to2);
}

void HelloWorld::SpriteProgressToVertical()
{
	auto to1 = ProgressTo::create(2, 100);
	auto to2 = ProgressTo::create(2, 100);

	auto left = ProgressTimer::create(pWoman1);
	left->setType(ProgressTimer::Type::BAR);
	left->setMidpoint(Vec2(0, 0));
	left->setBarChangeRate(Vec2(0, 1));
	left->setPosition(Vec2(140, 160));
	this->addChild(left);
	left->runAction(to1);

	auto right = ProgressTimer::create(pWoman2);
	right->setType(ProgressTimer::Type::BAR);
	right->setMidpoint(Vec2(0, 1));
	right->setBarChangeRate(Vec2(0, 1));
	right->setPosition(Vec2(340, 160));
	this->addChild(right);
	right->runAction(to2);	
}

void HelloWorld::SpriteProgressToRadialMidpointChnaged()
{
	auto to1 = ProgressTo::create(2, 100);
	auto to2 = ProgressTo::create(2, 100);

	auto left = ProgressTimer::create(pWoman1);
	left->setType(ProgressTimer::Type::RADIAL);
	left->setMidpoint(Vec2(0.25, 0.75));
	left->setPosition(Vec2(140, 160));
	this->addChild(left);
	left->runAction(to1);

	auto right = ProgressTimer::create(pWoman2);
	right->setType(ProgressTimer::Type::RADIAL);
	right->setMidpoint(Vec2(0.75, 0.25));
	right->setPosition(Vec2(340, 160));
	this->addChild(right);
	right->runAction(to2);
}

void HelloWorld::SpriteProgressBarVarious()
{
	auto to1 = ProgressTo::create(2, 100);
	auto to2 = ProgressTo::create(2, 100);
	auto to3 = ProgressTo::create(2, 100);

	auto left = ProgressTimer::create(pWoman1);
	left->setType(ProgressTimer::Type::BAR);
	left->setMidpoint(Vec2(0.5, 0.5));
	left->setBarChangeRate(Vec2(1, 0));
	left->setPosition(Vec2(140, 160));
	this->addChild(left);
	left->runAction(to1);

	auto middle = ProgressTimer::create(pWoman2);
	middle->setType(ProgressTimer::Type::BAR);
	middle->setMidpoint(Vec2(0.5, 0.5));
	middle->setBarChangeRate(Vec2(1, 1));
	middle->setPosition(Vec2(240, 160));
	this->addChild(middle);
	middle->runAction(to2);

	auto right = ProgressTimer::create(pWoman2);
	right->setType(ProgressTimer::Type::BAR);
	right->setMidpoint(Vec2(0.5, 0.5));
	right->setBarChangeRate(Vec2(0, 1));
	right->setPosition(Vec2(340, 160));
	this->addChild(right);
	right->runAction(to3);	
}

void HelloWorld::SpriteProgressBarTintAndFade()
{
	auto to = ProgressTo::create(6, 100);

	auto tint = Sequence::create(
		TintTo::create(1, 255, 128, 128),
		TintTo::create(1, 128, 255, 128),
		TintTo::create(1, 128, 128, 255),
		nullptr
	);

	auto fade = Sequence::create(
		FadeTo::create(1.0, 0),
		FadeTo::create(1.0, 255),
		nullptr
	);

	auto left = ProgressTimer::create(pWoman1);
	left->setType(ProgressTimer::Type::BAR);
	left->setMidpoint(Vec2(0.5, 0.5));
	left->setBarChangeRate(Vec2(1, 0));
	left->setPosition(Vec2(140, 160));
	this->addChild(left);
	left->runAction(RepeatForever::create(to->clone()));
	left->runAction(RepeatForever::create(tint->clone()));

	auto pLabelLeft = Label::createWithSystemFont("Tint", "", 20.0);
	pLabelLeft->setColor(Color3B::BLACK);
	pLabelLeft->setPosition(Vec2(pWoman1->getContentSize().width / 2, -10));
	left->addChild(pLabelLeft);

	auto middle = ProgressTimer::create(pWoman2);
	middle->setType(ProgressTimer::Type::BAR);
	middle->setMidpoint(Vec2(0.5, 0.5));
	middle->setBarChangeRate(Vec2(1, 1));
	middle->setPosition(Vec2(240, 160));
	this->addChild(middle);
	middle->runAction(RepeatForever::create(to->clone()));
	middle->runAction(RepeatForever::create(fade->clone()));

	auto pLabelMid = Label::createWithSystemFont("Fade", "", 20.0);
	pLabelMid->setColor(Color3B::BLACK);
	pLabelMid->setPosition(Vec2(pWoman2->getContentSize().width / 2, -10));
	middle->addChild(pLabelMid);

	auto right = ProgressTimer::create(pWoman1);
	right->setType(ProgressTimer::Type::BAR);
	right->setMidpoint(Vec2(0.5, 0.5));
	right->setBarChangeRate(Vec2(0, 1));
	right->setPosition(Vec2(340, 160));
	this->addChild(right);
	right->runAction(RepeatForever::create(to->clone()));
	right->runAction(RepeatForever::create(tint->clone()));
	// right 에 붙인 action 이 left에도 영향을 줌 (같은 Sprite라 그런가봄)
	right->runAction(RepeatForever::create(fade->clone()));

	auto pLabelRight = Label::createWithSystemFont("Tint & Fade", "", 20.0);
	pLabelRight->setColor(Color3B::BLACK);
	pLabelRight->setPosition(Vec2(pWoman1->getContentSize().width / 2, -10));
	right->addChild(pLabelRight);
}

void HelloWorld::myTick(float f)
{
	nNum++;
	this->SpriteProgressToRadial(nNum * 2);
	if (nNum > 50)
		nNum = 0;
}

void HelloWorld::SpriteProgressToRadial(float f)
{
	pt->setPercentage(f);
}

