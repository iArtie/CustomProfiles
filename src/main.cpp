#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/modify/CommentCell.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/modify/StatsCell.hpp>
#include <Geode/modify/GJAccountSettingsLayer.hpp>
#include "Options.hpp"
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;


template<typename T, typename U> constexpr size_t OFFSETBYMEMBER(U T::* member)
{
	return (char*)&((T*)nullptr->*member) - (char*)nullptr;
}

#define OBM(member) OFFSETBYMEMBER(member)

template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}


void FixLayerv3(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	CCObject* pObj = nullptr;
	auto layerChild = dynamic_cast<CCLayer*>(layer->getChildren()->objectAtIndex(0));
	//auto weaiconos = (CCSprite*)layerChild->getChildren()->objectAtIndex(7);
	//weaiconos->setVisible(false);
	/*auto laweaxd = (CCSprite*)layerChild->getChildren()->objectAtIndex(0);*/
	CCARRAY_FOREACH(layerChild->getChildren(), pObj) {
		CCNode* currentNode = (CCNode*)pObj;
		CCPoint xy = currentNode->getPosition();
		currentNode->getContentSize();

		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {

			currentNode->setVisible(false);
		}
	}
}
void FixLayerv2(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	CCObject* pObj = nullptr;
	//auto layerChild = dynamic_cast<CCLayer*>(layer->getChildren()->objectAtIndex(0));
	//auto weaiconos = (CCSprite*)layerChild->getChildren()->objectAtIndex(7);
	//weaiconos->setVisible(false);
	/*auto laweaxd = (CCSprite*)layerChild->getChildren()->objectAtIndex(0);*/
	CCARRAY_FOREACH(layer->getChildren(), pObj) {
		CCNode* currentNode = (CCNode*)pObj;
		CCPoint xy = currentNode->getPosition();
		currentNode->getContentSize();

		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {

			currentNode->setVisible(false);
		}
	}
}
void FixLayer(CCLayer* layer, int width, int height) {
	CCSize newNodeSize = { 0, 100 };
	CCObject* pObj = nullptr;
	/*auto layerChild = dynamic_cast<CCLayer*>(layer->getChildren()->objectAtIndex(0));*/
	
	
	//auto weaiconos = (CCSprite*)layerChild->getChildren()->objectAtIndex(7);
	//weaiconos->setVisible(false);
	/*auto laweaxd = (CCSprite*)layerChild->getChildren()->objectAtIndex(0);*/
	CCARRAY_FOREACH(layer->getChildren(), pObj) {
		CCNode* currentNode = (CCNode*)pObj;
		CCPoint xy = currentNode->getPosition();
		currentNode->getContentSize();

		CCSize contentSize = currentNode->getContentSize();

		if (contentSize.height == height && contentSize.width == width) {

			currentNode->setContentSize(newNodeSize);

			CCArray* children = currentNode->getChildren();

			currentNode->setZOrder(1);

			auto sprite0 = (CCSprite*)children->objectAtIndex(0);
			sprite0->setVisible(false);

			auto sprite1 = (CCSprite*)children->objectAtIndex(1);
			sprite1->setVisible(false);

			auto sprite2 = (CCSprite*)children->objectAtIndex(2);
			sprite2->setVisible(false);
			currentNode->setZOrder(2);

			auto sprite3 = (CCSprite*)children->objectAtIndex(3);
			sprite3->setVisible(false);
		}
	}

	
	

	
}

cocos2d::ccColor4B ToColor4B(ccColor3B sourceColor)
{
	return ccColor4B{ sourceColor.r, sourceColor.g, sourceColor.b,255 };
}

$on_mod(Loaded) {
	Mod::get()->addCustomSetting<SettingsValues>("Corners-section", "none");
	Mod::get()->addCustomSetting<SettingsValues>("Colors-section", "none");
	Mod::get()->addCustomSetting<SettingsValues>("Extras-section", "none");

	////Config thing? hope it works
	Mod::get()->addCustomSetting<SettingTestValue>("Account-settings", "none");
	Mod::get()->addCustomSetting<SettingAppValue>("ColorOptions",1);
	Mod::get()->addCustomSetting<CornerSettingsValue>("CornersOptions",3);
	
}

//hiii this is a test for mac :D


