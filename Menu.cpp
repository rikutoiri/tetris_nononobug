#include"Menu.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include"Input.h"

#define PI 3.1415926535897932384626433832795f


static int mImageHandle; //�摜�n���h���i�[�p�ϐ�

static int mImageTitle; 	// �摜�n���h���i�[�p�ϐ�
static int mImageCone;	
static int mImageMenu;

static int MenuNumber = 0;  //���j���[�J�[�\���Ǘ��p�ϐ�

static int mSoundsSelect;   //���t�@�C���i�[�p�ϐ�
static int mSoundsMove;

// ������
void Menu_Initialize() {
    mImageHandle = LoadGraph("images/Tetris_title.png"); //�摜�̃��[
    mImageTitle = LoadGraph("images/Tetris_title.png");     //�摜�̃��[�h
    mImageCone = LoadGraph("images/Tmino.png");
    //mImageMenu = LoadGraph("images/menu_r.png");

    mSoundsSelect = LoadSoundMem("sounds/����A�{�^������8.mp3");    //���艹�̃��[�h
    mSoundsMove = LoadSoundMem("sounds/�J�[�\���ړ�11.mp3");    //�ړ����̃��[�h

    // �a�f�l�Đ�
    PlayMusic("sounds/yamiyouen.mp3", DX_PLAYTYPE_LOOP);
}

// �I������
void Menu_Finalize() {

    DeleteGraph(mImageHandle); //�摜�̉��
    DeleteGraph(mImageTitle);       // �摜�̉��
    DeleteGraph(mImageCone);
    DeleteGraph(mImageMenu);

    StopSoundMem(mSoundsSelect);
    StopSoundMem(mSoundsMove);

    // �a�f�l��~
    StopMusic();
}

//�X�V
void Menu_Update() {
    //���j���[�J�[�\���ړ�����
    if (iKeyFlg & PAD_INPUT_DOWN) {
        PlaySoundMem(mSoundsMove, DX_PLAYTYPE_BACK);
        if (++MenuNumber > 3) MenuNumber = 0;
    }
    if (iKeyFlg & PAD_INPUT_UP) {
        PlaySoundMem(mSoundsMove, DX_PLAYTYPE_BACK);
        if (--MenuNumber < 0) MenuNumber = 3;
    }

    if (iKeyFlg == PAD_INPUT_1) { //Z�L�[��������Ă�����
        switch (MenuNumber) {       //�V�[���ɂ���ď����𕪊�
        case 0:    //���݂̉�ʂ����j���[�Ȃ�
            SceneMgr_ChangeScene(eScene_Game); //�V�[�����Q�[����ʂɕύX
            break;
        case 1:
            SceneMgr_ChangeScene(eScene_Help); //�V�[�����Q�[����ʂɕύX
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

//// �`��
//void Menu_Draw() {
//	DrawGraph(0, 0, mImageTitle, FALSE );
//
//    // ���j���[
//    DrawGraph(280, 340, mImageMenu, TRUE);
//
//    // ���j���[�J�[�\��
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
    //DrawString(180,450,"-- �E�N���b�N�Ń^�C�g�� --",0xFF0000);
}