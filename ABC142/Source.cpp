#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

#define INF 2e9

#define REP(i,n) for(long long i = 0; i < n;++i)
#define REPA(i,a,n) for(long long i = a; i < n; ++i)
#define ALL(a) a.begin, a.end()

using namespace std;

long long CommonDivisor(long long a, long long b) {

	if (a == 1 && b == 1) return 1;

	long long ret = 0;
	long long small = min(a, b);
	REPA(i, 1, small + 1) {
		if (a%i == 0 && b%i == 0) ret++;
	}

	return ret;
}

bool is_primne_all(vector<long long>& c) {
	// すべて素？
	REP(i, c.size()) {
		REPA(j, i+1, c.size()) {
			if (CommonDivisor(c[i], c[j]) != 1) return false; // 約数の個数が1個じゃないつまり素でない
		}
	}

	return true;
}

long long divisor(vector<long long> c, vector<long long> d) {

	if (d.size() == 0) return c.size(); // dが空なら終わり

	long long ret; // = このときの最大の答え

	long long a = d.back(); // 先頭
	d.pop_back();
	
	ret = divisor(c, d); // aを入れずに次

	c.push_back(a); // aを入れて次
	if (is_primne_all(c)) { // 入れても全て素なら
		ret = max(ret, divisor(c, d)); // 入れてない場合と入れた場合大きい方をretへ
	}

	return ret;
}


int main(void) {

	long long A, B;

	cin >> A >> B;

	vector<long long> d; // 公約数のvector

	long long small = min(A, B);
	REPA(i, 1, small + 1) {
		if (A%i == 0 && B%i == 0) d.push_back(i);
	}

	long long size = d.size();

	vector<long long> primers;

	long long ans = divisor(primers, d);
	
	cout << ans << endl;

	return 0;
}

//int main(void) {
//
//	int N;
//
//	cin >> N;
//
//	vector<pair<int, int>> A(N);
//	int num;
//
//	REP(i, N) {
//		cin >> num;
//		A[i] = make_pair(num, i + 1);
//	}
//
//	sort(A.begin(), A.end());
//
//	REP(i, N - 1) cout << A[i].second << ' ';
//	cout << A.back().second << endl;
//
//	return 0;
//}

//int main(void) {
//
//	int N;
//
//	cin >> N;
//
//	cout << ((N + 1) / 2) / (double)N << endl;
//
//	return 0;
//}

//int main(void) {
//
//	int N, K;
//
//	cin >> N >> K;
//
//	int height, count = 0;
//
//	REP(i, N) {
//		cin >> height;
//		if (height >= K) count++;
//	}
//
//	cout << count << endl;
//
//	return 0;
//}