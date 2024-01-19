#pragma once
#include <Geode/Geode.hpp>
using namespace cocos2d;

class ProfilesConfig : CCLayerColor
{
public:
	CCLayer* layerawa;
	static ProfilesConfig* create(CCLayer*layer);
	void show();
	void onOptionsBtnClick(CCObject* sender);

	void corner1(CCObject* sender);
	void corner2(CCObject* sender);
	void corner3(CCObject* sender);

	void color1(CCObject* sender);
	void color2(CCObject* sender);
	void color3(CCObject* sender);

	void onReturn(CCObject* sender);

	void disableInfolabel(CCObject* sender);
	bool init(CCLayer* layer);
	virtual void keyBackClicked();
	void backButton(CCObject*);
	void close();
};