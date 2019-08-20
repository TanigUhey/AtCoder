#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

#define INF 2e9

#define REP(i,n) for(int i = 0; i < n;++i)
#define REPA(i,a,n) for(int i = a; i < n; ++i)
#define ALL(a) a.begin, a.end()

using namespace std;

//int main(void) {
//
//	int a;
//	string s;
//
//	cin >> a >> s;
//
//	if (a >= 3200) cout << s << '\n';
//	else cout << "red\n";
//
//	return 0;
//}

//int main(void) {
//
//	int N;
//
//	cin >> N;
//
//	vector<int> A(N);
//
//	double sum = 0;
//
//	REP(i, N) cin >> A[i];
//
//	REP(i, N) {
//		sum += 1.0 / A[i];
//	}
//
//	cout << std::fixed;
//	cout << setprecision(10) << 1.0 / sum << '\n';
//
//	return 0;
//}

//int main(void) {
//
//	int N;
//
//	cin >> N;
//
//	vector <double> V(N);
//
//	REP(i, N) cin >> V[i];
//
//	sort(V.begin(), V.end());
//
//	double half;
//
//	REP(i, N-1) {
//
//		half = (V[i] + V[i + 1]) / 2;
//		V[i + 1] = half;
//		sort(V.begin() + i + 1, V.end());
//
//	}
//
//	cout << V.back() << '\n';
//
//
//	return 0;
//}

vector<vector<int>> memo;

typedef struct node {

	int id;
	vector<reference_wrapper<node>> nodes;
	int count = 0;
	int size = 0;

} NODE;

vector<int>& count_up(NODE &node, int x, vector<int> &temp_memo) {

	if (node.size == 0) {
		node.count += x;
		temp_memo.push_back(node.id);
		return temp_memo;
	}

	for (auto &n : node.nodes) {
		count_up(ref(n), x, temp_memo);
	}

	node.count += x;
	temp_memo.push_back(node.id);
	return temp_memo;
}

int main(void) {

	int N, Q;

	cin >> N >> Q;

	vector<NODE> tree(N);

	int a, b, p, x;

	REP(i, N - 1) {
		cin >> a >> b;
		tree[a - 1].nodes.push_back(tree[b - 1]);
		tree[a - 1].size++;
		tree[i].id = i;
	}

	tree[N-1].id = N-1;

	vector<int> px(N, 0);

	REP(i, Q) {
		cin >> p >> x;
		px[p-1] += x;
	}

	memo.resize(N);

	REP(i, N) {
		if(memo[i].size() == 0) count_up(ref(tree[i]), px[i], memo[i]);
		else {
			int s = memo[i].size();
			REP(j, s) tree[memo[i][j]].count += px[i];
		}
	}

	REP(i, N-1) cout << tree[i].count << ' ';
	cout << tree[N - 1].count << '\n';

	return 0;
}