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
#include "TestScene2.h"
#include "TestScene3.h"

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

	/* ��� ��ȯ
	auto item1 = MenuItemFont::create("pushScene", CC_CALLBACK_1(HelloWorld::doPushScene, this));
	item1->setColor(Color3B::BLACK);

	auto item2 = MenuItemFont::create("replaceScene", CC_CALLBACK_1(HelloWorld::doReplaceScene, this));
	item2->setColor(Color3B::BLACK);
	*/

	/* ��� ��ȯ �ִϸ��̼�
	auto item1 = MenuItemFont::create("pushScene transition", CC_CALLBACK_1(HelloWorld::doPushSceneTran, this));
	item1->setColor(Color3B::BLACK);

	auto item2 = MenuItemFont::create("replaceScene transition", CC_CALLBACK_1(HelloWorld::doReplaceSceneTran, this));
	item2->setColor(Color3B::BLACK);
	*/

	auto item1 = MenuItemFont::create("Scene1 -> Scene2", CC_CALLBACK_1(HelloWorld::doChangeScene, this));
	item1->setColor(Color3B::BLACK);

	// auto pMenu = Menu::create(item1, item2, nullptr);
	auto pMenu = Menu::create(item1, nullptr);
	pMenu->alignItemsVertically();
	this->addChild(pMenu);

	log("HelloWorld :: init");

    return true;
}


void HelloWorld::doPushScene(Ref* pSender)
{
	auto pScene = TestScene2::createScene();
	Director::getInstance()->pushScene(pScene);
}

void HelloWorld::doReplaceScene(Ref* pSender)
{
	auto pScene = TestScene3::createScene();
	Director::getInstance()->replaceScene(pScene);
}

void HelloWorld::doPushSceneTran(Ref* pSender)
{
	static int nIndex1 = 0;

	auto pScene = TestScene2::createScene();
	Director::getInstance()->pushScene(createTransition(nIndex1, 1, pScene));

	nIndex1++;
	if (nIndex1 > 40)
	{
		nIndex1 = 0;
	}
}

void HelloWorld::doReplaceSceneTran(Ref* pSender)
{
	static int nIndex2 = 2;

	auto pScene = TestScene3::createScene();
	Director::getInstance()->replaceScene(createTransition(nIndex2, 1, pScene));

	nIndex2--;
	if (nIndex2 < 0)
	{
		nIndex2 = 40;
	}
}

TransitionScene* HelloWorld::createTransition(int nIndex, float t, Scene* s)
{
	Director::getInstance()->setDepthTest(false);

	switch (nIndex)
	{
		// �����ϸ鼭 Zoom
	case 0: return TransitionJumpZoom::create(t, s);
		// �ð�������� ħ�� ���鼭 ����� �ٲ�
	case 1: return TransitionProgressRadialCCW::create(t, s);
		// �ð� �ݴ� �������� ħ�� ���鼭 ����� �ٲ�
	case 2: return TransitionProgressRadialCW::create(t, s);
	case 3: return TransitionProgressHorizontal::create(t, s);
	case 4: return TransitionProgressVertical::create(t, s);
	case 5: return TransitionProgressInOut::create(t, s);
	case 6: return TransitionProgressOutIn::create(t, s);
		// ����
	case 7: return TransitionCrossFade::create(t,s);
		// ������ �ѱ�����
	case 8: return TransitionPageTurn::create(t, s, false);
	case 9: return TransitionPageTurn::create(t, s, true);
		// �ٵ��ǹ��� �����ϴܺ��� ������ܼ����� �����
	case 10: return TransitionFadeTR::create(t, s);
		// �ٵ��ǹ��� ������ܺ��� �����ϴܼ����� �����
	case 11: return TransitionFadeBL::create(t, s);
		// �ϴܿ��� ������� �߶�
	case 12: return TransitionFadeUp::create(t, s);
		// ��ܿ��� �ϴ����� �߶�
	case 13: return TransitionFadeDown::create(t, s);
		// �ٵ��ǹ��� �Ѹ���
	case 14: return TransitionTurnOffTiles::create(t, s);
		// ���η� ����� ����
	case 15: return TransitionSplitRows::create(t, s);
		// ���η� ����� ����, �糡�� �ε���� ������ �������� ����
	case 16: return TransitionSplitCols::create(t, s);
		// ���̵��ξƿ� : ���� ȭ��
	case 17: return TransitionFade::create(t, s);
		// ���̵��ξƿ� : �Ͼ� ȭ��
	case 18: return TransitionFade::create(t, s, Color3B::WHITE);
		// X��(Ⱦ��)�� �������� ȸ��
	case 19: return TransitionFlipX::create(t, s, TransitionScene::Orientation::LEFT_OVER);
	case 20: return TransitionFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
		// Y�� (����)�� �������� ȸ��
	case 21: return TransitionFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);
	case 22: return TransitionFlipY::create(t, s, TransitionScene::Orientation::DOWN_OVER);
		// ���������鼭 ����������� �Ѿ
	case 23: return TransitionFlipAngular::create(t, s, TransitionScene::Orientation::LEFT_OVER);
	case 24: return TransitionFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
		// X��(Ⱦ��)�� �������� ȸ�� (Ȯ��)
	case 25: return TransitionZoomFlipX::create(t, s, TransitionScene::Orientation::LEFT_OVER);
	case 26: return TransitionZoomFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
		// Y��(����)�� �������� ȸ�� (Ȯ��)
	case 27: return TransitionZoomFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);
	case 28: return TransitionZoomFlipY::create(t, s, TransitionScene::Orientation::DOWN_OVER);
		// ���������鼭 ����������� �Ѿ (Ȯ��)
	case 29: return TransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::LEFT_OVER);
	case 30: return TransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
		// ������� ���� ������� Ȯ��
	case 31: return TransitionShrinkGrow::create(t, s);
		// ȸ���ϸ鼭 Zoom
	case 32: return TransitionRotoZoom::create(t, s);
		// ���ʿ��� ��������� ��Ÿ���� ��������� ���
	case 33: return TransitionMoveInL::create(t, s);
		// �����ʿ��� ��������� ��Ÿ��
	case 34: return TransitionMoveInR::create(t, s);
		// ���ʿ��� ��������� ��Ÿ��
	case 35: return TransitionMoveInT::create(t, s);
		// �Ʒ��ʿ��� ��������� ��Ÿ��
	case 36: return TransitionMoveInB::create(t, s);
		// ���ʿ��� ��������� ��Ÿ���� ��������� �о
	case 37: return TransitionSlideInL::create(t, s);
		// �����ʿ��� ��������� ��Ÿ���� ��������� �о
	case 38: return TransitionSlideInR::create(t, s);
		// ���ʿ��� ��������� ��Ÿ���� ��������� �о
	case 39: return TransitionSlideInT::create(t, s);
		// �Ʒ��ʿ��� ��������� ��Ÿ���� ��������� �о
	case 40: return TransitionSlideInB::create(t, s);
	default: break;
	}

	return nullptr;
}

void HelloWorld::doChangeScene(Ref* pSender)
{
	auto pScene = TestScene2::createScene();
	Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(1, pScene));
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	log("HelloWorld :: onEnter");
}

void HelloWorld::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();

	log("HelloWorld :: onEnterTransitionDidFinish");
}

void HelloWorld::onExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();

	log("HelloWorld :: onExitTransitionDidStart");
}

void HelloWorld::onExit()
{
	Scene::onExit();

	log("HelloWorld :: onExit");
}

HelloWorld::~HelloWorld()
{
	log("HelloWorld :: dealloc");
}
