#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//MODを取る場所間違っててクソ！！！もっとわかりやすくかけ！
int main() {

    ll N, K;
    cin >> N >> K;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    //点灯数を求める
    //自分の右側にいくつ有るか
    vector<ll > r_T(N, 0);
    for(ll i = 0; i < N; i++){
        for(ll j = i + 1; j < N; j++){
            if(vec[i] > vec[j]) r_T[i]++;
        }
    }
    //自分の左側にいくつ有るか
    vector<ll > l_T(N, 0);
    for(ll i = N - 1; i >= 0; i--){
        for(ll j = i - 1; j >= 0; j--){
            if(vec[i] > vec[j]) l_T[i]++;
        }
    }

    ll sum = 0;
    for(ll i = 0; i < N; i++){
        sum += r_T[i] * K % MOD;
        sum %= MOD;
        //cout << r_T[i] + l_T[i] << endl;
        sum += (r_T[i] + l_T[i]) * (((K-1) * K) / 2 % MOD) % MOD;
        //sum += l_T[i] * (K-1) % MOD;
        sum %= MOD;
    }

    cout << sum << endl;

}