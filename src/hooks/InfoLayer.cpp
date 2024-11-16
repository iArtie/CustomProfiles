#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include "../settings/OptionsV3.hpp"
#include "../utils/ownUtils.h"
//#include "../settings/Options.hpp"
using namespace geode::prelude;


class $modify(InfoLayer)
{
	void setupCommentsBrowser(cocos2d::CCArray * a1)
	{
		InfoLayer::setupCommentsBrowser(a1);


		if (this->m_level == nullptr && this->m_levelList == nullptr)
		{
			ownUtils::FixLayer(this->m_mainLayer, 340, 234);
		}

		/*if (this->m_levelList == nullptr)
		{
			FixLayer(this, 340, 234);
		}*/
	}

	bool init(GJGameLevel * a1, GJUserScore * a2, GJLevelList * a3)
	{
		if (!InfoLayer::init(a1, a2, a3)) return false;


		/*	if (a2 == nullptr)
			{
				FLAlertLayer::create("SI", "Es nulo!", "OK")->show();
			}
			else
			{
				if (a2 != nullptr)
				{
					FLAlertLayer::create("NO", "No es nulo!", "OK")->show();

				}
			}*/


		if (a1 == nullptr && a2 != nullptr)
		{
			int color1 = 0;
			int color2 = 0;

			auto winSize = CCDirector::sharedDirector()->getWinSize();
			auto Layer = (CCLayer*)this->getChildren()->objectAtIndex(0);
			/*auto brownsquare = (CCSprite*)Layer->getChildren()->objectAtIndex(0);
			brownsquare->setVisible(false);*/

			auto roundCorner = cocos2d::extension::CCScale9Sprite::create("GJ_square07.png");
			int halfWindowHeight = winSize.height / 2;
			int halfWindowWidth = winSize.width / 2;



			ccColor4B col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
			ccColor4B col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));

			//new sizes
			auto blackSize = CCSize(438, 292);
			auto blackBGSize = CCSize(850, 558);
			auto gradientsContentSize = CCSize(437, 287);
			auto cornerSize = CCSize(437, 289);
			auto commentSize = CCSize(350, 239.6);


			auto backgroundLayer = (CCSprite*)Layer->getChildren()->objectAtIndex(0);
			auto brownBG = (CCSprite*)backgroundLayer->getChildren()->objectAtIndex(0);

			auto commentsContainer = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");
			auto normalGradient = CCLayerGradient::create(col1, col2);
			auto invertGradient = CCLayerGradient::create(col2, col1);

			brownBG->setVisible(false);

			commentsContainer->setColor({ 154,154,154 });
			commentsContainer->setOpacity(77);
			commentsContainer->setZOrder(1);
			commentsContainer->setContentSize(commentSize);


			normalGradient->setZOrder(6);

			roundCorner->setZOrder(7);

			roundCorner->setPosition(brownBG->getPositionX() + 220, brownBG->getPositionY() + 144);
			roundCorner->setContentSize(blackSize);
			auto blackBG = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
			blackBG->setPosition(brownBG->getPositionX() + 220, brownBG->getPositionY() + 144);

			normalGradient->setScale(0.994);

			blackBG->setZOrder(7);
			blackBG->setOpacity(50);
			blackBG->setContentSize(blackBGSize);
			blackBG->setScale(0.5);
			blackBG->setColor({ 0,0,0 });
			roundCorner->setScale(1.006);
			auto whiteCorner = CCLayerGradient::create({ 255,255,255,255 }, { 255,255,255,255 });

			auto blackCorner = CCLayerGradient::create({ 0,0,0,255 }, { 0,0,0,255 });


			////New colors option settings
			//int colorID = Mod::get()->getSettingValue<SettingAppStruct>("ColorOptions").m_poss;
			auto colorID = Mod::get()->getSettingValue<SettingPosEnumColor>("color-options");
			/*int colorID = 3;*/
			switch (colorID)
			{

			case SettingPosEnumColor::Animnate: { //Animate color
				color1 = a2->m_color1;
				color2 = a2->m_color2;

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
				backgroundLayer->addChild(normalGradient, -4);
				backgroundLayer->addChild(invertGradient, -5);
				break;
			}
			case SettingPosEnumColor::Invert: { //Invert Color

				color1 = a2->m_color2;
				color2 = a2->m_color1;

				col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
				col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));

				normalGradient = CCLayerGradient::create(col1, col2);

				backgroundLayer->addChild(normalGradient, -4);
				break;
			}
			case SettingPosEnumColor::Normal: { //Normal color
				color1 = a2->m_color1;
				color2 = a2->m_color2;

				col1 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color1));
				col2 = ownUtils::ToColor4B(GameManager::sharedState()->colorForIdx(color2));

				normalGradient = CCLayerGradient::create(col1, col2);
				backgroundLayer->addChild(normalGradient, -4);
				break;
			}
			}
			//Corners

			//New corners option settings
		/*	int cornerID = Mod::get()->getSettingValue<SettingPosStruct>("CornersOptions").m_pos;*/
			auto cornerID = Mod::get()->getSettingValue<SettingPosEnum>("corner-options");

			/*int cornerID = 1;*/
			switch (cornerID)
			{
			case SettingPosEnum::Rounded: //Round corners
				backgroundLayer->addChild(roundCorner);
				break;
			case SettingPosEnum::Square: //Square corners
				backgroundLayer->addChild(whiteCorner);
				backgroundLayer->addChild(blackCorner);
				break;
			case SettingPosEnum::None: // No corners (idk why but some people like it)
				break;
			}

			normalGradient->setPosition({ 1.5,0 });
			normalGradient->setContentSize(gradientsContentSize);
			normalGradient->setScale(1.0);

			invertGradient->setZOrder(normalGradient->getZOrder() + 1);
			invertGradient->setContentSize(normalGradient->getContentSize());
			invertGradient->setPosition(normalGradient->getPosition());
			invertGradient->setScale(1.0);

			whiteCorner->setZOrder(normalGradient->getZOrder() - 2);
			whiteCorner->setContentSize(cornerSize);
			whiteCorner->setPositionX(normalGradient->getPositionX());
			whiteCorner->setPositionY(normalGradient->getPositionY() - 1);
			whiteCorner->setScale(1.02);

			blackCorner->setZOrder(normalGradient->getZOrder() - 1);
			blackCorner->setContentSize(whiteCorner->getContentSize());
			blackCorner->setPosition(whiteCorner->getPosition());
			blackCorner->setScale(1.01);

			auto boton = (CCSprite*)Layer->getChildren()->objectAtIndex(1);
			boton->setZOrder(-1);
			auto loadCommentsButton = (CCSprite*)boton->getChildren()->objectAtIndex(1);
			commentsContainer->setPosition(loadCommentsButton->getPositionX(), loadCommentsButton->getPositionY() - 0.5);
			loadCommentsButton->setZOrder(2);
			normalGradient->setTag(3);


			/*laweaxd->addChild(BG);*/
			backgroundLayer->addChild(blackBG);
			boton->addChild(commentsContainer);


		}
		return true;
	}
};
