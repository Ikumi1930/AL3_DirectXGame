#pragma once

//シーン名を列挙型で定義
enum SCENE {
	TITLE,
	STAGE,
	CLEAR
};

//シーン内での処理を行う基底クラス
class BaseScene {
protected:
	//シーン番号を管理する変数
	static int sceneNo;

public:
	//継承先で継承される関数
	//抽象クラスなので純粋仮想関数とする
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() = 0;

	//仮想デストラクタを用意しないと警告される
	virtual ~BaseScene();

	//シーン番号のゲッター
	int GetSceneNo();

};
