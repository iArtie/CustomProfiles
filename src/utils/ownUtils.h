#pragma once
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class ownUtils {
public:
	static void FixLayerv3(CCLayer* layer, int width, int height);
	static void FixLayerv2(CCLayer* layer, int width, int height);
	static void FixLayer(CCLayer* layer, int width, int height);
	static cocos2d::ccColor4B ToColor4B(ccColor3B sourceColor);
};