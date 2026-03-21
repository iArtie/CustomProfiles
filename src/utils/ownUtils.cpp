
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
    for (auto* node : CCArrayExt<CCNode*>(layer->getChildren())) {

		if (node->getContentSize().width == width && node->getContentSize().height == height)
		{
            if (auto* list = typeinfo_cast<GJCommentListLayer*>(node)) {

                list->setOpacity(0);
                for (auto* child : CCArrayExt<CCNode*>(list->getChildren())) {
                    auto id = child->getID();
                    if (id == "left-border" || id == "right-border" || id == "top-border" ||
                        id == "bottom-border" || id == "alphalaneous.happy_textures/outline" ||
                        id == "alphalaneous.happy_textures/special-border") {
                        child->setVisible(false);
                    }
                }

            }
		}
    }
}

void ownUtils::FixIconLayer(CCLayer* layer, int width, int height) {
    for (auto* node : CCArrayExt<CCNode*>(layer->getChildren())) {

		if (node->getContentSize().width == width && node->getContentSize().height == height)
		{
            if (auto* list = typeinfo_cast<GJCommentListLayer*>(node)) {

                list->setOpacity(0);
                for (auto* child : CCArrayExt<CCNode*>(list->getChildren())) {
                    auto id = child->getID();
                    if (id == "left-border" || id == "right-border" || id == "top-border" ||
                        id == "bottom-border" || id == "alphalaneous.happy_textures/outline" ||
                        id == "alphalaneous.happy_textures/special-border") {
                        child->setVisible(false);
                    }
                }

            }
		}
    }
}

cocos2d::ccColor4B ownUtils::ToColor4B(ccColor3B sourceColor)
{
	return ccColor4B{ sourceColor.r, sourceColor.g, sourceColor.b,255 };
}
