//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//	char S[5];
//
//	cin >> S;
//
//	char str = S[0];
//
//	for (int i = 1; i < 4; ++i) {
//		
//		if (S[i] == str) {
//			cout << "Bad" << endl;
//			return 0;
//		}
//		str = S[i];
//	}
//
//	cout << "Good" << endl; 
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <numeric>
//
//using namespace std;
//
//int main(void) {
//
//
//	int N, L;
//
//	cin >> N >> L;
//
//	vector<int> ringo(N);
//
//	iota(ringo.begin(), ringo.end(), L);
//
//	int aji;
//
//	if (L > 0) { //ëSÇƒê≥
//		aji = accumulate(ringo.begin() + 1, ringo.end(), 0);
//	}
//	else {
//		if (N <= abs(L)) { // ëSÇƒïâ
//			aji = accumulate(ringo.begin(), ringo.end() - 1, 0);
//		}
//		else { // 0Ç™ë∂ç›Ç∑ÇÈ
//			aji = accumulate(ringo.begin(), ringo.end(), 0);
//		}
//	}
//
//	cout << aji << endl;
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int gcd(unsigned long long int lnum, unsigned long long int rnum) {
	int m = lnum;
	int n = rnum;

	if (rnum > lnum) {
		m = rnum;
		n = lnum;
	}

	unsigned long long int r = n % m;
	while (r != 0) {
		n = m;
		m = r;
		r = n % m;
	}


	return m;
}

int lcm(unsigned long long int lnum, unsigned long long int rnum) {
	return lnum * rnum / gcd(lnum, rnum);
}

int main(void) {

	vector<bool> seisuu;
	unsigned long long int A, B, C, D;

	cin >> A >> B >> C >> D;

	unsigned long long int range = B - A + 1, lcmCD = lcm(C, D), dividableC, dividableD, dividableCD;
	
	dividableC = B / C;
	dividableD = B / D;
	dividableCD = B / lcmCD;
	cout << range - dividableC - dividableD + dividableCD << endl;

	dividableC -= (A - 1) / C;
	dividableD -= (A - 1) / D;
	dividableCD -= (A - 1) / lcmCD;

	cout << range - dividableC - dividableD + dividableCD << endl;

	return 0;
}