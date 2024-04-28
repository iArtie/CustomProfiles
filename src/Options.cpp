#include "Options.hpp"
#include <Geode/loader/Dirs.hpp>
#include <filesystem>
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

#ifdef GEODE_IS_WINDOWS
std::string GetOpenFileName() {
    OPENFILENAME ofn;
    char szFile[MAX_PATH] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "Executable Files (*.exe)\0*.exe\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrInitialDir = "\%appdata\%\\Spotify"; // Set your desired default path here
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    if (GetOpenFileName(&ofn))
        return std::string(szFile);
    else
        return "";
    return "";
}
#endif
void SettingAppNode::onPickFile(CCObject*) {
#ifdef GEODE_IS_MACOS
    if (auto path = file::pickFile(
        file::PickMode::OpenFile,
        {
            "/Applications", // sorry mac users but idk the path for spotify
            {}
        }
    )) {
        std::string strPath = path.unwrap().string();
        size_t lastBackslashPos = strPath.find_last_of('/');
        if (lastBackslashPos != std::string::npos) {
            std::string lastPart = strPath.substr(lastBackslashPos + 1);
            m_currentApp = lastPart;
            defaultApp_input->setString(lastPart.c_str());
            this->dispatchChanged();
        }
    }
#else

#endif
}

void SettingTestNode::onTestBtn(CCObject*) {
    auto scene = CCDirector::sharedDirector()->getRunningScene();
    auto GAM = GJAccountManager::sharedState();
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