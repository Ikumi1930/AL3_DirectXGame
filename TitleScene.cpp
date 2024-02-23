#include "TitleScene.h"

void TitleScene::Initialize() {

	input_ = Input::GetInstance();
	input_->Initialize();

	for (int i = 0; i <= 3; i++) {
		sprite_[i] = new Sprite();
		sprite_[i]->Initialize();
	}

	TextureManager::GetInstance()->Initialize(DirectXCommon::GetInstance()->GetDevice());

	uvChacker_ = TextureManager::Load("uvChecker.png");

	sprite_[0]->Create(uvChacker_, {0.0f, 0.0f});
	sprite_[0]->SetSize({1280.0f, 720.0f});
	sprite_[0]->SetColor({1.0f, 1.0f, 1.0f, 1.0f});

	sprite_[1]->Create(uvChacker_, {0.0f, 0.0f});
	sprite_[1]->SetSize({1280.0f, 720.0f});
	sprite_[1]->SetColor({1.0f, 0.0f, 1.0f, 1.0f});

	sprite_[2]->Create(uvChacker_, {0.0f, 0.0f});
	sprite_[2]->SetSize({1280.0f, 720.0f});
	sprite_[2]->SetColor({0.0f, 0.0f, 0.0f, 0.0f});

	isPushKey = false;
	spriteChangeTimer = 0;

}

void TitleScene::Update() { 
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
		sceneNo = STAGE;
	}

}

void TitleScene::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = DirectXCommon::GetInstance()->GetCommandList();
	for (int i = 0; i <= 3; i++) {
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

void TitleScene::Finalize() { 
	for (int i = 0; i < 3; i++) {
		delete sprite_[i];
	}
}