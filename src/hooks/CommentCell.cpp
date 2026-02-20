#include <Geode/Geode.hpp>
#include <Geode/modify/CommentCell.hpp>

using namespace geode::prelude;

class $modify(CommentCell) {

    void loadFromComment(GJComment * comment) {
        CommentCell::loadFromComment(comment);

        if (!comment->m_levelID || comment->m_hasLevelID) {
            static_cast<CCSprite*>(this->getChildren()->objectAtIndex(0))->setVisible(false);

            auto pos = this->getPosition();
            if (m_height == 36) {
                auto bg = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
                bg->setColor(ccBLACK);
                bg->setOpacity(32);
                bg->setScale(0.375f);
                bg->setContentSize({ 890, 85 });
                bg->setPosition(pos.x + 170, pos.y + 18);
                bg->setZOrder(-1);
                this->addChild(bg);
            }
            else {
                for (auto node : CCArrayExt<CCNode*>(m_mainLayer->getChildren())) {
                    if (auto bg = typeinfo_cast<cocos2d::extension::CCScale9Sprite*>(node)) {
                        bg->setColor(ccBLACK);
                        bg->setOpacity(32);
                    }
                }
            }
        }
    }

#if defined(GEODE_IS_ANDROID) || defined(GEODE_IS_MACOS) || defined(GEODE_IS_IOS)
    void draw() {
        if (this->m_backgroundLayer->isVisible())
            CommentCell::draw();
    }
#endif
};