#include "Help.h"
#include "SceneMgr.h"
#include "Dxlib.h"
#include "Input.h"

static int mImageHandle;	//�摜�n���h���i�[�p�ϐ�

//������
void Help_Initialize() {
    mImageHandle = LoadGraph("images/Tetris_title.png");  //�w�i�摜

}

//�I������
void Help_Finalize() {
    DeleteGraph(mImageHandle);//�摜�̉��

}

//�X�V
void Help_Update() {
    if (iKeyFlg == PAD_INPUT_2) { //X�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Menu); //�V�[�����Q�[����ʂɕύX
    }
}

//�`��
void Help_Draw() {
    DrawGraph(0, 0, mImageHandle, FALSE);

    SetFontSize(30);
    DrawString(20, 20, "�w���v���", 0xffffff, 0);

    SetFontSize(20);
    DrawString(20, 340, "�t�B�[���h������烉���_���ɗ������Ă���u���b�N��", 0xffffff, 0);
    DrawString(20, 360, "��肭���삵�A�z�u���Ă����p�Y���Q�[���ł��B", 0xffffff, 0);
    DrawString(20, 380, "1�񑵂����炻�̗񂪏�����悤�ɂȂ��Ă���̂�", 0xffffff, 0);
    DrawString(20, 400, "�Q�[���I�[�o�[�ɂȂ�Ȃ��悤�ɏ��������悤", 0xffffff, 0);

    DrawString(150, 450, "---- X�L�[�������ă^�C�g���֖߂� ----", 0xffffff, 0);
}