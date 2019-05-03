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

	MenuItemFont::setFontSize(28);

	auto pMenuItem = MenuItemFont::create(
		" Action ",
		CC_CALLBACK_1(HelloWorld::doAction, this));
	pMenuItem->setColor(Color3B::BLACK);

	auto pMenu = Menu::create(pMenuItem, nullptr);
	pMenu->setPosition(Vec2(240, 50));
	this->addChild(pMenu);

	/*
	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 150));
	this->addChild(pMan);

	pWoman = Sprite::create("Images/grossinis_sister1.png");
	pWoman->setPosition(Vec2(50, 110));
	this->addChild(pWoman);
	*/

	/* Ease Action
	pBall = Sprite::create("Images/r1.png");
	pBall->setPosition(Vec2(50, 100));
	pBall->setScale(0.7f);
	this->addChild(pBall);

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 150));
	pMan->setScale(0.5f);
	this->addChild(pMan);

	pWoman = Sprite::create("Images/grossinis_sister1.png");
	pWoman->setPosition(Vec2(50, 220));
	pWoman->setScale(0.5f);
	this->addChild(pWoman);

	pWoman2 = Sprite::create("Images/grossinis_sister2.png");
	pWoman2->setPosition(Vec2(50, 280));
	pWoman2->setScale(0.5f);
	this->addChild(pWoman2);
	*/

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 160));
	this->addChild(pMan);

    return true;
}

void HelloWorld::doAction(Ref* pSender)
{
	// doActionMove();
	// doActionJump();
	// doActionRotate();
	// doActionScale();
	// doActionTint();

	// doActionPlace();
	// doActionBlink();
	// doActionShow();
	// doActionFadInOut();

	/* Composite Action
	pMan->removeFromParentAndCleanup(true);

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 160));
	this->addChild(pMan);

	// ActionSequence();
	// ActionSpawn();
	// ActionRepeat();
	// ActionRepeatForever();
	// ActionDelayTime();
	*/

	/* Ease Action
	pBall->setPosition(Vec2(50, 100));
	pMan->setPosition(Vec2(50, 150));
	pWoman->setPosition(Vec2(50, 220));
	pWoman2->setPosition(Vec2(50, 280));

	// doActionEase();
	// doActionElastic();
	// doActionBounce();
	doActionSpeed();
	*/

	pMan->removeFromParentAndCleanup(true);

	this->removeChildByTag(1, true);
	this->removeChildByTag(2, true);
	this->removeChildByTag(3, true);

	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(50, 160));
	this->addChild(pMan);

	pMan->setVisible(false);

	auto action = Sequence::create(
		Place::create(Vec2(200, 200)),
		DelayTime::create(1.5),
		Show::create(),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callback1, this)),
		MoveBy::create(1.5, Vec2(200, 0)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callback2, this, pMan)),
		MoveBy::create(1.5, Vec2(0, -50)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::callback3, this, pMan, 42)),
		DelayTime::create(1.5),
		RemoveSelf::create(),
		nullptr
	);

	pMan->runAction(action);
}

void HelloWorld::doActionMove()
{
	auto myActionTo = MoveTo::create(2, Vec2(400, 0));
	auto myActionBy = MoveBy::create(2, Vec2(400, 0));

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);
}

void HelloWorld::doActionJump()
{
	auto myActionTo = JumpTo::create(2, Vec2(400, 0), 50, 3);
	auto myActionBy = JumpBy::create(2, Vec2(400, 0), 50, 3);

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);
}

void HelloWorld::doActionRotate()
{
	auto myActionTo = RotateTo::create(2, 270);
	auto myActionBy = RotateBy::create(2, 270);

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);
}

void HelloWorld::doActionScale()
{
	auto myActionTo = ScaleTo::create(2, 2.0);
	auto myActionBy = ScaleBy::create(2, 2.0);

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);
}

void HelloWorld::doActionTint()
{
	auto myActionTo = TintTo::create(2, 128, 128, 128);
	auto myActionBy = TintBy::create(2, 0, -30, 30);

	pMan->runAction(myActionTo);
	pWoman->runAction(myActionBy);
}

void HelloWorld::doActionPlace()
{
	auto myAction = Place::create(Vec2(300, 200));

	pMan->runAction(myAction);
}

void HelloWorld::doActionBlink()
{
	auto myAction = Blink::create(2, 5);

	pMan->runAction(myAction);
}

void HelloWorld::doActionShow()
{
	if (pMan->isVisible())
	{
		auto myAction = Hide::create();
		pMan->runAction(myAction);
	}
	else
	{
		auto myAction = Show::create();
		pMan->runAction(myAction);
	}
}

