#pragma once
#include "BaseScene.h"
#include "Input.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "DirectXCommon.h"

class TitleScene  : public BaseScene {
public:

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Finalize() override;

private:
	Input* input_;

	Sprite* sprite_;

	TextureManager* texture_;

	uint32_t uvChacker_;

	Vector4 material;

	bool isPushKey = false;

};
