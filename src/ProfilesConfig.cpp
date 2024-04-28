//#pragma once
//
//#include "ProfilesConfig.hpp"
//using namespace cocos2d;
//void ProfilesConfig::show()
//{
//	auto scene = CCDirector::sharedDirector()->getRunningScene();
//	scene->addChild(this);
//
//	auto fadeto = CCFadeTo::create(0.14, 100);
//	this->runAction(fadeto);
//	this->setTouchEnabled(true);
//}
//
//
//bool ProfilesConfig::init(CCLayer* layer)
//{
//	bool result = this->initWithColor(ccc4(0, 0, 0, 0));
//	this->layerawa = layer;
//	if (result)
//	{
//		auto dir = CCDirector::sharedDirector();
//		auto winSize = CCDirector::sharedDirector()->getWinSize();
//		
//		
//		
//		//layerawa->setTouchPriority(-1); // O algún valor apropiado
//		layerawa->setTouchMode(kCCTouchesOneByOne);
//
//		auto Exit = CCSprite::createWithSpriteFrameName("GJ_deleteBtn_001.png");
//		this->setTouchEnabled(true);
//
//		Exit->setScale(0.8f);
//		auto ExitBtn = CCMenuItemSpriteExtra::create(
//			Exit,
//			this,
//			menu_selector(ProfilesConfig::backButton)
//		);
//		ExitBtn->setPosition(winSize / 2);
//		layerawa->addChild(ExitBtn);
//	}
//	return result;
//}
//void ProfilesConfig::keyBackClicked()
//{
//	CCDirector::sharedDirector()->popSceneWithTransition(0.5F, PopTransition::kPopTransitionFade);
//}
//
//void ProfilesConfig::onOptionsBtnClick(CCObject* sender) {
//	auto OptionsBtn = dynamic_cast<CCMenuItemSpriteExtra*>(sender);
//
//	auto dir = CCDirector::sharedDirector();
//	
//	GameManager::sharedState()->setGameVariable("weaclosexd", true);
//	auto parentNode = OptionsBtn->getParent();
//	auto parentNode2 = parentNode->getParent();
//
//	/*parentNode2->setVisible(false);*/
//	auto parentNode3 = parentNode->getParent();
//
//	for (int i = 0; i < parentNode2->getChildrenCount(); ++i) {
//		auto nodelolas = (CCMenuItemSpriteExtra*)parentNode2->getChildren()->objectAtIndex(i);
//		CCSize contentSize2 = nodelolas->getContentSize();
//		
//		if (nodelolas->getTag() >= 50)
//		{
//			/*FLAlertLayer::create("Yes", "We are here!", "OK")->show();*/
//			nodelolas->setVisible(false);
//		}
//	}
//	auto Layer = (CCLayer*)parentNode2->getChildren()->objectAtIndex(9);
//		
//			Layer->setVisible(true);
//
//#ifdef GEODE_IS_WINDOWS
//			Layer->setScale(0);
//			auto fadeIn = CCFadeIn::create(0.04f);  // O cualquier duración que desees
//			auto scaleTo = CCScaleTo::create(0.04f, 1.0f);  // Escalar el fondo al tamaño original
//
//			auto fadeInWithEase = CCEaseBackOut::create(fadeIn);
//			auto scaleToWithEase = CCEaseBackOut::create(scaleTo);
//
//			auto spawn = CCSpawn::create(fadeInWithEase, scaleToWithEase, nullptr);
//			Layer->runAction(spawn);
//#endif // !GEODE_IS_WINDOWS
//
//	
//}
//
//void ProfilesConfig::corner1(CCObject* sender)
//{
//	auto corner1 = dynamic_cast<CCMenuItemToggler*>(sender);
//	auto parentNode = corner1->getParent();
//	/*auto parentNode2 = parentNode->getParent();*/
//	/*parentNode->setVisible(false);*/
//
//	/*auto parentNode3 = parentNode2->getParent();*/
//	/*auto Layer = (CCLayer*)parentNode->getChildren()->objectAtIndex(0);*/
//
//	for (int i = 0; i < 9; ++i) {
//		auto nodelol = (CCMenuItemToggler*)parentNode->getChildren()->objectAtIndex(i);
//
//
//		if (nodelol->getTag() == 11 && nodelol->isToggled() == true)
//		{
//			nodelol->toggle(1);
//		}
//
//		if (nodelol->getTag() == 11 && nodelol->isToggled() == false)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 12)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 13)
//		{
//			nodelol->toggle(0);
//		}
//		/*if (nodelol->isVisible() == false)
//		{
//			nodelol->setVisible(true);
//		}*/
//	}
//	if (GameManager::sharedState()->getGameVariable("profilecorner1") == true)
//	{
//		GameManager::sharedState()->setGameVariable("profilecorner1", false);
//		GameManager::sharedState()->setGameVariable("profilecorner2", false);
//		GameManager::sharedState()->setGameVariable("profilecorner3", false);
//	}
//	else
//	{
//		GameManager::sharedState()->setGameVariable("profilecorner1", true);
//		GameManager::sharedState()->setGameVariable("profilecorner2", false);
//		GameManager::sharedState()->setGameVariable("profilecorner3", false);
//	}
//	
//}
//
//void ProfilesConfig::corner2(CCObject* sender)
//{
//	auto corner2 = dynamic_cast<CCMenuItemToggler*>(sender);
//	auto parentNode = corner2->getParent();
//	for (int i = 0; i < 9; ++i) {
//		auto nodelol = (CCMenuItemToggler*)parentNode->getChildren()->objectAtIndex(i);
//
//
//
//
//		if (nodelol->getTag() == 11)
//		{
//			nodelol->toggle(0);
//		}
//		if (nodelol->getTag() == 12 && nodelol->isToggled() == true)
//		{
//			nodelol->toggle(1);
//		}
//
//		if (nodelol->getTag() == 12 && nodelol->isToggled() == false)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 13)
//		{
//			nodelol->toggle(0);
//		}
//	}
//	if (GameManager::sharedState()->getGameVariable("profilecorner2") == true)
//	{
//		GameManager::sharedState()->setGameVariable("profilecorner1", false);
//		GameManager::sharedState()->setGameVariable("profilecorner2", false);
//		GameManager::sharedState()->setGameVariable("profilecorner3", false);
//	}
//	else
//	{
//		GameManager::sharedState()->setGameVariable("profilecorner1", false);
//		GameManager::sharedState()->setGameVariable("profilecorner2", true);
//		GameManager::sharedState()->setGameVariable("profilecorner3", false);
//	};
//}
//
//void ProfilesConfig::corner3(CCObject* sender)
//{
//	auto corner3 = dynamic_cast<CCMenuItemToggler*>(sender);
//	auto parentNode = corner3->getParent();
//	for (int i = 0; i < 9; ++i) {
//		auto nodelol = (CCMenuItemToggler*)parentNode->getChildren()->objectAtIndex(i);
//
//
//
//
//		if (nodelol->getTag() == 11)
//		{
//			nodelol->toggle(0);
//		}
//		
//
//		if (nodelol->getTag() == 12)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 13 && nodelol->isToggled() == true)
//		{
//			nodelol->toggle(1);
//		}
//
//		if (nodelol->getTag() == 13 && nodelol->isToggled() == false)
//		{
//			nodelol->toggle(0);
//		}
//	}
//	if (GameManager::sharedState()->getGameVariable("profilecorner3") == true)
//	{
//		GameManager::sharedState()->setGameVariable("profilecorner1", false);
//		GameManager::sharedState()->setGameVariable("profilecorner2", false);
//		GameManager::sharedState()->setGameVariable("profilecorner3", false);
//	}
//	else
//	{
//		GameManager::sharedState()->setGameVariable("profilecorner1", false);
//		GameManager::sharedState()->setGameVariable("profilecorner2", false);
//		GameManager::sharedState()->setGameVariable("profilecorner3", true);
//	}
//}
//
//
//void ProfilesConfig::color1(CCObject* sender)
//{
//	auto color1 = dynamic_cast<CCMenuItemToggler*>(sender);
//	auto parentNode = color1->getParent();
//	/*auto parentNode2 = parentNode->getParent();*/
//	/*parentNode->setVisible(false);*/
//
//	/*auto parentNode3 = parentNode2->getParent();*/
//	/*auto Layer = (CCLayer*)parentNode->getChildren()->objectAtIndex(0);*/
//
//	for (int i = 0; i < 12; ++i) {
//		auto nodelol = (CCMenuItemToggler*)parentNode->getChildren()->objectAtIndex(i);
//
//
//		if (nodelol->getTag() == 21 && nodelol->isToggled() == true)
//		{
//			nodelol->toggle(1);
//		}
//
//		if (nodelol->getTag() == 21 && nodelol->isToggled() == false)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 22)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 25)
//		{
//			nodelol->toggle(0);
//			/*nodelol->toggle(0);*/
//		}
//	}
//	if (GameManager::sharedState()->getGameVariable("profilecolor1") == true)
//	{
//		GameManager::sharedState()->setGameVariable("profilecolor1", false);
//		GameManager::sharedState()->setGameVariable("profilecolor2", false);
//		GameManager::sharedState()->setGameVariable("profilecolor3", false);
//	}
//	else
//	{
//		GameManager::sharedState()->setGameVariable("profilecolor1", true);
//		GameManager::sharedState()->setGameVariable("profilecolor2", false);
//		GameManager::sharedState()->setGameVariable("profilecolor3", false);
//	}
//}
//
//void ProfilesConfig::color2(CCObject* sender)
//{
//	auto color2 = dynamic_cast<CCMenuItemToggler*>(sender);
//	auto parentNode = color2->getParent();
//	for (int i = 0; i < 12; ++i) {
//		auto nodelol = (CCMenuItemToggler*)parentNode->getChildren()->objectAtIndex(i);
//
//
//
//
//		if (nodelol->getTag() == 21)
//		{
//			nodelol->toggle(0);
//		}
//		if (nodelol->getTag() == 22 && nodelol->isToggled() == true)
//		{
//			nodelol->toggle(1);
//		}
//
//		if (nodelol->getTag() == 22 && nodelol->isToggled() == false)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 25)
//		{
//			
//			nodelol->toggle(0);
//		}
//
//
//	}
//	if (GameManager::sharedState()->getGameVariable("profilecolor2") == true)
//	{
//		GameManager::sharedState()->setGameVariable("profilecolor1", false);
//		GameManager::sharedState()->setGameVariable("profilecolor2", false);
//		GameManager::sharedState()->setGameVariable("profilecolor3", false);
//	}
//	else
//	{
//		GameManager::sharedState()->setGameVariable("profilecolor1", false);
//		GameManager::sharedState()->setGameVariable("profilecolor2", true);
//		GameManager::sharedState()->setGameVariable("profilecolor3", false);
//	}
//}
//
//void ProfilesConfig::color3(CCObject* sender)
//{
//	auto color3 = dynamic_cast<CCMenuItemToggler*>(sender);
//	auto parentNode = color3->getParent();
//	for (int i = 0; i < 12; ++i) {
//		auto nodelol = (CCMenuItemToggler*)parentNode->getChildren()->objectAtIndex(i);
//
//
//
//
//		if (nodelol->getTag() == 21)
//		{
//			nodelol->toggle(0);
//		}
//		
//		if (nodelol->getTag() == 22)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 25 && nodelol->isToggled() == false)
//		{
//			nodelol->toggle(0);
//		}
//
//		if (nodelol->getTag() == 25 && nodelol->isToggled() == true)
//		{
//			nodelol->toggle(1);
//		}
//	}
//	if (GameManager::sharedState()->getGameVariable("profilecolor3") == true)
//	{
//		GameManager::sharedState()->setGameVariable("profilecolor1", false);
//		GameManager::sharedState()->setGameVariable("profilecolor2", false);
//		GameManager::sharedState()->setGameVariable("profilecolor3", false);
//	}
//	else
//	{
//		GameManager::sharedState()->setGameVariable("profilecolor1", false);
//		GameManager::sharedState()->setGameVariable("profilecolor2", false);
//		GameManager::sharedState()->setGameVariable("profilecolor3", true);
//	}
//}
//
//void ProfilesConfig::onReturn(CCObject* sender) {
//	auto OptionsBtn = dynamic_cast<CCMenuItemSpriteExtra*>(sender);
//
//	auto dir = CCDirector::sharedDirector();
//
//	GameManager::sharedState()->setGameVariable("weaclosexd", false);
//	auto parentNode = OptionsBtn->getParent();
//	auto parentNode2 = parentNode->getParent();
//	//parentNode->setVisible(false);
//	parentNode2->setVisible(false);
//	auto parentNode3 = parentNode2->getParent();
//	/*parentNode3->setVisible(false);*/
//	/*auto Layer = (CCLayer*)parentNode3->getChildren()->objectAtIndex(0);
//	Layer->setScale(0);
//	Layer->setVisible(true);*/
//	auto fadeIn = CCFadeIn::create(0.04f);  // O cualquier duración que desees
//	auto scaleTo = CCScaleTo::create(0.04f, 1.0f);  // Escalar el fondo al tamaño original
//
//	auto fadeInWithEase = CCEaseBackOut::create(fadeIn);
//	auto scaleToWithEase = CCEaseBackOut::create(scaleTo);
//#ifdef GEODE_IS_WINDOWS
//	auto spawn = CCSpawn::create(fadeInWithEase, scaleToWithEase, nullptr);
//#endif // !GEODE_IS_WINDOWS
//	for (int i = 0; i < parentNode3->getChildrenCount(); ++i) {
//		auto nodelolas = (CCMenuItemSpriteExtra*)parentNode3->getChildren()->objectAtIndex(i);
//		CCSize contentSize2 = nodelolas->getContentSize();
//
//		if (nodelolas->getTag() >= 50)
//		{
//			/*nodelolas->setScale(0);*/
//			/*FLAlertLayer::create("Yes", "We are here!", "OK")->show();*/
//			nodelolas->setVisible(true);
//			/*nodelolas->runAction(spawn);*/
//		}
//	}
//	
//	
//
//}
//
//void ProfilesConfig::disableInfolabel(CCObject* sender)
//{
//	if (GameManager::sharedState()->getGameVariable("disableinfolabel") == true)
//	{
//		GameManager::sharedState()->setGameVariable("disableinfolabel", false);
//	}
//	else
//	{
//		if (GameManager::sharedState()->getGameVariable("disableinfolabel") == false)
//		{
//			GameManager::sharedState()->setGameVariable("disableinfolabel", true);
//		}
//	}
//	
//}
//void ProfilesConfig::backButton(CCObject* sender)
//{
//	keyBackClicked();
//}
//void ProfilesConfig::close()
//{
//	this->removeFromParentAndCleanup(true);
//}
//
//ProfilesConfig* ProfilesConfig::create(CCLayer*layer)
//{
//	auto v12 = new ProfilesConfig();
//	if (v12) {
//		if (v12->init(layer)) {
//			v12->autorelease();
//		}
//		else {
//			CC_SAFE_DELETE(v12);
//		}
//	}
//	return v12;
//
//}