#pragma once

typedef enum
{
	eScene_Menu, //���j���[���
	eScene_Game, //�Q�[�����
	eScene_Help,
	eScene_Config, //�ݒ���
	eScene_Stop,
	eScene_Rank,
	eScene_End,		//
	eScene_None, //��
	��
} eScene;

void SceneMgr_Initialize();//������
void SceneMgr_Finalize();//�I������
void SceneMgr_Update();//�X�V
void SceneMgr_Draw();//�`��

// ���� nextScene�ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene);

int SceneMgr_GameEnd_Status();