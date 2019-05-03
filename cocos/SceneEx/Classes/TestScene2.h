#ifndef __SceneTrans__TestScene2__
#define __SceneTrans__TestScene2__

#include "cocos2d.h"

class TestScene2 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(TestScene2);

	void doClose(Ref* pSender);

	void doChangeScene(Ref* pSender);

	void onEnter() override;
	void onEnterTransitionDidFinish() override;
	void onExitTransitionDidStart() override;
	void onExit() override;
	~TestScene2(void);
};

#endif