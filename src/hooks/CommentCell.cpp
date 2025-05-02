#include <Geode/Geode.hpp>
#include <Geode/modify/CommentCell.hpp>

using namespace geode::prelude;

template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}
class $modify(CommentCell)
{
	struct Fields {
		bool m_wasInProfilePage = false;
	};

	void loadFromComment(GJComment * a1)
	{
		CommentCell::loadFromComment(a1);

		if (a1->m_levelID == 0 || a1->m_hasLevelID == 1)
		{
			auto winSize = CCDirector::sharedDirector()->getWinSize();
			auto commentBGColor = (CCSprite*)this->getChildren()->objectAtIndex(0);
			commentBGColor->setVisible(false);

			CCSize smallContentSize = { 890, 85 };
			int X;
			int Y;
			Y = this->getPositionY() + 18;
			X = this->getPositionX() + 170;

			if (this->m_height == 36)
			{
				auto smallCommentSquare = cocos2d::extension::CCScale9Sprite::create("square02b_001.png");
				smallCommentSquare->setColor(ccBLACK);
				smallCommentSquare->setOpacity(32);
				smallCommentSquare->setScale(0.375);
				smallCommentSquare->setContentSize(smallContentSize);
				smallCommentSquare->setPositionX(X);
				smallCommentSquare->setPositionY(Y);
				smallCommentSquare->setZOrder(-1);
				this->addChild(smallCommentSquare);
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

	//Clean comments for android and macOS
#ifdef GEODE_IS_ANDROID

		void draw()
		{
			auto scene = CCDirector::get()->getRunningScene();


			//Border comments showing on transition fix
			if (scene->getChildByID("ProfilePage")) {
				this->m_fields->m_wasInProfilePage = true;
			}


			if (!this->m_fields->m_wasInProfilePage) {
				CommentCell::draw();
			}
		}
	
#endif

	//When macOS is sus
#ifdef GEODE_IS_MACOS

		void draw()
		{
			auto scene = CCDirector::get()->getRunningScene();


			//Border comments showing on transition fix
			if (scene->getChildByID("ProfilePage")) {
				this->m_fields->m_wasInProfilePage = true;
			}


			if (!this->m_fields->m_wasInProfilePage) {
				CommentCell::draw();
			}
		}
#endif

	//My first try to port one of my mods to iOS omg omg
#ifdef GEODE_IS_IOS

		void draw()
		{
			auto scene = CCDirector::get()->getRunningScene();


			//Border comments showing on transition fix
			if (scene->getChildByID("ProfilePage")) {
				this->m_fields->m_wasInProfilePage = true;
			}


			if (!this->m_fields->m_wasInProfilePage) {
				CommentCell::draw();
			}
		}
#endif
};
