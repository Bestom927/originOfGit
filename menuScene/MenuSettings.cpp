#include "MenuSettings.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

Scene* MenuSettings::createScene()
{
	return MenuSettings::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuSettings::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* settingMenuBackground = Sprite::create("menu/background.jpg");
	settingMenuBackground->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(settingMenuBackground);


	MenuItemFont::setFontName("POBG");
	MenuItemFont::setFontSize(86);

	//ÒôÐ§ÉèÖÃSound Effect

	auto* soundEffectLabel = Label::createWithSystemFont("Sound Effect", "Arial", 80, Size::ZERO, TextHAlignment::RIGHT);
	soundEffectLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 7));
	this->addChild(soundEffectLabel, 1);

	auto* soundEffectOff = MenuItemImage::create(
		"button/OFF-normal.png",
		"button/OFF-push.png");

	auto* soundEffectOn = MenuItemImage::create(
		"button/ON-normal.png",
		"button/ON-push.png");

	auto* soundEffectStatus = soundEffectOff;
	auto* soundEffectChoice = soundEffectOn;

	if (isEffect) {
		soundEffectStatus = soundEffectOn;
		soundEffectChoice = soundEffectOff;
	}

	auto soundEffectControlItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(MenuSettings::menuSoundEffectCallback, this),
		soundEffectStatus,
		soundEffectChoice,
		NULL);

	soundEffectControlItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 6));

	//ÒôÀÖÉèÖÃ Music
	//ÒôÀÖ±êÇ© Music Label (the white words to simblize the item)
	auto* musicLabel = Label::createWithSystemFont("Music", "Arial", 80, Size::ZERO, TextHAlignment::RIGHT);
	musicLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 5));
	this->addChild(musicLabel, 1);

	auto* musicOff = MenuItemImage::create(
		"button/OFF-normal.png",
		"button/OFF-push.png");

	auto* musicOn = MenuItemImage::create(
		"button/ON-normal.png",
		"button/ON-push.png");

	auto* musicStatus = musicOff;
	auto* musicChoice = musicOn;

	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
		 musicStatus = musicOn;
		 musicChoice = musicOff;
	}

	auto musicControlItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(MenuSettings::menuMusicCallback, this),
		musicStatus,
		musicChoice,
		NULL);

	musicControlItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8 * 4));


	//back

	auto* backItem = MenuItemImage::create(
		"button/BACK-normal.png",
		"button/BACK-push.png");

	auto backMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(MenuSettings::menuBackCallback, this),
		backItem,
		NULL);

	backMenuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 4));
	//this->addChild(backMenuItem);

	//menu
	Menu* mn = Menu::create(soundEffectControlItem, musicControlItem, backMenuItem, NULL);
	mn->setPosition(Size::ZERO);
	this->addChild(mn);


	return true;
}



void MenuSettings::menuSoundEffectCallback(Ref* pSender)
{
	auto* soundEffectControlItem = (MenuItemToggle*)pSender;
	log("soundEffectControlItem %d", soundEffectControlItem->getSelectedIndex());

	if (isEffect) {
		SimpleAudioEngine::getInstance()->playEffect("sound/Blip.wav");
		//°´¼üÉù
	}
	if (isEffect) //Ñ¡ÖÐ×´Ì¬ Off -> On
	{
		isEffect = false;
	}
	else
	{
		isEffect = true;
		SimpleAudioEngine::getInstance()->playEffect("sound/Blip.wav");
	}
	
}

void MenuSettings::menuMusicCallback(Ref* pSender)
{
	auto* musicControlItem = (MenuItemToggle*)pSender;
	log("menuMusicCallback %d", musicControlItem->getSelectedIndex());

	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) //Ñ¡ÖÐ×´Ì¬ Off -> On
	{
		SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/backgroundMusic.mp3");
	}
	else
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/backgroundMusic.mp3", true);
		//true--->loop
	}

	if (isEffect) {
		SimpleAudioEngine::getInstance()->playEffect("sound/Blip.wav");
		//°´¼üÉù
	}
}

void MenuSettings::menuBackCallback(cocos2d::Ref* pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	log("Touch back MenuItem %p", item);

	Director::getInstance()->popScene();

}
