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


    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    Button* button[10];
    for (int i = 0; i < 10; i++) {
        button[i] = Button::create("CloseNormal.png", "CloseSelected.png");
        //button->
    }












    auto closeItem = cocos2d::MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HomePage::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(cocos2d::Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = cocos2d::Menu::create(closeItem, NULL);
    menu->setPosition(cocos2d::Vec2::ZERO);
    this->addChild(menu, 1);


    return true;
}

//popScene
void HomePage::menuCloseCallback(Ref* pSender)
{
    cocos2d::Director::getInstance()->popScene();
}

