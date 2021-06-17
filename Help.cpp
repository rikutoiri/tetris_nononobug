#include "Help.h"
#include "SceneMgr.h"
#include "Dxlib.h"
#include "Input.h"

static int mImageHandle;	//画像ハンドル格納用変数

//初期化
void Help_Initialize() {
    mImageHandle = LoadGraph("images/Tetris_title.png");  //背景画像

}

//終了処理
void Help_Finalize() {
    DeleteGraph(mImageHandle);//画像の解放

}

//更新
void Help_Update() {
    if (iKeyFlg == PAD_INPUT_2) { //Xキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu); //シーンをゲーム画面に変更
    }
}

//描画
void Help_Draw() {
    DrawGraph(0, 0, mImageHandle, FALSE);

    SetFontSize(30);
    DrawString(20, 20, "ヘルプ画面", 0xffffff, 0);

    SetFontSize(20);
    DrawString(20, 340, "フィールド上方からランダムに落下してくるブロックを", 0xffffff, 0);
    DrawString(20, 360, "上手く操作し、配置していくパズルゲームです。", 0xffffff, 0);
    DrawString(20, 380, "1列揃ったらその列が消えるようになっているので", 0xffffff, 0);
    DrawString(20, 400, "ゲームオーバーにならないように消し続けよう", 0xffffff, 0);

    DrawString(150, 450, "---- Xキーを押してタイトルへ戻る ----", 0xffffff, 0);
}