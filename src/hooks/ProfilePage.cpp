#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../utils/ownUtils.h"
#include "../settings/OptionsV3.hpp"
#include "../utils/DiscordPopup.cpp"
class $modify(CustomProfilesPage,ProfilePage) {

    struct Fields
    {
        gd::string discordUsername;
    };

    void onDiscordProfile(CCObject* sender)
    {
        DiscordPopup::create(m_fields->discordUsername.c_str())->show();
        /*FLAlertLayer::create("Discord", m_fields->discordUsername.c_str(), "OK")->show();*/
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

        if (auto socialsMenu = m_mainLayer->getChildByID("socials-menu")) {

            if (!Mod::get()->getSettingValue<bool>("Disable-discord-button")) {

                if (score->m_discordUsername != "")
                {
                    if (!socialsMenu->getChildByID("discord-button"))
                    {
                        this->m_fields->discordUsername = fmt::format("@{}", score->m_discordUsername);
                        
                        auto discordSpr = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");

                        auto discordButton = CCMenuItemSpriteExtra::create(
                            discordSpr,
                            discordSpr,
                            this,
                            menu_selector(CustomProfilesPage::onDiscordProfile)
                        );

                        float referenceScale = 1.f;

                        int buttonCount = 0;

                        for (auto node : CCArrayExt<CCNode*>(socialsMenu->getChildren())) {
                            if (auto btn = typeinfo_cast<CCMenuItemSpriteExtra*>(node)) {
                                referenceScale = btn->getScale();

                                buttonCount++;
                            }
                        }

                        if (buttonCount > 0) {
                            discordButton->setScale(referenceScale);

                        }

                        if (buttonCount == 4) {
                            discordSpr->setScale(0.9f);
                            discordButton->setAnchorPoint({ 0.5,0.45 });
                            discordButton->setContentHeight(discordButton->getContentHeight() - 2);
                        }
                        else if (buttonCount == 5) {
                            discordSpr->setScale(0.825f);
                            discordButton->setAnchorPoint({ 0.5,0.4 });
                            discordButton->setContentHeight(discordButton->getContentHeight() - 2.5);
                        }

                        if (buttonCount == 1) {
                            if (auto statsMenu = m_mainLayer->getChildByID("stats-menu")) {
                                statsMenu->setScale(0.825f);

                                if (auto myStuffHint = typeinfo_cast<CCSprite*>(m_mainLayer->getChildByID("my-stuff-hint"))) {

                                    auto* frame = cocos2d::CCSpriteFrameCache::get()->spriteFrameByName("GJ_stuffTxt_001.png");
                                    myStuffHint->setDisplayFrame(frame);


                                }

                            }
                        }

                        discordButton->setTag(buttonCount + 1);
                        discordButton->setID("discord-button");
                        socialsMenu->addChild(discordButton);

                        if (!m_mainLayer->getChildByID("my-stuff-hint")) {

                            auto myStuffHint = CCSprite::createWithSpriteFrameName("GJ_stuffTxt_001.png");
                            myStuffHint->setPosition({ (winSize.width / 2) + 139.f, (winSize.height / 2) + 124.1f });

                            myStuffHint->setID("my-stuff-hint");
                            m_mainLayer->addChild(myStuffHint);
                            m_buttons->addObject(myStuffHint);
                        }

                        if (m_buttons) {
                            m_buttons->addObject(discordButton);
                        }

                    }
                    socialsMenu->updateLayout();
                }
            }
        }

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
        iconsContainer->setContentSize({ 356, 56 });
        iconsContainer->setColor({ 154,154,154 });
        iconsContainer->setOpacity(77);
        iconsContainer->setID("ccscale-icons"_spr);
        iconsContainer->setZOrder(-2);
        Layer->addChild(iconsContainer);

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