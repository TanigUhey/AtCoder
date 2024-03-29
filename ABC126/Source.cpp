// ABC126.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"

//#include <string>
//#include <iostream>
//#include <algorithm>
//
//
//using namespace std;
//
//int main()
//{
//    
//	int N, K;
//	string S;
//	string smallS;
//
//	cin >> N >> K;
//
//	cin >> S;
//	smallS = S;
//
//	transform(S.cbegin(), S.cend(), smallS.begin(), tolower);
//
//	S[K-1] = smallS[K-1];
//
//	cout << S;
//
//	return 0;
//
//}


#include <string>
#include <iostream>

using namespace std;

int main()
{

	string S;
	int first, last;
	bool fYY = 0, fMM = 0;
	bool lYY = 0, lMM = 0;

	cin >> S;

	last = first = atoi(S.c_str());

	last = first % 100;
	first = first / 100;

	// is first YY? 
	if (first >= 0 && first < 100) {

		fYY = true;

		// is first MM?
		if (first > 0 && first < 13) {

			fMM = true;

		}
	}

	// is last YY? 
	if (last >= 0 && last < 100) {
		lYY = true;

		// is first MM?
		if (last > 0 && last < 13) {

			lMM = true;

		}
	}

	string output;

	if (fYY && lYY) {

		if (fMM) {

			if (lMM) {
				output = "AMBIGUOUS";
			}
			else {
				output = "MMYY";
			}
		}
		else if(lMM) {
			output = "YYMM";
		}
		else
		{
		output = "NA";
		}


	}
	else {
		// neither first and last Year or month

		output = "NA";
	}

	cout << output << endl;

	return 0;

}


//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//int main()
//{
//
//	double sum = 0;
//	double p = 0;
//
//	int N, K, point;
//
//
//	cin >> N >> K;
//
//	const double dice_p = 1.0 / N;
//
//	// もし時間がかかるなら
//	// 最初のポイントがN/2以上のときは確率は同じ → 試行回数半分
//
//
//	// 最初にiが出たとき
//	for (int i = 1; i <= N; ++i) {
//		point = i;
//		p = dice_p;
//
//		while (point <= K) {
//
//			p *= 0.5;
//			point *= 2;
//
//		}
//
//		sum += p;
//	}
//
//	cout << std::setprecision(13) << sum;
//
//	return 0;
//
//}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
