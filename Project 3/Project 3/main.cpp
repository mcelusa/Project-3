#include "DxLib.h"
#include "Scene.h"

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 720;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetMainWindowText("Sample");
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	SetBackgroundColor(15, 35, 42);
	if (DxLib_Init() == -1) return -1;

	Scene* scene = new Scene();
	
	while (true)
	{
		ClearDrawScreen();// 画面クリア
		//---------  ここからプログラムを記述  ----------//


		scene->Update();


		//---------  ここまでにプログラムを記述  ---------//
		ScreenFlip();
		WaitTimer(20);
		if (ProcessMessage() == -1) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
