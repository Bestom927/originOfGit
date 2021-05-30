#pragma once
#ifndef __MYTESTSCENE__
#define __MYTESTSCENE__
#include "cocos2d.h"
using namespace cocos2d;

class MyTest :public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MyTest);
};
#endif
