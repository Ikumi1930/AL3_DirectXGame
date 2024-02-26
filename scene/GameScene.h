#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Enemy.h"
#include "Input.h"
#include "Model.h"
#include "Player.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <RailCamera.h>
#include <Skydome.h>
#include <sstream>
#include "SceneManager.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene : public BaseScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 衝突判定と応答
	/// </summary>
	void CheckAllCollisions();

	void Finalize() override;

	void AddEnemyBullet(EnemyBullet* enemyBullet);

	void AddEnemy(Enemy* enemy);

	void EnemyIni(Model* model, const Vector3 position);

	void LoadEnemyPopData();

	void UpDateEnemyPopCommands();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	Sprite* sprite_[3];

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t uvChacker_ = 0;

	// 3Dモデルデータ
	Model* model_ = nullptr;

	WorldTransform worldTransform_;
	// ビュープロジェクション
	ViewProjection viewProjection_;

	// 自キャラ
	Player* player_ = nullptr;

	// スカイドーム
	Skydome* skydome_ = nullptr;
	Model* modelSkydome_ = nullptr;

	RailCamera* railCamera_ = nullptr;

	bool isDebugCameraActive_ = false;
	DebugCamera* debugCamera_ = nullptr;
	// Enemy* enemy_ = nullptr;

	std::list<EnemyBullet*> enemyBullets_;
	std::list<Enemy*> enemys_;

	std::stringstream enemyPopCommands;
	bool isWait_ = false;
	int32_t waitTimer_ = 0;

	bool isChange;
	Vector4 spriteMaterial[3];

	bool isOverChange;
	bool isClearChange;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};