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
//		// 3Ç¬ÇÃÇ§Çøç≈ëÂílÇ∆ç≈è¨ílÇà¯Ç¢Çƒp[i]Ç∆àÍívÇµÇΩÇÁ2î‘ñ⁄
//		int sum = p[i - 1] + p[i] + p[i + 1];
//
//		// Ç∑Ç◊ÇƒìôÇµÇ¢èÍçá2î‘ñ⁄Ç…è¨Ç≥Ç≠Ç»Ç¢
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

	// ê¬ÇÇ®Ç¢ÇƒÇ›ÇÈ
	if (blue > 0) {
		narabi.push_back('b');
		ans += line_up(i - 1, red, blue - 1);
		narabi.pop_back();

		if (i > 0 && red > 0 && blue > 0) { // ê‘Çã≤ÇﬂÇÈÇ»ÇÁ
			narabi.push_back('r');
			ans += line_up(i, red - 1, blue);
			narabi.pop_back();
		}
	}

	if (i > 0 && red > 0) { // ê‘Çã≤ÇﬂÇÈÇ»ÇÁ
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