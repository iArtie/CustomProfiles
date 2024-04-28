#pragma once
#include <Geode/loader/SettingNode.hpp>

using namespace geode::prelude;

//CUSTOM SETTING ARE TAKED FROM "GDUTILS" thanks to Jouca and FireeDev

//Account Settings

class SettingTestValue;

class SettingTestValue : public SettingValue {
protected:
    std::string m_placeholder;
public:
    SettingTestValue(std::string const& key, std::string const& modID, std::string const& placeholder)
        : SettingValue(key, modID), m_placeholder(placeholder) {}

    bool load(matjson::Value const& json) override {
        return true;
    }
    bool save(matjson::Value& json) const override {
        return true;
    }
    SettingNode* createNode(float width) override;
};


class SettingTestNode : public SettingNode {
protected:
    bool init(SettingTestValue* value, float width) {
        if (!SettingNode::init(value))
            return false;
        this->setContentSize({ width, 35.f });
        auto menu = CCMenu::create();
        auto label = CCLabelBMFont::create("Account Settings", "bigFont.fnt");
        label->setScale(.5F);
        label->setPositionX(-78);
        auto playSpr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
        playSpr->setScale(0.6);
        //auto infoBtn
        auto testBtn = CCMenuItemSpriteExtra::create(
            playSpr,
            this,
            menu_selector(SettingTestNode::onTestBtn)
        );
        testBtn->setPositionX(142);
        
        menu->setPosition(width / 2, 18.f);
        menu->addChild(label);
        menu->addChild(testBtn);
        this->addChild(menu);
        return true;
    }

public:
    // because for some reason SettingNode doesnt expose description, i have to do all of this, smh.
    void onTestBtn(CCObject*);

    void commit() override {
        // Let the UI know you have committed the value
        this->dispatchCommitted();
    }

    // Geode calls this to query if the setting value has been changed, 
    // and those changes haven't been committed
    bool hasUncommittedChanges() override {
        return false;
    }

    // Geode calls this to query if the setting has a value that is 
    // different from its default value
    bool hasNonDefaultValue() override {
        return true;
    }

