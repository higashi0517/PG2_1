#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "math.h"

const char kWindowTitle[] = "LC1B_19_ヒガシ_サチエ_評価課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// 敵
	Enemy enemy;

	// プレイヤー
	Player player;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// 敵の更新
		enemy.Update();

		// プレイヤーの更新
		player.Update(preKeys, keys);

		// 衝突判定
		if (player.GetIsAlive()) {
			if (sqrtf
			((player.GetPos().x - enemy.GetPos().x) * (player.GetPos().x - enemy.GetPos().x) +
				(player.GetPos().y - enemy.GetPos().y) * (player.GetPos().y - enemy.GetPos().y)) < player.GetRadius() + enemy.GetRadius()) {

				player.SetIsAlive(false);
			}
		}

		// 弾と敵の衝突判定
		for (int i = 0; i < 10; i++) {
			if (player.GetBulletIsAlive(i)) {
				if (sqrtf
				((player.GetBulletPos(i).x - enemy.GetPos().x) * (player.GetBulletPos(i).x - enemy.GetPos().x) + 
					(player.GetBulletPos(i).y - enemy.GetPos().y) * (player.GetBulletPos(i).y - enemy.GetPos().y)) < player.GetBulletRadius(i) + enemy.GetRadius()) {

					player.SetBulletIsAlive(i, false);
					enemy.SetIsAlive(false);
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 敵の描画
		enemy.Draw();

		// プレイヤーの描画
		player.Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
