#include "GameClearScene.h"

void GameClearScene::Initialize() {

	input_ = Input::GetInstance();
	input_->Initialize();

	TextureManager::GetInstance()->Initialize(DirectXCommon::GetInstance()->GetDevice());

	titlepng[0] = TextureManager::Load("Clear1.png");
	titlepng[1] = TextureManager::Load("Clear2.png");
	uvChacker_ = TextureManager::Load("uvChecker.png");

	sprite_[0].reset(sprite_[0]->Create(titlepng[0], {0.0f, 0.0f}));
	sprite_[0]->SetSize({1280.0f, 720.0f});
	sprite_[0]->SetColor({1.0f, 1.0f, 1.0f, 1.0f});

	sprite_[1].reset(sprite_[1]->Create(titlepng[1], {0.0f, 0.0f}));
	sprite_[1]->SetSize({1280.0f, 720.0f});
	sprite_[1]->SetColor({1.0f, 1.0f, 1.0f, 1.0f});

	sprite_[2].reset(sprite_[2]->Create(uvChacker_, {0.0f, 0.0f}));
	sprite_[2]->SetSize({1280.0f, 720.0f});
	sprite_[2]->SetColor({0.0f, 0.0f, 0.0f, 0.0f});

	isPushKey = false;
	spriteChangeTimer = 0;
}

void GameClearScene::Update() {
	input_->Update();

	spriteChangeTimer++;

	if (spriteChangeTimer >= 90) {
		spriteChangeTimer = 0;
	}

	if (input_->PushKey(DIK_RETURN)) {
		isPushKey = true;
	}

	if (isPushKey == true) {
		material.w += 0.01f;
		sprite_[2]->SetColor({0.0f, 0.0f, 0.0f, material.w});
	}

	if (sprite_[2]->GetColor().w >= 1.0f) {
		sceneNo = TITLE;
	}
}

void GameClearScene::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = DirectXCommon::GetInstance()->GetCommandList();
	for (int i = 0; i <= 2; i++) {
		sprite_[i]->PreDraw(commandList);

		if (spriteChangeTimer <= 44) {
			sprite_[0]->Draw();
		} else if (spriteChangeTimer >= 45) {
			sprite_[1]->Draw();
		}

		if (isPushKey == true) {
			sprite_[2]->Draw();
		}

		sprite_[i]->PostDraw();
	}
}

void GameClearScene::Finalize() {}