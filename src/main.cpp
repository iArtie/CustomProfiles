#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/modify/CommentCell.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/modify/GJAccountSettingsLayer.hpp>
#include "ProfilesConfig.hpp"
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
void FixLayer(CCLayer* layer, int width, int height) {
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

class $modify(GJAccountSettingsLayer)
{
	void onClose(cocos2d::CCObject * sender)
	{
		if (GameManager::sharedState()->getGameVariable("weaclosexd") == false)
		{
			GJAccountSettingsLayer::onClose(sender);
		}
		if (GameManager::sharedState()->getGameVariable("weaclosexd") == true)
		{
			/*auto OptionsBtn = dynamic_cast<CCMenuItemSpriteExtra*>(sender);
			auto parentNode = OptionsBtn->getParent();
			parentNode->setVisible(false);*/
		}
	}
	bool init(int a1)
	{
		if (!GJAccountSettingsLayer::init(a1)) return false;


		/*std::cout << "version:" << Loader::get()->getVersion().getPatch() << std::endl;*/

#ifdef GEODE_IS_ANDROID
		return true;
#endif
		/*if (Loader::get()->getVersion() == 2.205)
		{
		}*/
#ifdef GEODE_IS_WINDOWS
		GameManager::sharedState()->setGameVariable("weaclosexd", false);
		auto butonCancel = ButtonSprite::create("Cancel", 65, 70, "bigFont.fnt", "GJ_button_01.png", 25, 1);
		auto winSize = CCDirector::sharedDirector()->getWinSize();
		auto Layer = (CCLayer*)this->getChildren()->objectAtIndex(0);

		auto CancelBtn = CCMenuItemSpriteExtra::create(
			butonCancel,
			this,
			menu_selector(ProfilesConfig::onReturn)
		);
		for (int i = 0; i < Layer->getChildrenCount(); ++i) {
			auto nodelol = (CCLayer*)Layer->getChildren()->objectAtIndex(i);

			if (i == 1)
			{
				auto buttonsas = (CCLayer*)nodelol->getChildren()->objectAtIndex(8);
				buttonsas->setVisible(false);

				CancelBtn->setContentSize(buttonsas->getContentSize());
				CancelBtn->setPosition(buttonsas->getPosition());
				CancelBtn->setScale(buttonsas->getScale());
				CancelBtn->setZOrder(buttonsas->getZOrder());
				auto spras = (CCLayer*)buttonsas->getChildren()->objectAtIndex(0);
				butonCancel->setContentSize(spras->getContentSize());
				butonCancel->setPosition(spras->getPosition());
				nodelol->addChild(CancelBtn);
			}

			/*if (nodelol->isVisible() == false)
			{
				nodelol->setVisible(true);
			}*/
		}
		CCSize size = { 440,290 };
		Layer->setVisible(false);
		Layer->setZOrder(15);
		/*auto config = ProfilesConfig::create(this);*/
		auto BG = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png");
		BG->setPosition(winSize / 2);
		BG->setContentSize(size);
		BG->setScale(0);
		this->addChild(BG);
		auto waexd = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
		waexd->setContentSize({ 360,55 });


		auto waexd2 = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
		waexd2->setContentSize({ 360,55 });


		auto fadeIn = CCFadeIn::create(0.04f);  // O cualquier duración que desees
		auto scaleTo = CCScaleTo::create(0.04f, 1.0f);  // Escalar el fondo al tamaño original

		auto fadeInWithEase = CCEaseBackOut::create(fadeIn);
		auto scaleToWithEase = CCEaseBackOut::create(scaleTo);

		auto spawn = CCSpawn::create(fadeInWithEase, scaleToWithEase, nullptr);

		auto Exit = CCSprite::createWithSpriteFrameName("GJ_deleteBtn_001.png");

		Exit->setScale(0.95f);
		auto ExitBtn = CCMenuItemSpriteExtra::create(
			Exit,
			this,
			menu_selector(GJAccountSettingsLayer::onClose)
		);

		auto onSpr = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
		auto offSpr = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");

		onSpr->setScale(.7);
		offSpr->setScale(.7);
		auto label = CCLabelBMFont::create("CustomProfiles Options", "bigfont.fnt");
		label->setPosition(winSize / 2);
		/*label->setPositionX(label->getPositionX() - 65);*/
		label->setPositionY(label->getPositionY() + 120);
		label->setScale(0.55);
		this->addChild(label);
		auto elmenu = CCMenu::create();

		elmenu->addChild(ExitBtn);



		auto label2 = CCLabelBMFont::create("Corners", "bigfont.fnt");
		label2->setPosition(winSize / 2);
		/*label2->setPositionX(0);*/
		label2->setPositionY(label2->getPositionY() + 80);

		waexd->setPosition(winSize / 2);
		/*waexd->setPositionX(waexd->getPositionX() - 65);*/
		waexd->setPositionY(waexd->getPositionY() + 38);
		waexd->setColor(ccBLACK);
		waexd->setOpacity(77);
		label2->setScale(0.55);

		auto menuglowxd = CCMenu::create();

		//Corners buttons
		auto toggle1 = CCMenuItemToggler::create(
			offSpr,
			onSpr,
			this,
			menu_selector(ProfilesConfig::corner1));
		/*toggle1->setSizeMult(1.5);*/







		toggle1->setPosition(winSize / 2);
		toggle1->setPositionX(toggle1->getPositionX() - 150);
		toggle1->setPositionY(toggle1->getPositionY() + 49);



		toggle1->setTag(11);

		auto labelcorner1 = CCLabelBMFont::create("Round", "bigfont.fnt");
		labelcorner1->setPosition(toggle1->getPosition());
		labelcorner1->setPositionX(labelcorner1->getPositionX() + 57);
		labelcorner1->setPositionY(labelcorner1->getPositionY() + 1);
		labelcorner1->setScale(0.75);

		menuglowxd->addChild(toggle1);
		menuglowxd->addChild(labelcorner1);

		auto toggle2 = CCMenuItemToggler::create(
			offSpr,
			onSpr,
			this,
			menu_selector(ProfilesConfig::corner2));
		/*toggle1->setSizeMult(1.5);*/

		/*toggle2->activate();*/




		toggle2->setPosition(winSize / 2);
		toggle2->setPositionX(toggle2->getPositionX() - 38);
		toggle2->setPositionY(toggle2->getPositionY() + 49);


		toggle2->setTag(12);

		auto labelcorner2 = CCLabelBMFont::create("Square", "bigfont.fnt");
		labelcorner2->setPosition(toggle2->getPosition());
		labelcorner2->setPositionX(labelcorner2->getPositionX() + 61);
		labelcorner2->setPositionY(labelcorner2->getPositionY() + 1);
		labelcorner2->setScale(0.75);

		menuglowxd->addChild(toggle2);
		menuglowxd->addChild(labelcorner2);


		auto toggle3 = CCMenuItemToggler::create(
			offSpr,
			onSpr,
			this,
			menu_selector(ProfilesConfig::corner3));
		/*toggle1->setSizeMult(1.5);*/

		/*toggle2->activate();*/




		toggle3->setPosition(winSize / 2);
		toggle3->setPositionX(toggle3->getPositionX() + 87);
		toggle3->setPositionY(toggle3->getPositionY() + 49);

		toggle3->setTag(13);

		auto labelcorner3 = CCLabelBMFont::create("None", "bigfont.fnt");
		labelcorner3->setPosition(toggle3->getPosition());
		labelcorner3->setPositionX(labelcorner3->getPositionX() + 50);
		labelcorner3->setPositionY(labelcorner3->getPositionY() + 1);
		labelcorner3->setScale(0.75);

		menuglowxd->addChild(toggle3);
		menuglowxd->addChild(labelcorner3);


		//Color options

		auto togglecolor1 = CCMenuItemToggler::create(
			offSpr,
			onSpr,
			this,
			menu_selector(ProfilesConfig::color1));
		/*toggle1->setSizeMult(1.5);*/

		/*togglecolor1->activate();*/

		togglecolor1->setTag(21);

		menuglowxd->setPosition(winSize / 2);
		menuglowxd->setPositionX(menuglowxd->getPositionX() - 350);
		menuglowxd->setPositionY(menuglowxd->getPositionY() - 177);



		togglecolor1->setPosition(winSize / 2);
		togglecolor1->setPositionX(togglecolor1->getPositionX() - 150);
		togglecolor1->setPositionY(togglecolor1->getPositionY() - 40);




		auto labelcolor1 = CCLabelBMFont::create("Animate", "bigfont.fnt");
		labelcolor1->setPosition(togglecolor1->getPosition());
		labelcolor1->setPositionX(labelcolor1->getPositionX() + 57);
		labelcolor1->setPositionY(labelcolor1->getPositionY() + 1);
		labelcolor1->setScale(0.60);

		menuglowxd->addChild(togglecolor1);
		menuglowxd->addChild(labelcolor1);

		auto togglecolor2 = CCMenuItemToggler::create(
			offSpr,
			onSpr,
			this,
			menu_selector(ProfilesConfig::color2));
		togglecolor2->setTag(22);
		/*toggle1->setSizeMult(1.5);*/

		/*toggle2->activate();*/




		togglecolor2->setPosition(winSize / 2);
		togglecolor2->setPositionX(togglecolor2->getPositionX() - 38);
		togglecolor2->setPositionY(togglecolor2->getPositionY() - 40);




		auto labelcolor2 = CCLabelBMFont::create("Invert", "bigfont.fnt");
		labelcolor2->setPosition(togglecolor2->getPosition());
		labelcolor2->setPositionX(labelcolor2->getPositionX() + 61);
		labelcolor2->setPositionY(labelcolor2->getPositionY() + 1);
		labelcolor2->setScale(0.75);

		menuglowxd->addChild(togglecolor2);
		menuglowxd->addChild(labelcolor2);


		auto togglecolor3 = CCMenuItemToggler::create(
			offSpr,
			onSpr,
			this,
			menu_selector(ProfilesConfig::color3));
		/*toggle1->setSizeMult(1.5);*/

		/*togglecolor3->activate()*/;




		togglecolor3->setPosition(winSize / 2);
		togglecolor3->setPositionX(togglecolor3->getPositionX() + 87);
		togglecolor3->setPositionY(togglecolor3->getPositionY() - 40);

		togglecolor3->setTag(25);
		//Corners
		if (GameManager::sharedState()->getGameVariable("profilecorner1") == true)
		{
			toggle1->toggle(1);
			toggle2->toggle(0);
			toggle3->toggle(0);
		}

		if (GameManager::sharedState()->getGameVariable("profilecorner2") == true)
		{
			toggle1->toggle(0);
			toggle2->toggle(1);
			toggle3->toggle(0);
		}

		if (GameManager::sharedState()->getGameVariable("profilecorner3") == true)
		{
			toggle1->toggle(0);
			toggle2->toggle(0);
			toggle3->toggle(1);
		}
		//Colors
		if (GameManager::sharedState()->getGameVariable("profilecolor1") == true)
		{
			togglecolor1->toggle(1);
			togglecolor2->toggle(0);
			togglecolor3->toggle(0);
		}

		if (GameManager::sharedState()->getGameVariable("profilecolor2") == true)
		{
			togglecolor1->toggle(0);
			togglecolor2->toggle(1);
			togglecolor3->toggle(0);
		}

		if (GameManager::sharedState()->getGameVariable("profilecolor3") == true)
		{
			togglecolor1->toggle(0);
			togglecolor2->toggle(0);
			togglecolor3->toggle(1);
		}


		auto labelcolor3 = CCLabelBMFont::create("Normal", "bigfont.fnt");
		labelcolor3->setPosition(togglecolor3->getPosition());
		labelcolor3->setPositionX(labelcolor3->getPositionX() + 53);
		labelcolor3->setPositionY(labelcolor3->getPositionY() + 1);
		labelcolor3->setScale(0.60);
		togglecolor3->setTag(25);

		menuglowxd->addChild(togglecolor3);
		menuglowxd->addChild(labelcolor3);
		this->addChild(label2);
		this->addChild(waexd);


		menuglowxd->setPosition(-1, -11);
		/*menuglowxd->setPosition(BG->getPositionX(), BG->getPositionY());*/
		/*menuglowxd->setPositionX(menuglowxd->getPositionX() - 350);
		menuglowxd->setPositionY(menuglowxd->getPositionY() - 177);*/

		this->addChild(menuglowxd, 2);







		auto label3 = CCLabelBMFont::create("Colors", "bigfont.fnt");
		label3->setPosition(winSize / 2);
		/*label3->setPositionX(label3->getPositionX() - 65);*/
		label3->setPositionY(label3->getPositionY() - 10);

		waexd2->setPosition(winSize / 2);
		/*waexd2->setPositionX(waexd2->getPositionX() - 65);*/
		waexd2->setPositionY(waexd2->getPositionY() - 52);
		waexd2->setColor(ccBLACK);
		waexd2->setOpacity(77);
		label3->setScale(0.55);
		this->addChild(label3);
		this->addChild(waexd2);
		auto Options = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");

		Options->setScale(0.7f);
		auto OptionsBtn = CCMenuItemSpriteExtra::create(
			Options,
			this,
			menu_selector(ProfilesConfig::onOptionsBtnClick)
		);


		/*OptionsBtn->setScale(0.7);*/

		auto disableinfo = CCMenuItemToggler::create(
			offSpr,
			onSpr,
			this,
			menu_selector(ProfilesConfig::disableInfolabel));
		if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
		{
			disableinfo->toggle(1);
		}

		if (GameManager::sharedState()->getGameVariable("disableinfolabel") == false)
		{
			disableinfo->toggle(0);
		}
		auto infolabel = CCLabelBMFont::create("Disable info button", "bigfont.fnt");

		disableinfo->setPosition(OptionsBtn->getPosition());
		disableinfo->setPositionX(disableinfo->getPositionX() - 390);


		infolabel->setPosition(disableinfo->getPosition());
		infolabel->setPositionX(infolabel->getPositionX() + 100);
		infolabel->setScale(0.5);
		auto optionsmenu = CCMenu::create();
		optionsmenu->addChild(OptionsBtn);
		optionsmenu->addChild(disableinfo);
		optionsmenu->addChild(infolabel);

		optionsmenu->setPosition(BG->getPositionX() + 196, BG->getPositionY() - 116);
		/*optionsmenu->setPosition(winSize / 2);*/
	/*	optionsmenu->setPosition(optionsmenu->getPositionX() + 131, optionsmenu->getPositionY() - 133);*/

		this->addChild(optionsmenu, 2);
		this->addChild(elmenu, 2);

		elmenu->setPosition(BG->getPositionX(), BG->getPositionY());
		elmenu->setPositionX(elmenu->getPositionX() - 210);
		elmenu->setPositionY(elmenu->getPositionY() + 135);

		BG->runAction(spawn);



		elmenu->setTag(50);
		optionsmenu->setTag(51);
		label->setTag(52);
		label2->setTag(53);
		label3->setTag(54);
		waexd->setTag(55);
		waexd2->setTag(56);
		menuglowxd->setTag(57);
		BG->setTag(58);
		/*ProfilesConfig::create(this)->show();*/
		/*FLAlertLayer::create("OMG", "Si funciona! :D", "OK")->show();*/
		return true;
#endif
		
	}
};
void updateColors(float dt,CCLayerGradient* gradient)
{
	// Obtén los colores actuales
	cocos2d::ccColor3B currentStartColor = gradient->getStartColor();
	cocos2d::ccColor3B currentEndColor = gradient->getEndColor();

	// Alterna entre dos colores
	if (currentStartColor == ccc3(255, 0, 0)) {
		gradient->setStartColor(ccc3(0, 255, 0));
		gradient->setEndColor(ccc3(0, 0, 255));
	}
	else {
		gradient->setStartColor(ccc3(255, 0, 0));
		gradient->setEndColor(ccc3(0, 255, 0));
	}
}


class $modify(InfoLayer)
{
	TodoReturn setupCommentsBrowser(cocos2d::CCArray*a1)
	{
		InfoLayer::setupCommentsBrowser(a1);

		
		if (this->m_level == nullptr && this->m_levelList == nullptr)
		{
			FixLayer(this, 340, 234);
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
class $modify(ProfilePage)
{

	bool init(int a1, bool a2)
	{
		if(!ProfilePage::init(a1, a2)) return false;
		auto nodelolas = (CCLayer*)this->getChildren()->objectAtIndex(0);
		
		return true;
	}

	TodoReturn setupCommentsBrowser(cocos2d::CCArray * a1)
	{
		ProfilePage::setupCommentsBrowser(a1);
		
		//auto hijos = Layer->getChildren();
		//for (int i = 0; i < hijos->count(); ++i) {
		//	auto hijo = hijos.at(i);

		//	// Verifica si el contentSize cumple con tus condiciones
		//	if (hijo->getContentSize().equals(Size(100.0f, 100.0f))) {
		//		// Llama a tu función personalizada
		//		tuFuncionPersonalizada(hijo);
		//	}
		//}
		FixLayer(this, 340, 100);
		
		
	}
#include <thread> // Necesario para std::this_thread::sleep_for
#include <chrono>
#include <iostream>
#include <sstream>
	void onUpdate(CCObject* sender)
	{
		ProfilePage::onUpdate(sender);
		auto Layer = (CCLayer*)this->getChildren()->objectAtIndex(0);
		CCObject* pObj = nullptr;

		CCARRAY_FOREACH(((CCLayer*)(this->getChildren()->objectAtIndex(0)))->getChildren(), pObj) {

			if (instanceof<cocos2d::CCMenu>(pObj)) {

				cocos2d::CCMenu* scale9Sprite = dynamic_cast<cocos2d::CCMenu*>(pObj);
				CCSize contentSize = scale9Sprite->getContentSize();
				/*scale9Sprite->setColor(ccBLACK);
				scale9Sprite->setOpacity(32);*/
				if (contentSize.width == 569 && contentSize.height == 320)
				{
					cocos2d::CCMenu* scale9Sprite = dynamic_cast<cocos2d::CCMenu*>(pObj);
					/*scale9Sprite->setColor(ccBLACK);
					scale9Sprite->setOpacity(32);*/
					if (this->m_ownProfile == true)
					{

						for (int i = 0; i < scale9Sprite->getChildrenCount(); ++i) {
							auto nodelolas = (CCMenuItemSpriteExtra*)scale9Sprite->getChildren()->objectAtIndex(i);
							CCSize contentSize2 = nodelolas->getContentSize();
							if (contentSize2.width >= 10 && contentSize2.width <= 12)
							{
								if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
								{
									/*FLAlertLayer::create("Yes", "We are here!", "OK")->show();*/
									nodelolas->setPositionY(+100000);
								}
							}
						}
					}
					else
					{
						for (int i = 0; i < scale9Sprite->getChildrenCount(); ++i) {
							auto nodelolas = (CCMenuItemSpriteExtra*)scale9Sprite->getChildren()->objectAtIndex(i);
							CCSize contentSize2 = nodelolas->getContentSize();
							if (contentSize2.width >= 10 && contentSize2.width <= 12)
							{
								if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
								{
									/*FLAlertLayer::create("Yes", "We are here!", "OK")->show();*/
									nodelolas->setPositionY(+100000);
								}
							}

							/*if (nodelol->isVisible() == false)
							{
								nodelol->setVisible(true);
							}*/
						}


					}
				}
			}

		}
		
	}
	TodoReturn loadPageFromUserInfo(GJUserScore*asas)
	{
		
		ProfilePage::loadPageFromUserInfo(asas);

		
		/*std::cout << OBM(&GJUserScore::m_color3) << std::endl;*/
		//color1 offset is 360
		//color2 offset is 364
		//color3 offset is 368
		auto winSize = CCDirector::sharedDirector()->getWinSize();
		auto Layer = (CCLayer*)this->getChildren()->objectAtIndex(0);
		auto blackSize = CCSize(438, 293);
		auto laweaxd = (CCSprite*)Layer->getChildren()->objectAtIndex(0);
		
		//7121
		auto pqwtest = (CCSprite*)Layer->getChildren()->objectAtIndex(3);


		if (GameManager::sharedState()->getGameVariable("startingmodsas") == false)
		{
			GameManager::sharedState()->setGameVariable("profilecorner1", true);
			GameManager::sharedState()->setGameVariable("profilecolor3", true);
			GameManager::sharedState()->setGameVariable("startingmodsas", true);
		}
		CCSize newNodeSize = { 0, 100 };
		CCObject* pObj = nullptr;
		auto layerChild = dynamic_cast<CCLayer*>(this->getChildren()->objectAtIndex(0));
		CCARRAY_FOREACH(layerChild->getChildren(), pObj) {
			CCNode* currentNode = (CCNode*)pObj;
			CCPoint xy = currentNode->getPosition();
			currentNode->getContentSize();

			CCSize contentSize = currentNode->getContentSize();

			if (instanceof<cocos2d::CCMenu>(pObj)) {

				if (contentSize.width == 569 && contentSize.height == 320)
				{
					cocos2d::CCMenu* scale9Sprite = dynamic_cast<cocos2d::CCMenu*>(pObj);
					/*scale9Sprite->setColor(ccBLACK);
					scale9Sprite->setOpacity(32);*/
					if (this->m_ownProfile == true)
					{

						/*auto infobutton = (CCMenuItemSpriteExtra*)scale9Sprite->getChildren()->objectAtIndex(10);
						if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
						{
							infobutton->setPositionY(+100000);
						}*/
						for (int i = 0; i < scale9Sprite->getChildrenCount(); ++i) {
							auto nodelolas = (CCMenuItemSpriteExtra*)scale9Sprite->getChildren()->objectAtIndex(i);
							CCSize contentSize2 = nodelolas->getContentSize();
							if (contentSize2.width >= 10 && contentSize2.width <= 12)
							{
								if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
								{
									/*FLAlertLayer::create("Yes", "We are here!", "OK")->show();*/
									nodelolas->setPositionY(+100000);
								}
							}
						}
					}
					else
					{
						for (int i = 0; i < scale9Sprite->getChildrenCount(); ++i) {
							auto nodelolas = (CCMenuItemSpriteExtra*)scale9Sprite->getChildren()->objectAtIndex(i);
							CCSize contentSize2 = nodelolas->getContentSize();
							if (contentSize2.width  >= 10 && contentSize2.width <= 12)
							{
								if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
								{
									/*FLAlertLayer::create("Yes", "We are here!", "OK")->show();*/
									nodelolas->setPositionY(+100000);
								}
							}

							/*if (nodelol->isVisible() == false)
							{
								nodelol->setVisible(true);
							}*/
						}
						
						
					}
				}
				
				
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
			pqwtest->setVisible(false);
			laweaxd->setVisible(false);
			auto BG = cocos2d::extension::CCScale9Sprite::create("GJ_square07.png");
			FixLayerv2(this, 340, 45);
			int owo = winSize.height / 2;
			int uwu = winSize.width / 2;
			BG->setZOrder(7);
			/*BG->setPosition(pqwtest->getPositionX() + 170, pqwtest->getPositionY()-18);*/
			
			BG->setContentSize(blackSize);
			
			pqwtest->setVisible(false);
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

			auto layerlol2 = CCLayerGradient::create(col2, col1);
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
			Layer->addChild(Idk);

			auto Idk2 = cocos2d::extension::CCScale9Sprite::create("square02c_001.png");
            Idk2->setPosition(winSize.width / 2, owo - 53);
            Idk2->setContentSize(comments);
            Idk2->setColor({ 154,154,154 });
            Idk2->setOpacity(77);



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
		}

	}
	TodoReturn updateBGColor(int a1)
	{
		CommentCell::updateBGColor(a1);
		CCObject* pObj = nullptr;
	 
		if (this->m_comment->m_levelID == 0 || this->m_comment->m_hasLevelID == 1) {

			CCARRAY_FOREACH(((CCLayer*)(this->getChildren()->objectAtIndex(1)))->getChildren(), pObj) {

				if (instanceof<cocos2d::extension::CCScale9Sprite>(pObj)) {

					cocos2d::extension::CCScale9Sprite* scale9Sprite = dynamic_cast<cocos2d::extension::CCScale9Sprite*>(pObj);
					scale9Sprite->setColor(ccBLACK);
					scale9Sprite->setOpacity(32);
				}

			}
		}
	}

	int weawa = 0;
#include <sstream>
#include <iostream>
#include <cstdio>


	void draw()
	{
		if (weawa == 0)
		{
			weawa = 1;
		}		

		/*std::cout << "Referencia:" << this->m_uReference << std::endl;
		
		std::cout << "Width:" << this->m_width << std::endl;
		std::cout << "Height:" << this->m_height << std::endl;*/
		//21.5
    //SOME SHIT FOR GEODE 
		if (this->m_uReference == 3 && this->m_width == 0) {
	   	CommentCell::draw();
	   }

		if (this->m_uReference == 3 && this->m_width <= 10) {
			CommentCell::draw();
		}
		if (this->m_uReference == 3 && this->m_width == 358) {
			CommentCell::draw();
		}

		if (this->m_uReference == 3 && this->m_width <= 12) {
			CommentCell::draw();
		}

		//Local leaderboard fix
		/*if (this->m_uReference == 2 && this->m_height >= 21 && this->m_height <= 22) {
			CommentCell::draw();
		}*/

		if (this->m_uReference == 3 && this->m_height >= 21 && this->m_height <= 22) {
			CommentCell::draw();
		}

		if (this->m_uReference == 2 && this->m_width <= 0) {
			CommentCell::draw();
		}
		if (this->m_uReference == 2 && this->m_width <= 10) {
			CommentCell::draw();
		}
		if (this->m_uReference == 2 && this->m_width == 358) {
			CommentCell::draw();
		}

		if (this->m_uReference == 2 && this->m_width == 0) {
			CommentCell::draw();
		}

		if (this->m_uReference ==2 && this->m_width >= 15)
		{
			if (this->m_height == 60) {
				CommentCell::draw();
			}
			else
			{
				if (this->m_height == 55)
				{
					CommentCell::draw();
				}
				else
				{

					if (this->m_height == 45)
					{
						CommentCell::draw();
					}
					else
					{
						if (this->m_height == 50)
						{
							CommentCell::draw();
						}
						else
						{
							if (this->m_height == 40)
							{
								CommentCell::draw();
							}
							else
							{
								if (this->m_height == 30)
								{
									CommentCell::draw();
								}
								else
								{
									if (this->m_height == 24)
									{
										CommentCell::draw();
									}
									else
									{
										if (this->m_height >= 21 && this->m_height <= 22)
										{
											CommentCell::draw();
										}
										else
										{
											if (this->m_height == 20)
											{
												CommentCell::draw();
											}
											else
											{
												if (this->m_height == 100)
												{
													CommentCell::draw();
												}
												else
												{
													if (this->m_height == 90 && this->m_width == 356)
													{
														CommentCell::draw();
													}
													else
													{
														if (this->m_height == 80 && this->m_width == 356)
														{
															CommentCell::draw();
														}
														else
														{


															if (this->m_comment->m_levelID == 0 || this->m_comment->m_hasLevelID == 1 /*|| self->m_fHeight != 36*/) {

																if (this->m_height == 36)
																{

																}
															}
															else
															{
																if (this->m_height == 36)
																{
																	CommentCell::draw();
																}



																if (this->m_comment->m_levelID != 0)
																{
																	CommentCell::draw();
																}

															}

														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
};