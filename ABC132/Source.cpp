//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	std::string S;
//
//	cin >> S;
//
//	for (auto alphabet : S) {
//		if (count(S.begin(), S.end(), alphabet) != 2) {
//			cout << "No" << endl;
//			return 0;
//		}
//	}
//
//	cout << "Yes" << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int n;
//	cin >> n;
//
//	vector<int> p(n);
//
//	for (int i = 0; i < n; i++) cin >> p[i];
//
//	int ans = 0;
//	for (int i = 1; i < n - 1; i++) {
//		
//		// 3つのうち最大値と最小値を引いてp[i]と一致したら2番目
//		int sum = p[i - 1] + p[i] + p[i + 1];
//
//		// すべて等しい場合2番目に小さくない
//		if (p[i - 1] == p[i] && p[i] == p[i + 1]) continue;
//
//		sum -= max({ p[i - 1], p[i], p[i + 1] });
//		sum -= min({ p[i - 1], p[i], p[i + 1] });
//
//		if (sum == p[i]) ans++;
//	}
//	
//	cout << ans << endl;
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//
//	int N, half;
//	cin >> N;
//
//	vector<int> d(N);
//
//	for (int i = 0; i < N; i++){
//		cin >> d[i];
//	}
//
//	sort(d.begin(), d.end());
//
//	cout << d[N / 2] - d[(N / 2) - 1] << endl;
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> narabi;

long long int line_up(int i, int red, int blue) {

	long long int ans = 0;

	// 青をおいてみる
	if (blue > 0) {
		narabi.push_back('b');
		ans += line_up(i - 1, red, blue - 1);
		narabi.pop_back();

		if (i > 0 && red > 0 && blue > 0) { // 赤を挟めるなら
			narabi.push_back('r');
			ans += line_up(i, red - 1, blue);
			narabi.pop_back();
		}
	}

	if (i > 0 && red > 0) { // 赤を挟めるなら
		narabi.push_back('r');
		ans += line_up(i, red - 1, blue);
		narabi.pop_back();
	}

	if(blue == 0) for (int i = 0; i < narabi.size(); i++) cout << narabi[i];
	cout << i << "," << blue;
	cout << std::endl;
	return blue == 0 && i == 0 ? ++ans : ans;
}

int main(void) {

	int N, K;

	cin >> N >> K;

	int red = N - K, blue = K;

	cout << line_up(3, red, blue) << endl;

	return 0;
}