class $modify(InfoLayer)
{
	void setupCommentsBrowser(cocos2d::CCArray*a1)
	{
		InfoLayer::setupCommentsBrowser(a1);

		
		if (this->m_level == nullptr && this->m_levelList == nullptr)
		{
			FixLayer(this->m_mainLayer, 340, 234);
		}

		/*if (this->m_levelList == nullptr)
		{
			FixLayer(this, 340, 234);
		}*/
	}

	bool init(GJGameLevel* a1, GJUserScore* a2, GJLevelList* a3)
	{
		if(!InfoLayer::init(a1, a2, a3)) return false;

		
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
			/*int color1 = a2->m_color1;
			int color2 = a2->m_color2;*/
			//Corners
			if (GameManager::sharedState()->getGameVariable("profilecorner1") == true)
			{
				
			}

			if (GameManager::sharedState()->getGameVariable("profilecorner2") == true)
			{
				
			}

			if (GameManager::sharedState()->getGameVariable("profilecorner3") == true)
			{

			}
			//Colors
			if (GameManager::sharedState()->getGameVariable("profilecolor1") == true)
			{
				color1 = a2->m_color1;
				color2 = a2->m_color2;
			}

			if (GameManager::sharedState()->getGameVariable("profilecolor2") == true)
			{
				color1 = a2->m_color2;
				color2 = a2->m_color1;
				
			}

			if (GameManager::sharedState()->getGameVariable("profilecolor3") == true)
			{
				color1 = a2->m_color1;
				color2 = a2->m_color2;
			}
			auto winSize = CCDirector::sharedDirector()->getWinSize();
			auto Layer = (CCLayer*)this->getChildren()->objectAtIndex(0);
			/*auto brownsquare = (CCSprite*)Layer->getChildren()->objectAtIndex(0);
			brownsquare->setVisible(false);*/

			auto BG = cocos2d::extension::CCScale9Sprite::create("GJ_square07.png");
			int owo = winSize.height / 2;
			int uwu = winSize.width / 2;

			

			ccColor4B col1 = ToColor4B(GameManager::sharedState()->colorForIdx(color1));
			ccColor4B col2 = ToColor4B(GameManager::sharedState()->colorForIdx(color2));


			auto blackSize = CCSize(438, 292);
			auto blackk = CCSize(850, 558);

			auto laweaxd = (CCSprite*)Layer->getChildren()->objectAtIndex(0);
			auto unua = (CCSprite*)laweaxd->getChildren()->objectAtIndex(0);

			auto loll = CCSize(445, 290);
			auto lol = CCSize(437, 287);

			auto lolas = CCSize(437, 289);
			auto comment = CCSize(350, 239.6);

			/*auto layerlol = CCLayerGradient::create(col1, col2);

			layerlol->setZOrder(laweaxd->getZOrder() - 1);
			layerlol->setScale(1.0);
			layerlol->setPosition(laweaxd->getPositionX() - 217, laweaxd->getPositionY() - 145);
			layerlol->setContentSize(lol);
			Layer->addChild(layerlol);*/

			auto Idk = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");
			auto layerlol1 = CCLayerGradient::create(col1, col2);
			auto layerlol2 = CCLayerGradient::create(col2, col1);

			unua->setVisible(false);
			Idk->setColor({ 154,154,154 });
			Idk->setOpacity(77);
			Idk->setZOrder(1);
			Idk->setContentSize(comment);
			
			/*auto BG = cocos2d::extension::CCScale9Sprite::create("bitZ_square03.png");*/
			layerlol1->setZOrder(6);
			
			BG->setZOrder(7);
			layerlol1->setPosition(unua->getPositionX() + 2, unua->getPositionY());
			BG->setPosition(unua->getPositionX() + 220, unua->getPositionY() + 144);
			BG->setContentSize(blackSize);
			auto BLackC = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
			BLackC->setPosition(unua->getPositionX() + 220, unua->getPositionY() + 144);
			layerlol1->setScale(0.994);
			BLackC->setZOrder(7);
			BLackC->setOpacity(50);
			BLackC->setContentSize(blackk);
			BLackC->setScale(0.5);
			BLackC->setColor({ 0,0,0 });
			BG->setScale(1.006);
			auto layerlol3 = CCLayerGradient::create({ 255,255,255,255 }, { 255,255,255,255 });

			auto layerlol4 = CCLayerGradient::create({ 0,0,0,255 }, { 0,0,0,255 });

			layerlol1->setContentSize(lol);
			layerlol1->setScale(1.0);
			layerlol2->setZOrder(layerlol1->getZOrder() + 1);
			layerlol2->setContentSize(layerlol1->getContentSize());
			layerlol2->setPosition(layerlol1->getPosition());
			layerlol2->setScale(1.0);

			layerlol3->setZOrder(layerlol1->getZOrder() - 2);
			layerlol3->setContentSize(lolas);
			layerlol3->setPositionX(layerlol1->getPositionX());
			layerlol3->setPositionY(layerlol1->getPositionY() - 1);
			layerlol3->setScale(1.02);

			layerlol4->setZOrder(layerlol1->getZOrder() - 1);
			layerlol4->setContentSize(layerlol3->getContentSize());
			layerlol4->setPosition(layerlol3->getPosition());
			layerlol4->setScale(1.01);
			auto boton = (CCSprite*)Layer->getChildren()->objectAtIndex(1);
			boton->setZOrder(-1);
			auto botonxd = (CCSprite*)boton->getChildren()->objectAtIndex(1);
			Idk->setPosition(botonxd->getPositionX(), botonxd->getPositionY() - 0.5);
			botonxd->setZOrder(2);
			layerlol1->setTag(3);

			if (GameManager::sharedState()->getGameVariable("profilecolor1") != true)
			{
				laweaxd->addChild(layerlol1);
			}

			if (GameManager::sharedState()->getGameVariable("profilecolor1") == true)
			{

				

				laweaxd->addChild(layerlol1);
				laweaxd->addChild(layerlol2);

				
				 // Crea la acción de desvanecimiento para layerlol2 con un delay
				auto fadeIn2 = CCFadeIn::create(1.8f);
				auto fadeOut2 = CCFadeOut::create(1.8f);
				auto sequence2 = CCSequence::create(fadeOut2, fadeIn2, nullptr);
				auto repeatedSequence2 = CCRepeatForever::create(sequence2);
				layerlol2->runAction(repeatedSequence2);
			}


			if (GameManager::sharedState()->getGameVariable("profilecolor1") == false &&
				GameManager::sharedState()->getGameVariable("profilecolor2") == false &&
				GameManager::sharedState()->getGameVariable("profilecolor3") == false)
			{
				/*pqwtest->setVisible(false);*/
				unua->setVisible(true);
				layerlol1->setVisible(false);
				layerlol2->setVisible(false);
				layerlol3->setVisible(false);
				layerlol4->setVisible(false);
				BLackC->setVisible(false);
				BG->setVisible(false);
			}


			//Corners
			if (GameManager::sharedState()->getGameVariable("profilecorner1") == true)
			{
				laweaxd->addChild(BG);
			}

			if (GameManager::sharedState()->getGameVariable("profilecorner2") == true)
			{
				laweaxd->addChild(layerlol3);
				laweaxd->addChild(layerlol4);
			}

			if (GameManager::sharedState()->getGameVariable("profilecorner3") == true)
			{

			}
			/*laweaxd->addChild(BG);*/
			laweaxd->addChild(BLackC);
			boton->addChild(Idk);
			/*unua->setScale(0.975);*/
		
		}
		return true;
	}
};


