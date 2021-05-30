#include "MyWorldScene.h"

CCScene* MyWorldScene::scene() {
	CCScene* scene = CCScene::create();
	MyWorldScene* layer = MyWorldScene::create();
	scene->addChild(layer);
	return scene;
}

bool MyWorldScene::init() {
	CCLabelTTF* label = CCLabelTTF::create("HI,dre u mt?", "Arial", 40);
	label->setPosition(ccp(200, 200));
	this->addChild(label);
	return true;
}