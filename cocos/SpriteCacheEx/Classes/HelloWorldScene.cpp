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

	auto cache = SpriteFrameCache::getInstance();
	// 1
	cache->addSpriteFramesWithFile("animations/grossini_family.plist");
	// 2
	cache->addSpriteFramesWithFile("animations/grossini.plist");
	// 3
	auto pSprite = SpriteFrame::create("Images/blocks9.png", Rect(0, 0, 96, 96));
	cache->addSpriteFrame(pSprite, "blocks9.png");

	// From 1
	auto pWoman = Sprite::createWithSpriteFrameName("grossinis_sister1.png");
	pWoman->setPosition(Vec2(120, 220));
	this->addChild(pWoman);

	// From 2
	auto pMan = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	pMan->setPosition(Vec2(240, 220));
	this->addChild(pMan);

	auto pBox = Sprite::createWithSpriteFrameName("blocks9.png");
	pBox->setPosition(Vec2(360, 220));
	this->addChild(pBox);



	auto texture1 = Director::getInstance()->getTextureCache()->addImage("Images/grossini_dance_atlas.png");
	auto texture2 = Director::getInstance()->getTextureCache()->addImage("animations/dragon_animation.png");

	auto pMan2 = Sprite::createWithTexture(texture1, Rect(0, 0, 85, 121));
	pMan2->setPosition(Vec2(120, 100));
	this->addChild(pMan2);

	auto pDragon = Sprite::createWithTexture(texture2, Rect(0, 0, 130, 140));
	pDragon->setPosition(Vec2(240, 100));
	this->addChild(pDragon);

	Director::getInstance()->getTextureCache()->addImageAsync(
		"Images/blocks9.png",
		CC_CALLBACK_1(HelloWorld::imageLoaded, this));

    return true;
}

void HelloWorld::imageLoaded(Ref* pSender)
{
	auto tex = static_cast<Texture2D*>(pSender);
	auto sprite = Sprite::createWithTexture(tex);
	sprite->setPosition(Vec2(360, 100));

	this->addChild(sprite);

	log("Image loaded: %p", pSender);
}