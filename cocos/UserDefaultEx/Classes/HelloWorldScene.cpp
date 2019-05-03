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

	std::string ret = UserDefault::getInstance()->getStringForKey("str_key");
	log("string is %s", ret.c_str());

	int i = UserDefault::getInstance()->getIntegerForKey("int_key");
	log("integer is %d", i);

	float f = UserDefault::getInstance()->getFloatForKey("float_key");
	log("float is %f", f);

	double d = UserDefault::getInstance()->getDoubleForKey("double_key");
	log("double is %f", d);

	bool b = UserDefault::getInstance()->getBoolForKey("bool_key");
	if (b)
	{
		log("bool is true");
	}
	else
	{
		log("bool is false");
	}

	log("***************************** init value **************************");

	UserDefault::getInstance()->setStringForKey("str_key", "value1");
	UserDefault::getInstance()->setIntegerForKey("int_key", 10);
	UserDefault::getInstance()->setFloatForKey("float_key", 2.3f);
	UserDefault::getInstance()->setDoubleForKey("double_key", 2.4);
	UserDefault::getInstance()->setBoolForKey("bool_key", true);

	ret = UserDefault::getInstance()->getStringForKey("str_key");
	log("string is %s", ret.c_str());

	i = UserDefault::getInstance()->getIntegerForKey("int_key");
	log("integer is %d", i);

	f = UserDefault::getInstance()->getFloatForKey("float_key");
	log("float is %f", f);

	d = UserDefault::getInstance()->getDoubleForKey("double_key");
	log("double is %f", d);

	b = UserDefault::getInstance()->getBoolForKey("bool_key");
	if (b)
	{
		log("bool is true");
	}
	else
	{
		log("bool is false");
	}

	log("***************************** after change value **************************");

	UserDefault::getInstance()->setStringForKey("str_key", "value2");
	UserDefault::getInstance()->setIntegerForKey("int_key", 11);
	UserDefault::getInstance()->setFloatForKey("float_key", 2.5f);
	UserDefault::getInstance()->setDoubleForKey("double_key", 2.6);
	UserDefault::getInstance()->setBoolForKey("bool_key", false);

	UserDefault::getInstance()->flush();

	ret = UserDefault::getInstance()->getStringForKey("str_key");
	log("string is %s", ret.c_str());

	i = UserDefault::getInstance()->getIntegerForKey("int_key");
	log("integer is %d", i);

	f = UserDefault::getInstance()->getFloatForKey("float_key");
	log("float is %f", f);

	d = UserDefault::getInstance()->getDoubleForKey("double_key");
	log("double is %f", d);

	b = UserDefault::getInstance()->getBoolForKey("bool_key");
	if (b)
	{
		log("bool is true");
	}
	else
	{
		log("bool is false");
	}


    return true;
}
