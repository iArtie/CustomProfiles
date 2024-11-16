#include <Geode/Geode.hpp>
#include <Geode/modify/StatsCell.hpp>
#include "settings/OptionsV3.hpp"

using namespace geode::prelude;

$on_mod(Loaded) {
	//Mod::get()->addCustomSetting<SettingsValues>("Corners-section", "none");
	//Mod::get()->addCustomSetting<SettingsValues>("Colors-section", "none");
	//Mod::get()->addCustomSetting<SettingsValues>("Extras-section", "none");

	//////Config thing? hope it works
	//Mod::get()->addCustomSetting<SettingTestValue>("Account-settings", "none");
	//Mod::get()->addCustomSetting<SettingAppValue>("ColorOptions", 3);
	//Mod::get()->addCustomSetting<CornerSettingsValue>("CornersOptions", 1);
	auto ret = Mod::get()->registerCustomSettingType("corner-options", &SettingPosValue::parse);
	if (!ret) {
		log::error("Unable to register setting type: {}", ret.unwrapErr());
	}

	auto ret2 = Mod::get()->registerCustomSettingType("color-options", &SettingPosValueColor::parse);
	if (!ret2) {
		log::error("Unable to register setting type: {}", ret.unwrapErr());
	}
	(void)Mod::get()->registerCustomSettingType("account-settings", &SettingTestValue::parse);
	//(void)Mod::get()->registerCustomSettingType("credit-buttons", &SettingCreditsValue::parse);
	/*(void)Mod::get()->registerCustomSettingType("notification-placement", &SettingPosValue::parse);*/
	

}

//New amazing code for clean comments
class $modify(StatsCell)
{
	void draw()
	{
		auto scene = CCDirector::get()->getRunningScene();
		if (!scene->getChildByID("ProfilePage")) {
			StatsCell::draw();
		}
	}
};