using OpenSettingsPopupFunction = std::function<void(Mod*)>;

//New amazing code for clean comments
class $modify(StatsCell)
{
	void draw()
	{
		auto scene = CCDirector::get()->getRunningScene();
		if (!scene->getChildByID("ProfilePage")) {
			/*StatsCell::draw();*/
		}
	}
};

#ifdef GEODE_IS_ANDROID || GEODe_IS_MACOS
class $modify(CommentCell)
{
	void draw()
	{
		auto scene = CCDirector::get()->getRunningScene();
		if (!scene->getChildByID("ProfilePage")) {
			/*CommentCell::draw();*/
		}
	}
};
#endif


class $modify(ProfilePage)
{

	bool init(int a1, bool a2)
	{
		if(!ProfilePage::init(a1, a2)) return false;
		auto nodelolas = (CCLayer*)this->getChildren()->objectAtIndex(0);
		
		return true;
	}

	//void onSettings(cocos2d::CCObject* sender)
	//{
	//	
	//	 geode::openSettingsPopup(Mod::get());
	//}

	void setupCommentsBrowser(cocos2d::CCArray * a1)
	{
		ProfilePage::setupCommentsBrowser(a1);
		FixLayer(this->m_mainLayer, 340, 100);
		
		
	}
#include <thread> // Necesario para std::this_thread::sleep_for
#include <chrono>
#include <iostream>
#include <sstream>
	void onUpdate(CCObject* sender)
	{
		ProfilePage::onUpdate(sender);
		auto Layer = this->m_mainLayer;
		CCObject* pObj = nullptr;
		
		auto menu = Layer->getChildByID("main-menu");

		auto infobutton = menu->getChildByID("info-button");

		if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true && infobutton != nullptr)
		{
			/*FLAlertLayer::create("Yes", "We are here!", "OK")->show();*/
			infobutton->setPositionY(+100000);
		}
	}
	

	class accManager
	{
		void callSet(CCObject* sender)
		{
		/*	auto sas = GJAccountSettingsLayer::init(1);*/
		}
	};


	class ownSt {
	public:
		void SettingsPop(CCObject* sender)
		{
			geode::openSettingsPopup(Mod::get());
		}
	};
	
	
	void loadPageFromUserInfo(GJUserScore* asas)
	{

		ProfilePage::loadPageFromUserInfo(asas);
		//New corners option settings
		int cornerID = Mod::get()->getSettingValue<SettingPosStruct>("CornersOptions").m_pos;//ConfigHandler::readConfigInt("notificationPlacement");
		/*std::cout << "Corner ID:" << cornerID << std::endl;*/
		switch (cornerID)
		{ 
		case 1:
			GameManager::sharedState()->setGameVariable("profilecorner1", true);
			GameManager::sharedState()->setGameVariable("profilecorner2", false);
			GameManager::sharedState()->setGameVariable("profilecorner3", false);
			break;
		case 2:
			GameManager::sharedState()->setGameVariable("profilecorner1", false);
			GameManager::sharedState()->setGameVariable("profilecorner2", true);
			GameManager::sharedState()->setGameVariable("profilecorner3", false);
			break;
		case 3:
			GameManager::sharedState()->setGameVariable("profilecorner1", false);
			GameManager::sharedState()->setGameVariable("profilecorner2", false);
			GameManager::sharedState()->setGameVariable("profilecorner3", true);
			break;
		}
		
		//New colors option settings
		int colorID = Mod::get()->getSettingValue<SettingAppStruct>("ColorOptions").m_poss;//ConfigHandler::readConfigInt("notificationPlacement");
		/*std::cout << "color ID:" << colorID << std::endl;*/
		switch (colorID)
		{
			
		case 1:
			GameManager::sharedState()->setGameVariable("profilecolor1", true);
			GameManager::sharedState()->setGameVariable("profilecolor2", false);
			GameManager::sharedState()->setGameVariable("profilecolor3", false);
			break;
		case 2:
			GameManager::sharedState()->setGameVariable("profilecolor1", false);
			GameManager::sharedState()->setGameVariable("profilecolor2", true);
			GameManager::sharedState()->setGameVariable("profilecolor3", false);
			break;
		case 3:
			GameManager::sharedState()->setGameVariable("profilecolor1", false);
			GameManager::sharedState()->setGameVariable("profilecolor2", false);
			GameManager::sharedState()->setGameVariable("profilecolor3", true);
			break;
		
		}

		//New infobutton setting
		if (Mod::get()->getSettingValue<bool>("Disable-info-button") == true)
		{
			GameManager::sharedState()->setGameVariable("disableinfolabel", true);

		}
		if (Mod::get()->getSettingValue<bool>("Disable-info-button") == false)
		{
			GameManager::sharedState()->setGameVariable("disableinfolabel", false);

		}


//#ifdef GEODE_IS_MACOS
//		if (Mod::get()->getSettingValue<bool>("Round-corners") == true)
//		{
//			Mod::get()->setSettingValue("Square-corners", false);
//			Mod::get()->setSettingValue("No-corners", false);
//			GameManager::sharedState()->setGameVariable("profilecorner1", true);
//			GameManager::sharedState()->setGameVariable("profilecorner2", false);
//			GameManager::sharedState()->setGameVariable("profilecorner3", false);
//		}
//		if (Mod::get()->getSettingValue<bool>("Square-corners") == true)
//		{
//			Mod::get()->setSettingValue("Round-corners", false);
//			Mod::get()->setSettingValue("No-corners", false);
//			GameManager::sharedState()->setGameVariable("profilecorner1", false);
//			GameManager::sharedState()->setGameVariable("profilecorner2", true);
//			GameManager::sharedState()->setGameVariable("profilecorner3", false);
//		}
//		if (Mod::get()->getSettingValue<bool>("No-corners") == true)
//		{
//			Mod::get()->setSettingValue("Square-corners", false);
//			Mod::get()->setSettingValue("Round-corners", false);
//			GameManager::sharedState()->setGameVariable("profilecorner1", false);
//			GameManager::sharedState()->setGameVariable("profilecorner2", false);
//			GameManager::sharedState()->setGameVariable("profilecorner3", true);
//		}
//
//		if (Mod::get()->getSettingValue<bool>("Animate-colors") == true)
//		{
//			Mod::get()->setSettingValue("Invert-Colors", false);
//			Mod::get()->setSettingValue("Normal-colors", false);
//			GameManager::sharedState()->setGameVariable("profilecolor1", true);
//			GameManager::sharedState()->setGameVariable("profilecolor2", false);
//			GameManager::sharedState()->setGameVariable("profilecolor3", false);
//		}
//
//		if (Mod::get()->getSettingValue<bool>("Invert-Colors") == true)
//		{
//			Mod::get()->setSettingValue("Animate-colors", false);
//			Mod::get()->setSettingValue("Normal-colors", false);
//			GameManager::sharedState()->setGameVariable("profilecolor1", false);
//			GameManager::sharedState()->setGameVariable("profilecolor2", true);
//			GameManager::sharedState()->setGameVariable("profilecolor3", false);
//		}
//
//		if (Mod::get()->getSettingValue<bool>("Normal-colors") == true)
//		{
//			Mod::get()->setSettingValue("Animate-colors", false);
//			Mod::get()->setSettingValue("Invert-Colors", false);
//			GameManager::sharedState()->setGameVariable("profilecolor1", false);
//			GameManager::sharedState()->setGameVariable("profilecolor2", false);
//			GameManager::sharedState()->setGameVariable("profilecolor3", true);
//		}
//
//		if (Mod::get()->getSettingValue<bool>("Disable-info-button") == true)
//		{
//			GameManager::sharedState()->setGameVariable("disableinfolabel", true);
//
//		}
//		if (Mod::get()->getSettingValue<bool>("Disable-info-button") == false)
//		{
//			GameManager::sharedState()->setGameVariable("disableinfolabel", false);
//
//		}
//
//#endif
		/*std::cout << OBM(&GJUserScore::m_color3) << std::endl;*/
		//color1 offset is 360
		//color2 offset is 364
		//color3 offset is 368
		auto winSize = CCDirector::sharedDirector()->getWinSize();
		auto Layer = this->m_mainLayer;
		auto blackSize = CCSize(438, 293);
		auto laweaxd = (CCSprite*)Layer->getChildByID("background");

		//7121
		/*auto pqwtest = (CCSprite*)Layer->getChildren()->objectAtIndex(3);*/


		if (GameManager::sharedState()->getGameVariable("startingmodsas") == false)
		{
			GameManager::sharedState()->setGameVariable("profilecorner1", true);
			GameManager::sharedState()->setGameVariable("profilecolor3", true);
			GameManager::sharedState()->setGameVariable("startingmodsas", true);
		}

		//NEW FUNCTION TO SETTINGS BC GJACCOUNTSETTINGSLAYER::CREATE() IS INLINED

		
	
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
			/*FixLayer(this, 340, 100);*/
			//if (this->m_ownProfile == true)
			//{
			//	auto buttons = (CCMenu*)Layer->getChildren()->objectAtIndex(4);
			//	/*buttons->setVisible(false);*/
			//	auto infobutton = (CCMenuItemSpriteExtra*)buttons->getChildren()->objectAtIndex(10);
			//	if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
			//	{
			//		infobutton->setPositionY(+100000);
			//	}
			//}

			/*pqwtest->setVisible(false);*/

			laweaxd->setVisible(false);
			auto BG = cocos2d::extension::CCScale9Sprite::create("GJ_square07.png");
			FixLayerv2(this->m_mainLayer, 340, 45);
			int owo = winSize.height / 2;
			int uwu = winSize.width / 2;
			BG->setZOrder(7);
			/*BG->setPosition(pqwtest->getPositionX() + 170, pqwtest->getPositionY()-18);*/
			
			BG->setContentSize(blackSize);
			
			/*pqwtest->setVisible(false);*/

			laweaxd->setVisible(false);
			int color1 = 0;
			int color2 = 0;
			/*int color1 = a2->m_color1;
			int color2 = a2->m_color2;*/
			
			//Colors
			
			if (GameManager::sharedState()->getGameVariable("profilecolor1") == true)
			{
				color1 = asas->m_color1;
				color2 = asas->m_color2;
			}
			if (GameManager::sharedState()->getGameVariable("profilecolor2") == true)
			{
				color1 = asas->m_color2;
				color2 = asas->m_color1;

			}

			if (GameManager::sharedState()->getGameVariable("profilecolor3") == true)
			{
				color1 = asas->m_color1;
				color2 = asas->m_color2;
			}
		
			ccColor4B col1 = ToColor4B(GameManager::sharedState()->colorForIdx(color1));
			ccColor4B col2 = ToColor4B(GameManager::sharedState()->colorForIdx(color2));

			auto loll = CCSize(850, 559);
			auto players = CCSize(356, 56);
			auto lol = CCSize(435, 288);

			auto lolas = CCSize(435, 290);
			auto comments = CCSize(356, 106);
			//2853
			auto layerlol1 = CCLayerGradient::create(col1, col2);

			layerlol1->setID("normal-gradient"_spr);
			auto layerlol2 = CCLayerGradient::create(col2, col1);
			layerlol2->setID("invert-gradient"_spr);
			auto layerlol3 = CCLayerGradient::create({ 255,255,255,255 }, { 255,255,255,255 });

			auto layerlol4 = CCLayerGradient::create({ 0,0,0,255 }, { 0,0,0,255 });
			
			layerlol1->setZOrder(laweaxd->getZOrder() - 2);
			layerlol1->setScale(1.0);
			layerlol1->setPosition(laweaxd->getPositionX() - 217, laweaxd->getPositionY() - 145);
			layerlol1->setContentSize(lol);

			layerlol2->setZOrder(layerlol1->getZOrder() + 2);
			layerlol2->setContentSize(layerlol1->getContentSize());
			layerlol2->setPosition(layerlol1->getPosition());

			layerlol3->setZOrder(layerlol1->getZOrder() -2);
			layerlol3->setContentSize(lolas);
			layerlol3->setPositionX(layerlol1->getPositionX());
			layerlol3->setPositionY(layerlol1->getPositionY()-1);
			layerlol3->setScale(1.02);

			layerlol4->setZOrder(layerlol1->getZOrder() - 1);
			layerlol4->setContentSize(layerlol3->getContentSize());
			layerlol4->setPosition(layerlol3->getPosition());
			layerlol4->setScale(1.01);


			//Corners
			if (GameManager::sharedState()->getGameVariable("profilecorner1") == true)
			{
				Layer->addChild(BG);
			}

			if (GameManager::sharedState()->getGameVariable("profilecorner2") == true)
			{
				Layer->addChild(layerlol3);
				Layer->addChild(layerlol4);
			}

			if (GameManager::sharedState()->getGameVariable("profilecorner3") == true)
			{

			}
			//Animate color
			if (GameManager::sharedState()->getGameVariable("profilecolor1") != true)
			{
				Layer->addChild(layerlol1);
			}
			
			if (GameManager::sharedState()->getGameVariable("profilecolor1") == true)
			{
				
				

				Layer->addChild(layerlol1);
				Layer->addChild(layerlol2);


				// Crea la acción de desvanecimiento para layerlol2 con un delay
				auto fadeIn2 = CCFadeIn::create(1.8f);
				auto fadeOut2 = CCFadeOut::create(1.8f);
				auto sequence2 = CCSequence::create(fadeOut2, fadeIn2, nullptr);
				auto repeatedSequence2 = CCRepeatForever::create(sequence2);
				layerlol2->runAction(repeatedSequence2);
    
	
			}

			
			/*Layer->addChild(layerlol1);*/
			
			BG->setPosition(winSize / 2);
			BG->setPositionY(BG->getPositionY() - 1);
			/*BG->setPosition(layerlol->getPosition());*/
			BG->setScale(1.006);
			auto Idk = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");
			/*Idk->setPosition(pqwtest->getPositionX() + 170, pqwtest->getPositionY() + 22);*/
			Idk->setPosition(winSize.width / 2, owo + 40);
			Idk->setZOrder(layerlol1->getZOrder() + 3);
			Idk->setContentSize(players);
			Idk->setColor({ 154,154,154 });
			Idk->setOpacity(77);
			Idk->setID("ccscale-icons"_spr);
			Layer->addChild(Idk);

			auto Idk2 = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");
            Idk2->setPosition(winSize.width / 2, owo - 53);
            Idk2->setContentSize(comments);
            Idk2->setColor({ 154,154,154 });
            Idk2->setOpacity(77);
			Idk2->setID("ccscale-comments"_spr);


            Idk2->setZOrder(layerlol1->getZOrder() + 3);

			Layer->addChild(Idk2);


			layerlol1->setTag(3);
			auto BLackC = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
			BLackC->setPosition(laweaxd->getPositionX(), laweaxd->getPositionY()-1);
			BLackC->setZOrder(laweaxd->getZOrder());
			BLackC->setColor(ccBLACK);
			BLackC->setOpacity(50);
			BLackC->setContentSize(loll);
			BLackC->setScale(0.5);
			Layer->addChild(BLackC);

			if (GameManager::sharedState()->getGameVariable("profilecolor1") == false &&
				GameManager::sharedState()->getGameVariable("profilecolor2") == false &&
				GameManager::sharedState()->getGameVariable("profilecolor3") == false)
			{
				/*pqwtest->setVisible(false);*/
				laweaxd->setVisible(true);
				layerlol1->setVisible(false);
				layerlol2->setVisible(false);
				layerlol3->setVisible(false);
				layerlol4->setVisible(false);
				BLackC->setVisible(false);
				BG->setVisible(false);
			}
		}

		
		/*FLAlertLayer::create("Geode", "Hello from my custom mod!", "OK")->show();*/
		
	}
	 
	
	
};
class $modify(CommentCell)
{
	void loadFromComment(GJComment * a1)
	{
		CommentCell::loadFromComment(a1);
		
		if (a1->m_levelID == 0 || a1->m_hasLevelID == 1)
		{
			auto winSize = CCDirector::sharedDirector()->getWinSize();
			auto carewaba = (CCSprite*)this->getChildren()->objectAtIndex(0);
			carewaba->setVisible(false);

			CCSize a = { 890, 85 };
			int X;
			int Y;
			Y = this->getPositionY() + 18;
			X = this->getPositionX() + 170;

			if (this->m_height == 36)
			{
				auto Idk2 = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
				Idk2->setColor(ccBLACK);
				Idk2->setOpacity(32);
				Idk2->setScale(0.375);
				Idk2->setContentSize(a);
				Idk2->setPositionY(Y);
				Idk2->setPositionX(X);
				Idk2->setZOrder(-1);
				this->addChild(Idk2);
			}
			else
			{
				CCObject* pObj = nullptr;
				CCARRAY_FOREACH(((CCLayer*)(this->getChildren()->objectAtIndex(1)))->getChildren(), pObj) {

					if (instanceof<cocos2d::extension::CCScale9Sprite>(pObj)) {

						cocos2d::extension::CCScale9Sprite* scale9Sprite = dynamic_cast<cocos2d::extension::CCScale9Sprite*>(pObj);
						scale9Sprite->setColor(ccBLACK);
						scale9Sprite->setOpacity(32);
					}

				}
			}
		}

	}
	//TodoReturn updateBGColor(int a1)
	//{
	//	CommentCell::updateBGColor(a1);
	//	CCObject* pObj = nullptr;
	// 
	//	if (this->m_comment->m_levelID == 0 || this->m_comment->m_hasLevelID == 1) {

