#include "MyTestScene.h"

Scene* MyTest::createScene() {
	Scene* scene = Scene::create();
	MyTest* layer = MyTest::create();
	scene->addChild(layer);
	return scene;
}

bool MyTest::init() {
	Label* label = Label::create("HI,dre u mt?", "Arial", 40);
	label->setPosition(ccp(200, 200));
	this->addChild(label);
	return true;
}