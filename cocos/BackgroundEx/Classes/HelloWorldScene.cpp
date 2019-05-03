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

	layer1 = Layer::create();
	this->addChild(layer1);

	layer2 = Layer::create();
	this->addChild(layer2);

	winSize = Director::getInstance()->getWinSize();

	this->createBackground();
	this->createDragon();
	this->createArrowButtons();

    return true;
}

void HelloWorld::createBackground()
{
	auto background1 = Sprite::create("Images/background1.png");
	background1->setAnchorPoint(Vec2(0, 0));
	background1->setPosition(Vec2(0, 0));

	auto background2 = Sprite::create("Images/background2.png");
	background2->setAnchorPoint(Vec2(0, 0));
	background2->setPosition(Vec2(512, 0));

	// auto voidNode = Layer::create();
	// voidNode->addChild(background1);
	// voidNode->addChild(background2);
	// voidNode->setTag(1);
	// this->addChild(voidNode, 0);

	layer1->addChild(background1);
	layer1->addChild(background2);
}

void HelloWorld::createDragon()
{
	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 6; i++)
	{
		int index = i % 4;
		int rowIndex = i / 4;

		animation->addSpriteFrameWithTexture(
			texture, Rect(index * 130, rowIndex * 140 + 70, 110, 70));
	}

	dragon = Sprite::createWithTexture(texture, Rect(0, 70, 110, 70));
	dragon->setPosition(Vec2(240, 160));
	layer1->addChild(dragon);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);
}

void HelloWorld::createArrowButtons()
{
	leftSprite = Sprite::create("Images/b1.png");
	leftSprite->setPosition(Vec2(180, 30));
	layer2->addChild(leftSprite, 2);

	leftPressedSprite = Sprite::create("Images/b2.png");
	leftPressedSprite->setPosition(leftSprite->getPosition());
	layer2->addChild(leftPressedSprite, 1);

	rightSprite = Sprite::create("Images/f1.png");
	rightSprite->setPosition(Vec2(300, 30));
	layer2->addChild(rightSprite, 2);

	rightPressedSprite = Sprite::create("Images/f2.png");
	rightPressedSprite->setPosition(rightSprite->getPosition());
	layer2->addChild(rightPressedSprite, 1);
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListener(listener);

	Scene::onExit();
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	isLeftPressed = false;
	isRightPressed = false;

	if (this->isTouchInside(leftSprite, touch) == true)
	{
		leftSprite->setVisible(false);
		isLeftPressed = true;
	}
	else if (this->isTouchInside(rightSprite, touch) == true)
	{
		rightSprite->setVisible(false);
		isRightPressed = true;
	}

	if (isLeftPressed == true || isRightPressed == true)
		this->startMovingBackground();

	return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (isLeftPressed == true && this->isTouchInside(leftSprite, touch) == false)
	{
		leftSprite->setVisible(true);
		this->stopMovingBackground();
	}
	else if (isRightPressed == true && this->isTouchInside(rightSprite, touch) == false)
	{
		rightSprite->setVisible(true);
		this->stopMovingBackground();
	}
}

void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (isLeftPressed == true || isRightPressed == true)
		this->stopMovingBackground();

	if (isLeftPressed == true)
		leftSprite->setVisible(true);

	if (isRightPressed == true)
		rightSprite->setVisible(true);
}

bool HelloWorld::isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch)
{
	auto touchPoint = touch->getLocation();

	bool bTouch = sprite->getBoundingBox().containsPoint(touchPoint);

	return bTouch;
}

void HelloWorld::startMovingBackground()
{
	if (isLeftPressed == true && isRightPressed == true)
		return;

	log("start moving");

	this->schedule(schedule_selector(HelloWorld::moveBackground));
}

void HelloWorld::stopMovingBackground()
{
	log("stop moving");
	this->unschedule(schedule_selector(HelloWorld::moveBackground));
}

void HelloWorld::moveBackground(float t)
{
	auto moveStep = 3;
	if (isLeftPressed)
	{
		moveStep = -3;
		dragon->setFlippedX(false);
	}
	else
	{
		moveStep = 3;
		dragon->setFlippedX(true);
	}

	auto newPos = Vec2(dragon->getPosition().x + moveStep, dragon->getPosition().y);

	if (newPos.x < 0)
	{
		newPos.x = 0;
	}
	else if (newPos.x > 512 * 2)
	{
		newPos.x = 512 * 2;
	}

	dragon->setPosition(newPos);

	layer1->runAction(Follow::create(dragon, Rect(0, 0, 512 * 2, 320)));
}
