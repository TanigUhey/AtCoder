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
    
    ll sum = 0;
    string S;
    
    cin >> S;
    
    int N = S.size();
    
    vi nums(N + 1, 0);
    
    REP(i, N){
        if(S[i] == '<'){ // 右に向かって調べる
            nums[i] = 0;
            REPA(j, i + 1, N){
                i++;
                nums[j] = nums[j - 1] + 1;
                if(S[j] == '>') break;
            }
        }
    }
    
    // 一番右端N+1を処理
    if(S[N - 1] == '<') nums[N] = nums[N - 1] + 1;
    else nums[N + 1] = 0;
    
    REPR(i, N - 1){
        if(S[i] == '>'){ // 左に向かって調べる
            nums[i + 1] = 0;
            REPR(j, i - 1){
                i--;
                // さっき調べた時より高くなければいけないなら上書き
                if(nums[j + 2] + 1 > nums[j + 1]) nums[j + 1] = nums[j + 2] + 1;
                if(S[j] == '<') break;
            }
        }
    }
    
    // 一番左端N+1を処理
    if(S[0] == '>') {
        if(nums[1] + 1 > nums[0]) nums[0] = nums[1] + 1;
    }
    else nums[0] = 0;
    
    REP(i, N + 1) sum += nums[i];

    psn(sum);
    
    return 0;
}