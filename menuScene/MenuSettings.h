#pragma once
#ifndef __MENUSETTINGS_H__
#define __MENUSETTINGS_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class MenuSettings : public cocos2d::Scene
{
    bool isEffect = false;
    bool isMusic = false;
public:
    static Scene* createScene();

    virtual bool init();


    void menuSoundEffectCallback(cocos2d::Ref* pSender);
    void menuMusicCallback(cocos2d::Ref* pSender);

    void menuBackCallback(cocos2d::Ref* pSender);


    // implement the "static create()" method manually
    CREATE_FUNC(MenuSettings);
};

#endif
