#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include "../utils/ownUtils.h"
#include "../settings/Options.hpp"
class $modify(ProfilePage)
{

	void setupCommentsBrowser(cocos2d::CCArray * a1)
	{
		ProfilePage::setupCommentsBrowser(a1);
		ownUtils::FixLayer(this->m_mainLayer, 340, 100);


	}

	void onUpdate(CCObject * sender)
	{
		ProfilePage::onUpdate(sender);
		auto Layer = this->m_mainLayer;
		CCObject* pObj = nullptr;

		auto menu = Layer->getChildByID("main-menu");

		auto infobutton = menu->getChildByID("info-button");

		if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true && infobutton != nullptr)
		{

			infobutton->setPositionY(+100000);
		}
	}


	class ownSt {
	public:
		void SettingsPop(CCObject* sender) //Method for open the mod settings popup
		{
			geode::openSettingsPopup(Mod::get());
		}
	};


	void loadPageFromUserInfo(GJUserScore * asas)
	{

		ProfilePage::loadPageFromUserInfo(asas);
		int color1 = 0;
		int color2 = 0;


		auto winSize = CCDirector::sharedDirector()->getWinSize();
		auto Layer = this->m_mainLayer;
		auto blackSize = CCSize(438, 293);
		auto brownBG = (CCSprite*)Layer->getChildByID("background");

		//7121
		/*auto pqwtest = (CCSprite*)Layer->getChildren()->objectAtIndex(3);*/


		if (GameManager::sharedState()->getGameVariable("startingmodsas") == false)
		{
			GameManager::sharedState()->setGameVariable("profilecorner1", true);
			GameManager::sharedState()->setGameVariable("profilecolor3", true);
			GameManager::sharedState()->setGameVariable("startingmodsas", true);
		}

		if (this->m_ownProfile == true)
		{
			auto bottomMenu = (CCMenu*)Layer->getChildByID("bottom-menu");
			auto settingsButton = (CCMenuItemSpriteExtra*)bottomMenu->getChildByID("settings-button");

			settingsButton->setTarget(this, menu_selector(ownSt::SettingsPop));

		}

		auto menu = Layer->getChildByID("main-menu");

		auto infobutton = menu->getChildByID("info-button");

		if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
		{
			/*FLAlertLayer::create("Yes", "We are here!", "OK")->show();*/
			if (infobutton != nullptr)
			{
				infobutton->setPositionY(+100000);
			}

		}

		if (Layer->getChildByTag(3) == nullptr)
		{

			brownBG->setVisible(false);

			auto roundCorner = cocos2d::extension::CCScale9Sprite::create("GJ_square07.png");

			ownUtils::FixLayerv2(this->m_mainLayer, 340, 45);

			int halfWindowHeight = winSize.height / 2;
			int halfWindowWidth = winSize.width / 2;


			roundCorner->setZOrder(7);
			roundCorner->setContentSize(blackSize);


			brownBG->setVisible(false);



			ccColor4B col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
			ccColor4B col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));

			auto blackBGContentSize = CCSize(850, 559);
			auto players = CCSize(356, 56);
			auto gradientSize = CCSize(435, 288);

			auto cornersSize = CCSize(435, 290);
			auto commentsSize = CCSize(356, 106);

			auto normalGradient = CCLayerGradient::create(col1, col2);
			auto invertGradient = CCLayerGradient::create(col2, col1);



			//New colors option settings
			int colorID = Mod::get()->getSettingValue<SettingAppStruct>("ColorOptions").m_poss;
			/*std::cout << "color ID:" << colorID << std::endl;*/
			switch (colorID)
			{

			case 1: { //Animate color
				color1 = asas->m_color1;
				color2 = asas->m_color2;

				col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
				col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));
				normalGradient = CCLayerGradient::create(col1, col2);
				invertGradient = CCLayerGradient::create(col2, col1);

				// Animation loop
				auto fadeIn = CCFadeIn::create(1.8f);
				auto fadeOut = CCFadeOut::create(1.8f);
				auto sequence = CCSequence::create(fadeOut, fadeIn, nullptr);
				auto repeatedSequence = CCRepeatForever::create(sequence);
				invertGradient->runAction(repeatedSequence);
				Layer->addChild(normalGradient);
				Layer->addChild(invertGradient);
				break;
			}
			case 2: { //Invert Color

				color1 = asas->m_color2;
				color2 = asas->m_color1;

				col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
				col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));

				normalGradient = CCLayerGradient::create(col1, col2);
				Layer->addChild(normalGradient);
				break;
			}
			case 3: { //Normal color
				color1 = asas->m_color1;
				color2 = asas->m_color2;

				col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
				col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));

				normalGradient = CCLayerGradient::create(col1, col2);
				Layer->addChild(normalGradient);
				break;
			}
			}


			normalGradient->setID("normal-gradient"_spr);
			invertGradient->setID("invert-gradient"_spr);

			auto whiteCorner = CCLayerGradient::create({ 255,255,255,255 }, { 255,255,255,255 });

			auto blackCorner = CCLayerGradient::create({ 0,0,0,255 }, { 0,0,0,255 });

			normalGradient->setZOrder(brownBG->getZOrder() - 2);
			normalGradient->setScale(1.0);
			normalGradient->setPosition(brownBG->getPositionX() - 217, brownBG->getPositionY() - 145);
			normalGradient->setContentSize(gradientSize);

			invertGradient->setZOrder(normalGradient->getZOrder() + 2);
			invertGradient->setContentSize(normalGradient->getContentSize());
			invertGradient->setPosition(normalGradient->getPosition());

			whiteCorner->setZOrder(normalGradient->getZOrder() - 2);
			whiteCorner->setContentSize(cornersSize);
			whiteCorner->setPositionX(normalGradient->getPositionX());
			whiteCorner->setPositionY(normalGradient->getPositionY() - 1);
			whiteCorner->setScale(1.02);

			blackCorner->setZOrder(normalGradient->getZOrder() - 1);
			blackCorner->setContentSize(whiteCorner->getContentSize());
			blackCorner->setPosition(whiteCorner->getPosition());
			blackCorner->setScale(1.01);


			//Corners

			//New corners option settings
			int cornerID = Mod::get()->getSettingValue<SettingPosStruct>("CornersOptions").m_pos;//ConfigHandler::readConfigInt("notificationPlacement");

			switch (cornerID)
			{
			case 1: //Round corners
				Layer->addChild(roundCorner);
				break;
			case 2: //Square corners
				Layer->addChild(whiteCorner);
				Layer->addChild(blackCorner);
				break;
			case 3: // No corners (idk why but some people like it)
				break;
			}

			roundCorner->setPosition(winSize / 2);
			roundCorner->setPositionY(roundCorner->getPositionY() - 1);
			roundCorner->setScale(1.006);

			auto iconsContainer = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");

			iconsContainer->setPosition(winSize.width / 2, halfWindowHeight + 40);
			iconsContainer->setZOrder(normalGradient->getZOrder() + 3);
			iconsContainer->setContentSize(players);
			iconsContainer->setColor({ 154,154,154 });
			iconsContainer->setOpacity(77);
			iconsContainer->setID("ccscale-icons"_spr);
			Layer->addChild(iconsContainer);

			auto commentsContainer = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");
			commentsContainer->setPosition(winSize.width / 2, halfWindowHeight - 53);
			commentsContainer->setContentSize(commentsSize);
			commentsContainer->setColor({ 154,154,154 });
			commentsContainer->setOpacity(77);
			commentsContainer->setID("ccscale-comments"_spr);


			commentsContainer->setZOrder(normalGradient->getZOrder() + 3);

			Layer->addChild(commentsContainer);


			normalGradient->setTag(3);
			auto blackBG = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
			blackBG->setPosition(brownBG->getPositionX(), brownBG->getPositionY() - 1);
			blackBG->setZOrder(brownBG->getZOrder());
			blackBG->setColor(ccBLACK);
			blackBG->setOpacity(50);
			blackBG->setContentSize(blackBGContentSize);
			blackBG->setScale(0.5);
			Layer->addChild(blackBG);



			//New infobutton settings - maked with gamevariable bc upload method have bugs with settingsValue
			if (Mod::get()->getSettingValue<bool>("Disable-info-button") == true)
			{
				GameManager::sharedState()->setGameVariable("disableinfolabel", true);

			}
			if (Mod::get()->getSettingValue<bool>("Disable-info-button") == false)
			{
				GameManager::sharedState()->setGameVariable("disableinfolabel", false);

			}
		}
	}
};