void HelloWorld::doActionFadInOut()
{
	if (pMan->getOpacity() == 0)
	{
		auto myAction = FadeIn::create(1.5);
		pMan->runAction(myAction);
	}
	else
	{
		auto myAction = FadeOut::create(1.5);
		pMan->runAction(myAction);
	}
}

void HelloWorld::ActionSequence()
{
	auto action = Sequence::create(
		MoveBy::create(2, Vec2(400, 0)),
		RotateBy::create(2, 720),
		nullptr
	);

	pMan->runAction(action);
}

void HelloWorld::ActionSpawn()
{
	auto action = Spawn::create(
		JumpBy::create(4, Vec2(400, 0), 50, 4),
		RotateBy::create(2, 720),
		nullptr
	);

	pMan->runAction(action);
}

void HelloWorld::ActionRepeat()
{
	auto myActionForward = MoveBy::create(2, Vec2(400, 0));
	auto myActionBack = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBack, nullptr);

	auto rep = Repeat::create(myAction, 3);

	pMan->runAction(rep);
}

void HelloWorld::ActionRepeatForever()
{
	auto myActionForward = MoveBy::create(2, Vec2(400, 0));
	auto myActionBack = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBack, nullptr);

	auto rep = RepeatForever::create(myAction);

	pMan->runAction(rep);
	
}

void HelloWorld::ActionDelayTime()
{
	auto act1 = RotateTo::create(1, 150);
	auto act2 = RotateTo::create(1, 0);

	auto myAction = Sequence::create(
		act1,
		DelayTime::create(2.0),
		act2,
		DelayTime::create(1.0),
		nullptr
	);

	auto rep = RepeatForever::create(myAction);

	pMan->runAction(rep);
}

void HelloWorld::doActionEase()
{
	// 정상 속도
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	// 빨라지기
	auto ease_in = EaseIn::create(move->clone(), 2.0f);
	// 느려지기
	auto ease_out = EaseOut::create(move->clone(), 2.0f);
	// 빨라졌다 느려지기
	auto ease_inout = EaseInOut::create(move->clone(), 2.0f);

	pBall->runAction(move);
	pMan->runAction(ease_in);
	pWoman->runAction(ease_out);
	pWoman2->runAction(ease_inout);
}

void HelloWorld::doActionElastic()
{
	// 정상 속도
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	auto ease_in = EaseElasticIn::create(move->clone(), 0.4f);
	auto ease_out = EaseElasticOut::create(move->clone(), 0.4f);
	auto ease_inout = EaseElasticInOut::create(move->clone(), 0.4f);

	pBall->runAction(move);
	pMan->runAction(ease_in);
	pWoman->runAction(ease_out);
	pWoman2->runAction(ease_inout);
}

void HelloWorld::doActionBounce()
{
	// 정상 속도
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	auto ease_in = EaseBounceIn::create(move->clone());
	auto ease_out = EaseBounceOut::create(move->clone());
	auto ease_inout = EaseBounceInOut::create(move->clone());

	pBall->runAction(move);
	pMan->runAction(ease_in);
	pWoman->runAction(ease_out);
	pWoman2->runAction(ease_inout);	
}

void HelloWorld::doActionSpeed()
{
	// 정상 속도
	auto move = MoveBy::create(3.0f, Vec2(400, 0));

	auto ease_in = Speed::create(move->clone(), 1.0f);
	auto ease_out = Speed::create(move->clone(), 2.0f);
	auto ease_inout = Speed::create(move->clone(), 3.0f);

	pBall->runAction(move);
	pMan->runAction(ease_in);
	pWoman->runAction(ease_out);
	pWoman2->runAction(ease_inout);
}

void HelloWorld::callback1()
{
	auto label = Label::createWithSystemFont("callback 1 called", "", 16);

	label->setPosition(Vec2(120, 160));
	label->setColor(Color3B::BLACK);
	label->setTag(1);

	this->addChild(label);
}

void HelloWorld::callback2(Ref* sender)
{
	auto label = Label::createWithSystemFont("callback 2 called", "", 16);

	label->setPosition(Vec2(240, 140));
	label->setColor(Color3B::RED);
	label->setTag(2);

	this->addChild(label);

	auto tItem = (Sprite *)sender;
	int i = tItem->getTag();
	log("tag num : %d", i);
}

void HelloWorld::callback3(Ref* sender, long data)
{
	auto label = Label::createWithSystemFont("callback 3 called", "", 16);

	label->setPosition(Vec2(360, 120));
	label->setColor(Color3B::BLUE);
	label->setTag(3);

	this->addChild(label);

	log("param Data : %ld", data);
}