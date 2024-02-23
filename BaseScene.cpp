#include "BaseScene.h"

//タイトルシーンで初期化
int BaseScene::sceneNo = TITLE;

//仮想デストラクタの定義
//純粋仮想関数化していないので、ここで定義できる
BaseScene::~BaseScene(){};

//シーン番号のゲッター
int BaseScene::GetSceneNo() { return sceneNo; }