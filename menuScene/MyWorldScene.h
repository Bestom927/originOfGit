#pragma once
#ifndef __MYWORLDSCENE__
#define __MYWORLDSCENE__
#include "cocos2d.h"
using namespace cocos2d;

class MyWorldScene :public CCLayer {
public:
	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(MyWorldScene);
};
#endif
