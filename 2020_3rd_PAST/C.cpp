#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000000;
ll INF = 11451419194545;

ll useMod = 0;
ll fast_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1);
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a % MOD, n / 2);
    }
}


int main(){

    ll A, R, N;
    cin >> A >> R >> N;

    if(A <= 1000000000 && R == 1){
        cout << A << endl;
        return 0;
    }
    
    for(ll i = 0; i < (N >= 30 ? 30 : N); i++){
        if(1000000000 < A * fast_pow(R, i)){
            cout << "large" << endl;
            return 0;
        }
    }

    cout << A * fast_pow(R, N-1) << endl;

}