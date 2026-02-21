#include <Geode/Geode.hpp>

using namespace geode::prelude;

class DiscordPopup : public geode::Popup {
protected:
    CCLabelBMFont* m_tagLabel = nullptr;
    std::string m_value;

    bool init(std::string const& value) {
        if (!Popup::init(170.f, 130.f, "square01_001.png"))
            return false;

        this->setTitle("Discord","goldFont.fnt",0.85);

        m_value = value;

        m_tagLabel = CCLabelBMFont::create(
            m_value.c_str(),"chatFont.fnt");
        
		m_tagLabel->limitLabelWidth(m_mainLayer->getContentWidth() - 30, 1.f, 0);

        auto btn = CCMenuItemSpriteExtra::create(
            m_tagLabel,
            this,
            menu_selector(DiscordPopup::onCopytoClipboard)
        );

        m_tagLabel->setPosition(CCDirector::sharedDirector()->getWinSize()/2);
		m_closeBtn->setVisible(false);
		auto btn1Spr = ButtonSprite::create("OK", 90, 0, 0.95, false);

        btn1Spr->setScale(0.85f);

		m_title->setPositionY(m_title->getPositionY() - 4);

        auto btn1 = CCMenuItemSpriteExtra::create(
            btn1Spr,
            this,
            menu_selector(DiscordPopup::onClose)
		);
        btn->setContentSize({ 400.f, 17.f });
        m_tagLabel->setPositionY(10);


        m_buttonMenu->addChildAtPosition(btn, Anchor::Center);

		m_tagLabel->setPositionX(m_tagLabel->getPositionX() - btn->getPositionX());
        m_buttonMenu->addChildAtPosition(btn1, Anchor::Bottom);

		btn1->setPositionY(28);
		

        
        return true;
    }

    void onCopytoClipboard(CCObject*) {
        geode::utils::clipboard::write(m_value);
        Notification::create("Copied to clipboard")->show();
    }

public:
    static DiscordPopup* create(std::string const& text) {
        auto ret = new DiscordPopup();
        if (ret && ret->init(text)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};
