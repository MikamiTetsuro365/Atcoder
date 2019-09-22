#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

ll fast_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1) % mod;
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a % mod, n / 2) % mod;
    }
}

//等差数列の和 初項a 公比r 項数n
ll tousa_sum(ll a, ll r, ll n){
    ll sum = a * (fast_pow(r, n) - 1 ) * fast_pow((r - 1), mod - 2);
    return sum;
}
//https://oeis.org/A097166
int main(){

    ll N;
    cin >> N;
    
    //ll ans = (4 * fast_pow(10, N) - 1) * fast_pow(3, mod - 2) % mod;
    ll ans = (fast_pow(10, N) + tousa_sum(3, 10, N) ) % mod;

    cout << ans << endl;

} 