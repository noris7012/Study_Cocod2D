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

#include "tinyxml2/tinyxml2.h"

#include "json/rapidjson.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"

USING_NS_CC;
using namespace tinyxml2;

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

	//xml();
	json();

    return true;
}

void HelloWorld::xml()
{
	FileUtils* util = FileUtils::getInstance();

	std::string path = util->fullPathForFilename("data/test_data.xml");
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	XMLError error = doc->LoadFile(path.c_str());

	if (error != 0)
	{
		log("Error Number : %d", error);
		return;
	}

	XMLElement* root = doc->RootElement();

	XMLElement* val = root->FirstChildElement("total");
	if (val)
	{
		log("val element = %s", val->GetText());
	}

	val = val->NextSiblingElement("page");
	if (val)
	{
		log("val element = %s", val->GetText());
	}

	val = val->NextSiblingElement("per");
	if (val)
	{
		log("val element = %s", val->GetText());
	}

	XMLElement* array = val->NextSiblingElement();
	XMLElement* child = array->FirstChildElement();
	while (child)
	{
		XMLElement* child2 = child->FirstChildElement();
		while (child2)
		{
			log("child element = %s", child2->GetText());
			child2 = child2->NextSiblingElement();
		}
		child = child->NextSiblingElement();
	}

	delete doc;
}

void HelloWorld::json()
{
	FileUtils* util = FileUtils::getInstance();

	std::string jsonData = util->getStringFromFile("data/test_data.json");
	log("%s\n", jsonData.c_str());

	rapidjson::Document doc;
	doc.Parse<0>(jsonData.c_str());
	if (doc.HasParseError())
	{
		log("Get Parse Error %s\n", doc.GetParseError());
		return;
	}

	std::string str = doc["string"].GetString();
	log("name = %s", str.c_str());

	int n1 = doc["integer"].GetInt();
	log("i = %d", n1);

	bool isTF = doc["bool"].GetBool();
	log("t = %d", isTF);

	float n2 = doc["float"].GetFloat();
	log("f = %.2f", n2);

	const rapidjson::Value &arr = doc["array"];
	if (arr.IsArray())
	{
		for (rapidjson::SizeType i = 0; i < arr.Size(); ++i)
		{
			auto name = arr[i]["name"].GetString();
			auto age = arr[i]["age"].GetInt();
			log("name:%s, age:%d", name, age);
		}
	}
}
