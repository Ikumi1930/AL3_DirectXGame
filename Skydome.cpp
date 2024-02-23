#include "Skydome.h"

    void
    Skydome::Initialize(Model* model, const Vector3& position) {
	assert(model);
	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {300.0f, 300.0f, 300.0f};
}

void Skydome::Update() {
	worldTransform_.UpdateMatrix();
	worldTransform_.rotation_.y += 0.001f;
}

void Skydome::Draw(ViewProjection& view) { model_->Draw(worldTransform_, view); }
