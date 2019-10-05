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

	string S;
	long long K;

	cin >> S >> K;
	int size = S.size();
	char c1, c2; // 現在の文字、一つ前に調べた文字
	int index1 = 0, index2 = size; // 頭から数えて2種類目の文字の位置、末尾版
	int len = 1;
	long long ans = 0;

	c1 = S[0];
	c2 = S.back();
	if (c1 == c2) { // 先頭と末尾の文字が同じ
		index1++;
		index2--;
		REPA(i, 1, size) { // 先頭何文字続いてる？
			if (c1 != S[i]) {
				break;
			}
			index1++;
		}
		
		for (int i = size - 2; i >= 0; i--) { // 末尾何文字続いてる？
			c1 = S[i];
			if (c1 != c2) {
				break;
			}
			index2--;
		}
	}

	// 文字が全て同じ時index1は末尾を越え、index2は先頭を指している
	if (index1 > index2) {
		cout << (size * K) / (long long)2 << endl;
		return 0;
	}

	// 先頭末尾に関係なく置換しなければいけない数を数える
	c2 = S[index1];
	REPA(i, index1 + 1, index2 + 1) {
		c1 = S[i];
		if (c1 == c2) {
			REPA(j, i, index2 + 1) { // 何文字続いてる？
				c2 = S[j];
				if (c1 == c2) {
					len++;
				}
				else {
					break;
				}
				i++;
			}
			ans += len / (long long)2; // 置換回数は[連続した文字列長/2]回(切り捨て)
			len = 1;
		}
		else c2 = c1;
	}
	ans *= K;

	// 境界の数 = K-1
	len = index1 + (size - index2);
	ans += (K - 1) * (long long)(len / 2);

	// 先頭
	ans += index1 / 2;

	// 末尾
	ans += (size - index2) / 2;

	cout << ans << endl;
	
	return 0;
}