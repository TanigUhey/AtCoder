#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

#define INF 2e9

#define REP(i,n) for(int i = 0; i < n;++i)
#define REPA(i,a,n) for(int i = a; i < n; ++i)
#define ALL(a) a.begin(), a.end()

using namespace std;

int main(void) {

	int N, a, b, c, sum = 0;
	vector<int> l(2001);

	cin >> N;

	vector<int> len(N);

	REP(i, N) {
		cin >> len[i];
		l[len[i]]++;
	}

	sort(ALL(len));

	REP(i, N){
		a = len[i];
		REPA(j, i + 1, N){
			b = len[j];
			int temp_sum = sum;
			for(int k = a + b - 1; k >= b ; k--){
				sum += l[k];
			}
			if(temp_sum != sum) sum -= l[a];
			j += b;
		}
	}

	cout << sum << endl;
	return 0;
}

// int main(void) {
//
// 	int N, sum = 1;
// 	string S;
//
// 	cin >> N >> S;
//
// 	char c = S[0];
//
// 	REPA(i, 1, N){
// 		if(c != S[i]){
// 			sum++;
// 		}
// 		c = S[i];
// 	}
//
// 	cout << sum << endl;
//
// 	return 0;
// }

// int main(void) {
//
// 	int N;
// 	long long int sum = 0;
//
// 	cin >> N;
//
// 	vector<int> d(N);
//
// 	REP(i, N) cin >> d[i];
//
// 	REP(i, N){
// 		REPA(j, i + 1, N){
// 			sum += d[i] * d[j];
// 		}
// 	}
//
// 	cout << sum << endl;
//
// 	return 0;
// }

// int main(void) {
//
// 	int A, B;
//
// 	cin >> A >> B;
//
// 	cout << (A > B * 2 ? A - (B * 2) : 0) << endl;
//
// 	return 0;
// }