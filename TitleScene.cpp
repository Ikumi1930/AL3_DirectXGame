#include "TitleScene.h"

void TitleScene::Initialize() {

	input_ = Input::GetInstance();
	input_->Initialize();

	sprite_ = new Sprite();
	sprite_->Initialize();

	TextureManager::GetInstance()->Initialize(DirectXCommon::GetInstance()->GetDevice());

	uvChacker_ = TextureManager::Load("uvChecker.png");

	sprite_->Create(uvChacker_, {0.0f, 0.0f});

	sprite_->SetSize({1280.0f, 720.0f});
	sprite_->SetColor({0.0f, 0.0f, 0.0f, 0.0f});

	isPushKey = false;

}

void TitleScene::Update() { 
	input_->Update();

	if (input_->PushKey(DIK_RETURN)) {
		isPushKey = true;
	}

	if (isPushKey == true) {
		material.w += 0.01f;
		sprite_->SetColor({0.0f, 0.0f, 0.0f, material.w});
	}

	if (sprite_->GetColor().w >= 1.0f) {
		sceneNo = STAGE;
	}

}

void TitleScene::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = DirectXCommon::GetInstance()->GetCommandList();

	sprite_->PreDraw(commandList);

	if (isPushKey == true) {
		sprite_->Draw();
	}

	sprite_->PostDraw();

}

void TitleScene::Finalize() { delete sprite_; }