	//		CCARRAY_FOREACH(((CCLayer*)(this->getChildren()->objectAtIndex(1)))->getChildren(), pObj) {

	//			if (instanceof<cocos2d::extension::CCScale9Sprite>(pObj)) {

	//				cocos2d::extension::CCScale9Sprite* scale9Sprite = dynamic_cast<cocos2d::extension::CCScale9Sprite*>(pObj);
	//				scale9Sprite->setColor(ccBLACK);
	//				scale9Sprite->setOpacity(32);
	//			}

	//		}
	//	}
	//}

	//dklsnl
	int weawa = 0;
#include <sstream>
#include <iostream>
#include <cstdio>

	//btbr
	//void draw()
	//{
	//	if (weawa == 0)
	//	{
	//		weawa = 1;
	//	}		

	//	/*std::cout << "Referencia:" << this->m_uReference << std::endl;
	//	
	//	std::cout << "Width:" << this->m_width << std::endl;
	//	std::cout << "Height:" << this->m_height << std::endl;*/
	//	//21.5
 //   //SOME SHIT FOR GEODE 
	//	if (this->m_uReference == 3 && this->m_width == 0) {
	//   	CommentCell::draw();
	//   }

	//	if (this->m_uReference == 3 && this->m_width <= 10) {
	//		CommentCell::draw();
	//	}
	//	if (this->m_uReference == 3 && this->m_width == 358) {
	//		CommentCell::draw();
	//	}

