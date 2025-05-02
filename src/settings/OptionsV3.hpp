#pragma once
#include <Geode/ui/TextInput.hpp>
using namespace geode::prelude;


//TAKED FROM GDUTILS
//Thanks to Jouca and Firee


/*
    --- Account Button ---
*/

class SettingTestValue : public SettingV3 {
public:
    static Result<std::shared_ptr<SettingV3>> parse(std::string const& key, std::string const& modID, matjson::Value const& json) {
        auto res = std::make_shared<SettingTestValue>();
        auto root = checkJson(json, "SettingTestValue");
        res->init(key, modID, root);
        res->parseNameAndDescription(root);
        root.checkUnknownKeys();
        return root.ok(std::static_pointer_cast< SettingV3>(res));
    }

    bool load(matjson::Value const& json) override {
        return true;
    }
    bool save(matjson::Value& json) const override {
        return true;
    }
    bool isDefaultValue() const override {
        return true;
    }
    void reset() override {}
    SettingNodeV3* createNode(float width) override;
};


class SettingTestNode : public SettingNodeV3 {
protected:
    bool init(std::shared_ptr<SettingTestValue> setting, float width) {
        if (!SettingNodeV3::init(setting, width))
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
    void onCommit() override {}
    void onResetToDefault() override {}

public:
    void onTestBtn(CCObject*);
    bool hasUncommittedChanges() const override {
        return false;
    }
    bool hasNonDefaultValue() const override {
        return false;
    }
    static SettingTestNode* create(std::shared_ptr<SettingTestValue> setting, float width) {
        auto ret = new SettingTestNode();
        if (ret && ret->init(setting, width)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

/*
    Corners Options
*/

const int DEFAULT_POS = 4;

enum class SettingPosEnum : int {
    Rounded,
    Square,
    None,
    BottomRight
};

template <>
struct matjson::Serialize<SettingPosEnum> {
    static matjson::Value toJson(SettingPosEnum const& value) {
        switch (value) {
        case SettingPosEnum::Rounded:
            return 1;
        case SettingPosEnum::Square:
            return 2;
        case SettingPosEnum::None:
            return 3;
        default:
        case SettingPosEnum::BottomRight:
            return 4;
        }
    }
    static Result<SettingPosEnum> fromJson(matjson::Value const& value) {
        switch (value.asInt().unwrapOrDefault()) {
        case 1: return Ok(SettingPosEnum::Rounded);
        case 2: return Ok(SettingPosEnum::Square);
        case 3: return Ok(SettingPosEnum::None);
        case 4: return Ok(SettingPosEnum::BottomRight);
        default: return Err("Invalid SettingPosEnum value '{}'", value.asInt().unwrapOrDefault());
        }
    }
    static bool is_json(matjson::Value const& json) {
        return json.isNumber() || json.isString();
    }
};

class SettingPosValue : public SettingBaseValueV3<SettingPosEnum> {
public:
    static Result<std::shared_ptr<SettingV3>> parse(std::string const& key, std::string const& modID, matjson::Value const& json) {
        auto res = std::make_shared<SettingPosValue>();
        auto root = checkJson(json, "SettingPosValue");
        res->parseBaseProperties(key, modID, root);
        root.checkUnknownKeys();
        return root.ok(std::static_pointer_cast<SettingV3>(res));
    }
    SettingNodeV3* createNode(float width) override;
};


template <>
struct geode::SettingTypeForValueType<SettingPosEnum> {
    using SettingType = SettingPosValue;
};

class SettingPosNode : public SettingValueNodeV3<SettingPosValue> {
protected:
    CCMenuItemToggler* corner1Btn;
    CCMenuItemToggler* corner2Btn;
    CCMenuItemToggler* corner3Btn;
    CCMenuItemToggler* corner4Btn;

    int getActiveCornerTag(SettingPosEnum corner) {
        switch (corner) {
        case SettingPosEnum::Rounded: // Rounded corners
            return 2004;
        case SettingPosEnum::Square: // Square corners
            return 2005;
        case SettingPosEnum::None: // Without corners
            return 2006;
        case SettingPosEnum::BottomRight: // idk why lol
        default:
            return 2007;
        }
    }
    SettingPosEnum tagToCorner(int tag) {
        switch (tag) {
        case 2004: // Rounded Corners
            return SettingPosEnum::Rounded;
        case 2005: // Square Corners
            return SettingPosEnum::Square;
        case 2006: // Without Corners
            return SettingPosEnum::None;
        default:
        case 2007: // idk why lol
            return SettingPosEnum::BottomRight;
        }
    }

    bool init(std::shared_ptr<SettingPosValue> setting, float width) {
        if (!SettingValueNodeV3::init(setting, width))
            return false;
        this->setContentSize({ width, 50.f });
        CCSprite* toggleOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
        CCSprite* toggleOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
        toggleOn->setScale(.7F);
        toggleOff->setScale(.7F);

        auto labelcorner1 = CCLabelBMFont::create("Rounded", "bigFont.fnt");
        corner1Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosNode::onCornerClick)
        );

        auto labelcorner2 = CCLabelBMFont::create("Square", "bigFont.fnt");
        corner2Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosNode::onCornerClick)
        );

        auto labelcorner3 = CCLabelBMFont::create("None", "bigFont.fnt");
        corner3Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosNode::onCornerClick)
        );
        corner4Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosNode::onCornerClick)
        );

        labelcorner1->setScale(.45f);
        labelcorner1->setPosition({ -45,22 });

        labelcorner2->setScale(.45f);
        labelcorner2->setPosition({ 75,23 });

        labelcorner3->setScale(.45f);
        labelcorner3->setPosition({ 180,22 });

        corner1Btn->setTag(getActiveCornerTag(SettingPosEnum::Rounded));
        corner2Btn->setTag(getActiveCornerTag(SettingPosEnum::Square));
        corner3Btn->setTag(getActiveCornerTag(SettingPosEnum::None));
        corner4Btn->setTag(getActiveCornerTag(SettingPosEnum::BottomRight));


        
        getButtonMenu()->setContentSize({ width / 2, 45.F });
        corner1Btn->setPosition({ 15, 22 });

        corner2Btn->setPosition({ 130, 22 });

        corner3Btn->setPosition({ 230, 22 });
        getButtonMenu()->addChild(corner1Btn);
        getButtonMenu()->addChild(corner2Btn);
        getButtonMenu()->addChild(corner3Btn);

        getButtonMenu()->addChild(labelcorner1);
        getButtonMenu()->addChild(labelcorner2);
        getButtonMenu()->addChild(labelcorner3);
       /* getButtonMenu()->addChildAtPosition(tlBtn, Anchor::Left);
        getButtonMenu()->addChildAtPosition(trBtn, Anchor::Center);
        getButtonMenu()->addChildAtPosition(blBtn, Anchor::Right);*/
       /* getButtonMenu()->addChildAtPosition(brBtn, Anchor::BottomRight);*/

        
        getButtonMenu()->updateLayout();
        getButtonMenu()->setAnchorPoint({ 0.5, 0.5 });
        getButtonMenu()->updateAnchoredPosition(Anchor::Center, { 0, 0 });
        this->getNameLabel()->setVisible(false);
        auto currentCorner = static_cast<SettingPosEnum>(this->getValue());
        corner1Btn->toggle(!(corner1Btn->getTag() == getActiveCornerTag(currentCorner)));
        corner2Btn->toggle(!(corner2Btn->getTag() == getActiveCornerTag(currentCorner)));
        corner3Btn->toggle(!(corner3Btn->getTag() == getActiveCornerTag(currentCorner)));
        corner4Btn->toggle(!(corner4Btn->getTag() == getActiveCornerTag(currentCorner)));
        this->updateState(nullptr);
        return true;
    }

    void updateState(CCNode* invoker) override {
        SettingValueNodeV3::updateState(invoker);
        auto currentCorner = static_cast<SettingPosEnum>(this->getValue());
    }
    void onCornerClick(CCObject* sender) {
        corner1Btn->toggle(true);
        corner2Btn->toggle(true);
        corner3Btn->toggle(true);
       /* brBtn->toggle(true);*/
        SettingPosEnum value = tagToCorner(sender->getTag());
        this->setValue(value, static_cast<CCNode*>(sender));
    };
    void onResetToDefault() override {
        corner1Btn->toggle(false);
        corner2Btn->toggle(true);
        corner3Btn->toggle(true);
     /*   brBtn->toggle(false);*/
        this->setValue(SettingPosEnum::Rounded, nullptr);
    }
