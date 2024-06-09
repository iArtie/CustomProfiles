#include "Options.hpp"
#include "ownAccLayer.h"
#include <Geode/loader/Dirs.hpp>
#include <filesystem>
//#include "ownCCMenuItemToggler.h"
int cycleTypes = -1;

SettingNode* SettingsValues::createNode(float width) {
    return SettingSectionNode::create(this, width);
}
SettingNode* SettingTestValue::createNode(float width) {
    return SettingTestNode::create(this, width);
}
SettingNode* SettingAppValue::createNode(float width) {
    return SettingAppNode::create(this, width);
}
SettingNode* CornerSettingsValue::createNode(float width) {
    return SettingPosCornerNode::create(this, width);
}


void SettingTestNode::onTestBtn(CCObject* sender) {
    auto scene = CCDirector::sharedDirector()->getRunningScene();
    auto GAM = GJAccountManager::sharedState();

   /* auto onSt = ProfilePage::onSettings(sender);*/


    auto stl = GJAccountSettingsLayer::create(GAM->m_accountID);
    stl->show();
   /* cycleTypes = cycleTypes + 1;
    if (cycleTypes > 4) cycleTypes = 0;
    bool newRate = Mod::get()->getSettingValue<bool>("newRate");
    bool daily = Mod::get()->getSettingValue<bool>("daily");
    bool weekly = Mod::get()->getSettingValue<bool>("weekly");
    if (!newRate && cycleTypes == 0) cycleTypes = 1;
    if (!daily && cycleTypes == 1) cycleTypes = 2;
    if (!weekly && cycleTypes == 2) cycleTypes = 3;
    if (!newRate && !daily && !weekly) {
        cycleTypes = 5;
    }*/

  
    
   

}