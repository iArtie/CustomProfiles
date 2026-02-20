
#include "ownUtils.h"
#include <Geode/Geode.hpp>

using namespace geode::prelude;




void ownUtils::FixLayerv3(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	CCObject* pObj = nullptr;
	auto layerChild = dynamic_cast<CCLayer*>(layer->getChildren()->objectAtIndex(0));

	for (auto currentNode : CCArrayExt<CCNode*>(layerChild->getChildren())) {
		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {
			currentNode->setVisible(false);
		}
	}

}
void ownUtils::FixLayerv2(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	CCObject* pObj = nullptr;

	for (auto obj : CCArrayExt(layer->getChildren())) {
		auto currentNode = static_cast<CCNode*>(obj);

		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {
			currentNode->setVisible(false);
		}
	}

}
void ownUtils::FixLayer(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	
	for (auto currentNode : CCArrayExt<CCNode*>(layer->getChildren())) {
		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {
			currentNode->setContentSize(newNodeSize);
			currentNode->setZOrder(1);

			if (auto children = currentNode->getChildren()) {
				

				for (int i = 0; i < 4; i++) {
					if (auto sprite = static_cast<CCSprite*>(children->objectAtIndex(i))) {
						sprite->setVisible(false); // remove brown corners
					}
				}
			}

			currentNode->setZOrder(2);
		}
	}

}


cocos2d::ccColor4B ownUtils::ToColor4B(ccColor3B sourceColor)
{
	return ccColor4B{ sourceColor.r, sourceColor.g, sourceColor.b,255 };
}