    // Geode calls this to reset the setting's value back to default
    void resetToDefault() override {

    }
    static SettingTestNode* create(SettingTestValue* value, float width) {
        auto ret = new SettingTestNode;
        if (ret && ret->init(value, width)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

/*
    --- Section ---
*/

class SettingsValues;

class SettingsValues : public SettingValue {
protected:
    std::string m_placeholder;
public:
    SettingsValues(std::string const& key, std::string const& modID, std::string const& placeholder)
        : SettingValue(key, modID), m_placeholder(placeholder) {}

    bool load(matjson::Value const& json) override {
        return true;
    }
    bool save(matjson::Value& json) const override {
        return true;
    }
    SettingNode* createNode(float width) override;
};

class SettingSectionNode : public SettingNode {
protected:
    bool init(SettingsValues* value, float width) {
        if (!SettingNode::init(value))
            return false;
        this->setContentSize({ width, 40.f });
        auto menu = CCMenu::create();
        std::string sectionName = Mod::get()->getSettingDefinition(value->getKey())->get<CustomSetting>()->json->get<std::string>("name");
        auto infoSpr = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
        infoSpr->setScale(.7F);
        //auto infoBtn
        auto infoBtn = CCMenuItemSpriteExtra::create(
            infoSpr,
            this,
            menu_selector(SettingSectionNode::onInfoBtn)
        );
        infoBtn->setID(value->getKey());
        infoBtn->setPositionX(Mod::get()->getSettingDefinition(value->getKey())->get<CustomSetting>()->json->get<int>("posX"));
        auto label = CCLabelBMFont::create(sectionName.c_str(), "goldFont.fnt");

        label->setScale(.6F);
        menu->setPosition(width / 2, 23.f);
        menu->addChild(label);
        menu->addChild(infoBtn);
        this->addChild(menu);
        return true;
    }

    void onInfoBtn(CCObject* sender) {
        // i dont want to deal with template hell
        auto node = reinterpret_cast<CCMenuItemSpriteExtra*>(sender);
        if (node == nullptr) return;
        FLAlertLayer::create(nullptr,
            Mod::get()->getSettingDefinition(node->getID())->get<CustomSetting>()->json->get<std::string>("name").c_str(),
            Mod::get()->getSettingDefinition(node->getID())->get<CustomSetting>()->json->get<std::string>("description").c_str(),
            "OK",
            nullptr,
            Mod::get()->getSettingDefinition(node->getID())->get<CustomSetting>()->json->get<int>("scale")
        )->show();
    }

public:
    void commit() override {
        // Let the UI know you have committed the value
        this->dispatchCommitted();
    }

    // Geode calls this to query if the setting value has been changed, 
    // and those changes haven't been committed
    bool hasUncommittedChanges() override {
        return false;
    }

    // Geode calls this to query if the setting has a value that is 
    // different from its default value
    bool hasNonDefaultValue() override {
        return true;
    }

    // Geode calls this to reset the setting's value back to default
    void resetToDefault() override {

    }
    static SettingSectionNode* create(SettingsValues* value, float width) {
        auto ret = new SettingSectionNode;
        if (ret && ret->init(value, width)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

/*
    Notification Position
*/

const int DEFAULT_POS = 1;
const int DEFAULT_POSS = 3;
struct SettingPosStruct {
    int m_pos;
};

class CornerSettingsValue;

class CornerSettingsValue : public SettingValue {
protected:
    int m_pos;
public:
    CornerSettingsValue(std::string const& key, std::string const& modID, int const& position)
        : SettingValue(key, modID), m_pos(position) {}

    bool load(matjson::Value const& json) override {
        try {
            m_pos = static_cast<int>(json.as<int>());
            return true;
        }
        catch (...) {
            return false;
        }
    }
    bool save(matjson::Value& json) const override {
        json = static_cast<int>(m_pos);
        return true;
    }
    SettingNode* createNode(float width) override;
    void setPos(int pos) {
        m_pos = pos;
    }
    int getPos() const {
        return m_pos;
    }
};

template<>
struct SettingValueSetter<SettingPosStruct> {
    static SettingPosStruct get(SettingValue* setting) {
        auto posSetting = static_cast<CornerSettingsValue*>(setting);
        struct SettingPosStruct defaultStruct = { posSetting->getPos() };
        return defaultStruct;
    };
    static void set(CornerSettingsValue* setting, SettingPosStruct const& value) {
        setting->setPos(value.m_pos);
    };
};

class SettingPosCornerNode : public SettingNode {
protected:
    int m_currentPos;
    CCMenuItemToggler* option1Btn;
    CCMenuItemToggler* option2Btn;
    CCMenuItemToggler* option3Btn;
    CCMenuItemToggler* brBtn;

    int getOptionTag(int corner) {
        switch (corner) {
        case 1: 
            return 4004;
        case 2: 
            return 4005;
        case 3: 
            return 4006;
        case 4: 
        default:
            return 4007;
        }
    }
    int tagToCorner(int tag) {
        switch (tag) {
        case 4004: // Top Left
            return 1;
        case 4005: // Top Right
            return 2;
        case 4006: // Bottom Left
            return 3;
        default:
        case 4007: // Bottom Right
            return 4;
        }
    }
    bool init(CornerSettingsValue* value, float width) {
        if (!SettingNode::init(value))
            return false;
        m_currentPos = value->getPos();
        this->setContentSize({ width, 40.f });
        auto menu = CCMenu::create();
        
        CCSprite* toggleOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
        CCSprite* toggleOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
        toggleOn->setScale(.7F);
        toggleOff->setScale(.7F);
        menu->setPosition(width / 2, 23.f);

        auto labelcorner1 = CCLabelBMFont::create("Rounded", "bigfont.fnt");
        option1Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosCornerNode::onOptionsClick)
        );

        auto labelcorner2 = CCLabelBMFont::create("Square", "bigfont.fnt");
        option2Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosCornerNode::onOptionsClick)
        );

        auto labelcorner3 = CCLabelBMFont::create("None", "bigfont.fnt");
        option3Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosCornerNode::onOptionsClick)
        );
        brBtn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosCornerNode::onOptionsClick)
        );
        labelcorner1->setScale(.45f);
        labelcorner1->setPosition({-130,-5});


        option1Btn->setPosition({ -85, -5 });

        labelcorner2->setScale(.45f);
        labelcorner2->setPosition({ -20,-5 });
        option2Btn->setPosition({ 25, -5 });

        labelcorner3->setScale(.45f);
        labelcorner3->setPosition({ 115,-5 });
        option3Btn->setPosition({ 150, -5 });
        brBtn->setPosition({ 100, -10 });

        option1Btn->setTag(getOptionTag(1));
        option2Btn->setTag(getOptionTag(2));
        option3Btn->setTag(getOptionTag(3));
        brBtn->setTag(getOptionTag(4));
        int currentCorner = m_currentPos;
        option1Btn->toggle(!(option1Btn->getTag() == getOptionTag(currentCorner)));
        option2Btn->toggle(!(option2Btn->getTag() == getOptionTag(currentCorner)));
        option3Btn->toggle(!(option3Btn->getTag() == getOptionTag(currentCorner)));
        brBtn->toggle(!(brBtn->getTag() == getOptionTag(currentCorner)));


        menu->addChild(labelcorner1);
        menu->addChild(labelcorner2);
        menu->addChild(labelcorner3);

        menu->addChild(option1Btn);
        menu->addChild(option2Btn);
        menu->addChild(option3Btn);
      /*  menu->addChild(brBtn);*/

        this->addChild(menu);
        return true;
    }
    void onOptionsClick(CCObject* sender) {
        option1Btn->toggle(true);
        option2Btn->toggle(true);
        option3Btn->toggle(true);
     /*   brBtn->toggle(true);*/
        m_currentPos = tagToCorner(sender->getTag());
        this->dispatchChanged();
    };
    void onInfoBtn(CCObject* sender) {
        FLAlertLayer::create(
            Mod::get()->getSettingDefinition(this->m_value->getKey())->get<CustomSetting>()->json->get<std::string>("name").c_str(),
            Mod::get()->getSettingDefinition(this->m_value->getKey())->get<CustomSetting>()->json->get<std::string>("description").c_str(),
            "OK"
        )->show();
    }
