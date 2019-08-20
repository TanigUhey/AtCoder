#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 2e9

#define REP(i,n) for(int i = 0; i < n;++i)
#define REPA(i,a,n) for(int i = a; i < n; ++i)
#define ALL(a) a.begin, a.end()

using namespace std;

//int main(void) {
//
//	long A, B, K;
//
//	cin >> A >> B;
//
//	long c = abs(A - B);
//
//	if (c % 2 != 0) {
//		cout << "IMPOSSIBLE\n";
//		return 0;
//	}
//
//	K = max(A, B) - (c / 2);
//
//	cout << K << '\n';
//
//	return 0;
//}

//int main(void) {
//
//	int N;
//
//	cin >> N;
//
//	vector<int> p(N + 1);
//
//	int pi = 0, pj = 0;
//
//	REP(i, N) {
//		cin >> p[i];
//
//		if (p[i] != i + 1) {
//			if (pi == 0) {
//				pi = i + 1;
//			}
//			else if (pj == 0) {
//				pj = i + 1;
//			}
//			else {
//				cout << "NO\n";
//				return 0;
//			}
//		}
//	}
//
//	if (pi == 0) {
//		cout << "YES\n";
//	}
//	else if (pj == 0) {
//		cout << "NO\n";
//	}
//	else if (pi == p[pj-1] && p[pi-1] == pj) {
//		cout << "YES\n";
//	}
//	else {
//		cout << "NO\n";
//	}
//
//	return 0;
//}


//int main(void) {
//
//	int N;
//	long kill = 0, sum = 0;
//
//	cin >> N;
//
//	vector<long> A(N + 1), B(N);
//
//	REP(i, N + 1) cin >> A[i];
//	REP(i, N) cin >> B[i];
//
//	REP(i, N) {
//		kill = min(A[i], B[i]);
//		A[i] -= kill;
//		B[i] -= kill;
//		sum += kill;
//		if (B[i] != 0) {
//			kill = min(A[i+1], B[i]);
//			A[i+1] -= kill;
//			B[i] -= kill;
//			sum += kill;
//		}
//	}
//
//	cout << sum << "\n";
//
//	return 0;
//}

int main(void) {

	string S;

	cin >> S;
	


	cout << "\n";

	return 0;
}