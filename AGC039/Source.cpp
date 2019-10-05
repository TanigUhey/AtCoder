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
	char c1, c2; // ���݂̕����A��O�ɒ��ׂ�����
	int index1 = 0, index2 = size; // �����琔����2��ޖڂ̕����̈ʒu�A������
	int len = 1;
	long long ans = 0;

	c1 = S[0];
	c2 = S.back();
	if (c1 == c2) { // �擪�Ɩ����̕���������
		index1++;
		index2--;
		REPA(i, 1, size) { // �擪�����������Ă�H
			if (c1 != S[i]) {
				break;
			}
			index1++;
		}
		
		for (int i = size - 2; i >= 0; i--) { // ���������������Ă�H
			c1 = S[i];
			if (c1 != c2) {
				break;
			}
			index2--;
		}
	}

	// �������S�ē�����index1�͖������z���Aindex2�͐擪���w���Ă���
	if (index1 > index2) {
		cout << (size * K) / (long long)2 << endl;
		return 0;
	}

	// �擪�����Ɋ֌W�Ȃ��u�����Ȃ���΂����Ȃ����𐔂���
	c2 = S[index1];
	REPA(i, index1 + 1, index2 + 1) {
		c1 = S[i];
		if (c1 == c2) {
			REPA(j, i, index2 + 1) { // �����������Ă�H
				c2 = S[j];
				if (c1 == c2) {
					len++;
				}
				else {
					break;
				}
				i++;
			}
			ans += len / (long long)2; // �u���񐔂�[�A������������/2]��(�؂�̂�)
			len = 1;
		}
		else c2 = c1;
	}
	ans *= K;

	// ���E�̐� = K-1
	len = index1 + (size - index2);
	ans += (K - 1) * (long long)(len / 2);

	// �擪
	ans += index1 / 2;

	// ����
	ans += (size - index2) / 2;

	cout << ans << endl;
	
	return 0;
}