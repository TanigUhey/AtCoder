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
//	int A, B, C;
//
//	cin >> A >> B >> C;
//
//	C = C - max(0, min(A - B, C));
//
//	cout << C << '\n';
//
//	return 0;
//}

//int main(void) {
//
//	int N;
//
//	cin >> N;
//
//	int ans = 0;
//
//	ans += min(9, N);
//	
//	if (N > 99) {
//		ans += min(N - 99, 900);
//	}
//	if (N > 9999) {
//		ans += min(N - 9999, 90000);
//	}
//
//
//	cout << ans << '\n';
//
//	return 0;
//}

//int main(void) {
//
//	int N;
//
//	cin >> N;
//
//	vector<int> H(N);
//
//	REP(i, N) cin >> H[i];
//
//	int max = H[0] - 1;
//
//	REP(i, N) {
//		if (max < H[i]) {
//			max = H[i] - 1;
//		}
//		if (max > H[i]) {
//			cout << "No\n";
//			return 0;
//		}
//	}
//
//	cout << "Yes\n";
//
//	return 0;
//}


int main(void) {

	string S;

	cin >> S;
	
	int N = S.size();

	vector<int> c(N, 0);
	int length;

	REP(i, N) {
		REPA(j, i+1, N) {
			if (S[j] == 'L') {
				REPA(k, j, N) {
					if (S[k] == 'R' || k == N - 1) {
						if (k == N - 1) k++;
						length = k - i;
						if (length % 2 == 0) {
							c[j] = length / 2;
							c[j - 1] = length / 2;
						}
						else {
							if ((j - i) > (k - j)) { // R‚Ì•û‚ª‘½‚¢
								if ((j - i) % 2 == 0) { // R‚ª‹ô”ŒÂ
									c[j] = (length + 1) / 2;
									c[j - 1] = (length - 1) / 2;
								}
								else { // R‚ªŠï”ŒÂ
									c[j] = (length - 1) / 2;
									c[j - 1] = (length + 1) / 2;
								}
								
							}
							else { // L‚Ì•û‚ª‘½‚¢
								if ((k - j) % 2 == 0) { // L‚ª‹ô”ŒÂ
									c[j] = (length - 1) / 2;
									c[j - 1] = (length + 1) / 2;
								}
								else { // L‚ªŠï”ŒÂ
									c[j] = (length + 1) / 2;
									c[j - 1] = (length - 1) / 2;
								}
								
							}
						}

						if (k == N - 1) i = k;
						else i = k - 1;
						break;
					}
				}
				
				break;
			}
		}
	}

	REP(i, N) cout << c[i] << ' ';
	cout << '\n';

	return 0;
}
