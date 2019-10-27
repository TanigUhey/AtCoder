#include <bits/stdc++.h>

#define INF 2e9

#define REP(i,n) for(int i = 0; i < n;++i)
#define REPA(i,a,n) for(int i = a; i < n; ++i)
#define REPR(i,a) for(int i = a; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }
template<typename A> void printsn(A a){ cout << a << endl; }
template<typename A, typename... B> void printsn(A a, B... b){ cout << a << ' '; printsn(b...); }

int main() {

    int a, b, x;

    cin >> a >> b >> x;

    double h = x / (a * a); // 水が溜まっている高さ
    double r = 45.0;

    double beta;

    if(b / 2 >= h){ // 半分か少ない
        beta = (b * 2) - (h * 2); // 現在の高さが半分の筒に延長する
    }

    double l = (x * 2) / sqrt(a * a + b * b);
    double t = sqrt(l * l - beta * beta);
    double cosl = (t * t + beta * beta - l * l) / (2 * l * t);

    printsn(l, t, beta, cosl);

    return 0;
}

// int main() {
//
//     ll N, min = 1000000000001;
//
//     cin >> N;
//
//     double times = sqrt(N);
//
//     for(ll i = 1; i < 1000001; i++){
//         if(N % i == 0){
//             if(min > i + (ll)(N / i) - 2){
//                 min = i + (ll)(N / i) - 2;
//             }
//         }
//     }
//
//     printsn(min);
//
//     return 0;
//}

// int main() {
//
//     int N;
//
//     cin >> N;
//
//     REP(i, 9){
//         REPA(j, i, 9){
//             if((i + 1) * (j + 1) == N) {
//                 printsn("Yes");
//                 return 0;
//             }
//         }
//     }
//
//     printsn("No");
//
//     return 0;
// }

// int main(void) {
//
//     int A, B;
//
//     cin >> A >> B;
//
//     if(A < 10 && B < 10) printsn(A * B);
//     else printsn(-1);
//
//     return 0;
// }