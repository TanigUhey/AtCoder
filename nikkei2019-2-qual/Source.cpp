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
template<typename A> void psn(A a){ cout << a << endl; }
template<typename A, typename... B> void psn(A a, B... b){ cout << a << ' '; psn(b...); }

int main(void) {
    
    int N, a, count = 0;
    ll sum = 1, temp = 0, m = 998244353;
    cin >> N;
    
    vi A(N);
    vector<ll> D(N, 0);
    REP(i, N) {
        cin >> A[i];
        D[A[i]]++;
    }

    if(N == 1){
        if(D[0] == 1) psn(1);
        else psn(0);
        return 0;
    }
    
    if(A[0] != 0) {
        psn(0);
        return 0;
    }

    REP(i, N - 1){
        if(D[i] == 0 && count != N){ // 途中で辺がなくなる場合
            psn(0);
            return 0;
        }
        if(i == 0 && D[i] != 1){ // 頂点が一つでない場合
            psn(0);
            return 0;
        }
        
        count += D[i]; // 計算済みの頂点の数
        if(i == 0){
            sum = 1;
            continue;
        }
        
        if(D[i - 1] == 1) continue;
        
        // sum *= pow(D[i-1], D[i]);
        // Dが大きいとmで割る前にオーバーフローしてしまう
        temp = D[i];
        while(temp > 0){
            sum = (sum * D[i - 1]) % m;
            temp--;
        }
    }
    
    psn(sum);
    
    return 0;
}


// int main(void) {
//
//     int N;
//
//     cin >> N;
//
//     if(N % 2 == 0){
//         psn((N / 2) - 1);
//     } else {
//         psn((N / 2));
//     }
//
//     return 0;
// }