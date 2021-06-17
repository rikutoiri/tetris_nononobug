#pragma once

#define TILE_SIZE 12
#define MAP_WIDTH  14               // フィールドの幅
#define MAP_HEIGHT 25               // フィールドの高さ
#define WAIT 60

//bool put(int x, int y, byte t, int a, bool test)
//{
//	for (int j = 0; j < 4; j++) {
//		for (int i = 0; i < 4; i++) {
//			int p[] = { i,3 - j,3 - i,j };
//			int q[] = { j,i,3 - j,3 - i };
//			if (mBlock[t][ q[a]][ p[a]] == 0) {
//				continue;
//			}
//
//			byte v = t;
//			if (!s) {
//				v = 7
//			}
//			else if (mField[y + j][x + i] != 7) {
//				return(false);
//			}
//			if (!test) {
//				mField[y + j][ x + i] = v;
//			}
//		}
//	}
//	return(true);
//}



void Game_Initialize();//初期化
void Game_Finalize();//終了処理
void Game_Update();//更新
void Game_Draw();//描画

void Timer();


int Game_GetScore(); // スコアデータ取得