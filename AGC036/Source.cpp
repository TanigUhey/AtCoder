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

int main(void) {

	unsigned long long N, K;
	
	cin >> N >> K;

	vector<int> A(N), s;
	vector<int> l(200000, -1);
	int head = -1; // s�̐擪

	REP(i, N) cin >> A[i];

	typedef struct {
		int head;
		vector<int> s;
	}joutai;

	vector<joutai> state;

	for(unsigned long long i = 0; i < N*K; ++i) {
		if (i % N == 0 && state.size()) { // ������邽�тɈȑO�Ɠ�����Ԃ��Ȃ����`�F�b�N
			REP(j, state.size()) {
				if (state[j].head == head && state[j].s == s) { // ���e�ƃw�b�h����v
					unsigned long long skip = (N * K - i) / (((i / N) - j) * N);
					i += skip * N;
					break;
				}
			}
		}

		if (i >= N * K) break;

		if (i % N == 0) { // ������邽�тɏ�ԕۑ�
			state.push_back({ head, s });
		}

		if (l[A[i%N]] <= head && l[A[i%N]] != -1) { // ��ԑ����Y���̈ʒu�𒲂ׂđ��݂���ꍇ
			head = l[A[i%N]] - 1; // ���O�܂�head�𓮂��������폜
			s.resize(head + 1);
		}
		else {
			head++;
			if (s.size() <= head) s.push_back(A[i%N]);
			else s[head] = A[i%N];
			l[A[i%N]] = head;
		}
	}

	REP(i, head+1) {
		cout << s[i];
		if (i != head) cout << ' ';
	}

	cout << endl;

	return 0;
}