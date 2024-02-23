#include "TitleScene.h"

void TitleScene::Initialize() {

	input_ = Input::GetInstance();
	input_->Initialize();

}

void TitleScene::Update() { 
	input_->Update();

	if (input_->PushKey(DIK_RETURN)) {
		sceneNo = STAGE;
	}

}

void TitleScene::Draw() {

}

void TitleScene::Finalize() {

}