public:
    void commit() override {    
        static_cast<CornerSettingsValue*>(m_value)->setPos(m_currentPos);
        this->dispatchCommitted();
    }
    bool hasUncommittedChanges() override {
        return m_currentPos != static_cast<CornerSettingsValue*>(m_value)->getPos();
    }
    bool hasNonDefaultValue() override {
        return m_currentPos != DEFAULT_POS;
    }

    // Geode calls this to reset the setting's value back to default
    void resetToDefault() override {
        option1Btn->toggle(false);
        option2Btn->toggle(true);
        option3Btn->toggle(true);
        //brBtn->toggle(false);
        m_currentPos = DEFAULT_POS;
    }
    static SettingPosCornerNode* create(CornerSettingsValue* value, float width) {
        auto ret = new SettingPosCornerNode;
        if (ret && ret->init(value, width)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};




//COLORS

struct SettingAppStruct {
    int m_pos;
};

class SettingAppValue;

class SettingAppValue : public SettingValue {
protected:
    int m_pos;
public:
    SettingAppValue(std::string const& key, std::string const& modID, int const& position)
        : SettingValue(key, modID), m_pos(position) {}

    bool load(matjson::Value const& json) override {
        try {
            m_pos = static_cast<int>(json.as<int>());
            return true;
        }
        catch (...) {
            return false;
        }
    }
    bool save(matjson::Value& json) const override {
        json = static_cast<int>(m_pos);
        return true;
    }
    SettingNode* createNode(float width) override;
    void setPos(int pos) {
        m_pos = pos;
    }
    int getPos() const {
        return m_pos;
    }
};

template<>
struct SettingValueSetter<SettingAppStruct> {
    static SettingAppStruct get(SettingValue* setting) {
        auto appSetting = static_cast<SettingAppValue*>(setting);
        struct SettingAppStruct defaultStruct = { appSetting->getPos() };
        return defaultStruct;
    };
    static void set(SettingAppValue* setting, SettingAppStruct const& value) {
        setting->setPos(value.m_pos);
    };
};


// I LOVE TEMPLATES

class SettingAppNode : public SettingNode {
protected:
    int m_currentPos;
    CCMenuItemToggler* option1Btn;
    CCMenuItemToggler* option2Btn;
    CCMenuItemToggler* option3Btn;
    CCMenuItemToggler* brBtn;

    int getOptionTag(int option) {
        switch (option) {
        case 1:
            return 3004;
        case 2: 
            return 3005;
        case 3: 
            return 3006;
        case 4: 
        default:
            return 3007;
        }
    }
    int tagToCorner(int tag) {
        switch (tag) {
        case 3004: 
            return 1;
        case 3005: 
            return 2;
        case 3006: 
            return 3;
        default:
        case 3007: 
            return 4;
        }
    }
    bool init(SettingAppValue* value, float width) {
        if (!SettingNode::init(value))
            return false;
        m_currentPos = value->getPos();
        this->setContentSize({ width, 40.f });
        auto menu = CCMenu::create();

        CCSprite* toggleOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
        CCSprite* toggleOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
        toggleOn->setScale(.7F);
        toggleOff->setScale(.7F);
        menu->setPosition(width / 2, 23.f);

        auto labelcorner1 = CCLabelBMFont::create("Animate", "bigfont.fnt");

        
        option1Btn = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(SettingAppNode::onOptionsClick), 0.6);

        auto labelcorner2 = CCLabelBMFont::create("Invert", "bigfont.fnt");
        option2Btn = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(SettingAppNode::onOptionsClick), 0.6);

        auto labelcorner3 = CCLabelBMFont::create("Normal", "bigfont.fnt");
        option3Btn = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(SettingAppNode::onOptionsClick), 0.6);

        brBtn = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(SettingAppNode::onOptionsClick), 1.0);
        labelcorner1->setScale(.45f);
        labelcorner1->setPosition({ -130,-5 });


        option1Btn->setPosition({ -85, -5 });

        labelcorner2->setScale(.45f);
        labelcorner2->setPosition({ -20,-5 });
        option2Btn->setPosition({ 25, -5 });

        labelcorner3->setScale(.45f);
        labelcorner3->setPosition({ 105,-5 });
        option3Btn->setPosition({ 150, -5 });
        brBtn->setPosition({ 100, -10 });

        option1Btn->setTag(getOptionTag(1));
        option2Btn->setTag(getOptionTag(2));
        option3Btn->setTag(getOptionTag(3));
        brBtn->setTag(getOptionTag(4));
        int currentCorner = m_currentPos;
        option1Btn->toggle(!(option1Btn->getTag() == getOptionTag(currentCorner)));
        option2Btn->toggle(!(option2Btn->getTag() == getOptionTag(currentCorner)));
        option3Btn->toggle(!(option3Btn->getTag() == getOptionTag(currentCorner)));
        brBtn->toggle(!(brBtn->getTag() == getOptionTag(currentCorner)));


        menu->addChild(labelcorner1);
        menu->addChild(labelcorner2);
        menu->addChild(labelcorner3);

        menu->addChild(option1Btn);
        menu->addChild(option2Btn);
        menu->addChild(option3Btn);
        /*  menu->addChild(brBtn);*/

        this->addChild(menu);
        return true;
    
    }

    void onOptionsClick(CCObject* sender) {
        option1Btn->toggle(false);
        option2Btn->toggle(false);
        option3Btn->toggle(false);
        /*   brBtn->toggle(true);*/
        m_currentPos = tagToCorner(sender->getTag());
        this->dispatchChanged();
    };
    void onReset(CCObject*) {
        createQuickPopup(
            "Reset",
            "Are you sure you want to <cr>reset</c> <cl>" +
            Mod::get()->getSettingDefinition(this->m_value->getKey())->get<CustomSetting>()->json->get<std::string>("name") +
            "</c> to <cy>default</c>?",
            "Cancel", "Reset",
            [this](auto, bool btn2) {
                if (btn2) {
                    this->resetToDefault();
                }
            }
        );
    }
    
    void onInfoBtn(CCObject* sender) {
        /*FLAlertLayer::create(
            setting()->getDefinition().getDisplayName().c_str(),
            setting()->castDefinition().description.value(),
            "OK"
        )->show();*/
        FLAlertLayer::create(
            Mod::get()->getSettingDefinition(this->m_value->getKey())->get<CustomSetting>()->json->get<std::string>("name").c_str(),
            Mod::get()->getSettingDefinition(this->m_value->getKey())->get<CustomSetting>()->json->get<std::string>("description").c_str(),
            "OK"
        )->show();
    }
    public:
        void commit() override {
            static_cast<SettingAppValue*>(m_value)->setPos(m_currentPos);
            this->dispatchCommitted();
        }
        bool hasUncommittedChanges() override {
            return m_currentPos != static_cast<SettingAppValue*>(m_value)->getPos();
        }
        bool hasNonDefaultValue() override {
            return m_currentPos != DEFAULT_POSS;
        }

        // Geode calls this to reset the setting's value back to default
        void resetToDefault() override {
            option1Btn->toggle(false);
            option2Btn->toggle(false);
            option3Btn->toggle(true);
      /*      brBtn->toggle(false);*/
            m_currentPos = DEFAULT_POSS;
        }
    static SettingAppNode* create(SettingAppValue* value, float width) {
        auto ret = new SettingAppNode;
        if (ret && ret->init(value, width)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};
