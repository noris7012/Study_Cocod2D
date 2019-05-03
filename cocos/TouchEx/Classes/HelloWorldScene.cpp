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

	/* 터치
	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);
	*/

	/* 드래그 앤 드롭
	auto pLabel = LabelTTF::create("블럭을 터치해서 드래그 하세요.", "Arial", 20);
	pLabel->setPosition(Vec2(240, 280));
	pLabel->setColor(Color3B::BLACK);
	this->addChild(pLabel, 101);

	sprite1 = Sprite::create("Images/CyanSquare.png");
	sprite1->setPosition(Vec2(240, 160) + Vec2(-80, 80));
	this->addChild(sprite1);

	sprite2 = Sprite::create("Images/MagentaSquare.png");
	sprite2->setPosition(Vec2(240, 160));
	this->addChild(sprite2);

	sprite3 = Sprite::create("Images/YellowSquare.png");
	sprite3->setPosition(Vec2(0, 0));
	sprite2->addChild(sprite3);

	sprite1->setTag(1);
	sprite2->setTag(2);
	sprite3->setTag(3);

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		log("touch began... x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Vec2 locationInNode = touch->getLocation();
		Size s = target->getContentSize();
		Rect rect = Rect(target->getPositionX() - s.width / 2, target->getPositionY() - s.height / 2, s.width, s.height);

		if (rect.containsPoint(locationInNode))
		{
			reZorder(target);

			log("sprited%d onTouchBegan... x = %f, y = %f", target->getTag(), locationInNode.x, locationInNode.y);
			target->setOpacity(180);
			return true;
		}

		return false;
	};

	listener->onTouchMoved = [](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setPosition(target->getPosition() + touch->getDelta());
		// target->setPosition(touch->getLocation());
	};

	listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		log("sprite onTouchedEnded.. ");
		target->setOpacity(255);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sprite3);
	*/

	/* 회전
	pMan = Sprite::create("Images/grossini.png");
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	bSelect = false;
	*/

	auto pLabel1 = Label::createWithSystemFont("Fixed priority test", "", 20);
	pLabel1->setPosition(Vec2(240, 300));
	pLabel1->setColor(Color3B::BLACK);
	this->addChild(pLabel1, 101);

	auto pLabel2 = Label::createWithSystemFont(
		"Fixed priority, Blue: 10, Red: 20, Yellow: 30\n"
		"작은 수가 더 높은 우선 순위를 가집니다."
		, ""
		, 20
	);
	pLabel2->setPosition(Vec2(240, 270));
	pLabel2->setColor(Color3B::BLUE);
	this->addChild(pLabel2, 101);

	sprite1 = Monster::create("Images/CyanSquare.png");
	sprite1->setPosition(Vec2(240, 160) + Vec2(-50, 0));
	sprite1->setPriority(10);
	sprite1->setPriorityWithThis(true);
	this->addChild(sprite1);

	sprite2 = Monster::create("Images/MagentaSquare.png");
	sprite2->setPosition(Vec2(240, 160));
	sprite2->setPriority(20);
	sprite2->setPriorityWithThis(true);
	this->addChild(sprite2);

	sprite3 = Monster::create("Images/YellowSquare.png");
	sprite3->setPosition(Vec2(100, 50));
	sprite3->setPriority(30);
	sprite3->setPriorityWithThis(true);
	sprite2->addChild(sprite3);
		
    return true;
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	/* 싱글 터치
	listener = EventListenerTouchOneByOne::create();
	// Swallow touches only available in OneByOne mode
	// 핸들링된 터치 이벤트를 터치 이벤트 array에서 지우겠다는 의미이다.
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);

	// The priority of the touch listener is based on the draw order of sprite
	// 터치리스너의 우선순위를 (노드가) 화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	*/

	/* 멀티 터치
	listener = EventListenerTouchAllAtOnce::create();

	listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
	listener->onTouchesCancelled= CC_CALLBACK_2(HelloWorld::onTouchesCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	*/

	/* 회전
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	*/
}

void HelloWorld::onExit()
{
	/* 터치
	_eventDispatcher->removeEventListener(listener);
	*/

	/* 회전
	_eventDispatcher->removeEventListener(listener);
	*/

	Scene::onExit();
}

/* 싱글 터치
bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchBegan id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);

	bool bTouch = pMan->getBoundingBox().containsPoint(touchPoint);
	if (bTouch)
	{
		log("Sprite clicked...");
	}

	return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchMoved = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);
}

void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchEnded= %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);
}

void HelloWorld::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{
	
}
*/

/* 멀티 터치
bool HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();

	log("onTouchBegan id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);

	bool bTouch = pMan->getBoundingBox().containsPoint(touchPoint);
	if (bTouch)
	{
		log("Sprite clicked...");
	}

	return true;
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();

	log("onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);	
}

void HelloWorld::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();

	log("onTouchEnded id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);	
}

void HelloWorld::onTouchesCancelled(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	
}
*/

/* 드래그 앤 드롭
void HelloWorld::reZorder(cocos2d::Sprite* pSender)
{
	sprite1->setLocalZOrder(0);
	sprite2->setLocalZOrder(0);
	sprite3->setLocalZOrder(0);

	pSender->setLocalZOrder(1);
}
*/

/* 회전
bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPoint = touch->getLocation();

	bSelect = pMan->getBoundingBox().containsPoint(touchPoint);

	return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (bSelect)
	{
		Vec2 oldPoint = touch->getPreviousLocation();
		Vec2 nowPoint = touch->getLocation();

		Vec2 firstVector = oldPoint - pMan->getPosition();
		float firstRotateAngle = -firstVector.getAngle();
		float previousTouch = CC_RADIANS_TO_DEGREES(firstRotateAngle);

		Vec2 secondVector = nowPoint - pMan->getPosition();
		float secondRotateAngle = -secondVector.getAngle();
		float currentTouch = CC_RADIANS_TO_DEGREES(secondRotateAngle);

		gRotation += currentTouch - previousTouch;
		gRotation = fmod(gRotation, 360);

		pMan->setRotation(gRotation);
	}
}

void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	bSelect = false;
}
*/

