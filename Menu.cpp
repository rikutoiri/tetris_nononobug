#include"Menu.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include"Input.h"

#define PI 3.1415926535897932384626433832795f


static int mImageHandle; //画像ハンドル格納用変数

static int mImageTitle; 	// 画像ハンドル格納用変数
static int mImageCone;	
static int mImageMenu;

static int MenuNumber = 0;  //メニューカーソル管理用変数

static int mSoundsSelect;   //音ファイル格納用変数
static int mSoundsMove;

// 初期化
void Menu_Initialize() {
    mImageHandle = LoadGraph("images/Tetris_title.png"); //画像のロー
    mImageTitle = LoadGraph("images/Tetris_title.png");     //画像のロード
    mImageCone = LoadGraph("images/Tmino.png");
    //mImageMenu = LoadGraph("images/menu_r.png");

    mSoundsSelect = LoadSoundMem("sounds/決定、ボタン押下8.mp3");    //決定音のロード
    mSoundsMove = LoadSoundMem("sounds/カーソル移動11.mp3");    //移動音のロード

    // ＢＧＭ再生
    PlayMusic("sounds/yamiyouen.mp3", DX_PLAYTYPE_LOOP);
}

// 終了処理
void Menu_Finalize() {

    DeleteGraph(mImageHandle); //画像の解放
    DeleteGraph(mImageTitle);       // 画像の解放
    DeleteGraph(mImageCone);
    DeleteGraph(mImageMenu);

    StopSoundMem(mSoundsSelect);
    StopSoundMem(mSoundsMove);

    // ＢＧＭ停止
    StopMusic();
}

//更新
void Menu_Update() {
    //メニューカーソル移動処理
    if (iKeyFlg & PAD_INPUT_DOWN) {
        PlaySoundMem(mSoundsMove, DX_PLAYTYPE_BACK);
        if (++MenuNumber > 3) MenuNumber = 0;
    }
    if (iKeyFlg & PAD_INPUT_UP) {
        PlaySoundMem(mSoundsMove, DX_PLAYTYPE_BACK);
        if (--MenuNumber < 0) MenuNumber = 3;
    }

    if (iKeyFlg == PAD_INPUT_1) { //Zキーが押されていたら
        switch (MenuNumber) {       //シーンによって処理を分岐
        case 0:    //現在の画面がメニューなら
            SceneMgr_ChangeScene(eScene_Game); //シーンをゲーム画面に変更
            break;
        case 1:
            SceneMgr_ChangeScene(eScene_Help); //シーンをゲーム画面に変更
            break;
        case 2:
            SceneMgr_ChangeScene(eScene_Rank);	//
            break;
        case 3:
            SceneMgr_ChangeScene(eScene_End);	//
            break;
        }
    }

}

//// 描画
//void Menu_Draw() {
//	DrawGraph(0, 0, mImageTitle, FALSE );
//
//    // メニュー
//    DrawGraph(280, 340, mImageMenu, TRUE);
//
//    // メニューカーソル
//    DrawRotaGraph(245, 360 + MenuNumber * 40, 0.7f, PI / 2, mImageCone, TRUE);
//
//}

void Menu_Draw() {
    DrawGraph(0, 0, mImageHandle, FALSE);
    SetFontSize(40);
    DrawString(350, 330, "START", GetColor(255, 255, 255));
    DrawString(350, 370, "HELP", GetColor(255, 255, 255));
    DrawString(350, 410, "RANKING", GetColor(255, 255, 255));
    DrawString(350, 450, "END", GetColor(255, 255, 255));
    //
    DrawGraph(120, 245, mImageMenu, TRUE);
    //
    DrawRotaGraph(320, 345 + MenuNumber * 40, 0.7f, PI / 2, mImageCone, TRUE);

    //SetFontSize(20);
    //DrawString(180,450,"-- 右クリックでタイトル --",0xFF0000);
}