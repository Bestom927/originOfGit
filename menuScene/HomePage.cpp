#include "HomePage.h"
#include "cocos2d.h"

#include "ui/CocosGUI.h"

using namespace cocos2d::ui;

cocos2d::Scene* HomePage::createScene()
{
    return HomePage::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HomePage::init()
{
    if (!Scene::init())
    {
        return false;
    }






    return true;
}

//popScene
void HomePage::menuCloseCallback(Ref* pSender)
{
    cocos2d::Director::getInstance()->popScene();
}
