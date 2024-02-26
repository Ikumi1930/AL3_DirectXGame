#pragma once
#include "BaseScene.h"
#include "Input.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "DirectXCommon.h"

class GameOverScene : public BaseScene {
public:

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Finalize() override;

private:
	
	Input* input_;

	std::unique_ptr<Sprite> sprite_[4];

	TextureManager* texture_;

	uint32_t uvChacker_;
	uint32_t titlepng[2];

	Vector4 material[2];

	bool isPushKey = false;

	int spriteChangeTimer = 0;

	bool isChange;

};
