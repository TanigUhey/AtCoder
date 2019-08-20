//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int P, Q, R, sum;
//
//	cin >> P >> Q >> R;
//
//	if (P < Q) {
//		sum = P;
//		sum += min(Q, R);
//	}
//	else {
//		sum = Q;
//		sum += min(P, R);
//	}
//
//	cout << sum << endl; 
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//
//	int N, weight, S1 = 0, S2 = 0, sum = 0, min = 100 * 100;
//	vector<int> W;
//
//	cin >> N;
//
//	for (int i = 0; i < N; ++i) {
//		cin >> weight;
//		W.push_back(weight);
//		sum += weight;
//	}
//
//	S1 = sum;
//
//	for (int T = 0; T < N; ++T) {
//		S1 -= W[T];
//		S2 += W[T];
//		if (abs(S1 - S2) < min) {
//			min = abs(S1 - S2);
//		}
//	}
//
//	cout << min << endl;
//}

#include <iostream>
#include <vector>

using namespace std;

int down_stairs(const vector<int>& a, int stair_num, int danger) {

	if (stair_num == danger) {
		return 1;
	}
	else if (stair_num < danger) {
		return 0;
	}

	long result = 0;

	if (stair_num - 1 >= 0) 
		result += down_stairs(a, stair_num - 1, danger); // ˆê’i~‚è‚é
	
		

	if (stair_num - 2 >= 0)
		result += down_stairs(a, stair_num - 2, danger); // “ñ’i~‚è‚é
	
		

	
	return result;
}

int main(void) {

	int N, M, danger;

	vector<int> a;

	cin >> N >> M;

	a.push_back(-1);

	for (int i = 0; i < M; ++i) {
		cin >> danger;
		a.push_back(danger);
		
	}

	long result = 1;
	int pre_danger = N + 1;

	for (int i = 0; i < M + 1; ++i) {

		danger = a.back();
		result *= down_stairs(a, pre_danger - 1, danger + 1);
		a.pop_back();
		pre_danger = danger;
	}
	
	

	result = result % 1000000007;

	cout << result << endl;
}
