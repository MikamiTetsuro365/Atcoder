#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll fast_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1);
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a, n / 2);
    }
}

int main() {
    ll N = 0;
    cin >> N;

    //多分10の倍数は現れない
    if(N % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
    ll cn = 10;
    vector<ll > A(18, 0);

    for(ll i = 1; i <= 18; i++){
        A[i-1] = N / fast_pow(10, i);
        cout << A[i-1] << endl;
    }

    ll tmp = 0;
    for(ll i = 18; i >= 1; i--){
        A[i-1] -= tmp;
        tmp += A[i-1] * (9 * i);
        cout << A[i-1] << endl;
    }

    ll ans = 0;
    for(ll i = 18; i >= 1; i--){
        //cout << ":" << A[i-1] << endl;
        ans += A[i-1] * i;
        //ans -= tmp;
        //tmp += A[i-1] * i;
        //cout << tmp << endl;
    }

    cout << ans << endl;
}