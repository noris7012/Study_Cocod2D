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

	auto wlayer = LayerColor::create(Color4B::BLACK);
	this->addChild(wlayer);

	auto pLabel1 = Label::create("Hello World", "", 34);
	pLabel1->setPosition(Vec2(240, 220));
	this->addChild(pLabel1);

	/* ���� ����
	auto pLabel2 = Label::createWithSystemFont("���ع��� ��λ��� ������ �⵵�� �ϴ����� �����ϻ� �츮���� ����", "", 34, Size(300, 200), TextHAlignment::CENTER, TextVAlignment::CENTER);
	pLabel2->setPosition(Vec2(240, 120));
	pLabel2->setColor(Color3B::RED);
	this->addChild(pLabel2);
    */

	/* ��Ʈ�� ��Ʈ
	auto pLabel2 = Label::createWithBMFont("fonts/bitmapFontTest.fnt", "Hi Hello World");
	pLabel2->setPosition(Vec2(240, 120));
	this->addChild(pLabel2);
	*/

	/* ĳ���͸�
	auto pLabel2 = Label::createWithCharMap("fonts/tuffy_bold_italic-charmap.png", 48, 64, ' ');
	pLabel2->setPosition(Vec2(240, 120));
	pLabel2->setString("1234");
	this->addChild(pLabel2);
	*/

	/* ĳ���͸� with plist
	auto pLabel2 = Label::createWithCharMap("fonts/tuffy_bold_italic-charmap.plist");
	pLabel2->setPosition(Vec2(240, 120));
	pLabel2->setString("1234");
	this->addChild(pLabel2);
	*/

	TTFConfig ttfConfig("fonts/Scissor Cuts.ttf", 40);

	auto pLabel2 = Label::createWithTTF(ttfConfig, "Normal");
	pLabel2->setPosition(Vec2(240, 120));
	pLabel2->setColor(Color3B::WHITE);
	this->addChild(pLabel2);

	auto pLabel3 = Label::createWithTTF(ttfConfig, "Glow");
	pLabel3->setPosition(Vec2(240, 150));
	pLabel3->setColor(Color3B::GREEN);
	pLabel3->enableGlow(Color4B::WHITE);
	this->addChild(pLabel3);

	ttfConfig.outlineSize = 2;
	ttfConfig.bold = true;

	auto pLabel4 = Label::createWithTTF(ttfConfig, "Outline");
	pLabel4->setPosition(Vec2(240, 180));
	pLabel4->setColor(Color3B::WHITE);
	pLabel4->enableOutline(Color4B::BLUE);
	this->addChild(pLabel4);

	auto pLabel5 = Label::createWithTTF(ttfConfig, "Shadow");
	pLabel5->setPosition(Vec2(240, 210));
	pLabel5->setColor(Color3B::RED);
	pLabel5->enableShadow(Color4B::BLACK);
	this->addChild(pLabel5);

	/*
	 * LabelTestNew.cpp�� ���캸�� �پ��� ������ ���� �ִ�.
	 * ��Ƽ�÷����� ��ǥ�� �����Ѵٸ� Ʈ�� Ÿ�� ��Ʈ�� �߰��ؼ� ����ϴ� ���� ����.
	 * ��Ʈ�� ��Ʈ ������ ����ϴ� ����� ĳ���͸��� ����ϴ� ����� Ʈ�� Ÿ�� ��Ʈ�� ����ϴ� ����� ���� �ξ� ������.
	 */

    return true;
}
