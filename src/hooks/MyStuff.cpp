#include <Geode/Geode.hpp>
#include <Geode/modify/MyStuffPopup.hpp>

using namespace geode::prelude;

class $modify(CustomMyStuffPopup, MyStuffPopup) {
    struct Fields {
        std::string discordUsername;
    };

    void onDiscordProfile(CCObject*) {
        if (m_fields->discordUsername.empty()) return;
        geode::utils::clipboard::write(m_fields->discordUsername);
        Notification::create("Copied to clipboard")->show();
    }

    bool init(GJUserScore* score) {
        if (!MyStuffPopup::init(score)) return false;
        if (!score || score->m_discordUsername.empty()) return true;

        m_fields->discordUsername = fmt::format("@{}", score->m_discordUsername);

        auto bg = m_mainLayer->getChildByType<CCScale9Sprite>(0);
        bg->setContentHeight(120.f);
        for (auto child : CCArrayExt<CCNode*>(m_mainLayer->getChildren())) {
            if (child != bg) child->setPositionY(child->getPositionY() + 10.f);
        }

        auto childBG = CCScale9Sprite::create("square02b_001.png");
        childBG->setPosition({ bg->getPositionX(), bg->getPositionY() - 12.f });
        childBG->setContentSize({ 210.f, 70.f });
        childBG->setColor(ccBLACK);
        childBG->setOpacity(50);
        m_mainLayer->addChild(childBG);

        auto prefix = TextArea::create("<cl>Discord</c>:", "chatFont.fnt", 0.7f, 70.f, { 0.5f, 0.5f }, 20.f, false, 0);
        prefix->setPosition({ -16.f, 2.f });

        auto label = CCLabelBMFont::create(m_fields->discordUsername.c_str(), "chatFont.fnt");
        label->limitLabelWidth(130.f, 0.7f, 0.f);

        auto btn = CCMenuItemSpriteExtra::create(
            label, this, menu_selector(CustomMyStuffPopup::onDiscordProfile));
        btn->setAnchorPoint({ 0.f, 0.5f });
        btn->setPosition({ -2.f, 0.f });

        auto row = CCMenu::create();
        row->addChild(prefix);
        row->addChild(btn);

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        row->setPosition({ winSize.width / 2.f, winSize.height / 2.f - 30.f });
        m_mainLayer->addChild(row);

        return true;
    }
};  