	//	if (this->m_uReference == 3 && this->m_width <= 12) {
	//		CommentCell::draw();
	//	}

	//	//Local leaderboard fix
	//	/*if (this->m_uReference == 2 && this->m_height >= 21 && this->m_height <= 22) {
	//		CommentCell::draw();
	//	}*/

	//	if (this->m_uReference == 3 && this->m_height >= 21 && this->m_height <= 22) {
	//		CommentCell::draw();
	//	}

	//	if (this->m_uReference == 2 && this->m_width <= 0) {
	//		CommentCell::draw();
	//	}
	//	if (this->m_uReference == 2 && this->m_width <= 10) {
	//		CommentCell::draw();
	//	}
	//	if (this->m_uReference == 2 && this->m_width == 358) {
	//		CommentCell::draw();
	//	}

	//	if (this->m_uReference == 2 && this->m_width == 0) {
	//		CommentCell::draw();
	//	}

	//	if (this->m_uReference ==2 && this->m_width >= 15)
	//	{
	//		if (this->m_height == 60) {
	//			CommentCell::draw();
	//		}
	//		else
	//		{
	//			if (this->m_height == 55)
	//			{
	//				CommentCell::draw();
	//			}
	//			else
	//			{

	//				if (this->m_height == 45)
	//				{
	//					CommentCell::draw();
	//				}
	//				else
	//				{
	//					if (this->m_height == 50)
	//					{
	//						CommentCell::draw();
	//					}
	//					else
	//					{
	//						if (this->m_height == 40)
	//						{
	//							CommentCell::draw();
	//						}
	//						else
	//						{
	//							if (this->m_height == 30)
	//							{
	//								CommentCell::draw();
	//							}
	//							else
	//							{
	//								if (this->m_height == 24)
	//								{
	//									CommentCell::draw();
	//								}
	//								else
	//								{
	//									if (this->m_height >= 21 && this->m_height <= 22)
	//									{
	//										CommentCell::draw();
	//									}
	//									else
	//									{
	//										if (this->m_height == 20)
	//										{
	//											CommentCell::draw();
	//										}
	//										else
	//										{
	//											if (this->m_height == 100)
	//											{
	//												CommentCell::draw();
	//											}
	//											else
	//											{
	//												if (this->m_height == 90 && this->m_width == 356)
	//												{
	//													CommentCell::draw();
	//												}
	//												else
	//												{
	//													if (this->m_height == 80 && this->m_width == 356)
	//													{
	//														CommentCell::draw();
	//													}
	//													else
	//													{


	//														if (this->m_comment->m_levelID == 0 || this->m_comment->m_hasLevelID == 1 /*|| self->m_fHeight != 36*/) {

	//															if (this->m_height == 36)
	//															{

	//															}
	//														}
	//														else
	//														{
	//															if (this->m_height == 36)
	//															{
	//																CommentCell::draw();
	//															}



	//															if (this->m_comment->m_levelID != 0)
	//															{
	//																CommentCell::draw();
	//															}

	//														}

	//													}
	//												}
	//											}
	//										}
	//									}
	//								}
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	
};
