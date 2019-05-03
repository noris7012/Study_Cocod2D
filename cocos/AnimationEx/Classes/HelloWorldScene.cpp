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

	/* Sprite Frame
	auto pMan = Sprite::create("Images/grossini_dance_01.png");
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	animation->addSpriteFrameWithFile("Images/grossini_dance_01.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_02.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_03.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_04.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_05.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_06.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_07.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_08.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_09.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_10.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_11.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_12.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_13.png");
	animation->addSpriteFrameWithFile("Images/grossini_dance_14.png");

	auto animate = Animate::create(animation);

	//pMan->runAction(animate);

	auto rep = RepeatForever::create(animate);
	pMan->runAction(rep);
	*/

	/*
	 * Sprite Sheet
	// 1. From Sprite
	auto sprite = Sprite::create("Images/grossini_dance_atlas.png");
	auto texture1 = sprite->getTexture();

	// 2. From Texture
	auto texture2 = Director::getInstance()->getTextureCache()->addImage("Images/grossini_dance_atlas.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 14; i++)
	{
		int column = i % 5;
		int row = i / 5;

		animation->addSpriteFrameWithTexture(
			texture2,
			Rect(column * 85, row * 121, 85, 121)
		);
	}

	auto pMan = Sprite::createWithTexture(texture1, Rect(0, 0, 85, 121));
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pMan->runAction(rep);
	 */

	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("animations/grossini.plist");

	Vector<SpriteFrame*> animFrames;

	char str[100] = { 0 };
	for (int i = 1; i < 15; i++)
	{
		sprintf(str, "grossini_dance_%02d.png", i);
		SpriteFrame* frame = cache->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}

	auto pMan = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	pMan->setPosition(Vec2(240, 160));
	this->addChild(pMan);

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);

	pMan->runAction(rep);

    return true;
}

