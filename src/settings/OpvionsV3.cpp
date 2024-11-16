#include "OptionsV3.hpp"

int cycleTypes = -1;

SettingNodeV3* SettingTestValue::createNode(float width) {
    return SettingTestNode::create(static_pointer_cast<SettingTestValue>(shared_from_this()), width);
}
SettingNodeV3* SettingPosValue::createNode(float width) {
    return SettingPosNode::create(static_pointer_cast<SettingPosValue>(shared_from_this()), width);
}

SettingNodeV3* SettingPosValueColor::createNode(float width) {
    return SettingPosNodeColor::create(static_pointer_cast<SettingPosValueColor>(shared_from_this()), width);
}


void SettingTestNode::onTestBtn(CCObject*) {

    auto scene = CCDirector::sharedDirector()->getRunningScene();
        auto GAM = GJAccountManager::sharedState();
    
       /* auto onSt = ProfilePage::onSettings(sender);*/
    
    
        auto stl = GJAccountSettingsLayer::create(GAM->m_accountID);
        stl->show();
}