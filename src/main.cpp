#include <Geode/Geode.hpp>
#include <Geode/modify/StatsCell.hpp>
#include "settings/Options.hpp"

using namespace geode::prelude;

$on_mod(Loaded) {
	Mod::get()->addCustomSetting<SettingsValues>("Corners-section", "none");
	Mod::get()->addCustomSetting<SettingsValues>("Colors-section", "none");
	Mod::get()->addCustomSetting<SettingsValues>("Extras-section", "none");

	////Config thing? hope it works
	Mod::get()->addCustomSetting<SettingTestValue>("Account-settings", "none");
	Mod::get()->addCustomSetting<SettingAppValue>("ColorOptions", 3);
	Mod::get()->addCustomSetting<CornerSettingsValue>("CornersOptions", 1);

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

