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
using namespace cocos2d::ui;

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

	Size editBoxSize = Size(300, 60);

	std::string pNormalSprite = "Images/green_edit.png";
	_editName = ui::EditBox::create(editBoxSize, ui::Scale9Sprite::create(pNormalSprite));
	_editName->setPosition(Vec2(240, 250));
	_editName->setFontSize(25);
	_editName->setFontColor(Color3B::RED);
	_editName->setPlaceHolder("Name:");
	_editName->setPlaceholderFontColor(Color3B::WHITE);
	_editName->setMaxLength(8);
	_editName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	_editName->setDelegate(this);
	addChild(_editName);

	_editPassword = ui::EditBox::create(editBoxSize, "Images/orange_edit.png");
	_editPassword->setPosition(Vec2(240, 150));
	_editPassword->setFontSize(25);
	_editPassword->setFontColor(Color3B::GREEN);
	_editPassword->setPlaceHolder("Password:");
	_editPassword->setMaxLength(6);
	_editPassword->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	_editPassword->setInputFlag(ui::EditBox::InputFlag::PASSWORD);
	_editPassword->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);
	_editPassword->setDelegate(this);
	addChild(_editPassword);

	_editEmail = ui::EditBox::create(Size(editBoxSize.width, editBoxSize.height), "Images/yellow_edit.png");
	_editEmail->setPosition(Vec2(240, 50));
	_editEmail->setFontSize(25);
	_editEmail->setPlaceHolder("Email:");
	_editEmail->setInputMode(ui::EditBox::InputMode::EMAIL_ADDRESS);
	_editEmail->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	_editEmail->setDelegate(this);
	addChild(_editEmail);

    return true;
}

void HelloWorld::editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox)
{
	log("editBox %p DidBegin !", editBox);
}

void HelloWorld::editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox)
{
	log("editBox %p DidEnd !", editBox);
}

void HelloWorld::editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text)
{
	log("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

void HelloWorld::editBoxReturn(cocos2d::ui::EditBox* editBox)
{
	log("editBox %p was returned !", editBox);
}
