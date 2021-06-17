#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Input.h"

int Tile[11]; //�^�C��
int s;	//�T�C�Y
int v;	//
int x;	//x��
int y;	//y��
int i;	//�Y����
int j;	//�Y����

static int gameScore;

int mX, mY, mA, mWait;
int mT, mNext;
int mKeyL, mKeyR, mKeyX, mKeyZ;

bool mGameOver;

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�

int mBlock[7][4][4] = {
	{
		{0,0,0,0},		//�ԃu���b�N
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//�I�����W�u���b�N
		{0,1,1,1},
		{0,1,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//���F�u���b�N
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//�΃u���b�N
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//���F�u���b�N
		{1,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//�u���b�N
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//�s���N�u���b�N
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0},
	},
};

int mField[MAP_HEIGHT][MAP_WIDTH] = {	//�t�B�[���h
	{9,9,9,9,7,7,7,7,7,7,9,9,9,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,8,8,8,8,8,8,8,8,8,8,8,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

bool put(int x, int y, int t, int a, bool s, bool test)	//�u���b�N���o��  �{��
{
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			int p[] = { i,3 - j,3 - i,j };
			int q[] = { j,i,3 - j,3 - i };
			if (mBlock[t][q[a]][p[a]] == 0) {
				continue;
			}

			v = t;
			if (!s) {
				v = 7;
			}
			else if (mField[y + j][x + i] != 7) {
				return(false);
			}
			if (!test) {
				mField[y + j][x + i] = v;
			}
		}
	}
	return(true);
}

//������
void Game_Initialize() {
	//mImageHandle = LoadDivGraph("images/tile.png");

}
//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX

	}

	Timer();
	WaitTimer(16);

}

void next() {
	mX = 5;
	mY = 2;
	mT = mNext;
	mWait = WAIT;

	mA = 0;
	if (mKeyX > 0)mA = 3;
	if (mKeyZ > 0)mA = 1;

	if (!put(mX, mY, mT, mA, true, false)) {
		mGameOver = true;
	}

	put(5, -1, mNext, 0, false, false);
	mNext = GetRand(6);
	put(5, -1, mNext, 0, true, false);
}


void wait() {
	if (--mWait == 0) {
		next();
	}

	if (mWait == WAIT / 2 - 1) {
		for (int y = 22; y > 2; y--) {
			int n = 0;
			for (int x = 2; x < 12; x++) {
				if (mField[y][x] < 7) {
					n++;
				}
			}
			if (n != 10) {
				continue;
			}
			for (int x = 2; x < 12; x++) {
				mField[y][x] = 10;
			}
		}
	}
	if (mWait == 1) {
		for (int y = 22; y > 2; y--) {
			if (mField[y][2] != 10) {
				continue;
			}
			mWait = WAIT / 2 - 2;
			for (int i = y; i > 3; i--) {
				for (int x = 2; x < 12; x++) {
					mField[i][x] = mField[i - 1][x];
				}
			}
			for (int x = 2; x < 12; x++) {
				mField[3][x] = 7;
			}
			y++;
		}
	}
}

void tick() {
	if (mGameOver) {
		return;
	}
	if (mWait <= WAIT / 2) {
		wait();
		return;
	}

	put(mX, mY, mT, mA, false, false);

	int a = mA;
	if (mKeyX == 1) a--;
	if (mKeyZ == 1) a++;
	a &= 3;
	if (put(mX, mY, mT, a, true, true)) {
		mA = a;
	}
	int x = mX;
	if (mKeyL == 1 || mKeyL > 20)	x--;
	if (mKeyR == 1 || mKeyR > 20)	x++;
	if (put(x, mY, mT, mA, true, true)) {
		mX = x;
	}
	if (put(mX, mY + 1, mT, mA, true, true)) {
		mY++;
		mWait = WAIT;
	}
	else {
		mWait--;
	}

	put(mX, mY, mT, mA, true, false);
}

void onPaint() {
	s = TILE_SIZE * 2;		//�^�C���̃T�C�Y2�{
	for (/*int*/ y = 0; y < MAP_HEIGHT; y++) {		//�t�B�[���h
		for (/*int */x = 0; x < MAP_WIDTH; x++) {
			DrawExtendGraph(x * s, y * s, x * s + s, y * s + s, Tile[mField[y][x]], FALSE);	//// �摜����ʂ����ς��ɕ`��

		}
	}
}

void Timer() {
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mKeyL++;
	}
	else {
		mKeyL = 0;
	}if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mKeyR++;
	}
	else {
		mKeyR = 0;
	}if (CheckHitKey(KEY_INPUT_X))
	{
		mKeyX++;
	}
	else {
		mKeyX = 0;
	}if (CheckHitKey(KEY_INPUT_Z))
	{
		mKeyZ++;
	}
	else {
		mKeyZ = 0;
	}
	tick();
	onPaint();
}

//�`��
void Game_Draw() {

	LoadDivGraph("images/tile.png", 11, 11, 1, TILE_SIZE, TILE_SIZE, Tile);	//�摜����
	mNext = GetRand(6);
	next();

}


int Game_GetScore() {
	return gameScore;
}