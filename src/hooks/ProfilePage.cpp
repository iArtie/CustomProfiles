#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/modify/MyStuffPopup.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../utils/ownUtils.h"
#include "../settings/OptionsV3.hpp"
#include "../utils/DiscordPopup.cpp"


class $modify(CustomProfilesPage,ProfilePage) {

    struct Fields
    {
        std::string discordUsername;
    };
    static void onModify(auto& self) {
        if (!self.setHookPriorityAfterPost(
            "ProfilePage::setupCommentsBrowser",
            "alphalaneous.happy_textures"
        )) {
            log::warn("Failed to set hook priority AfterPost");
        }
    
    }

    void setupCommentsBrowser(CCArray* array) {
    
        ProfilePage::setupCommentsBrowser(array);

        ownUtils::FixLayer(m_mainLayer, 340, 100);
    }


    void loadPageFromUserInfo(GJUserScore* score) {
        ProfilePage::loadPageFromUserInfo(score);

        if (!Mod::get()->getSavedValue<bool>("first-start")) {

            Mod::get()->setSettingValue("color-options", SettingPosEnumColor::Normal);
            Mod::get()->setSettingValue("corner-options", SettingPosEnum::Rounded);
            Mod::get()->setSavedValue("first-start", true);
        }


        auto winSize = CCDirector::sharedDirector()->getWinSize();

        if (m_ownProfile) {
            auto bottomMenu = (CCMenu*)m_mainLayer->getChildByID("bottom-menu");
            auto settingsButton = (CCMenuItemSpriteExtra*)bottomMenu->getChildByID("settings-button");
            settingsButton->setTarget(this, menu_selector(ProfilePage::onSettings));
        }

        if (Mod::get()->getSettingValue<bool>("Disable-info-button")) {
            auto menu = m_mainLayer->getChildByID("main-menu");
            auto infobutton = menu->getChildByID("info-button");
            if (infobutton) infobutton->setPositionY(100000);
        }

        if (m_mainLayer->getChildByTag(3)) return;

        auto Layer = m_mainLayer;
        auto brownBG = (CCSprite*)Layer->getChildByID("background");
        brownBG->setVisible(false);
        ownUtils::FixLayerv2(Layer, 340, 45);

        int color1 = score->m_color1;
        int color2 = score->m_color2;
        auto col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
        auto col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));

        auto normalGradient = CCLayerGradient::create(col1, col2);
        auto invertGradient = CCLayerGradient::create(col2, col1);

        switch (Mod::get()->getSettingValue<SettingPosEnumColor>("color-options")) {
        case SettingPosEnumColor::Animate:
            color1 = score->m_color1;
            color2 = score->m_color2;
            col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
            col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));
            normalGradient = CCLayerGradient::create(col1, col2);
            invertGradient = CCLayerGradient::create(col2, col1);
            invertGradient->runAction(CCRepeatForever::create(CCSequence::create(CCFadeOut::create(1.8f), CCFadeIn::create(1.8f), nullptr)));
            Layer->addChild(normalGradient);
            Layer->addChild(invertGradient);
            break;
        case SettingPosEnumColor::Invert:
            color1 = score->m_color2;
            color2 = score->m_color1;
            col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
            col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));
            normalGradient = CCLayerGradient::create(col1, col2);
            Layer->addChild(normalGradient);
            break;
        case SettingPosEnumColor::Normal:
            Layer->addChild(normalGradient);
            break;
        }

        normalGradient->setID("normal-gradient"_spr);
        invertGradient->setID("invert-gradient"_spr);
        normalGradient->setTag(3);
        normalGradient->setZOrder(-5);
        normalGradient->setContentSize({ 435, 288 });
        normalGradient->setPosition(winSize.width / 2 - 217, winSize.height / 2 - 145);

        invertGradient->setZOrder(-3);
        invertGradient->setContentSize(normalGradient->getContentSize());
        invertGradient->setPosition(normalGradient->getPosition());

        // Corners
        auto roundCorner = cocos2d::extension::CCScale9Sprite::create("GJ_square07.png");
        roundCorner->setContentSize({ 438, 293 });
        roundCorner->setPosition(winSize / 2);
        roundCorner->setPositionY(roundCorner->getPositionY() - 1);
        roundCorner->setScale(1.006);
        roundCorner->setZOrder(7);

        auto whiteCorner = CCLayerGradient::create({ 255,255,255,255 }, { 255,255,255,255 });
        whiteCorner->setContentSize({ 435, 290 });
        whiteCorner->setPosition(normalGradient->getPosition());
        whiteCorner->setPositionY(whiteCorner->getPositionY() - 1);
        whiteCorner->setScale(1.02);
        whiteCorner->setZOrder(-7);

        auto blackCorner = CCLayerGradient::create({ 0,0,0,255 }, { 0,0,0,255 });
        blackCorner->setContentSize(whiteCorner->getContentSize());
        blackCorner->setPosition(whiteCorner->getPosition());
        blackCorner->setScale(1.01);
        blackCorner->setZOrder(-6);

        switch (Mod::get()->getSettingValue<SettingPosEnum>("corner-options")) {
        case SettingPosEnum::Rounded: 
            Layer->addChild(roundCorner); 
            break;
        case SettingPosEnum::Square: 
            Layer->addChild(whiteCorner); 
            Layer->addChild(blackCorner); 
            break;
        case SettingPosEnum::None: 
            break;
        }

        auto blackBG = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
        blackBG->setPosition(winSize.width / 2, winSize.height / 2 - 1);
        blackBG->setColor(ccBLACK);
        blackBG->setOpacity(50);
        blackBG->setZOrder(-1);
        blackBG->setContentSize({ 850, 559 });
        blackBG->setScale(0.5f);
        Layer->addChild(blackBG);

        auto iconsContainer = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");
        iconsContainer->setPosition(winSize.width / 2, winSize.height / 2 + 40);
        iconsContainer->setContentSize({ 400, 56 });
        iconsContainer->setColor({ 154,154,154 });
        iconsContainer->setOpacity(77);
        iconsContainer->setID("ccscale-icons"_spr);
        iconsContainer->setZOrder(-2);
        Layer->addChild(iconsContainer);


        auto iconBorder = typeinfo_cast<CCScale9Sprite*>(m_mainLayer->getChildByID("icon-background-border"));
		if (iconBorder) {
			iconBorder->setVisible(false);
		}

		auto iconBG = typeinfo_cast<CCScale9Sprite*>(m_mainLayer->getChildByID("icon-background"));
		if (iconBG) {
			iconBG->setVisible(false);
		}

        auto commentsContainer = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");
        commentsContainer->setPosition(winSize.width / 2, winSize.height / 2 - 53);
        commentsContainer->setContentSize({ 356, 106 });
        commentsContainer->setColor({ 154,154,154 });
        commentsContainer->setOpacity(77);
        commentsContainer->setID("ccscale-comments"_spr);
        commentsContainer->setZOrder(-2);
        Layer->addChild(commentsContainer);
  
    }

    void onSettings(CCObject* sender) { 
        geode::openSettingsPopup(Mod::get()); 
    }

   
};