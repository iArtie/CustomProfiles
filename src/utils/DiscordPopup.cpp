#include <Geode/Geode.hpp>

using namespace geode::prelude;

class DiscordPopup : public geode::Popup {
protected:
    TextArea* m_textArea = nullptr;
    std::string m_value;

    bool init(std::string const& value) {
        if (!Popup::init(170.f, 130.f, "square01_001.png"))
            return false;

        this->setTitle("Discord","goldFont.fnt",0.85);

        m_value = value;

        m_textArea = TextArea::create(
            m_value.c_str(),"chatFont.fnt",1.0f,100.0f,{ 0.5f, 0.5f },30.0f,false
        );

        auto btn = CCMenuItemSpriteExtra::create(
            m_textArea,
            this,
            menu_selector(DiscordPopup::onCopytoClipboard)
        );

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
        m_textArea->setPositionY(10);


        m_buttonMenu->addChildAtPosition(btn, Anchor::Center);

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
