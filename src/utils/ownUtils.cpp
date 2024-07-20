
#include "ownUtils.h"
#include <Geode/Geode.hpp>

using namespace geode::prelude;




void ownUtils::FixLayerv3(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	CCObject* pObj = nullptr;
	auto layerChild = dynamic_cast<CCLayer*>(layer->getChildren()->objectAtIndex(0));

	CCARRAY_FOREACH(layerChild->getChildren(), pObj) {
		CCNode* currentNode = (CCNode*)pObj;
		CCPoint xy = currentNode->getPosition();
		currentNode->getContentSize();

		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {

			currentNode->setVisible(false);
		}
	}
}
void ownUtils::FixLayerv2(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	CCObject* pObj = nullptr;

	CCARRAY_FOREACH(layer->getChildren(), pObj) {
		CCNode* currentNode = (CCNode*)pObj;
		CCPoint xy = currentNode->getPosition();
		currentNode->getContentSize();

		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {

			currentNode->setVisible(false);
		}
	}
}
void ownUtils::FixLayer(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	CCObject* pObj = nullptr;
	CCARRAY_FOREACH(layer->getChildren(), pObj) {
		CCNode* currentNode = (CCNode*)pObj;
		CCPoint xy = currentNode->getPosition();
		currentNode->getContentSize();

		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {

			currentNode->setContentSize(newNodeSize);

			CCArray* children = currentNode->getChildren();

			currentNode->setZOrder(1);

			for (int i = 0; i < 4; i++)
			{
				auto sprite = (CCSprite*)children->objectAtIndex(i); //for remove brown corners on comments
				sprite->setVisible(false);
			}

			currentNode->setZOrder(2);
		}
	}





}

cocos2d::ccColor4B ownUtils::ToColor4B(ccColor3B sourceColor)
{
	return ccColor4B{ sourceColor.r, sourceColor.g, sourceColor.b,255 };
}
