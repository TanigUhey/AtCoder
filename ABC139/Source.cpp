#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>

#define INF 2e9

#define REP(i,n) for(int i = 0; i < n;++i)
#define REPA(i,a,n) for(int i = a; i < n; ++i)
#define ALL(a) a.begin, a.end()

using namespace std;

//int main(void) {
//
//	string S, T;
//
//	cin >> S >> T;
//
//	int correct = 0;
//
//	if (S[0] == T[0]) correct++;
//	if (S[1] == T[1]) correct++;
//	if (S[2] == T[2]) correct++;
//
//	cout << correct << '\n';
//
//	return 0;
//}

//int main(void) {
//
//	int A, B, count = 0, socket = 1;
//
//	cin >> A >> B;
//
//	if (B == 1) {
//		cout << count << '\n';
//		return 0;
//	}
//
//	socket = A;
//	count++;
//
//	while (B > socket) {
//		count++;
//		socket += A - 1;
//	}
//
//	cout << count << '\n';
//
//	return 0;
//}

//int main(void) {
//
//	int N, count = 0, max = 0;
//
//	cin >> N;
//
//	vector<int> H(N);
//
//	REP(i, N) cin >> H[i];
//
//	for (int i = N - 1; i > 0; i--) {
//		if (H[i] <= H[i - 1]) count++;
//		else {
//			if (max < count) max = count;
//			count = 0;
//		}
//	}
//
//	if (max == 0) max = count;
//	cout << max << '\n';
//
//	return 0;
//}

//int main(void) {
//
//	long N;
//
//	cin >> N;
//
//	long long max = ((N * (N + 1)) / 2) - N;
//
//	cout << max << '\n';
//	
//	return 0;
//}

typedef struct {
	int enemy;
	int is_finsh; // 0:no 1:ing 2:yes
}GAME;

int main(void) {

	int N;

	cin >> N;

	vector<vector<GAME>> A(N);
	vector<vector<int>> game_finish;

	REP(i, N) {
		REP(j, N - 1) { // jはそのまま優先度
			cin >> A[i][j].enemy;
			A[i][j].is_finsh = 0;
		}

		
	}
	
	int day = 1;

	REP(i, N) {
		REP(j, N - 1) {
			if (A[i][j].is_finsh != 2) { // 試合が始まっていないか対戦相手が準備完了
				game_finish[i][A[i][j].enemy] = 1; // この日に試合開始
			}
		}
	}

	return 0;
}