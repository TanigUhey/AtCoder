//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int N, A, B;
//
//	cin >> N >> A >> B;
//
//	cout << min(N*A, B) << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//double distance(const vector<int>& p1, const vector<int>& p2) {
//
//	int p1_size = p1.size();
//	double d = 0;
//
//	if (p1_size != p2.size()) return 0.1; // –â‘è‚É‰e‹¿‚µ‚È‚¢‚æ‚¤‚É®”‚¶‚á‚È‚¢’l‚ğ•Ô‚·
//
//	for (int i = 0; i < p1_size; ++i) {
//		d += pow(abs(p1[i] - p2[i]), 2);
//	}
//
//	return sqrt(d);
//}
//
//int main(void) {
//
//	int N, D, integer = 0;
//	double d;
//
//	cin >> N >> D;
//
//	vector<vector<int>> X;
//
//	for (int i = 0; i < N; ++i) {
//		vector<int> point(D);
//		for (int j = 0; j < D; ++j) {
//			cin >> point[j];
//		}
//		X.push_back(point);
//	}
//
//	for (int i = 0; i < N - 1; ++i) {
//		for (int j = i + 1; j < N; ++j) {
//			d = distance(X[i], X[j]);
//
//			if (ceil(d) == floor(d)) integer++;
//		}
//	}
//
//	cout << integer << endl;
//
//	return 0;
//}


#include <iostream>

using namespace std;

int main(void) {

	int L, R, si, sj, min = 2019;

	cin >> L >> R;

	for (int i = L; i < R && i < L + 2019; ++i) {
		si = i % 2019;
		for (int j = i + 1; j < R + 1 && j < i + 2019; ++j) {
			sj = (si * j) % 2019;

			if (sj < min) {
				min = sj;
				if (min == 0) cout << min << endl; return 0;
			}
				

		}
	}

	cout << min << endl;

	return 0;
}
