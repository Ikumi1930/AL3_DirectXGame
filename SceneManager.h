#pragma once

#include <memory>
#include "BaseScene.h"
#include "GameScene.h"
#include "Input.h"
#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "TitleScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

class SceneManager{
private:
	//シーンを保持するメンバ変数
	//[]の中はBaseSceneのSCENEの中の数だけ増える
	std::unique_ptr<BaseScene> sceneArr_[4];

	//どのステージを呼び出すかを管理する変数
	int currentSceneNo_;//現在のシーン
	int prevSceneNo_;//前のシーン

	//BaseSceneの変数や関数を使用できるようにする
	BaseScene* baseScene_;

	//Inputの変数や関数を使用できるようにする
	Input* input_;

	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	// 汎用機能
	Input* input = nullptr;
	Audio* audio = nullptr;
	AxisIndicator* axisIndicator = nullptr;
	PrimitiveDrawer* primitiveDrawer = nullptr;
	ImGuiManager* imguiManager;

public:
	SceneManager();//コンストラクタ
	~SceneManager();//デストラクタ

	int Run();//この関数でゲームループを呼び出す

};