public:
    static SettingPosNode* create(std::shared_ptr<SettingPosValue> setting, float width) {
        auto ret = new SettingPosNode();
        if (ret && ret->init(setting, width)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

/*
    Colors Options
*/

const int DEFAULT_POSS = 4;

enum class SettingPosEnumColor : int {
    Animnate,
    Invert,
    Normal,
    BottomRight
};

template <>
struct matjson::Serialize<SettingPosEnumColor> {
    static matjson::Value toJson(SettingPosEnumColor const& value) {
        switch (value) {
        case SettingPosEnumColor::Animnate:
            return 1;
        case SettingPosEnumColor::Invert:
            return 2;
        case SettingPosEnumColor::Normal:
            return 3;
        default:
        case SettingPosEnumColor::BottomRight:
            return 4;
        }
    }
    static Result<SettingPosEnumColor> fromJson(matjson::Value const& value) {
        switch (value.asInt().unwrapOrDefault()) {
        case 1: return Ok(SettingPosEnumColor::Animnate);
        case 2: return Ok(SettingPosEnumColor::Invert);
        case 3: return Ok(SettingPosEnumColor::Normal);
        case 4: return Ok(SettingPosEnumColor::BottomRight);
        default: return Err("Invalid SettingPosEnum value '{}'", value.asInt().unwrapOrDefault());
        }
    }
    static bool is_json(matjson::Value const& json) {
        return json.isNumber() || json.isString();
    }
};

class SettingPosValueColor : public SettingBaseValueV3<SettingPosEnumColor> {
public:
    static Result<std::shared_ptr<SettingV3>> parse(std::string const& key, std::string const& modID, matjson::Value const& json) {
        auto res = std::make_shared<SettingPosValueColor>();
        auto root = checkJson(json, "SettingPosValue");
        res->parseBaseProperties(key, modID, root);
        root.checkUnknownKeys();
        return root.ok(std::static_pointer_cast<SettingV3>(res));
    }
    SettingNodeV3* createNode(float width) override;
};


template <>
struct geode::SettingTypeForValueType<SettingPosEnumColor> {
    using SettingType = SettingPosValueColor;
};

class SettingPosNodeColor : public SettingValueNodeV3<SettingPosValueColor> {
protected:
    CCMenuItemToggler* color1Btn;
    CCMenuItemToggler* color2Btn;
    CCMenuItemToggler* color3Btn;
    CCMenuItemToggler* color4Btn;

    int getActiveColorTag(SettingPosEnumColor color) {
        switch (color) {
        case SettingPosEnumColor::Animnate: // Animate color
            return 3004;
        case SettingPosEnumColor::Invert: // Invert color
            return 3005;
        case SettingPosEnumColor::Normal: // Normal color
            return 3006;
        case SettingPosEnumColor::BottomRight: // idk why lol
        default:
            return 3007;
        }
    }
    SettingPosEnumColor tagToColor(int tag) {
        switch (tag) {
        case 3004: // Animate color
            return SettingPosEnumColor::Animnate;
        case 3005: // Invert color
            return SettingPosEnumColor::Invert;
        case 3006: // Normnal color
            return SettingPosEnumColor::Normal;
        default:
        case 3007: // idk why lol
            return SettingPosEnumColor::BottomRight;
        }
    }

    bool init(std::shared_ptr<SettingPosValueColor> setting, float width) {
        if (!SettingValueNodeV3::init(setting, width))
            return false;
        this->setContentSize({ width, 50.f });
        CCSprite* toggleOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
        CCSprite* toggleOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
        toggleOn->setScale(.7F);
        toggleOff->setScale(.7F);

        auto labelcolor1 = CCLabelBMFont::create("Animate", "bigFont.fnt");
        color1Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosNodeColor::onColorClick)
        );

        auto labelcolor2 = CCLabelBMFont::create("Invert", "bigFont.fnt");
        color2Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosNodeColor::onColorClick)
        );

        auto labelcolor3 = CCLabelBMFont::create("Normal", "bigFont.fnt");
        color3Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosNodeColor::onColorClick)
        );
        color4Btn = CCMenuItemToggler::create(
            toggleOn,
            toggleOff,
            this,
            menu_selector(SettingPosNodeColor::onColorClick)
        );

        labelcolor1->setScale(.45f);
        labelcolor1->setPosition({ -45,22 });

        labelcolor2->setScale(.45f);
        labelcolor2->setPosition({ 75,23 });

        labelcolor3->setScale(.45f);
        labelcolor3->setPosition({ 180,22 });

        color1Btn->setTag(getActiveColorTag(SettingPosEnumColor::Animnate));
        color2Btn->setTag(getActiveColorTag(SettingPosEnumColor::Invert));
        color3Btn->setTag(getActiveColorTag(SettingPosEnumColor::Normal));
        color4Btn->setTag(getActiveColorTag(SettingPosEnumColor::BottomRight));



        getButtonMenu()->setContentSize({ width / 2, 45.F });
        color1Btn->setPosition({ 15, 22 });

        color2Btn->setPosition({ 130, 22 });

        color3Btn->setPosition({ 230, 22 });
        getButtonMenu()->addChild(color1Btn);
        getButtonMenu()->addChild(color2Btn);
        getButtonMenu()->addChild(color3Btn);

        getButtonMenu()->addChild(labelcolor1);
        getButtonMenu()->addChild(labelcolor2);
        getButtonMenu()->addChild(labelcolor3);
        /* getButtonMenu()->addChildAtPosition(tlBtn, Anchor::Left);
         getButtonMenu()->addChildAtPosition(trBtn, Anchor::Center);
         getButtonMenu()->addChildAtPosition(blBtn, Anchor::Right);*/
         /* getButtonMenu()->addChildAtPosition(brBtn, Anchor::BottomRight);*/


        getButtonMenu()->updateLayout();
        getButtonMenu()->setAnchorPoint({ 0.5, 0.5 });
        getButtonMenu()->updateAnchoredPosition(Anchor::Center, { 0, 0 });
        this->getNameLabel()->setVisible(false);
        auto currentColor = static_cast<SettingPosEnumColor>(this->getValue());
        color1Btn->toggle(!(color1Btn->getTag() == getActiveColorTag(currentColor)));
        color2Btn->toggle(!(color2Btn->getTag() == getActiveColorTag(currentColor)));
        color3Btn->toggle(!(color3Btn->getTag() == getActiveColorTag(currentColor)));
        color4Btn->toggle(!(color4Btn->getTag() == getActiveColorTag(currentColor)));
        this->updateState(nullptr);
        return true;
    }

    void updateState(CCNode* invoker) override {
        SettingValueNodeV3::updateState(invoker);
        auto currentCorner = static_cast<SettingPosEnumColor>(this->getValue());
    }
    void onColorClick(CCObject* sender) {
        color1Btn->toggle(true);
        color2Btn->toggle(true);
        color3Btn->toggle(true);
        /* brBtn->toggle(true);*/
        SettingPosEnumColor value = tagToColor(sender->getTag());
        this->setValue(value, static_cast<CCNode*>(sender));
    };
    void onResetToDefault() override {
        color1Btn->toggle(true);
        color2Btn->toggle(true);
        color3Btn->toggle(false);
        /*   brBtn->toggle(false);*/
        this->setValue(SettingPosEnumColor::Normal, nullptr);
    }
public:
    static SettingPosNodeColor* create(std::shared_ptr<SettingPosValueColor> setting, float width) {
        auto ret = new SettingPosNodeColor();
        if (ret && ret->init(setting, width)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};
